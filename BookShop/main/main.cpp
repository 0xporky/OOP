// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Audio.h"
#include "Book.h"
#include "Magazine.h"
#include "Shelf.h"

#include <iostream>

using namespace std;

typedef bookshop::Book bBook;
typedef bookshop::Magazine bMagazine;
typedef bookshop::Audio bAudio;
typedef bookshop::Shelf<bBook> tBookShelf;
typedef bookshop::Shelf<bMagazine> tMagazineShelf;
typedef bookshop::Shelf<bAudio> tAudioShelf;

void add_books(tBookShelf &BookShelf);

int _tmain(int argc, _TCHAR* argv[])
{
	
	tBookShelf BookShelf;
	tMagazineShelf MagazineShelf;
	tAudioShelf AudioShelf;

	add_books(BookShelf);
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