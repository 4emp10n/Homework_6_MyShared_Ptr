template<class T>
class MyShared_ptr
{
    private:
    T* m_ptr = nullptr;
    int* m_ptrCounter = nullptr;
    public:
    MyShared_ptr(): m_ptr(nullptr), m_ptrCounter(new int(1)){}
    MyShared_ptr(T* ptr = nullptr): m_ptr(ptr), m_ptrCounter(new int (1)){}

    MyShared_ptr(const MyShared_ptr& ptr);

};

template<class T>
MyShared_ptr<T>::MyShared_ptr(const MyShared_ptr& ptr)
{
    m_ptr = ptr;
    m_ptrCounter = ptr.m_ptrCounter;

    if(ptr.m_ptrCounter != nullptr)
    {
        (*m_ptrCounter)++;
    }
}