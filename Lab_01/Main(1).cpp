// Nazwa pliku wykonywalnego: Biblos

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac klasy reprezentujace B5Page oraz Book.
// Obydwie klasy mogą być oparte o bardziej ogólną klase Page.
// Page zawiera w sobie naglowek (header) oraz bufor na tekst.
// Odpowiednie zależności dziedziczenia lub zawierania proszę
// wywnioskować z treści main().

// W zadaniu mozna korzystac z elementow bilbioteki standardowej
// zwlaszcza klasy std::string, ktora jest dostepna w pliku o nazwie
// "string".

// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). 

// Rozwiązanie może być oparte o CMake lub własny Makefile.
// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie Biblos. Program nalezy kompilowac z flagami -Wall -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow (w tym wlasnych wczesniej
// przygotowanych plikow oprocz makefile)

// Rozwiazanie (archiwum biblos.tar.gz zawierajace dodane pliki, makefile i Main.cpp)
// nalezy wgrac do UPEL.

#include "Book.h"

 
int main()
{
    B5Page* b5_page = new B5Page();
    b5_page->Print();
    b5_page->SetHeader("C++, pierwsze starcie");
    b5_page->Print();
    B5Page* b5_page_copy = b5_page->Copy();
    b5_page_copy->Print();
     
    Book* CppBook = new Book("Programowanie Obiektowe 1");
    CppBook->AddPage(b5_page);           
    CppBook->AddPage(b5_page);           
    CppBook->AddPage(b5_page_copy);
    CppBook->AddPage(b5_page_copy);
    CppBook->Print();
    
    delete b5_page;
    delete b5_page_copy;


    // Ustawianie naglowku na wszystkich stronach oprocz pierwszej (tytulowej)                           
    CppBook->SetHeader("Nuda jest wrogiem programistow");                     
    CppBook->Print();

    delete CppBook;
 
    return 0;
}

/* Wynik działania programu:
brachwal@vbox:[build]$ ./Biblos 
[Page::header]  empty
[Page::text]    empty
[Page::header]  C++, pierwsze starcie
[Page::text]    empty
[Page::header]  C++, pierwsze starcie (Copy)
[Page::text]    empty
[WARNING]:: Trying to add already existing page!
[WARNING]:: Trying to add already existing page!

[Book::autor]       Anonym
[Page(0)::text]     Title: Programowanie Obiektowe 1
[Page(1)::header]   C++, pierwsze starcie
[Page(1)::text]     empty
[Page(2)::header]   C++, pierwsze starcie (Copy)
[Page(2)::text]     empty

[Book::autor]       Anonym
[Page(0)::text]     Title: Programowanie Obiektowe 1
[Page(1)::header]   Nuda jest wrogiem programistow
[Page(1)::text]     empty
[Page(2)::header]   Nuda jest wrogiem programistow
[Page(2)::text]     empty
*/