#include <iostream>
class RawMemoryManager{
    public:
        RawMemoryManager(int);
        void alloc(int);
        void deallocate();
        ~RawMemoryManager(); 
    private:
        int mem_size;
        int *p;
};


