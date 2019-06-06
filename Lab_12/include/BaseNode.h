#pragma once

#include <typeinfo>

class BaseNode {

	public:

	BaseNode ():Next(NULL){};
	virtual ~BaseNode () {delete Next;};

	template <typename T>
	bool isType() const 
	{
		 return RTTI(typeid(T)); 
	}

	virtual bool RTTI(const std::type_info&) const
	{
		return false;
	}

	BaseNode* next()  { return Next; }

		BaseNode *Next;
};
