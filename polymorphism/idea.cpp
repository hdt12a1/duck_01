#include <iostream>

template <typename T>
class Auto_ptr1
{
	T* m_ptr;
public:
	// Pass in a pointer to "own" via the constructor
	Auto_ptr1(T* ptr=nullptr)
		:m_ptr(ptr)
	{
        std::cout << "Default Constructor" << std::endl;
	}

	// The destructor will make sure it gets deallocated
	~Auto_ptr1()
	{
        std::cout << "Destructor" << std::endl;
		delete m_ptr;
	}

	// Overload dereference and operator-> so we can use Auto_ptr1 like m_ptr.
	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
};

// A sample class to prove the above works
class Resource
{
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
    Resource *ptrr = new Resource();
	Auto_ptr1<Resource> res(new Resource()); // Note the allocation of memory here

        // ... but no explicit delete needed

	// Also note that we use <Resource>, not <Resource*>
        // This is because we've defined m_ptr to have type T* (not T)

	return 0;
} // res goes out of scope here, and destroys the allocated Resource for us