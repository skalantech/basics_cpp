using namespace System;
using namespace System::Collections;

void Test(Object^ o) {
    Int32^ i = dynamic_cast<Int32^>(o);

    if (i)
        Console::WriteLine(i);
    else
        Console::WriteLine("Not a boxed int");
}

public delegate void MyDel();
ref class MyClass {
public:
    void Test1() {}
};

void Test1(Object^ x) {
    Console::WriteLine("Type is {0}", x->GetType());
}


value struct DataCollection {
private:
    int Size;
    array<String^>^ x;

public:
    DataCollection(int i) : Size(i) {
        x = gcnew array<String^>(Size);
        for (int i = 0; i < Size; i++)
            x[i] = i.ToString();
    }

    void f(int Item) {
        if (Item >= Size)
        {
            System::Console::WriteLine("Cannot access array element {0}, size is {1}", Item, Size);
            return;
        }
        else
            System::Console::WriteLine("Array value: {0}", x[Item]);
    }
};

void f(DataCollection y, int Item) {
    y.f(Item);
}

int main() {
    String^ str = "test";
    Test(str);

    int n = 100;
    Test(n);

    // handle to Object can hold any ref type
    Object^ h_MyClass = gcnew MyClass;

    ArrayList^ arr = gcnew ArrayList();
    arr->Add(gcnew MyClass);

    h_MyClass = dynamic_cast<MyClass^>(arr[0]);
    Test1(arr);

    Int32^ bi = 1;
    Test1(bi);

    MyClass^ h_MyClass2 = gcnew MyClass;

    MyDel^ DelInst = gcnew MyDel(h_MyClass2, &MyClass::Test1);
    Test1(DelInst);

    DataCollection^ a = gcnew DataCollection(10);
    f(*a, 7);   // dereference a handle, return handle's object
    a->f(11);   // access member via dereferenced handle
    (*a).f(9);  // same as the last one
}