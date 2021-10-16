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
    MyShared_ptr(MyShared_ptr && ptr); // move constructor
    MyShared_ptr& operator=(MyShared_ptr & ptr); // copy assignment
    MyShared_ptr& operator=(MyShared_ptr && ptr); // move assignment
    int getCount() const { return *m_ptrCounter; }
    T* get() const { return this->m_ptr; }
    T* operator->() const { return this->m_ptr; }
    T& operator*() const { return *(this->m_ptr); }
    ~MyShared_ptr(); // destructor
	
};

template<class T>
MyShared_ptr<T>::MyShared_ptr(const MyShared_ptr<T>& ptr)
{
    m_ptr = ptr.m_ptr;
    m_ptrCounter = ptr.m_ptrCounter;

    if(ptr.m_ptrCounter != nullptr)
    {
        (*m_ptrCounter)++;
    }
}

template <class T>
MyShared_ptr<T>& MyShared_ptr<T>::operator=(MyShared_ptr<T> & ptr) // copy assignment
{
    (*m_ptrCounter)--;
    if (*m_ptrCounter == 0)
    {
        if (m_ptr != nullptr) 
            delete m_ptr;
        delete m_ptrCounter;
    }
    m_ptr = ptr.m_ptr;
    m_ptrCounter = ptr.m_ptrCounter;
    
    if (ptr.m_ptrCounter != nullptr)
    {
        (*m_ptrCounter)++;
    }
}

template<class T>
MyShared_ptr<T>::MyShared_ptr(MyShared_ptr<T> && ptr) // move constructor
{
    this->m_ptr = ptr.m_ptr; 
    this->m_ptrCounter = ptr.m_ptrCounter;

    ptr.m_ptr = ptr.m_ptrCounter = nullptr; 
}

template<class T>
MyShared_ptr<T>& MyShared_ptr<T>::operator=(MyShared_ptr<T> && ptr) // move assignment
{
    (*m_ptrCounter)--;
    if (*m_ptrCounter == 0)
    {
        if (m_ptr != nullptr) 
            delete m_ptr;
        delete m_ptrCounter;
    }
    
    this->m_ptr = ptr.m_ptr; 
    this->m_ptrCounter = ptr.m_ptrCounter;

    ptr.m_ptr = ptr.m_ptrCounter = nullptr; 
}

template<class T>
MyShared_ptr<T>::~MyShared_ptr()
{
    (*m_ptrCounter)--;
    if (*m_ptrCounter == 0)
    {
        if (m_ptr != nullptr) 
            delete m_ptr;
        delete m_ptrCounter;
    }
}
