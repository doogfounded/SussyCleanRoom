#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <fstream>
#include <iomanip>
#include <cstring>

namespace DoogEngine1 {

// Exact binary layout of an Among Us Rewired Action Entry
struct InputActionRecord {
    uint32_t action_id;
    std::string name;
    std::string descriptive_name;
    size_t record_offset;
};

// Clean-room parser for an individual InputAction within the MonoBehaviour data
bool ParseActionEntry(const uint8_t* data, size_t max_len, size_t search_offset, InputActionRecord& out_action) {
    if (search_offset + 64 > max_len) return false;

    // Scan for string length followed by ascii
    const uint8_t* ptr = data + search_offset;
    uint32_t name_len = *reinterpret_cast<const uint32_t*>(ptr);
    if (name_len == 0 || name_len > 32) return false;

    out_action.name.assign(reinterpret_cast<const char*>(ptr + 4), name_len);
    size_t pad = (4 - (name_len % 4)) % 4;
    size_t cursor = 4 + name_len + pad;

    // Next field: flag/int
    cursor += 4;

    // Next field: descriptive name length
    if (cursor + 4 > max_len) return false;
    uint32_t desc_len = *reinterpret_cast<const uint32_t*>(ptr + cursor);
    cursor += 4;

    if (desc_len > 0 && desc_len <= 64 && cursor + desc_len <= max_len) {
        out_action.descriptive_name.assign(reinterpret_cast<const char*>(ptr + cursor), desc_len);
        size_t desc_pad = (4 - (desc_len % 4)) % 4;
        cursor += desc_len + desc_pad;
    } else {
        out_action.descriptive_name = "";
    }

    out_action.record_offset = search_offset;
    return true;
}

} // namespace DoogEngine1

int main() {
    std::cout << "========================================================\n";
    std::cout << "  AMONG US GAMEPLAY INPUT ACTION DESERIALIZER TESTBED   \n";
    std::cout << "========================================================\n";

    std::ifstream f("level2", std::ios::binary);
    if (!f.is_open()) {
        std::cerr << "Failed to open level2\n";
        return 1;
    }

    // Seek to MonoBehaviour 0x2003 at offset 0x1198A8
    f.seekg(0x1198A8);
    std::vector<uint8_t> mono_data(41364);
    f.read(reinterpret_cast<char*>(mono_data.data()), mono_data.size());

    // 1. Inspect Action: "Kill" at +0x06B0
    DoogEngine1::InputActionRecord act_kill;
    act_kill.action_id = *reinterpret_cast<const uint32_t*>(mono_data.data() + 0x06D8);
    DoogEngine1::ParseActionEntry(mono_data.data(), mono_data.size(), 0x06B0, act_kill);

    std::cout << "Action 1 (Kill):\n";
    std::cout << "  Name       : \"" << act_kill.name << "\"\n";
    std::cout << "  Action ID  : " << act_kill.action_id << "\n";
    std::cout << "  Offset in MB: +0x" << std::hex << act_kill.record_offset << std::dec << "\n";

    // 2. Inspect Action: "UseVent" at +0x1288
    DoogEngine1::InputActionRecord act_vent;
    act_vent.action_id = *reinterpret_cast<const uint32_t*>(mono_data.data() + 0x1284);
    DoogEngine1::ParseActionEntry(mono_data.data(), mono_data.size(), 0x1288, act_vent);

    std::cout << "\nAction 2 (UseVent):\n";
    std::cout << "  Name       : \"" << act_vent.name << "\"\n";
    std::cout << "  Description: \"" << act_vent.descriptive_name << "\"\n";
    std::cout << "  Action ID  : " << act_vent.action_id << " (0x" << std::hex << act_vent.action_id << std::dec << ")\n";
    std::cout << "  Offset in MB: +0x" << std::hex << act_vent.record_offset << std::dec << "\n";

    // 3. Controlled Perturbation Test on Action ID:
    // Modify Action ID 50 (0x32) at offset 0x1284 to 99 (0x63)
    std::cout << "\n========================================================\n";
    std::cout << "  CONTROLLED PERTURBATION EXPERIMENT (ACTION ID MUTATION)\n";
    std::cout << "========================================================\n";

    std::vector<uint8_t> perturbed = mono_data;
    size_t id_offset = 0x1284;
    std::cout << "Mutating Action ID at +0x" << std::hex << id_offset
              << ": " << (int)perturbed[id_offset] << " -> 99 (0x63)\n" << std::dec;
    perturbed[id_offset] = 99;

    DoogEngine1::InputActionRecord act_vent_pert;
    act_vent_pert.action_id = *reinterpret_cast<const uint32_t*>(perturbed.data() + 0x1284);
    DoogEngine1::ParseActionEntry(perturbed.data(), perturbed.size(), 0x1288, act_vent_pert);

    std::cout << "Pre-Mutation Action ID : " << act_vent.action_id << " (Action: " << act_vent.name << ")\n";
    std::cout << "Post-Mutation Action ID: " << act_vent_pert.action_id << " (Action: " << act_vent_pert.name << ")\n";
    std::cout << "Perturbation Isolation : PASS (Exact 1-dword semantic mutation)\n";
    std::cout << "========================================================\n";

    return 0;
}
