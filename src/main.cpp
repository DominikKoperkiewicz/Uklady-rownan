#include <iostream>
#include <fstream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"



using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */


int main()
{
  UkladRownanLiniowych   UklRown;

std::fstream plik;
plik.open( "example.txt", std::ios::in );

plik >> UklRown;

  cout << endl << " Start programu " << endl << endl;
  cout << UklRown << "\n\n";
  cout << "          Rozwiazania: " << UklRown.oblicz() << "\n";
  cout << "         Wektor bledu:  Ax - b  = " << UklRown.blad() << "\n";
  cout << "Dlugosc wektora bledu: |Ax - b| = " << UklRown.blad().dlugosc() << "\n";
}
