#include <stdlib.h>
#include <algorithm>
#include <cassert>

#include "linear.h"

Linear::Linear(const std::size_t totalSize):
    Allocator(totalSize){
    }

void Linear::init(){
    if (m_start_ptr != NULL){
        free(m_start_ptr);
    }
    m_start_ptr = malloc(total_size);
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

void* Linear::alloc(const std::size_t size, const std::size_t aligment) {
    std::size_t padding = 0;
    std::size_t padded_address = 0;
    const std::size_t current_address = (std::size_t)m_start_ptr + m_offset;
    if (aligment != 0 && m_offset % aligment != 0) {
        padding = CalculatePadding(current_address, aligment);
    }

    if(m_offset + padding + size > total_size){
        return NULL;
    }

    m_offset += padding;
    const std::size_t next_address = current_address + padding;
    m_offset += size;

    used = m_offset;
    peak = std::max(peak, used);
    return (void*) next_address;
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

