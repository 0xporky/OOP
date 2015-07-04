
#include "stdafx.h"
#include "Audio.h"

namespace bookshop {

	Audio::Audio(c_str name, c_str singer, c_i tracks, c_d price, c_b is_new) :
		Item(name, price, is_new), singer(singer), tracks(tracks)
	{}

	c_str Audio::get_singer() const {
		return this->singer;
	}

	c_i Audio::get_tracks() const {
		return this->tracks;
	}
}