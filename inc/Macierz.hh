#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include "Wektor.hh"

#include <iostream>


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Macierz {
    Wektor tab[ROZMIAR];

  public:

    Macierz(); //Jednostkowa
    Macierz(Wektor* tab);
    Macierz(Wektor A, Wektor B, Wektor C);

    Macierz & operator += (const Macierz & M);
    Macierz & operator -= (const Macierz & M);
    Macierz operator+ (const Macierz & M) const;
    Macierz operator- (const Macierz & M) const;
    Macierz operator* (const double l) const;
    Wektor operator* (const Wektor W) const;
    Macierz operator/ (const double l) const;

    const Macierz transponowana() const;
    const double wyznacznik() const; //metoda Gaussa
    const Macierz odwrotna() const;

    const Wektor & operator[] (int index) const; //element - M[wiersz][kolumna]
    Wektor & operator[] (int index);
};



/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
std::istream& operator >> (std::istream &Strm, Macierz &Mac);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
std::ostream& operator << (std::ostream &Strm, const Macierz &Mac);


#endif
