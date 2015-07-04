
#pragma once

#include "Item.h"

namespace bookshop {

	class Book : public Item {
	public:
		Book(c_str name, c_str author, c_str publisher, c_d price, c_b is_new);

		c_str get_author() const;
		c_str get_publisher() const;
		
	private:
		std::string author;
		std::string publisher;
	};

}