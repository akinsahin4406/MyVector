#pragma once

#include <iostream>
#include <bits/stdc++.h>

template<typename T>
class MyVector
{
    private:
    T *m_ptr;
    int count;
    int capacity_count;

    void check_capacity()
    {
        T *ptr = m_ptr; 
        capacity_count *= 2;
        m_ptr = new T[capacity_count];
        for(int i=0;i<count;++i)
        {
            m_ptr[i] = ptr[i];
        }
        delete[] ptr;
    }
    public:
    MyVector():
    count{0}, capacity_count{1}
    {
        m_ptr = new T[capacity_count];
    }

     MyVector(std::initializer_list<T> l)
     {
        count = l.size();
        capacity_count = count;
        m_ptr = new T[capacity_count];
        for(auto &t:l)
        {
            std::cout << t << " ";
            *m_ptr = t;
            ++m_ptr;
        }
     }

    void push_back(T x)
    {
        if(count >= capacity_count)
        {
            check_capacity();
        }
        m_ptr[count] = x;
        ++count;
    }

    void push_front(T x)
    {
        if(count >= capacity_count)
        {
            capacity_count *= 2;
        }
        T *ptr = m_ptr;
        m_ptr = new T[capacity_count];
        m_ptr[0] = x;

        for(int i=0;i<count;++i)
        {
            m_ptr[i+1] = ptr[i];
        }
        ++count;
    }

    T* insert(T x, int index)
    {
        T* ret = nullptr;
        if(count >= capacity_count)
        {
            capacity_count *= 2;
        }
        T *ptr = m_ptr;
        ++count;
        m_ptr = new T[capacity_count];
        for(int j=0;j<count;++j)
        {
            if (j == index)
            {
                m_ptr[j] = x;
                m_ptr[j+1] =ptr[j];
                ret = &m_ptr[j];
            }
            else
            {
                if (j < index)
                    m_ptr[j] = ptr[j];
                else
                    m_ptr[j+1] = ptr[j];
            }
        }
        return ret;
    }

    T* front() const
    {
        return m_ptr[0];
    }

    int size() const
    {
        return count;
    }

    int capacity() const
    {
        return capacity_count;
    }

    T& operator [](int index)
    {
        return m_ptr[index];
    }

    T& at(int index)
    {
        if (index > count -1)
        {
            std::cout << "Bound exceeded" << std::endl;
        }
        return m_ptr[index];
    }
    void reserve(int new_capacity)
    {
        delete[] m_ptr;
        capacity_count = new_capacity;
        m_ptr = new T[capacity_count];
    }

    bool empty() const
    {
        return count == 0;
    }

    void printValues()
    {
        for(int j=0;j<count;++j)
        {
            std::cout << "value :" << m_ptr[j] << std::endl;
        }
    }
};
