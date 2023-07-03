ref class MyClass {
public:
    MyClass() : i() {}
    int i;
    void Test() {
        i++;
        System::Console::WriteLine(i);
    }
};

ref struct A {
    void Test1(unsigned int&) {}
    void Test2(unsigned int%) {}
    unsigned int i;
};

int main() {
    MyClass^ p_MyClass = gcnew MyClass;
    p_MyClass->Test();

    MyClass^ p_MyClass2;
    p_MyClass2 = p_MyClass;

    p_MyClass = nullptr;
    p_MyClass2->Test();

    A a;
    a.i = 9;
    //a.Test1(a.i);   // C2664
    a.Test2(a.i);   // OK

    unsigned int j = 0;
    a.Test1(j);   // OK
}