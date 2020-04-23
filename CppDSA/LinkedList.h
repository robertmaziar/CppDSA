#pragma once

#include <cassert>
#include <ostream>

template <typename T>
class LinkedList
{
private:
	struct Node
	{
		Node* Next{ nullptr };
		T Data{};

		Node()
		{
		}

		explicit Node(const T& data) : Data{ data }
		{
		}

		Node(const T& data, Node* next) : Data{ data }, Next{ next }
		{
		}
	};

	Node* m_head{ nullptr };
	int m_count{ 0 };

	LinkedList(const LinkedList&) = delete;
	LinkedList& operator=(const LinkedList&) = delete;

public:

	typedef Node* Position;

	LinkedList()
	{
	}

	~LinkedList()
	{
		Clear();
	}

	int Count() const
	{
		return m_count;
	}

	bool IsEmpty() const
	{
		if (m_count == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Clear()
	{
		while (!IsEmpty())
		{
			RemoveHead();
		}
	}

	void InsertHead(const T& value)
	{
		Node* node = new Node{ value };
		node->Next = m_head;
		m_head = node;

		++m_count;
	}

	void RemoveHead()
	{
		assert(!IsEmpty());

		Node* newHead = m_head->Next;

		delete m_head;

		m_head = newHead;

		--m_count;
	}

	T ElementAt(Position node)
	{
		assert(!IsEmpty());
		assert(node != nullptr);

		return node->Data;
	}

	void InsertAfter(Position node, const T& value)
	{
		assert(node != nullptr);

		Node* newNode = new Node{ value };
		newNode->Next = node->Next;
		node->Next = newNode;

		++m_count;
	}

	void RemoveAfter(Position node)
	{
		assert(!IsEmpty());
		assert(node != nullptr);

		Node* obsoleteNode = node->Next;
		node->Next = obsoleteNode->Next;

		delete obsoleteNode;

		--m_count;
	}

	Position Find(const T& value)
	{
		if (IsEmpty())
		{
			return nullptr;
		}

		Node* node = m_head;
		while (node != nullptr)
		{
			if (node->Data == value)
			{
				return node;
			}

			node = node->Next;
		}

		return nullptr;
	}

	friend std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list)
	{
		if (list.IsEmpty())
		{
			os << "[ Empty List ]";
			return os;
		}

		os << "[ ";

		Node* node = list.m_head;
		while (node != nullptr)
		{
			os << node->Data << " ";

			node = node->Next;
		}

		os << "]";
		return os;
	}
};
