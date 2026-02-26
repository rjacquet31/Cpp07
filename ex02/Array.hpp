#include <cstddef>
#include <stdexcept>
#include <iostream>

template <typename T>
class Array
{
private:
    T*              _data;
    unsigned int    _size;

public:
    Array() : _data(NULL), _size(0)
    {
        std::cout << "Array Default Constructor called" << std::endl;
    }

    Array(unsigned int n) : _data(new T[n]()), _size(n)
    {
        std::cout << "Array Parameterized Constructor called" << std::endl;
    }

    Array(const Array& other) : _data(NULL), _size(0)
    {
        *this = other;
        std::cout << "Array Copy Constructor called" << std::endl;
    }

    Array& operator=(const Array& other)
    {
        std::cout << "Array Assignment operator called" << std::endl;
        if (this != &other)
        {
            delete[] _data;
            _size = other._size;
            if (_size == 0)
                _data = NULL;
            else
            {
                _data = new T[_size];
                for (unsigned int i = 0; i < _size; i++)
                    _data[i] = other._data[i];
            }
        }
        return (*this);
    }

    ~Array()
    {
        std::cout << "Array Destructor called" << std::endl;
        delete[] _data;
    }

    T& operator[](unsigned int index)
    {
        if (index >= _size)
            throw std::out_of_range("Index out of bounds");
        return (_data[index]);
    }

    class InvalidIndexException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return ("Error: Invalid index");
        }
    };

    unsigned int size() const
    {
        return (_size);
    }
};

