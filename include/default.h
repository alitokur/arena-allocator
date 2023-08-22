#include <iostream>
#include "Allocator.h"

class RawMemoryManager:public Allocator{
    public:
        //constructors
        RawMemoryManager();

        virtual void* alloc(
                const std::size_t size, 
                const std::size_t aligment = 0
                )override;

        virtual void deallocate(void* ptr)override;

        virtual void init()override;

        virtual ~RawMemoryManager(); 

};


