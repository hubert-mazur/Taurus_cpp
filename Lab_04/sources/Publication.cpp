#include "Publication.h"
#include "Magazine.h"
#include "Book.h"

 	Publication* Publication::Create (std::string name,int number_of_pages,std::string format) 
		{
			if (name == "Book")
			{
				// zwracana publikacja typu book

				Publication* class_pointer = new Book;
				class_pointer->_name = name;
				class_pointer->_number_of_pages = number_of_pages;
				class_pointer->_format = format;
				return class_pointer;
			}
			else if (name == "Magazine")
			{
				// zwracana publikacja typu Magazine

				Publication* class_pointer = new Magazine;
				class_pointer->_name = name;
				class_pointer->_number_of_pages = number_of_pages;
				class_pointer->_format = format;
				return class_pointer;
			}
			else
			{
				std::cout<<"Can not recognize type of publication! Please type only allowed types of publications!\nLeaving!\n";
				abort ();

				// w przypadku niezdefiniowanej publikacji program konczy dzialanie
			}
			
		}


