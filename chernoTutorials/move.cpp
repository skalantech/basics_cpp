#include <iostream>
// #include <stdio.h>
#include <string.h>

class String
{
public:
    String() = default;
    String(const char* string)
    {
        printf("Created!\n");
        m_Size = strlen(string);
        m_Data = new char[m_Size];
        memcpy(m_Data, string, m_Size);
    }

    String(const String& other)
    {
        printf("Copied!\n");
        m_Size = other.m_Size;
        m_Data = new char[m_Size];
        memcpy(m_Data, other.m_Data, m_Size);
    }

    String& operator=(const String& other)
    {
        printf("Copied!\n");
        if (this == &other)
            return *this;
        delete [] m_Data;    
        m_Size = other.m_Size;
        m_Data = new char[m_Size];
        memcpy(m_Data, other.m_Data, m_Size);
        return *this;
    }

    String(String&& other) noexcept //shallow copy that realocate the reference
    {                               // std::move
        printf("Moved!\n");
        m_Size = other.m_Size;
        m_Data = other.m_Data;
        
        other.m_Size = 0;
        other.m_Data = nullptr;
    }

    String& operator=(String&& other) noexcept 
    {        
        printf("Moved!\n"); 
        if (this != &other)
        {                                 
            delete[] m_Data;

            m_Size = other.m_Size;
            m_Data = other.m_Data;
            
            other.m_Size = 0;
            other.m_Data = nullptr;
        }
        return *this; 
    }

    ~String()
    {
        printf("Deleted!\n");
        delete m_Data;
    }

    void Print()
    {
        for(uint32_t i = 0; i < m_Size; i++) 
            printf("%c", m_Data[i]);

        printf("\n");
    }
private:
    char* m_Data;
    uint32_t m_Size;  
};

class Entity
{
public:
    Entity(const String& name) : m_Name(name)
    {
    }

    Entity(String&& name) : m_Name(std::move(name)) // like doing this "m_Name(std::move(name))"
    {
    }

    void PrintName()
    {
        m_Name.Print();
    }

private:
    String m_Name;
};

int main()
{
    Entity entity(String("Carlos"));
    entity.PrintName();

    String string = "Alissa";
    // String destination = string; // makes a copy
    
    // String destination((String&&)string);   // moves
    // String destination = (String&&)string;  // moves
    String destination = std::move(string); // moves

    String string2 = "apple";
    std::cout << "Apple: ";
    string2.Print();
    
    String dest = " ";
    std::cout << "Dest: ";
    dest.Print();
    dest = std::move(string2); // convert string2 in temporary! 
    std::cout << "Apple: "; 
    string2.Print();
    std::cout << "Dest: ";
    dest.Print();
    String dest2 = " ";
    dest2 = dest;
    std::cout << "Dest2: ";
    dest2.Print();
    std::cout << "Dest: ";
    dest.Print();

    std::cin.get();

    return 0;
}