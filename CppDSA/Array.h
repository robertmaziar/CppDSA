#pragma once
#include <cassert>
#include <ostream>
#include <utility>
using std::swap;

class IndexOutOfBoundsException {};

template <typename T>
class Array
{
public:
	// Default constructor
	Array()
	{
	}

	// Destructor
	~Array()
	{
		delete[] m_ptr;
	}

	// Constructor to create an array with the given size (element count)
	explicit Array(int size)
	{
		assert(size >= 0);

		if (size != 0)
		{
			m_ptr = new T[size]{};
			m_size = size;
		}
	}

	// Copy constructor
	Array(const Array& source)
	{
		if (!source.IsEmpty())
		{
			m_size = source.m_size;
			m_ptr = new T[m_size]{};

			for (int i = 0; i < m_size; i++)
			{
				m_ptr[i] = source.m_ptr[i];
			}
		}
	}

	// Move constructor
	Array(Array&& source) : m_ptr{ source.m_ptr }, m_size{ source.m_size }
	{
		source.m_ptr = nullptr;
		source.m_size = 0;
	}

	// Assignment operator (via copy-and-swap idiom)
	Array& operator=(Array source)
	{
		swap(*this, source);
		return *this;
	}

	// Swap two array objects (member-wise swap)
	friend void swap(Array& a, Array& b) noexcept
	{
		swap(a.m_ptr, b.m_ptr);
		swap(a.m_size, b.m_size);
	}

	int Size() const
	{
		return m_size;
	}

	bool IsEmpty() const
	{
		if (m_size == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// Safe element access with bounds checking
	T& operator[](int index)
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

	// Safe read-only element access with bounds checking
	T operator[](int index) const
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
	T* m_ptr{ nullptr };
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

// Enable idiomatic stream insertion for Array objects
// (e.g. cout << ... << myArray << ...)
template <typename T>
inline std::ostream& operator<<(std::ostream& os, const Array<T>& a) {
	os << "[ ";
	for (int i = 0; i < a.Size(); i++)
	{
		os << a[i] << " ";
	}
	os << "]";

	return os;
}
