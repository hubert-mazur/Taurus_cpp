// Nazwa pliku wykonywalnego: DynamicArray

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Proszę napisać kontener będący opakowaniem na tablicę dynamiczną. 
// Dla uproszczenia, rozmiar kontenera jest stały w trakcie działania programu,
// proszę pamiętać o zarządzaniu pamięcią.

// Jako uzupełnienie kontenera, należy napisać podklasę Iterator, który
// będzie pomocny przy operacjach na kolejnych elementach tej tablicy.

// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty 
// (miec czytelny i dobrze napisany kod). 

// Program nalezy kompilowac z flagami -Wall -g.

// Makefile (lub CMakeLists.txt) dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie mobile. Program nalezy kompilowac z flagami -Wall -g.
// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow (w tym wlasnych wczesniej
// przygotowanych plikow oprocz makefile)

// Rozwiazanie (archiwum darray.tar.gz zawierajace w folderze dodane pliki, makefile i Main.cpp)
// nalezy wgrac do UPEL.

// Autorzy: Hubert Mazur, Hubert Uliaszyk

#include "main.hpp"
#include "main.hpp"

#include <iostream>
#include <string>
#include <numeric>

int main(){
    
    // array indexing
    DynArray<int> arr(5);   
    for(int i = 0; i < arr.size(); ++i){
        arr[i] = i*i;
    }
    std::cout << "DynArray<int> = " << arr << std::endl;
    
    arr[0] = 10.5;   
    std::cout << "DynArray<int>[0] = " << arr[0] << std::endl;
    
    // array iterators
    const std::string staticArray[4] = {"Anna", "Elsa", "Olaf", "Zen"};
    DynArray<std::string> strArr(4, staticArray);
    
    std::cout << "DynArray<std::string> = "<< strArr << std::endl;

    for(DynArray<std::string>::Iterator it = strArr.begin(); it != strArr.end(); ++it){
        std::cout << "\tBefore: " << *it << std::endl;
        it->append(" Ice");                             // usage of std::string::append
        std::cout << "\tAfter : " << *it << std::endl;
    }

    std::cout << "DynArray<std::string> = "<< strArr << std::endl;
    
    return 0;
}

/* Wynik działania programu
DynArray<int> = {"0","1","4","9","16"}
DynArray<int>[0] = 10
DynArray<std::string> = {"Anna","Elsa","Olaf","Zen"}
    Before: Anna
    After : Anna Ice
    Before: Elsa
    After : Elsa Ice
    Before: Olaf
    After : Olaf Ice
    Before: Zen
    After : Zen Ice
DynArray<std::string> = {"Anna Ice","Elsa Ice","Olaf Ice","Zen Ice"}
*/
