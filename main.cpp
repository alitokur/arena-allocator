#include <iostream>
#include <vector>

#include "default.h"
#include "linear.h"
#include "Allocator.h"

const auto A = static_cast<std::size_t>(1e9);

/*
 * TODO:
 * 1-)create memory with arena allocator, return pointer as a int
 * 2-)use that memory with a problem case
 * 3-)free memory 
 */

int main (int argc, char *argv[]) {
    Allocator* linear_manager = new Linear(A);
    linear_manager->init();
    linear_manager->alloc(123, 8);
    return 0;
}
