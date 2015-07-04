
#pragma once

#include <vector>
#include <stdexcept>

#include "Book.h"
#include "Audio.h"
#include "Magazine.h"

namespace bookshop {

	enum SortDirection {INC = 1, DEC};

	template <typename T>
	class Shelf
	{
	public:
		Shelf() {};
		~Shelf();

		void add_item(T *item);

		const T *most_expensive() const;
		const T *cheapest() const;

		void sort_by_price(SortDirection direct);
		const double avg_price() const;

		const T *operator [] (const int idx) const;
		const int size() const;

	private:
		Shelf(Shelf &obj);

		std::vector<T*> arr;
	};

}