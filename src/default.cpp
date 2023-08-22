#include <cstdlib>
#include <iostream>
#include "default.h"
RawMemoryManager::RawMemoryManager():Allocator(0){
}

void RawMemoryManager::init(){

}

void* RawMemoryManager::alloc(const std::size_t size, const std::size_t aligment){
    return malloc(size);
}

RawMemoryManager::~RawMemoryManager(){
    
}

void RawMemoryManager::deallocate(void* ptr){
    free (ptr);
}
