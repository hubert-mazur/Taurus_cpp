// Nazwa pliku wykonywalnego: Biblos

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// -----------------------------------------------------------------
// Głównym tematem zadania jest definiowanie przeciążonych wersji operatorów

// Uwaga: zadanie można realizować poprzez rozszerzenie/modyfikację
//        implementacji z poprzednich zajęć.
// Tak więc, zadanie może polegać na uzupełnieniu wcześniej definiowanej 
// klasy Book dziedziczącej po interfejsie Publication
// 
// Obowiązujace założenia projektowe:
// * Klasa Pulication jest klasą abstrakcyjną
// * Reszta wynika z treści main, lub jest uwzględniona w komentarzu

// W zadaniu mozna korzystac z elementow bilbioteki standardowej
// zwlaszcza klasy std::string, std::vector

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
// przygotowanych plikow oprocz makefile).

// Rozwiazanie (archiwum biblos.tar.gz zawierajace dodane pliki, makefile i Main.cpp)
// nalezy wgrac do UPEL.

#include "Book.h"
 
int main()
{
    Publication* CppBook15B5 { Publication::Create("Book",15,"B5") };  // typ publikacji, liczba stron, format
    Publication* CppBook20A4 { Publication::Create("Book",20,"A4") };
    Publication* CppBook10A4 { Publication::Create("Book",10,"A4") };

     Book* CppBook15B5Ptr = dynamic_cast<Book*>(CppBook15B5);
     std::cout<< "B5 number of pages: " << CppBook15B5Ptr->NPages() << "\n";
     ++(*CppBook15B5Ptr); // dodanie nowej/pustej strony
     std::cout<< "B5 number of pages: " << CppBook15B5Ptr->NPages() << "\n";

    Book* CppBook20A4Ptr = dynamic_cast<Book*>(CppBook20A4);
    Book* CppBook10A4Ptr = dynamic_cast<Book*>(CppBook10A4);

    CppBook20A4Ptr->TitlePagePtr()->SetTitle("Book with 20 pages");
    
    std::cout<< "\"" << CppBook20A4Ptr->TitlePagePtr()->GetTitle() << "\"";
    std::cout<< " => Actual number of pages: " << CppBook20A4->NPages()<<"\n"; // liczba stron = bez wliczania TitlePage
    
    *CppBook20A4Ptr = *CppBook15B5Ptr;	// błąd przypisania, nieprawidłowy format, oryginał jest nie zmodyfikowany, komunikat na ekran
    *CppBook20A4Ptr = *CppBook10A4Ptr;	// OK, przypisanie polega na podmianie stron, bez strony tytułowej
	
	std::cout<< "\"" << CppBook20A4Ptr->TitlePagePtr()->GetTitle() << "\"";
    std::cout<< " => Actual number of pages: " << CppBook20A4->NPages()<<"\n";
    
    std::cout<<std::endl;

    delete CppBook15B5;
    delete CppBook10A4;
    delete CppBook20A4;
 
    return 0;
}

/* Wynik działania programu:
brachwal@vbox:[build]$ ./Biblos 
B5 number of pages: 15
B5 number of pages: 16
"Book with 20 pages" => Actual number of pages: 20
[ERROR]:: Trying to assign different formats!
"Book with 20 pages" => Actual number of pages: 10

*/