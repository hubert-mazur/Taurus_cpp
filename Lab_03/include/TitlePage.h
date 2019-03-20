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
		void Print (void) override {};
		void SetHeader (std::string) override {};
		virtual std::string Text (void) override {};
		std::string get_autor()
		{
			return _autor;
		}
	private:
	std::string _autor;
	std::string _sub_title;
};