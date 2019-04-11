// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Celem zadania jest rozszerzenie funkcjonalności otrzymanego kodu, ale też rozwijanego 
// na ostatnich zajęciach!
// Rozszerzenie dotyczy operacji na współrzędnych geograficznych, czyli implementacje
// związane klasą Gps

// UWAGA: Otrzymujecie Państwo implementacje klas typu Haversine niezbędnych do operacji 
// na współrzędnych geograficznych. Proszę przeanalizować i wykorzystać zaimplementowane klasy:
// - PointedDistance
// - Distance
// - Coordinate
//
// ZADANIE: Celem zadania jest:
// - implementacja klasy Compass, przechowującej np. jako std::string info o kierunku świata
// - uzupełnienie klasy Gps o dziedziczenie po klasie Compass
// - implementacja klasy TrackingSystem dziedziczącej po klasie Compass
// - implementacja klasy TrackingUnit dziedziczącej po klasach Gps oraz TrackingSystem

// - uzupełnienie
// UWAGA: Wymagania projektowe:
//		- implementacja kodu jest dowolna - nie powienien być zmodyfikowany jedynie plik Main.cpp;
//      - należy zadbać o zasadność zawieranie/dziedziczenia odpowiednich klas/cech/informacji
//      - założony schemat dziedziczenia stanowi problem "diamentu"

// Ostateczny program powinien byc przyjazny dla programisty (miec czytelny i dobrze napisany kod).

// Makefile (lub CMakeLists.txt) dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie TrackingUnit. Program nalezy kompilowac z flagami -Wall -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow (w tym wlasnych wczesniej
// przygotowanych plikow oprocz makefile)

// Rozwiazanie (archiwum TrackingUnit.tar.gz zawierajace w folderze dodane pliki, makefile i Main.cpp)
// nalezy wgrac do UPEL.

#include "Main.h"

int main(){

	Compass myCompass;
	TrackingSystem myTrackingSystem;
	TrackingUnit myTrackingUnit;
	Gps myGps("Garmin",19.9449799,50.0646501);

	std::cout<<"[INFO]:: **** Inheritance behavior ****" << "\n";

	std::cout<<"[INFO]:: Direction from compass instance:         "
		<< myCompass.CompassDirection()<<"\n";
	
	std::cout<<"[INFO]:: Direction from tracking system instance: "
		<< myTrackingSystem.CompassDirection()<<"\n";
	
	std::cout<<"[INFO]:: Direction from tracking unit instance:   "
		<< myTrackingUnit.CompassDirection()<<"\n";
	
	std::cout<<"[INFO]:: Direction from gps instance:             "
		<< myGps.CompassDirection()<<"\n";

	std::cout<<"[INFO]:: **** Actual lab07 problem ****" << "\n";

	myTrackingUnit.Location(myGps.Location());
	
	myTrackingUnit.Start(); // set current Gps location as a starting point
	
	std::cout<<"[INFO]:: Distance before Go: "
		<< myTrackingUnit.Distance() << " [km]"<< "\n";	

	std::cout<<"[INFO]:: Start position: "
		<< myTrackingUnit.LocationInfo() << "\n";

	myTrackingUnit.Go(2000,Compass::North());
	
	std::cout<<"[INFO]:: End position:   "
		<< myTrackingUnit.LocationInfo() << "\n";

	std::cout<<"[INFO]:: Distance after Go: "
		<< myTrackingUnit.Distance() << " [km]"<< "\n";	
	return 0;
}

/* Wynik dzialania programu:
brachwal@vbox:[build]$ ./Gps 
[INFO]:: **** Inheritance behavior ****
[INFO]:: Direction from compass instance:         C/West
[INFO]:: Direction from tracking system instance: T/North
[INFO]:: Direction from tracking unit instance:   TUnit/South
[INFO]:: Direction from gps instance:             G/East
[INFO]:: **** Actual lab07 problem ****
[INFO]:: Distance before Go: 0 [km]
[INFO]:: Start position: Longitude: 19.944981 Latitude: 50.064651
[INFO]:: End position:   Longitude: 19.944981 Latitude: 50.082649
[INFO]:: Distance after Go: 2.00126 [km]
*/
