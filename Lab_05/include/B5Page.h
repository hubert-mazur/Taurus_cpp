#pragma once
#include "Page.h"

class B5Page : public Page {

		 std::string GetHeader(void) override 
		 {
			 return _Header;
		 }

		 void SetHeader(std::string str) override
		 {
			 _Header = str;
		 }

		 std::string GetTextBuffer (void) override
		 {
			 return _Text_buffer;
		 }

		 void SetTextBuffer (std::string str) override
		 {
			 _Text_buffer = str;
		 }
};