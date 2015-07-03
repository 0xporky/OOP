
#include "stdafx.h"
#include "Book.h"

namespace bookshop {

	Book::Book(c_str name, c_str author, c_str publisher, c_d price, c_b is_new) :
		Item(name, price, is_new), author(author), publisher(publisher)
	{}

	c_str Book::get_author() const {
		return this->author;
	}

	c_str Book::get_publisher() const {
		return this->publisher;
	}
}