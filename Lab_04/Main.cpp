// Nazwa pliku wykonywalnego: Biblos

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// -----------------------------------------------------------------
// Prosze napisac klasy reprezentujace 
// Book oraz Magazine ktore dzidziczą po interfejsie Publication
// 
// Poniżej założenia projektowe (wymagane):
// * Klasy Pulication jest klasą abstrakcyjną
// * Proszę pamiętać uwzględnianiu override dla metod virtual
//
// Info: Metoda Publication::Create tworzy wrzorzec projektowy 
//       który nazywamy fabryką - w zależności od przekazanych informacji
//       zwraca wskaźnik finalnie utworzonego obiektu
// -----------------------------------------------------------------

// Uwaga: zadanie można realizować poprzez rozszerzenie/modyfikację
//        implementacji z poprzednich zajęć.

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
    Publication* CppBook { Publication::Create("Book",120,"B5") };  // typ publikacji, liczba stron, format
    Publication* CppMagazine { Publication::Create("Magazine",50,"A4") };
    
    std::cout<< "    Book DOI: " << CppBook->DOI() << "\n";             // DOI - digital object identifier
    std::cout<< "Magazine DOI: " << CppMagazine->DOI() << "\n";
    std::cout<< std::endl;

     delete CppBook;
     delete CppMagazine;

    return 0;
}

/* Wynik działania programu: brachwal@vbox:[build]$ ./Biblos 
brachwal@vbox:[build]$ ./Biblos 
    Book DOI: B/00.0000/000
Magazine DOI: M/00.0000/000

*/