// CppDSA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Array.h"
using std::cout;
using std::cin;
using std::endl;

constexpr int kNotFound = -1;

int LinearSearch(int element, const int* v, int size)
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

int BinarySearch(int element, const int* v, int size)
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

void Print(const std::vector<int>& v)
{
	cout << "[ ";
	for (int x : v)
	{
		cout << x << " ";
	}
	cout << "]\n";
}


int main()
{
#pragma region Arrays
	/*cout << "Creating an empty array.\n";
	Array<int> a{};
	cout << "a.Size() is " << a.Size() << "\n";
	assert(a.IsEmpty());

	cout << "-----------------------------------------\n";

	cout << "Creating an array containing 10 elements.\n";
	Array<int> b{ 10 };
	cout << "b.Size() is " << b.Size() << "\n";
	assert(!b.IsEmpty());

	cout << "-----------------------------------------\n";

	cout << "Creating an array containing 3 elements.\n";
	Array<int> c{ 3 };
	cout << "Setting c[0] = 10\n";
	c[0] = 10;
	cout << "c[0] is " << c[0] << "\n";

	cout << "-----------------------------------------\n";

	cout << "Creating an array containing 3 elements.\n";
	try
	{
		Array<int> d{ 10 };
		for (int i = 0; i < d.Size(); i++)
		{
			d[i] = (i + 1) * 10;
		}

		cout << "Array elements: ";
		for (int i = 0; i < d.Size(); i++)
		{
			cout << d[i] << " ";
		}
		cout << "\n";

		cout << "Array size is " << d.Size() << "\n";
		cout << "Please enter an array index: ";
		int index{};
		cin >> index;

		cout << "The element at index " << index << " is " << d[index] << "\n";
	}
	catch (const IndexOutOfBoundsException& e)
	{
		cout << "\n*** ERROR: Invalid array index ***\n";
	}

	cout << "-----------------------------------------\n";

	cout << "Using operator override to cout array.\n";
	Array<int> e{ 10 };
	for (int i = 0; i < e.Size(); i++)
	{
		e[i] = (i + 1) * 10;
	}
	cout << "Array elements: " << e << "\n";*/
#pragma endregion

#pragma region Linear Search
	//cout << "-----------------------------------------\n";

	//cout << "Linear Searching through an array containing 5 elements.\n";
	//std::vector<int> v{ 33, 44, 55, 11, 22 };
	//cout << "Array elements: ";
	//Print(v);

	//cout << "Element to search?" << endl;
	//int x;
	//cin >> x;

	//int position = LinearSearch(x, v.data(), v.size());
	//if (position == kNotFound)
	//{
	//	cout << "Element not found." << endl;
	//}
	//else
	//{
	//	cout << "Element found at index " << position << "." << endl;
	//}
#pragma endregion

#pragma region Binary Search
	cout << "-----------------------------------------\n";

	cout << "Binary Searching through an array containing 5 elements.\n";
	std::vector<int> v{ 11, 22, 33, 44, 55 };
	cout << "Array elements: ";
	Print(v);

	cout << "Element to search?" << endl;
	int x;
	cin >> x;

	int position = BinarySearch(x, v.data(), v.size());
	if (position == kNotFound)
	{
		cout << "Element not found." << endl;
	}
	else
	{
		cout << "Element found at index " << position << "." << endl;
	}
#pragma endregion
}
