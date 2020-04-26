#include "Wektor.hh"
#include <cmath>
#include <iostream>

/*
template <typename TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR>::Wektor(TYP tablica[])
{
    for(int i = 0; i < ROZMIAR; i++)
    {
        this->tab[i] = tablica[i];
    }
}
*/

template <typename TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> & Wektor<TYP,ROZMIAR>::operator += (const Wektor<TYP,ROZMIAR> & W2)
{
    for(int i = 0; i < ROZMIAR; i++)
    {
        this->tab[i] = this->tab[i] + W2.tab[i];
    }

    return *this;
}

template <typename TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> & Wektor<TYP,ROZMIAR>::operator -= (const Wektor<TYP,ROZMIAR> & W2)
{
    for(int i = 0; i < ROZMIAR; i++)
    {
        this->tab[i] = this->tab[i] - W2.tab[i];
    }

    return *this;
}

template <typename TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> Wektor<TYP,ROZMIAR>::operator + (const Wektor<TYP,ROZMIAR> & W2) const
{
    Wektor<TYP,ROZMIAR> wynik;
    for(int i = 0; i < ROZMIAR; i++)
    {
        wynik.tab[i] = this->tab[i] + W2.tab[i];
    }

    return wynik;
}

template <typename TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> Wektor<TYP,ROZMIAR>::operator - (const Wektor<TYP,ROZMIAR> & W2) const
{
    Wektor<TYP,ROZMIAR> wynik;
    for(int i = 0; i < ROZMIAR; i++)
    {
        wynik.tab[i] = this->tab[i] - W2.tab[i];
    }
    return wynik;
}

template <typename TYP, int ROZMIAR>
TYP Wektor<TYP,ROZMIAR>::operator * (const Wektor<TYP,ROZMIAR> & W2) const
{
    TYP wynik = 0;

    for(int i = 0; i < ROZMIAR; i++)
    {
        wynik += this->tab[i] * W2.tab[i];
    }
    return wynik;
}

template <typename TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> Wektor<TYP,ROZMIAR>::operator * (double l) const
{
    Wektor<TYP,ROZMIAR> wynik;
    for(int i = 0; i < ROZMIAR; i++)
    {
        wynik.tab[i] += this->tab[i] * l;
    }
    return wynik;
}

template <typename TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> Wektor<TYP,ROZMIAR>::operator / (double l) const
{
    Wektor<TYP,ROZMIAR> wynik;
    for(int i = 0; i < ROZMIAR; i++)
    {
        wynik.tab[i] += this->tab[i] / l;
    }
    return wynik;
}

template <typename TYP, int ROZMIAR>
double Wektor<TYP,ROZMIAR>::dlugosc() const
{
    double wynik;
    for(int i = 0; i < ROZMIAR; i++)
    {
        wynik += this->tab[i]*this->tab[i];
    }

    return sqrt(wynik);
}

template <typename TYP, int ROZMIAR>
bool Wektor<TYP,ROZMIAR>::operator == (const Wektor<TYP,ROZMIAR> & W2) const
{
    for(int i = 0; i < ROZMIAR; i++)
    {
        if( fabs(this->tab[i] - W2.tab[i]) > 0.00001 ) return false;
    }
    return true;
}

template <typename TYP, int ROZMIAR>
bool Wektor<TYP,ROZMIAR>::operator != (const Wektor<TYP,ROZMIAR> & W2) const
{
    return !(*this == W2);
}

template <typename TYP, int ROZMIAR>
const TYP & Wektor<TYP,ROZMIAR>::operator[] (int index) const
{
    if (index < 0 || index > ROZMIAR)
    {
        std::cerr << "indeks poza zakresem\n";
        exit(1);
    }

    return this->tab[index];
}

template <typename TYP, int ROZMIAR>
TYP & Wektor<TYP,ROZMIAR>::operator[] (int index)
{
    if (index < 0 || index > ROZMIAR)
    {
        std::cerr << "indeks poza zakresem\n";
        exit(1);
    }

    return (this->tab[index]);
}


template <typename TYP, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, Wektor<TYP,ROZMIAR> &Wek)
{

    for(int i = 0; i < ROZMIAR; i++)
    {
        Strm >> Wek[i];
    }
    return Strm;
}

template <typename TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, const Wektor<TYP,ROZMIAR> &Wek)
{
    Strm << "[" << Wek[0];
    for(int i = 1; i < ROZMIAR; i++)
    {
        Strm << ", " << Wek[i];
    }
    Strm << "]";
    return Strm;
}


