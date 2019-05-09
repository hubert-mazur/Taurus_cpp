#pragma once

#include <iostream>
#include <string>

class Pomieszczenie {

	public:
		Pomieszczenie (std::string str):name(str)
		{
			std::cout<<"Tworze pomieszczenie: "<<name<<std::endl;
		}

		void zetrzyj_kurze () const
		{
			std::cout<<"Scieram podloge w pomieszczeniu: "<<name<<std::endl;
		}
		
		void umyj_podloge() const 
		{
			std::cout<<"Myje podloge w pomieszczeniu: "<<name<<std::endl;
		}

		void odkurz () const
		{
			std::cout<<"Odkurzam w pomieszczeniu: "<<name<<std::endl;
		}

		std::string getName () const
		{
			return name;
		}

		template <typename T>
			void wstaw (const T &object) const
			{
				std::cout<<"Wstawiam "<<object<<" do pomieszczenia: "<<name<<std::endl;
			}


	protected:
		std::string name;

};

