
#include "stdafx.h"
#include "Shelf.h"

namespace bookshop {

	template <typename T>
	Shelf<T>::~Shelf() {
		for (int i = 0; i < this->size(); i++) {
			delete arr[i];
		}
	}

	template <typename T>
	void Shelf<T>::add_item(T *item) {
		this->arr.push_back(item);
	}

	template <typename T>
	const T *Shelf<T>::most_expensive() const {
		T *tmp = nullptr;
		if (this->size() == 0) {
			return tmp;
		}

		tmp = arr[0];
		for (int i = 1; i < this->size(); i++) {
			if (tmp->get_price() < arr[i]->get_price()) {
				tmp = arr[i];
			}
		}
		return tmp;
	}

	template <typename T>
	const T *Shelf<T>::cheapest() const {
		T *tmp = nullptr;
		if (this->size() == 0) {
			return tmp;
		}

		tmp = arr[0];
		for (int i = 1; i < this->size(); i++) {
			if (tmp->get_price() > arr[i]->get_price()) {
				tmp = arr[i];
			}
		}
		return tmp;
	}

	template <typename T>
	void Shelf<T>::sort_by_price(SortDirection direct) {
		int size = this->size();
		if (this->size() == 0) {
			return;
		}
		for (int i = 1; i < size; i++) {
			T *tmp = arr[i];
			double tmp_price = tmp->get_price();
			for (int j = i - 1; j >= 0; j--) {
				double price = arr[j]->get_price();
				if (price < tmp_price && direct == SortDirection::INC) break;
				if (price > tmp_price && direct == SortDirection::DEC) break;
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}

	template <typename T>
	const double Shelf<T>::avg_price() const {
		double avg_price = 0;
		for (int i = 0; i < this->size(); i++) {
			avg_price += arr[i]->get_price();
		}
		return avg_price / this->size();
	}

	template <typename T>
	const T *Shelf<T>::operator [] (const int idx) const {
		if (idx > this->size() - 1) throw std::length_error("Too large index.");
		if (idx < 0) throw std::range_error("Index is above 0.");
		return this->arr[idx];
	}

	template <typename T>
	const int Shelf<T>::size() const {
		return this->arr.size();
	}

	template class Shelf<Book>;
	template class Shelf<Audio>;
	template class Shelf<Magazine>;
}