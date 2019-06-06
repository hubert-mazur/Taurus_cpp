// Nazwa pliku wykonywalnego: TrackingUnit

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Celem zadania jest rozszerzenie funkcjonalności wcześniej zaimplementowanego projektu 
// (w tym przypadku można wyorzystać kod z Lab07)
// Tym razem rozszerzenie dotyczy funkcji szablonowych, w dość nietypowym zastosowaniu.
// Mianowicie, chcemy aby w jakims wiekszym programie wystepowala klasa Factory, ktora gwarantuje 
// ze mamy mozliwosc wytworzenia identycznych obiektow.
// Prosze zwrocic uwage ze sama klasa Factory nie jest szablonowa a tylko funkcje sa szablonowe.
// W rozwiazaniu nalezy skozystac ze statycznych skladnikow funkcji i tego ze kazda instancjacja 
// szablonu to jest odrebna funkcja.

// Ostateczny program powinien byc przyjazny dla programisty (miec czytelny i dobrze napisany kod).

// Makefile (lub CMakeLists.txt) dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie TrackingUnit. Program nalezy kompilowac z flagami -Wall -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek, ani zadnych innych materialow 
// (w tym wlasnych wczesniej przygotowanych plikow oprocz makefile i własnego kodu z zajęć)

// Rozwiazanie (archiwum TrackingUnit.tar.gz zawierajace w folderze dodane pliki, makefile i Main.cpp)
// nalezy wgrac do UPEL.

#include "Main.h"

int main(){

	Factory fGps1;
	fGps1.prototype<Gps>(Gps("Garmin",19.,21.));

	Gps gps1 = fGps1.produce<Gps>();
	std::cout<<"[INFO]:: GPS1 location: "<< gps1.LocationInfo()<<"\n";

	Factory fTU1;
	fTU1.prototype<TrackingUnit>( TrackingUnit(gps1) );
	

	TrackingUnit trkUnit1 = fTU1.produce<TrackingUnit>();
	std::cout<<"[INFO]::  TU1 location: "<< trkUnit1.LocationInfo()<<"\n";

	fTU1.prototype<Gps>(Gps("Garmin",49.,12.)); // Nieważne dla której fabryki zmieniam prototyp (?)
	Gps gps2 = fGps1.produce<Gps>();
	fTU1.prototype<TrackingUnit>( TrackingUnit(gps2) );

	TrackingUnit trkUnit2 = fTU1.produce<TrackingUnit>();
	std::cout<<"[INFO]::  TU2 location: "<< trkUnit2.LocationInfo()<<"\n";

	return 0;
}

/* Wynik dzialania programu:
brachwal@vbox:[build]$ ./Gps 
[INFO]:: GPS1 location: Longitude: 19.000000 Latitude: 21.000000
[INFO]::  TU1 location: Longitude: 19.000000 Latitude: 21.000000
[INFO]::  TU2 location: Longitude: 49.000000 Latitude: 12.000000
*/
