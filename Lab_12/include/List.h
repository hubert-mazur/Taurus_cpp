#pragma once

#include "BaseNode.h"
#include "Node.h"

class List {

	public:

	List ()
	{
		Head = NULL;
	}

	template <typename T>
	void add (T value)
	{
		BaseNode *temp = new Node<T> (value);
		
		if (!Head)
		{
			Head = temp;
		}
		else
		{
			BaseNode *it = Head;
			temp->Next = it;
			Head = temp;
		}
	}

	BaseNode * head () const 
	{
		return Head;
	}

	template <typename T>
	static T get (const BaseNode *object)
	{
		if (object->isType<T>() == false)
			throw std::runtime_error("Types!\n");
		return static_cast<const Node<T>*> (object)->get();
	}

	~List ()
	{
		delete Head;
	}


	private:
		BaseNode *Head;

};