
#pragma once

#include <string>

namespace bookshop {

	typedef const std::string c_str;
	typedef const double c_d;
	typedef const bool c_b;
	typedef const int c_i;

	class Item {
	public:

		Item(c_str name, c_d price, c_b is_new);
		Item(const char *name, c_d price, c_b is_new);

		virtual ~Item() = 0 {};

		c_str get_name() const;

		void set_price(c_d price);
		c_d get_price() const;

		void set_status(c_b status);
		c_b get_status() const;

	private:
		Item(Item &obj);
		std::string name;
		double price;
		bool is_new;
	};

}