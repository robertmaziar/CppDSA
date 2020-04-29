#pragma once
#include <vector>

constexpr int kNotFound = -1;

template <typename T>
int LinearSearch(T element, const T* v, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (v[i] == element)
		{
			return i;
		}
	}

	return kNotFound;
}

template <typename T>
void Print(const std::vector<T>& v)
{
	std::cout << "[ ";
	for (int x : v)
	{
		std::cout << x << " ";
	}
	std::cout << "]\n";
}
