#pragma once

#include <ostream>
#include "Array.h"

class StackOverflowException {};
class StackUnderflowException {};

template <typename T>
class Stack
{
public:
	explicit Stack(int maxStackSize) : m_array{ maxStackSize }, m_top{ -1 }
	{
	}

	void Push(const T& element)
	{
		if (Size() >= MaxSize())
		{
			throw StackOverflowException{};
		}
		else
		{
			m_top++;
			m_array[m_top] = element;
		}
	}

	T Pop()
	{
		if (Size() <= 0)
		{
			throw StackUnderflowException{};
		}
		else
		{
			T topElement = m_array[m_top];
			m_top--;
			return topElement;
		}
	}

	const T& Top() const
	{
		return m_array[m_top];
	}

	int Size() const
	{
		return (m_top + 1);
	}

	bool IsEmpty() const
	{
		if (Size() == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int MaxSize() const
	{
		return m_array.Size();
	}

	void Clear()
	{
		m_top = -1;
	}

	friend std::ostream& operator<<(std::ostream& os, const Stack<T>& stack) {
		if (stack.IsEmpty())
		{
			os << "[*** Empty Stack ***]\n\n";
			return os;
		}

		os << "[Stack]\n";

		for (int i = stack.m_top; i >= 0; i--)
		{
			os << "  " << stack.m_array[i] << '\n';
		}

		return os;
	}

private:
	Array<T> m_array;
	int m_top;
};

