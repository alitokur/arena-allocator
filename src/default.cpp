#include <cstdlib>
#include <iostream>
#include "default.h"

RawMemoryManager::RawMemoryManager(int _size):mem_size{_size}{
    alloc(mem_size);
};

void RawMemoryManager::alloc(int _size){
    p = (int*)malloc(_size);
    if(p != NULL){
        std::cout << "Memory has been allocated" 
            "at address: " << p << std::endl;
    }
}

RawMemoryManager::~RawMemoryManager(){
    free(p);
}

void RawMemoryManager::deallocate(){
    free (p);
}
