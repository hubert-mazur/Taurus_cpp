#pragma once

#include "BaseNode.h"
#include <typeinfo>


template <typename T>
class Node: public BaseNode {

	public:
		Node (T val):value(val){};

		virtual ~Node() = default;

	virtual bool RTTI( const std::type_info& ti) const 
	{ 
		return ti == typeid(value); 
	}

	T get () const
	{
		return value;
	}

	private:
		T value;

};