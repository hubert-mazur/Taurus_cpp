# pragma once 
#include <string>
class Page {

	public:
		virtual std::string GetHeader() = 0;
		virtual std::string GetTextBuffer () = 0;
		virtual void SetHeader(std::string) = 0;
		virtual void SetTextBuffer(std::string) = 0;
		virtual ~Page() = default;
		Page (std::string str1,std::string str2):_Header(str1),_Text_buffer(str2) {};
		Page(const Page& object)
		{
			_Header = object._Header;
			_Text_buffer = object._Text_buffer;
		}
	protected:
		std::string _Header;
		std::string _Text_buffer;
};