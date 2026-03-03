#include <cstddef>

template <typename T>
void iter(T *array, size_t length, void (*f)(const T &))
{
    for (size_t i = 0; i < length; i++)
        f(array[i]);
}

template <typename T, typename Func>
void iter(T* array, std::size_t length, Func f)
{
    for (std::size_t i = 0; i < length; ++i)
        f(array[i]);
}