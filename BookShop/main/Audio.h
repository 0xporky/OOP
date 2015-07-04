
#pragma once

#include "Item.h"

namespace bookshop {

	class Audio : public Item {
	public:
		Audio(c_str name, c_str singer, c_i tracks, c_d price, c_b is_new);

		c_str get_singer() const;
		c_i get_tracks() const;

	private:
		std::string singer;
		int tracks;
	};

}