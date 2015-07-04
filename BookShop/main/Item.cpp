
#include "stdafx.h"
#include "Item.h"

namespace bookshop {

	Item::Item(c_str name, c_d price, c_b is_new) :
		name(name), price(price), is_new(is_new)
	{}

	Item::Item(const char *name, c_d price, c_b is_new) :
	name(name), price(price), is_new(is_new)
	{}

	void Item::set_price(c_d price) {
		this->price = price;
	}

	c_d Item::get_price() const {
		return this->price;
	}

	void Item::set_status(c_b status) {
		this->is_new = status;
	}

	c_b Item::get_status() const {
		return this->is_new;
	}

	const std::string Item::get_name() const {
		return this->name;
	}

}