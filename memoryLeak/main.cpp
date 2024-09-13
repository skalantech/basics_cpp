#include <iostream>
#include <memory>
#include <string>

struct AllocationMetrics
{
    uint32_t totalAllocated = 0;
    uint32_t totalFreed = 0;
    uint32_t currentUsage() {return totalAllocated - totalFreed;}
};

static AllocationMetrics s_AllocationMetrics;

void* operator new(size_t size)
{
    std::cout << "Allocating " << size << "bytes\n";
    s_AllocationMetrics.totalAllocated += size;
    return malloc(size);
}

void operator delete(void* memory, size_t size)
{
    std::cout << "Freeing " << size << "bytes\n";
    s_AllocationMetrics.totalFreed += size;
    free(memory);
}

struct Object
{
    int x, y, z;
};

static void PrintMemoryUsage()
{
    std::cout << "Memory Usage: " << s_AllocationMetrics.currentUsage() << " bytes\n";
}

int main()
{
    PrintMemoryUsage();
    std::string name = "Carlos";

    PrintMemoryUsage();
    Object* obj = new Object;

    PrintMemoryUsage();
    std::unique_ptr<Object> obj1 = std::make_unique<Object>();

    PrintMemoryUsage();
    delete obj;

    PrintMemoryUsage();

    return 0;
}