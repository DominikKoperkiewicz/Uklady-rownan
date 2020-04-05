#include "Macierz.hh"


/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Macierz, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

Macierz::Macierz()
{
    Wektor W;
    for(int i = 0; i < ROZMIAR; i++)
    {
        this->tab[i] = W;
    }
}

const Wektor & Macierz::operator[] (int index) const
{
    if (index < 0 || index > ROZMIAR)
    {
        std::cerr << "indeks poza zakresem\n";
        exit(1);
    }
    return (this->tab[index]);
}

Wektor & Macierz::operator[] (int index)
{
    if (index < 0 || index > ROZMIAR)
    {
        std::cerr << "indeks poza zakresem\n";
        exit(1);
    }
    return (this->tab[index]);
}

std::istream& operator >> (std::istream &Strm, Macierz &Mac)
{
    for(int i = 0; i < ROZMIAR; i++)
    {
        Strm >> Mac[i];
    }
    return Strm;
}

std::ostream& operator << (std::ostream &Strm, const Macierz &Mac)
{
    for(int i = 0; i < ROZMIAR; i++)
    {
        Strm << Mac[i] << "\n";
    }
    return Strm;
}
