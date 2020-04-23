// CppDSA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include "Array.h"
//#include "LinearSearch.h"
//#include "BinarySearch.h"
//#include "Stack.h"
#include "LinkedList.h"
using std::cout;
using std::cin;
using std::endl;

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
	//cout << "-----------------------------------------\n";

	//cout << "Binary Searching through an array containing 5 elements.\n";
	//std::vector<int> v{ 11, 22, 33, 44, 55 };
	//cout << "Array elements: ";
	//Print(v);

	//cout << "Element to search?" << endl;
	//int x;
	//cin >> x;

	//int position = BinarySearch(x, v.data(), v.size());
	//if (position == kNotFound)
	//{
	//	cout << "Element not found." << endl;
	//}
	//else
	//{
	//	cout << "Element found at index " << position << "." << endl;
	//}
#pragma endregion

#pragma region Stack
	//cout << "-----------------------------------------\n";

	//cout << "Basic Stack in action.\n";
	//try
	//{
	//	Stack<int> stack{ 10 };
	//	assert(stack.IsEmpty());
	//	assert(stack.MaxSize() == 10);

	//	cout << "Stack created:" << endl;
	//	cout << stack;

	//	cout << "Pushing some elements:" << endl;
	//	cout << "stack.Push(10)" << endl;
	//	cout << "stack.Push(20)" << endl;
	//	cout << "stack.Push(64)" << endl;
	//	stack.Push(10);
	//	stack.Push(20);
	//	stack.Push(64);
	//	assert(stack.Size() == 3);
	//	cout << stack;

	//	cout << "stack.Pop(): " << stack.Pop() << endl;
	//	cout << "stack.Pop(): " << stack.Pop() << endl;
	//	assert(stack.Size() == 1);
	//	assert(!stack.IsEmpty());

	//	cout << "stack.Top(): " << stack.Top() << endl;
	//	assert(stack.Size() == 1);

	//	cout << "Current stack:" << endl;
	//	cout << stack;
	//}
	//catch (const StackOverflowException& e)
	//{
	//	cout << "\n*** Stack Underflow Exception ***\n" << endl;
	//}
#pragma endregion

#pragma region Linked List
	cout << "-----------------------------------------\n";

	LinkedList<int> l{};
	cout << " Created an empty list: " << l << "\n\n";

	cout << " Inserting some elements...\n";
	l.InsertHead(10);
	l.InsertHead(64);
	l.InsertHead(80);
	l.InsertHead(77);
	cout << " Current list: " << l << "\n\n";

	cout << " Inserting a new element (500) after node with value 64.\n";
	auto position = l.Find(64);
	l.InsertAfter(position, 500);
	cout << " Current list: " << l << "\n\n";

	cout << " Removing current head.\n";
	l.RemoveHead();
	cout << " Current list: " << l << "\n\n";

	cout << " Clearing the whole list.\n";
	l.Clear();
	cout << " Current list: " << l << "\n\n";
#pragma endregion
}
