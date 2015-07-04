// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Shelf.h"

#include <iostream>
#include <typeinfo>

using namespace std;

typedef bookshop::Book bBook;
typedef bookshop::Magazine bMagazine;
typedef bookshop::Audio bAudio;
typedef bookshop::Shelf<bBook> tBookShelf;
typedef bookshop::Shelf<bMagazine> tMagazineShelf;
typedef bookshop::Shelf<bAudio> tAudioShelf;

void add_books(tBookShelf &BookShelf);
void add_magazines(tMagazineShelf &MagazineShelf);
void add_audio(tAudioShelf &AudioShelf);
void print_obj(const bBook *item);
void print_obj(const bMagazine *item);
void print_obj(const bAudio *item);

int _tmain(int argc, _TCHAR* argv[])
{
	
	tBookShelf BookShelf;
	tMagazineShelf MagazineShelf;
	tAudioShelf AudioShelf;

	add_books(BookShelf);
	add_magazines(MagazineShelf);
	add_audio(AudioShelf);

	cout << "All info.\n";
	for (int i = 0; i < BookShelf.size(); i++) {
		print_obj(BookShelf[i]);
		cin.get();
	}

	cout << "\n\n\n";

	for (int i = 0; i < MagazineShelf.size(); i++) {
		print_obj(MagazineShelf[i]);
		cin.get();
	}

	cout << "\n\n\n";

	for (int i = 0; i < AudioShelf.size(); i++) {
		print_obj(AudioShelf[i]);
		cin.get();
	}

	cout << "\n\n\n";

	cout << "Most expensive book.\n";
	print_obj(BookShelf.most_expensive());
	cin.get();

	cout << "Most expensive magazine.\n";
	print_obj(MagazineShelf.most_expensive());
	cin.get();

	cout << "Most expensive audio.\n";
	print_obj(AudioShelf.most_expensive());
	cin.get();

	cout << "\n\n\n";

	cout << "Most cheapest book.\n";
	print_obj(BookShelf.cheapest());
	cin.get();

	cout << "Most cheapest magazine.\n";
	print_obj(MagazineShelf.cheapest());
	cin.get();

	cout << "Most cheapest audio.\n";
	print_obj(AudioShelf.cheapest());
	cin.get();

	cout << "\n\n\n";

	cout << "Sorting by price.\n";
	BookShelf.sort_by_price(bookshop::SortDirection::INC);
	MagazineShelf.sort_by_price(bookshop::SortDirection::INC);
	AudioShelf.sort_by_price(bookshop::SortDirection::INC);

	cout << "All info.\n";
	for (int i = 0; i < BookShelf.size(); i++) {
		print_obj(BookShelf[i]);
		cin.get();
	}

	cout << "\n\n\n";

	for (int i = 0; i < MagazineShelf.size(); i++) {
		print_obj(MagazineShelf[i]);
		cin.get();
	}

	cout << "\n\n\n";

	for (int i = 0; i < AudioShelf.size(); i++) {
		print_obj(AudioShelf[i]);
		cin.get();
	}

	cout << "\n\n\n";

	cout << "AVG book price: " << BookShelf.avg_price() << endl;
	cout << "AVG magazine price: " << MagazineShelf.avg_price() << endl;
	cout << "AVG audio price: " << AudioShelf.avg_price() << endl;

	cout << "\n\n\n";

	try {
		print_obj(AudioShelf[4]);
	}
	catch (const std::length_error &e) {
		cout << "Length error " << e.what();
	}

	cout << endl;

	return 0;
}

void add_books(tBookShelf &BookShelf) {
	bBook *Book1 = new bBook(string("The Little Paris Bookshop"), string("Nina George"), string("Crown (June 23, 2015)"), 13.10, false);
	BookShelf.add_item(Book1);
	bBook *Book2 = new bBook(string("All the Light We Cannot See"), string("Anthony Doerr"), string("Scribner (May 6, 2014)"), 13.50, true);
	BookShelf.add_item(Book2);
	bBook *Book3 = new bBook(string("In the Kingdom of Ice"), string("Hampton Sides"), string("Doubleday (August 5, 2014)"), 18.90, false);
	BookShelf.add_item(Book3);
}

void add_magazines(tMagazineShelf &MagazineShelf) {
	bMagazine *Magazine1 = new bMagazine(string("Game informer"), 25.10, false);
	MagazineShelf.add_item(Magazine1);
	bMagazine *Magazine2 = new bMagazine(string("National Geographic"), 50.50, true);
	MagazineShelf.add_item(Magazine2);
	bMagazine *Magazine3 = new bMagazine(string("Woman's Day"), 10.90, false);
	MagazineShelf.add_item(Magazine3);
}

void add_audio(tAudioShelf &AudioShelf) {
	bAudio *Audio1 = new bAudio(string("LOVELESS"), string("MY BLOODY VALENTINE"), 19, 10.10, false);
	AudioShelf.add_item(Audio1);
	bAudio *Audio2 = new bAudio(string("2001"), string("DR DRE"), 9, 20.50, true);
	AudioShelf.add_item(Audio2);
	bAudio *Audio3 = new bAudio(string("WHAT’S GOING ON"), string("MARVIN GAYE"), 12, 30.90, false);
	AudioShelf.add_item(Audio3);
}

void print_obj(const bBook *item) {
	cout << "Info about book.\n";
	cout << "Name:\t" << item->get_name() << endl;
	cout << "Author:\t" << item->get_author() << endl;
	cout << "Publisher:\t" << item->get_publisher() << endl;
	cout << "Price:\t" << item->get_price() << endl;
	cout << "Is new:\t" << item->get_status() << endl << endl;
}

void print_obj(const bMagazine *item) {
	cout << "Info about magazine.\n";
	cout << "Name:\t" << item->get_name() << endl;
	cout << "Price:\t" << item->get_price() << endl;
	cout << "Is new:\t" << item->get_status() << endl << endl;
}

void print_obj(const bAudio *item) {
	cout << "Info about audio.\n";
	cout << "Name:\t" << item->get_name() << endl;
	cout << "Singer:\t" << item->get_singer() << endl;
	cout << "Tracks:\t" << item->get_tracks() << endl;
	cout << "Price:\t" << item->get_price() << endl;
	cout << "Is new:\t" << item->get_status() << endl << endl;
}