#pragma once
#include <string>
#include "ObiektMiotajacy.h"
#include <iostream>
class MyExceptions {

	public:
		virtual void PrzedstawSie()
		{
			std::cout<<"Nazywam sie "<<type_info<<" (adres obiektu: <"<<this<<">)"<<std::endl;
		}

		
		virtual ~MyExceptions () = default;
		

		// MyExceptions (ObiektMiotajacy *pointer = NULL):freeable(pointer){};

		MyExceptions (ObiektMiotajacy *object) {freeable = object;}

		std::string get_type ()
		{
			return type_info;
		}

		ObiektMiotajacy *get_free_p ()
		{
			return freeable;
		}

		void Set_NULL (void)
		{
			freeable = NULL;
		}

	protected:
		std::string type_info;
		ObiektMiotajacy *freeable;
};

class typ1 : public MyExceptions {
	public:
		typ1():MyExceptions(NULL) {type_info = "1";};
		typ1(ObiektMiotajacy *object):MyExceptions(object){type_info = "1";};
};

class typ2 : public MyExceptions {
	public:
				typ2():MyExceptions(NULL) {type_info = "2";};
		typ2( ObiektMiotajacy* object):MyExceptions(object){type_info = "2";};
};

class typ3 : public MyExceptions {
	public:
				typ3():MyExceptions(NULL) {type_info = "3";};
		typ3( ObiektMiotajacy *object):MyExceptions(object){type_info = "3";};

};

class typ4 : public MyExceptions {
	public:
		typ4():MyExceptions(NULL) {type_info = "4";};
		typ4( ObiektMiotajacy *object):MyExceptions(object){type_info = "4";};
};

inline void Przetworz (MyExceptions *object)
{
	std::cout<<"Przetworz - wyjatek typu "<<object->get_type()<<" o adresie: <"<<object<<">"<<std::endl;
	if (object->get_free_p())
		delete object->get_free_p();
	object->Set_NULL();
	delete object;
	throw (new typ4());
}


