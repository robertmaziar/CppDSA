// CppDSA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cassert>
using std::cout;
using std::cin;

class IndexOutOfBoundsException {};

class IntArray
{
public:
	IntArray()
	{
	}

	~IntArray()
	{
		delete[] m_ptr;
	}

	explicit IntArray(int size)
	{
		if (size != 0)
		{
			m_ptr = new int[size]{};
			m_size = size;
		}
	}

	int Size() const
	{
		return m_size;
	}

	bool IsEmpty() const 
	{
		return (m_size == 0);
	}

	int& operator[](int index)
	{
		if (IsValidIndex(index))
		{
			return m_ptr[index];
		}
		else
		{
			throw IndexOutOfBoundsException{};
		}
	}

	int operator[](int index) const
	{
		if (IsValidIndex(index))
		{
			return m_ptr[index];
		}
		else
		{
			throw IndexOutOfBoundsException{};
		}
	}

private:
	int* m_ptr{ nullptr };
	int m_size{ 0 };

	bool IsValidIndex(int index) const
	{
		if (index >= 0 && index < m_size)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};


int main()
{
    cout << "Creating an empty array.\n";
	IntArray a{};
	cout << "a.Size() is " << a.Size() << "\n";
	assert(a.IsEmpty());

	cout << "-----------------------------------------\n";

	cout << "Creating an array containing 10 elements.\n";
	IntArray b{ 10 };
	cout << "b.Size() is " << b.Size() << "\n";
	assert(!b.IsEmpty());

	cout << "-----------------------------------------\n";

	cout << "Creating an array containing 3 elements.\n";
	IntArray c{ 3 };
	cout << "Setting c[0] = 10\n";
	c[0] = 10;
	cout << "c[0] is " << c[0] << "\n";

	cout << "-----------------------------------------\n";

	cout << "Creating an array containing 3 elements.\n";
	try
	{
		IntArray d{ 10 };
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
}

