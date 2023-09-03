#pragma once

#include <cstddef>
//baseclass 
template<class T>
class Allocator{
    protected:
        std::size_t total_size;
        std::size_t used;
        std::size_t peak;

    public:
        Allocator(const std::size_t _total_size) : 
            total_size{ _total_size },used{ 0 },peak{ 0 }{ }

        virtual ~Allocator()
        { 
            total_size = 0;
        }

        virtual T* alloc(const std::size_t size, const std::size_t aligment = 0) = 0 ;
        virtual void deallocate(void* ptr) = 0;
        virtual void init() = 0;
};
