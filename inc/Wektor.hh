#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Wektor {
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
    double tab[ROZMIAR];

  public:
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */
      Wektor();
      Wektor(double x, double y, double z);
      Wektor(double tablica[]);

      Wektor & operator += (const Wektor & W2); //W1 += W2  , W1 += W3 += W4
      Wektor & operator -= (const Wektor & W2);
      Wektor operator + (const Wektor & W2) const; //W1 + W2
      Wektor operator - (const Wektor & W2) const;
      double operator * (const Wektor & W2) const; //skalarnie
      Wektor operator * (double l) const; // W1 * 2
      Wektor operator / (double l) const; // W1 / 2

      double dlugosc() const; //modul

      bool operator == (const Wektor & W2) const;
      bool operator != (const Wektor & W2) const;

      const double & operator[] (int index) const;
      double & operator[] (int index);
};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
std::istream& operator >> (std::istream &Strm, Wektor &Wek);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
std::ostream& operator << (std::ostream &Strm, const Wektor &Wek);

#endif
