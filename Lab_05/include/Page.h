# pragma once 
#include <string>
class Page {

	public:
		virtual std::string GetHeader(void) = 0;
		virtual std::string GetTextBuffer (void) = 0;
		virtual void SetHeader(std::string) = 0;
		virtual void SetTextBuffer(std::string) = 0;
		virtual ~Page() = default;
		
	protected:
		std::string _Header;
		std::string _Text_buffer;
};