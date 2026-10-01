#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <fstream>
#include <iomanip>
#include <cstring>

namespace DoogEngine1 {

// Exact binary layout of Unity GameObject component reference
struct ComponentRef {
    int32_t file_id;
    int64_t path_id;
};

// Exact parsed representation of an application-specific GameObject
struct GameObjectRecord {
    uint32_t component_count;
    std::vector<ComponentRef> components;
    uint32_t layer;
    uint32_t name_length;
    std::string name;
    uint16_t tag;
    bool is_active;
    size_t bytes_consumed;
};

// Clean-room deserializer for GameObject binary record
bool DeserializeGameObject(const uint8_t* data, size_t max_len, GameObjectRecord& out_obj) {
    if (!data || max_len < 16) return false;

    size_t cursor = 0;

    // 1. Read component array
    uint32_t comp_count = *reinterpret_cast<const uint32_t*>(data + cursor);
    cursor += 4;
    out_obj.component_count = comp_count;
    out_obj.components.clear();

    if (cursor + comp_count * 12 > max_len) return false;

    for (uint32_t i = 0; i < comp_count; ++i) {
        ComponentRef ref;
        ref.file_id = *reinterpret_cast<const int32_t*>(data + cursor);
        cursor += 4;
        ref.path_id = *reinterpret_cast<const int64_t*>(data + cursor);
        cursor += 8;
        out_obj.components.push_back(ref);
    }

    // 2. Read Layer
    if (cursor + 4 > max_len) return false;
    out_obj.layer = *reinterpret_cast<const uint32_t*>(data + cursor);
    cursor += 4;

    // 3. Read Name string
    if (cursor + 4 > max_len) return false;
    uint32_t name_len = *reinterpret_cast<const uint32_t*>(data + cursor);
    cursor += 4;
    out_obj.name_length = name_len;

    if (cursor + name_len > max_len) return false;
    out_obj.name.assign(reinterpret_cast<const char*>(data + cursor), name_len);
    cursor += name_len;

    // 4-byte string alignment
    size_t pad = (4 - (name_len % 4)) % 4;
    cursor += pad;

    // 4. Read Tag
    if (cursor + 2 > max_len) return false;
    out_obj.tag = *reinterpret_cast<const uint16_t*>(data + cursor);
    cursor += 2;

    // 5. Read IsActive
    if (cursor + 1 > max_len) return false;
    out_obj.is_active = (data[cursor] != 0);
    cursor += 1;

    // Final 4-byte struct alignment
    if (cursor % 4 != 0) {
        cursor += (4 - (cursor % 4));
    }

    out_obj.bytes_consumed = cursor;
    return true;
}

} // namespace DoogEngine1

void PrintGameObject(const std::string& label, const DoogEngine1::GameObjectRecord& obj) {
    std::cout << "========================================================\n";
    std::cout << label << "\n";
    std::cout << "--------------------------------------------------------\n";
    std::cout << "  Name            : \"" << obj.name << "\"\n";
    std::cout << "  Name Length     : " << obj.name_length << "\n";
    std::cout << "  Components Count: " << obj.component_count << "\n";
    for (size_t i = 0; i < obj.components.size(); ++i) {
        std::cout << "    Component[" << i << "]: FileID=" << obj.components[i].file_id
                  << ", PathID=0x" << std::hex << obj.components[i].path_id << std::dec << "\n";
    }
    std::cout << "  Layer           : " << obj.layer << " (UI / Foreground)\n";
    std::cout << "  Tag             : " << obj.tag << "\n";
    std::cout << "  IsActive        : " << (obj.is_active ? "TRUE" : "FALSE") << "\n";
    std::cout << "  Bytes Consumed  : " << obj.bytes_consumed << " bytes\n";
}

int main() {
    std::cout << "========================================================\n";
    std::cout << "   CLEAN-ROOM GAME RECORD DESERIALIZER VERIFICATION     \n";
    std::cout << "========================================================\n";

    // 1. Load real slice from level2 at offset 0x41080
    std::ifstream f("level2", std::ios::binary);
    if (!f.is_open()) {
        std::cerr << "Failed to open level2\n";
        return 1;
    }
    f.seekg(0x41080);
    std::vector<uint8_t> buffer(512);
    f.read(reinterpret_cast<char*>(buffer.data()), buffer.size());

    // 2. Parse GameObject 0 (Offset 0x00 in buffer)
    DoogEngine1::GameObjectRecord obj0;
    bool ok0 = DoogEngine1::DeserializeGameObject(buffer.data(), buffer.size(), obj0);
    if (ok0) {
        PrintGameObject("1. Deserialized Object 0 (Real Binary Stream)", obj0);
    }

    // 3. Parse GameObject 1 (Offset 0x38 in buffer)
    DoogEngine1::GameObjectRecord obj1;
    bool ok1 = DoogEngine1::DeserializeGameObject(buffer.data() + 0x38, buffer.size() - 0x38, obj1);
    if (ok1) {
        PrintGameObject("2. Deserialized Object 1 (Real Binary Stream)", obj1);
    }

    // 4. CONTROLLED PERTURBATION EXPERIMENT:
    // Modify exactly ONE byte in a cloned buffer:
    // In GameObject 0, IsActive is at offset 0x32 (50 bytes).
    // Original value is 0x01 (true). Let's perturb it to 0x00 (false).
    std::cout << "\n========================================================\n";
    std::cout << "   CONTROLLED PERTURBATION EXPERIMENT (1 BYTE MUTATION) \n";
    std::cout << "========================================================\n";

    std::vector<uint8_t> perturbed_buffer = buffer;
    size_t active_byte_offset = 0x32; // Offset of IsActive byte for Obj 0

    std::cout << "Mutating byte at offset 0x" << std::hex << active_byte_offset
              << ": 0x" << (int)perturbed_buffer[active_byte_offset] << " -> 0x00\n" << std::dec;
    perturbed_buffer[active_byte_offset] = 0x00;

    DoogEngine1::GameObjectRecord obj0_perturbed;
    bool ok_pert = DoogEngine1::DeserializeGameObject(perturbed_buffer.data(), perturbed_buffer.size(), obj0_perturbed);

    std::cout << "\nBefore Perturbation -> IsActive = " << (obj0.is_active ? "TRUE" : "FALSE")
              << " | Name = \"" << obj0.name << "\"\n";
    std::cout << "After Perturbation  -> IsActive = " << (obj0_perturbed.is_active ? "TRUE" : "FALSE")
              << " | Name = \"" << obj0_perturbed.name << "\"\n";

    bool perturbation_isolated = (obj0.is_active == true && obj0_perturbed.is_active == false &&
                                  obj0.name == obj0_perturbed.name && obj0.layer == obj0_perturbed.layer);
    std::cout << "Perturbation Isolation: " << (perturbation_isolated ? "PASS (Exact 1-bit semantic mutation)" : "FAIL") << "\n";
    std::cout << "========================================================\n";

    return 0;
}
