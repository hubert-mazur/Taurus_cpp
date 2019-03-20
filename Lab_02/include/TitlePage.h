# pragma once
# include "Page.h"

class TitlePage : public Page
{

	public:
		void SetSubTitle (std::string str)
		{
			_sub_title=str;
		}
		void SetAuthor (std::string str)
		{
			_autor=str;
		}
		TitlePage(std::string str=""){};
		void Print (void) override
		{

		}
		void SetHeader (std::string str) override
		{

		}
	private:
	std::string _autor;
	std::string _sub_title;
};