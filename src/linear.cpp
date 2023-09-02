#include <stdlib.h>
#include <algorithm>
#include <cassert>
#include <iostream>

#include "linear.h"

Linear::Linear(const std::size_t totalSize):
    Allocator(totalSize){
    }

void Linear::init(){
    if (m_start_ptr != NULL){
        free(m_start_ptr);
    }
    m_start_ptr = malloc(total_size);
    std::cout << "m_start_ptr: " << m_start_ptr << std::endl;
    m_offset = 0;
}

Linear::~Linear(){
    free(m_start_ptr);
    m_start_ptr = NULL;

}
// TODO: create utils class for this function
std::size_t CalculatePadding(const std::size_t baseAddress, const std::size_t alignment) {
    const std::size_t multiplier = (baseAddress / alignment) + 1;
    const std::size_t alignedAddress = multiplier * alignment;
    const std::size_t padding = alignedAddress - baseAddress;
    return padding;
}

int* Linear::alloc(const std::size_t size, const std::size_t aligment) {
    std::size_t padding = 0;
    std::size_t padded_address = 0;
    const std::size_t current_address = (std::size_t)m_start_ptr + m_offset;
    std::cout << "current_address: " << current_address << std::endl; 
    if (aligment != 0 && m_offset % aligment != 0) {
        padding = CalculatePadding(current_address, aligment);
        std::cout << "calculateOadding: " << padding << std::endl; 
    }

    if(m_offset + padding + size > total_size){
        return NULL;
    }

    m_offset += padding;
    std::cout << "new offset: " << m_offset << std::endl;
    const std::size_t next_address = current_address + padding;
    std::cout << "next_address: " << next_address << std::endl;
    m_offset += size;
    std::cout << "new offset_2: " << m_offset << std::endl;
    used = m_offset;
    std::cout << "used: " << used << std::endl;
    peak = std::max(peak, used);
    std::cout << "peak: " << peak << std::endl;
    return (int*) next_address;
}

void Linear::deallocate(void* ptr){
    //use reset method
    assert(false && "Use Reset() method");
}

void Linear::Reset(){
    m_offset = 0;
    used = 0;
    peak = 0; 
}

