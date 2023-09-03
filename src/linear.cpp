#include <stdlib.h>
#include <algorithm>
#include <cassert>
#include <iostream>
#include "Allocator.h"
#include "linear.h"

template<class T>
Linear<T>::Linear(const std::size_t totalSize):
    Allocator<T>::Allocator(totalSize){
        std::cout << "here we are!" << std::endl;
    }

template<class T>
void Linear<T>::init(){
    if (m_start_ptr != NULL){
        free(m_start_ptr);
    }
    m_start_ptr = malloc(this->total_size);
    std::cout << "m_start_ptr: " << m_start_ptr << std::endl;
    m_offset = 0;
}

template<class T>
Linear<T>::~Linear(){
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

template<class T>
T* Linear<T>::alloc(const std::size_t size, const std::size_t aligment) {
    std::size_t padding = 0;
    std::size_t padded_address = 0;
    const std::size_t current_address = (std::size_t)m_start_ptr + m_offset;
    std::cout << "current_address: " << current_address << std::endl; 
    if (aligment != 0 && m_offset % aligment != 0) {
        padding = CalculatePadding(current_address, aligment);
        std::cout << "calculateOadding: " << padding << std::endl; 
    }

    if(m_offset + padding + size > this->total_size){
        return NULL;
    }

    m_offset += padding;
    std::cout << "new offset: " << m_offset << std::endl;
    const std::size_t next_address = current_address + padding;
    std::cout << "next_address: " << next_address << std::endl;
    m_offset += size;
    std::cout << "new offset_2: " << m_offset << std::endl;
    this->used = m_offset;
    std::cout << "used: " << this->used << std::endl;
    this->peak = std::max(this->peak, this->used);
    std::cout << "peak: " << this->peak << std::endl;
    return (int*) next_address;
}

template<class T>
void Linear<T>::deallocate(void* ptr){
    //use reset method
    assert(false && "Use Reset() method");
}
template <class T>
void Linear<T>::Reset(){
    m_offset = 0;
    this->used = 0;
    this->peak = 0; 
}

template class Linear<int>;


