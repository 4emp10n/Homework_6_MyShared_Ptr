template<class T>
class MyShared_ptr
{
    private:
    T* ptr = nullptr;
    int* ptrCounter = nullptr;
    public:
    MyShared_ptr(): ptr(nullptr), ptrCounter(new int(1)){}
    MyShared_ptr(T* ptr = nullptr): ptr(ptr), ptrCounter(new int (1)){}
};