#include <cstdlib>
#include <iostream>

template <typename T>
class DynamicArray
{
public:
    DynamicArray();
    DynamicArray(std::size_t size);
    DynamicArray(const DynamicArray& other);

    ~DynamicArray();

    DynamicArray& operator=(const DynamicArray& other);

    T& operator[](std::size_t index);

    void setSize(std::size_t newSize);
    std::size_t getSize() const;

    void clear();

    void push_back(const T& element);

    void pop_back();
    T back() const;

    void reserve(std::size_t reservedSpace);
    std::size_t getCapacity() const;

    void shrinkToFit();

    bool operator==(const DynamicArray& other) const;

private:
    T* m_data;
    std::size_t m_size;
    std::size_t m_capacity;
};

template <typename T>
DynamicArray<T>::DynamicArray() : m_data(nullptr), m_size(0), m_capacity(0)
{
}

template <typename T>
DynamicArray<T>::DynamicArray(std::size_t size) : m_size(size), m_capacity(size)
{
    m_data = new T[size];
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray& other) : m_size(other.m_size), m_capacity(other.m_capacity)
{
    m_data = new T[m_capacity];
    for (std::size_t i = 0; i < m_size; ++i)
    {
        m_data[i] = other.m_data[i];
    }
}

template <typename T>
DynamicArray<T>::~DynamicArray()
{
    delete[] m_data;
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& other)
{
    if (this != &other)
    {
        delete[] m_data;
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_data = new T[m_capacity];
        for (std::size_t i = 0; i < m_size; ++i)
        {
            m_data[i] = other.m_data[i];
        }
    }
    return *this;
}

template <typename T>
T& DynamicArray<T>::operator[](std::size_t index)
{

    return m_data[index];
}

template <typename T>
void DynamicArray<T>::setSize(std::size_t newSize)
{
    m_size = newSize;
}

template <typename T>
std::size_t DynamicArray<T>::getSize() const
{
    return m_size;
}

template <typename T>
void DynamicArray<T>::clear()
{
    m_size = 0;
}

template <typename T>
void DynamicArray<T>::push_back(const T& element)
{
    if (m_size == m_capacity)
    {
        reserve(m_capacity == 0 ? 1 : m_capacity * 2);
    }
    m_data[m_size++] = element;
}

template <typename T>
void DynamicArray<T>::pop_back()
{
    if (m_size > 0)
    {
        --m_size;
    }
}

template <typename T>
T DynamicArray<T>::back() const
{
    if (m_size > 0)
    {
        return m_data[m_size - 1];
    }

    throw std::out_of_range("DynamicArray is empty");
}

template <typename T>
void DynamicArray<T>::reserve(std::size_t reservedSpace)
{
    if (reservedSpace > m_capacity)
    {
        T* newData = new T[reservedSpace];
        for (std::size_t i = 0; i < m_size; ++i)
        {
            newData[i] = m_data[i];
        }
        delete[] m_data;
        m_data = newData;
        m_capacity = reservedSpace;
    }
}

template <typename T>
std::size_t DynamicArray<T>::getCapacity() const
{
    return m_capacity;
}

template <typename T>
void DynamicArray<T>::shrinkToFit()
{
    if (m_capacity > m_size)
    {
        reserve(m_size);
    }
}

template <typename T>
bool DynamicArray<T>::operator==(const DynamicArray& other) const
{
    if (this == &other)
    {
        return true;
    }

    if (m_size != other.m_size)
    {
        return false;
    }

    for (std::size_t i = 0; i < m_size; ++i)
    {
        if (m_data[i] != other.m_data[i])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    DynamicArray<int> m_container;
    m_container.reserve(4);
    m_container.push_back(25);
    m_container.push_back(30);
    m_container.push_back(10);
    m_container.push_back(39);

    // OOPS, 5th element was added
    // allocate more memory on heap
    m_container.push_back(55);

    return 0;
}
