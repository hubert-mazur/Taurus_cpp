#pragma once

#include <iostream>


template <typename T>
class DynArray { 
/** This is a template class. It reminds simple array. Provides basic functionality*/ 
	
	public:
	
	explicit DynArray (int size) /** constructor takes int as argument, creates array*/
	{
		array = new T [size];
		length = size;
	}

	T& operator[](int elem) /** operator[], provides array indexing from global scope*/
	{
		return *(array + elem);
	}


	int size() const /** class member, returns length of existing array*/
	{
		return length;
	}

	T* getArray() const /** class member, returns pointer to array*/
	{
		return array;
	}

	~DynArray () /** Deconstructor, deletes array*/
	{
		delete [] array;
		length = 0;
	}

	DynArray (int size,const std::string *stringArray) /** Overloaded class constructor, takes string array, and copy it's values*/
	{
		array = new T [size];
		length = size;

		for (int i=0;i<size;i++)
			array[i] = stringArray[i];
	}

	T* begin () const /** Class method, returns pointer to array start*/
	{
		return array;
	}

	T* end () const /** Class method, returns pointer to array start*/
	{
		return (array + length);
	}




	class Iterator {
		/** Inside class for iterating*/
		public:
			Iterator (T* object) /** Class copy constructor*/
			{
				box = object;
			}

			T operator* () /** Operator *, returns dereferenced array*/
			{
				return *box;
			}

			T* operator-> () /** Operator ->, returns pointer to array*/
			{
				return box;
			}

			bool operator!= (T *object) /** Operator !=, checks whether objects are same*/
			{
				if (box == object)
					return 	false;
				else
					return true;
			}

			T* operator++ () /** Increment operator for private member*/
			{
				return box++;
			}

			private:
				T *box; /** Private member, pointer to array*/

	};



private:
	T *array; /** Private member, pointer to array of template depend type*/
	int length; /** Private member representing lenght of array*/

};

	template <typename T>
	std::ostream& operator<< (std::ostream &ostr,DynArray <T> &object)
	/** Overloaded operator << for manipulating output, takes template depend type of DynArray class*/
	{
		ostr<<"{";

		for (int i=0;i<object.size()-1;i++)
		{
			ostr<<"\"" <<object.getArray()[i]<<"\",";
		}
		ostr<<object.getArray()[object.size()-1]<<"\"}";
		return ostr;
	}

