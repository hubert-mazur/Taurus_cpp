// ** ZADANIE WYKONYWANE W PARACH ***
// Zespół:
// 1. Konrad Perlowski
// 2. Huber Mazur

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Celem zadania jest rozszerzenie funkcjonalności otrzymanego kodu.
// Rozszerzenie dotyczy operacji na współrzędnych geograficznych, czyli implementacje
// związane klasą Gps

// ZADANIE: Otrzymujecie Państwo implementacje klas typu Haversine niezbędnych do operacji 
// na współrzędnych geograficznych. Rzecz w tym, że implementacja ta nie jest kompletna,
// należy więc je uzupełnić, tak aby możliwy był do uruchomienia interfejs wykorzystany w poniższej
// funkcji main. Lista rzeczy do zrobienia:
// - implementacja klasy Gps z wykorzystaniem klasy Coordinate
// - implementacja klasy Distance z wykorzystaniem klasy Coordinate
// - uzupełnienie klasy Coordinate - powinna posiadać przeciążony odpowiedni operator
// - Wszystkie klasy nalezy wyposażyć w niezbędny interfejs, wykorzystant w main

// UWAGA: Wymagania projektowe:
//		- implementacja kodu jest dowolna - nie powienien być zmodyfikowany jedynie plik Main.cpp;
//      - należy zadbać o zasadność zawieranie/dziedziczenia odpowiednich klas/cech/informacji
//		- definicja klasy Distance ma wykorzystywać ideę delegowania konstruktorów;
// 		- Informacje o współrzednych (klasa Coordinate) zawarte są w klasie Gps
// 		- do policzenia dystansu w km pomiędzy dwoma wspolrzednymi wykorzystac 
//    	  funkcje Haversine(...) juz zdefiniowaną;

// W zadaniu mozna korzystac z elementow bilbioteki standardowej
// zwlaszcza klasy std::string oraz std::vector

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod).

// Makefile (lub CMakeLists.txt) dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie Gps. Program nalezy kompilowac z flagami -Wall -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow (w tym wlasnych wczesniej
// przygotowanych plikow oprocz makefile)

// Rozwiazanie (archiwum gps.tar.gz zawierajace w folderze dodane pliki, makefile i Main.cpp)
// nalezy wgrac do UPEL.

#include "Main.h"

int main(){

	Gps myGps1, myGps2;

	// Set location parameters stored in GPS Coordinate instance:
	Coordinate Krakow { myGps1.Location(19.9449799,50.0646501) };
	Coordinate Warszwa{ myGps2.Location(21.012229,52.229676) };

	Krakow+=PointedDistance(2,"South"); // move 2 meters into South;
	Krakow+=PointedDistance(5,"West"); 	// move 5 meters into West;

	Warszwa+=PointedDistance(1,"North"); // move 1 meters into South;
	Warszwa+=PointedDistance(3,"East"); // move 1 meters into East;

	Distance distanceBetweenCities(Krakow,Warszwa);
	std::cout<<"[INFO]::   Krakow location " << myGps1.LocationInfo()<<"\n";
	std::cout<<"[INFO]:: Warszawa location " << myGps2.LocationInfo()<<"\n";
	std::cout<<"[INFO]:: Distance " << distanceBetweenCities.Value() << " [km]\n";

	// simple check:
	Distance distance(   Krakow.Longitude(),
						 Krakow.Latitude(),
						 Warszwa.Longitude(),
						 Warszwa.Latitude() );

	std::cout<<"[INFO]:: Distance check " << distance.Value() << " [km]" <<std::endl;

	return 0;
}

/* Wynik dzialania programu:
brachwal@vbox:[build]$ ./Gps 
[INFO]::   Krakow location Longitude: 19.944981 Latitude: 50.064651
[INFO]:: Warszawa location Longitude: 21.012230 Latitude: 52.229675
[INFO]:: Distance 252.013 [km]
[INFO]:: Distance check 252.013 [km]
*/
