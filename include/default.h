//MyTemplate 
#pragma once

#include <iostream>
#include "Allocator.h"
template<class T>
class RawMemoryManager:public Allocator<T>{
    public:
        //constructors
        RawMemoryManager();

        virtual T* alloc(
                const std::size_t size, 
                const std::size_t aligment = 0
                )override;

        virtual void deallocate(void* ptr)override;

        virtual void init()override;

        virtual ~RawMemoryManager(); 
};

   
