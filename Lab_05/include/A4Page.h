#pragma once
#include "Page.h"

class A4Page : public Page {
		public:

		 std::string GetHeader() override
		 {
			 return _Header;
		 }

		 void SetHeader(std::string str) override
		 {
			 _Header = str;
		 }

		 std::string GetTextBuffer () override
		 {
			 return _Text_buffer;
		 }
		 
		 void SetTextBuffer (std::string str) override
		 {
			 _Text_buffer = str;
		 }
		 A4Page(const A4Page& object):Page(object) {};
		 explicit A4Page(std::string str = "NULL",std::string str2 = "NULL"): Page(str,str2) {};
};