
#pragma once

#include "Item.h"

namespace bookshop {

	class Magazine : public Item {
	public:
		Magazine(c_str name, c_d price, c_b is_new);
	};

}