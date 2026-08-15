#ifndef BUFFER_CONTEXT_H
#define BUFFER_CONTEXT_H

#include <cstdint>
#include <cstddef>
#include <vector>

namespace DoogEngine {

struct BufferContext {
    uint8_t* data = nullptr;
    size_t size = 0;
    size_t cursor = 0;
    bool has_overflow = false;

    // Execution path logger for differential probing
    std::vector<uint32_t> state_trace;

    void log_state(uint32_t state_id) {
        state_trace.push_back(state_id);
    }
};

} // namespace DoogEngine

#endif // BUFFER_CONTEXT_H