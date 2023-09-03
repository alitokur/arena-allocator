#include <iostream>
#include <vector>

#include "default.h"
#include "linear.h"
#include "Allocator.h"

//should i need this?
const auto A = static_cast<std::size_t>(1e9);

int main (int argc, char *argv[]) {
    Allocator<int>* linear_manager = new Linear<int>(100);
    linear_manager->init();
    int *x = linear_manager->alloc(32, 8);
    *x = 1;
    int *y = linear_manager->alloc(32, 8);
    *y = 2;
    int *z = linear_manager->alloc(36, 8);
    *z = 3;
    std::cout << "message: " << *x << std::endl;
    std::cout << "message: " << *y << std::endl;
    std::cout << "message: " << *z << std::endl;
    return 0;
}
