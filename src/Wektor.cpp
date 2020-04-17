#include "Wektor.hh"
#include <cmath>
#include <iostream>

/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Wektor, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */
      Wektor::Wektor()
      {
          //for(double x : this->tab) x = 0;
          for(int i = 0; i < ROZMIAR; i++)
          {
              this->tab[i] = 0;
          }
      }

      Wektor::Wektor(double x, double y, double z)
      {
          this->tab[0] = x;
          this->tab[1] = y;
          this->tab[2] = z;
      }

      Wektor::Wektor(double tablica[])
      {
          for(int i = 0; i < ROZMIAR; i++)
          {
              this->tab[i] = tablica[i];
          }
      }

      Wektor & Wektor::operator += (const Wektor & W2)
      {
          for(int i = 0; i < ROZMIAR; i++)
          {
              this->tab[i] = this->tab[i] + W2.tab[i];
          }
          return *this;
      }

      Wektor & Wektor::operator -= (const Wektor & W2)
      {
          for(int i = 0; i < ROZMIAR; i++)
          {
              this->tab[i] = this->tab[i] - W2.tab[i];
          }
          return *this;
      }

      Wektor Wektor::operator + (const Wektor & W2) const
      {
          Wektor wynik;
          for(int i = 0; i < ROZMIAR; i++)
          {
              wynik.tab[i] = this->tab[i] + W2.tab[i];
          }

          return wynik;
      }

      Wektor Wektor::operator - (const Wektor & W2) const
      {
          Wektor wynik;
          for(int i = 0; i < ROZMIAR; i++)
          {
              wynik.tab[i] = this->tab[i] - W2.tab[i];
          }
          return wynik;
      }

      double Wektor::operator * (const Wektor & W2) const
      {
          double wynik = 0;

          for(int i = 0; i < ROZMIAR; i++)
          {
              wynik += this->tab[i] * W2.tab[i];
          }
          return wynik;
      }

      Wektor Wektor::operator * (double l) const
      {
          Wektor wynik;
          for(int i = 0; i < ROZMIAR; i++)
          {
              wynik.tab[i] += this->tab[i] * l;
          }
          return wynik;
      }

      Wektor Wektor::operator / (double l) const
      {
          Wektor wynik;
          for(int i = 0; i < ROZMIAR; i++)
          {
              wynik.tab[i] += this->tab[i] / l;
          }
          return wynik;
      }

      double Wektor::dlugosc() const
      {
          double wynik;
          for(int i = 0; i < ROZMIAR; i++)
          {
              wynik += this->tab[i]*this->tab[i];
          }
          return sqrt(wynik);
      }

      bool Wektor::operator == (const Wektor & W2) const
      {
          for(int i = 0; i < ROZMIAR; i++)
          {
              if( fabs(this->tab[i] - W2.tab[i]) > 0.00001 ) return false;
          }
          return true;
      }

      bool Wektor::operator != (const Wektor & W2) const
      {
          return !(*this == W2);
      }

        const double & Wektor::operator[] (int index) const
        {
            if (index < 0 || index > ROZMIAR)
            {
                std::cerr << "indeks poza zakresem\n";
                exit(1);
            }
            return this->tab[index];
        }

        double & Wektor::operator[] (int index)
        {
            if (index < 0 || index > ROZMIAR)
            {
                std::cerr << "indeks poza zakresem\n";
                exit(1);
            }
            return (this->tab[index]);
        }


std::istream& operator >> (std::istream &Strm, Wektor &Wek)
{

    for(int i = 0; i < ROZMIAR; i++)
    {
        Strm >> Wek[i];
    }
    return Strm;
}

std::ostream& operator << (std::ostream &Strm, const Wektor &Wek)
{
    Strm << "[" << Wek[0];
    for(int i = 1; i < ROZMIAR; i++)
    {
        Strm << ", " << Wek[i];
    }
    Strm << "]";
    return Strm;
}
