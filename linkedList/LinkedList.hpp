/**
*	Author: Emilia Paz
*	Date: August 29th, 2018
*	File: LinkedList.hpp
*	Description: Brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList()
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int LinkedList<T>::size() const
{
	return(m_size);
}

template <typename T>
bool LinkedList<T>::search(T value) const
{
	Node<T>* temp = m_front;
	bool isFound = false;

	int i=0;
	while (isFound==false && i<m_size)
	{
		if (temp->getValue() == value)
		{
			isFound = true;
		}
		temp = temp->getNext();
		i++;
	}

	return(isFound);
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);

}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{

	// Empty list, can't remove node from the list
	if (m_size==0)
	{
		return(false);
	}

	// One element in the list
	else if (m_size==1)
	{
		delete m_front;
		m_front = nullptr;
		m_size--;
		return(true);
	}

	// Move until the last node of the list
	else
	{
		Node<T>* lastNode = nullptr;
		Node<T>* secondIntoLast = m_front;
		for (int i=1; i<m_size-1; i++)
		{
			secondIntoLast = secondIntoLast->getNext();
		}
		lastNode = secondIntoLast->getNext();
		secondIntoLast->setNext(nullptr);
		delete lastNode;
		m_size--;
		return(true);
	}

}

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}
