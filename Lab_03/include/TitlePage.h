#pragma once
#include "Page.h"

class TitlePage : public Page
{

  public:
	void Print(void) override{};
	void SetHeader(std::string) override{};

	void SetSubTitle(std::string str)
	{
		_sub_title = str;
	}

	void SetAuthor(std::string str)
	{
		_autor = str;
	}

	std::string get_autor()
	{
		return _autor;
	}
	
	virtual std::string Text(void) override
	{
		return _text_buffer;
	};



  private:
	std::string _autor;
	std::string _sub_title;
};