#pragma once
#include <vector>

constexpr int kNotFound = -1;

template <typename T>
T BinarySearch(T element, const T* v, int size)
{
	int left = 0;
	int right = size - 1;

	while (left <= right)
	{
		int middle = (left + right) / 2;

		if (v[middle] == element)
		{
			return middle;
		}
		else if (v[middle] < element)
		{
			left = middle + 1;
		}
		else if (v[middle] > element)
		{
			right = middle - 1;
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
