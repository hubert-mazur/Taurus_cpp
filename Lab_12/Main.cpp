 
// Nazwa pliku wykonywalnego: PolyList
// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Proszę napisać polimorficzną listę przechowującą dane jako wartosci.
// W sklad takiej listy wchodza elementy Node, ktore musza byc dostosowane 
// do roznych typow przechowywanych. 
// Czyli gdzies w srodku musi byc typ: Node<int> Node<flaot> -> narzuca sie odpowiednia 
// hierarchia. 
// UWAGA: Wirtualne zachowanie potrzebne w implementacji isType mozna uzyskac 
// po zamanie typu na jego identyfikator (RTTI)
// UWAGA: Mozna kozystac z dokumentacji mechanizmu RTTI:
// http://en.cppreference.com/w/cpp/language/typeid
//
// W przypadku "metody" get zakladamy ze typy pasuja (mozna to sprawdzic 
// za pomoca isType) a wiec mozna wykonac odpowiednie rzutowanie.
// UWAGA: Prosze nie zapomniec o sprzatnieciu pamieci (virtual ~).

// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty 
// (miec czytelny i dobrze napisany kod). 

// Program nalezy kompilowac z flagami -Wall -g.

// Makefile (lub CMakeLists.txt) dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie mobile. Program nalezy kompilowac z flagami -Wall -g.
// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek, ani zadnych innych 
// materialow (w tym wlasnych wczesniej przygotowanych plikow oprocz makefile)
// -> oprócz zasobów określonych wcześniej

// Rozwiazanie (archiwum polylist.tar.gz zawierajace w folderze dodane pliki, 
// makefile i Main.cpp nalezy wgrac do UPEL.

#include <iostream>
#include "List.h"


int main() {
  using namespace std;
  List al;
  al.add<int>(7);
  al.add<float>(4.56); // dodaje na poczatku
  al.add<double>(4.566); // to jest teraz pierwsza

  cout << al.head()->isType<float>()  << endl;
  cout << al.head()->isType<int>()  << endl;

  cout << al.head()->next()->isType<float>()  << endl;
  cout << al.head()->next()->isType<int>()  << endl;
  cout << al.head()->next()->next()->isType<int>()  << endl;

  cout << List::get<double>(al.head()) << std::endl; // pierwszy jest double
  
}
/* wynik
0
0
1
0
1
4.566
 */
