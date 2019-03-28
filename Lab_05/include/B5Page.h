#pragma once
#include "Page.h"

class B5Page : public Page {
		
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
		 B5Page(const B5Page& object):Page(object) {};
		 
		 explicit B5Page(std::string str = "NULL",std::string str2 = "NULL"): Page(str,str2) {};
};