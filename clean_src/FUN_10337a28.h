#pragma once
#include <cstdint>
#include <cstdlib>

namespace DoogEngine1 {

// CRT bypass: alias to standard C calloc
inline void FUN_10337a28() {
    [[maybe_unused]] void* p = std::calloc(1, 1);
}

} // namespace DoogEngine1

