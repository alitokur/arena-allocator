#include <iostream>
#include <vector>

#include "default.h"
#include "Allocator.h"

const std::vector<std::size_t> ALLOCATION_SIZES {32, 64, 256, 512, 1024, 2048, 4096};
const std::vector<std::size_t> ALIGNMENTS {8, 8, 8, 8, 8, 8, 8};

int main (int argc, char *argv[]) {
    Allocator* default_c = new RawMemoryManager();
    std::cout << default_c->alloc(ALLOCATION_SIZES[0], ALIGNMENTS[0]) << std::endl;
    return 0;
}
