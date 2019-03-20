// Nazwa pliku wykonywalnego: Biblos

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac klasy reprezentujace 
// B5Page, TitlePage, Book.
// Obydwie klasy (XPage) mogą być oparte o bazową klase Page.
// Page zawiera w sobie naglowek (header) oraz bufor na tekst.
// Odpowiednie zależności dziedziczenia lub zawierania proszę
// wywnioskować z treści main().

// Uwaga: zadanie można realizować poprzez rozszerzenie implementacji
//        z poprzednich zajęć.

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
        
    Book CppBook("OOP",5,"B5");                // przekazywany tytul ksiazki, liczba stron, format           
    
    std::cout<<"Number of pages in the book: "
             << CppBook.size() << std::endl;    // strona tytułowa wliczona.

    TitlePage* titlePage = CppBook.TitlePagePtr();
    titlePage->SetSubTitle("Thursday Lab.");
    titlePage->SetAuthor("StudentX");

    CppBook[1]->SetHeader("C++, pierwsze starcie");
    CppBook[2]->SetHeader("Nuda jest wrogiem programistow");

    std::cout<< CppBook << std::endl;
 
    return 0;
}

/* Wynik działania programu: brachwal@vbox:[build]$ ./Biblos 
Number of pages in the book: 6
[Book::Title]       OOP (Thursday Lab.)
[Book::Autor]       StudentX
[Page(0)::header]   C++, pierwsze starcie
[Page(0)::text]     empty
[Page(1)::header]   Nuda jest wrogiem programistow
[Page(1)::text]     empty
[Page(2)::text]     empty
[Page(3)::text]     empty
[Page(4)::text]     empty

*/