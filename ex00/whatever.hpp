template <typename T>
T max(T a, T b)
{
    return (a > b) ? a : b;
}

template <typename U>
U min(U a, U b)
{
    return (a > b) ? b : a;
}

template <typename V>
void swap(V &a, V &b)
{
	V temp = a;
	a = b;
	b = temp;
}


