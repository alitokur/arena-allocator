#pragma once
#include "Allocator.h"

template<class T>
class Linear : public Allocator<T>{
    protected:
        void* m_start_ptr = NULL;
        std::size_t m_offset;

    public:
        Linear(const std::size_t totalSize);
        virtual ~Linear(); 
        virtual T* alloc(const std::size_t size, const std::size_t aligment=0) override;
        virtual void deallocate(void* ptr) override;
        virtual void init() override;
        virtual void Reset();

    private:
        Linear(Linear &l_a);
};
