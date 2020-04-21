// CppDSA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Array.h"
using std::cout;
using std::cin;

int main()
{
#pragma region Arrays
	cout << "Creating an empty array.\n";
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
	cout << "Array elements: " << e << "\n";
#pragma endregion
}
