#include <cstdlib>
#include <iostream>
#include "default.h"

template<class T>
RawMemoryManager<T>::RawMemoryManager():Allocator<T>(0){
}

template<class T>
void RawMemoryManager<T>::init(){

}
template <class T>
T* RawMemoryManager<T>::alloc(const std::size_t size, const std::size_t aligment){
    return (int*)malloc(size);
}

template <class T>
RawMemoryManager<T>::~RawMemoryManager(){
    
}

template <class T>
void RawMemoryManager<T>::deallocate(void* ptr){
    free (ptr);
}

template class RawMemoryManager<int>;
