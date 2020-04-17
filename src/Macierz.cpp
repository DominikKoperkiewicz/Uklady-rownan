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
        this->tab[i][i] = 1;
    }
}

Macierz::Macierz(Wektor* tab)
{
    for(int i = 0; i < ROZMIAR; i++)
    {
        this->tab[i] = tab[i];
    }
}

Macierz::Macierz(Wektor A, Wektor B, Wektor C)
{
    this->tab[0] = A;
    this->tab[1] = B;
    this->tab[2] = C;
}

Macierz & Macierz::operator += (const Macierz & M)
{
    *this = *this + M;
    return *this;
}

Macierz & Macierz::operator -= (const Macierz & M)
{
    *this = *this - M;
    return *this;
}

Macierz Macierz::operator+ (const Macierz & M) const
{
    Macierz Wynik;
    for(int i = 0; i < ROZMIAR; i++)
    {
        Wynik[i] = this->tab[i] + M[i];
    }
    return Wynik;
}

Macierz Macierz::operator- (const Macierz & M) const
{
    Macierz Wynik;
    for(int i = 0; i < ROZMIAR; i++)
    {
        Wynik[i] = this->tab[i] - M[i];
    }
    return Wynik;
}

Macierz Macierz::operator* (const double l) const
{
    Macierz Wynik;
    for(int i = 0; i < ROZMIAR; i++)
    {
        Wynik[i] = this->tab[i] * l;
    }
    return Wynik;
}

Wektor Macierz::operator* (const Wektor W) const
{
    Wektor Wynik;
    double tmp = 0;

    for(int i = 0; i < ROZMIAR; i++)
    {
        tmp += this->tab[i] * W;
        Wynik[i] = tmp;
        tmp = 0;
    }

    return Wynik;
}

Macierz Macierz::operator/ (const double l) const
{
    Macierz Wynik;
    for(int i = 0; i < ROZMIAR; i++)
    {
        Wynik[i] = this->tab[i] / l;
    }
    return Wynik;
}

const Macierz Macierz::transponowana() const
{
    Wektor W;
    Macierz Wynik;
    for(int i = 0; i < ROZMIAR; i++)
    {
        for(int j = 0; j < ROZMIAR; j++)
        {
            W[j] = this->tab[j][i];
        }
        Wynik.tab[i] = W;
    }
    return Wynik;
}

const double Macierz::wyznacznik() const
{
    Macierz M = *this;
    double Wynik = M[0][0];

    for(int i = 0; i < ROZMIAR - 1; i++)
    {
        for(int j = 0; j < ROZMIAR - (i+1); j++)
        {
            M[i+j+1] -= M[i] * ( M[i+j+1][i] / M[i][i] );
        }
    }

    for(int i = 1; i < ROZMIAR; i++) { Wynik *= M[i][i]; }

    return Wynik;
}

const Macierz Macierz::odwrotna() const
{
    Macierz M = *this;
    Macierz Wynik; //Macierz jednostkowa
    double tmp;
    for(int i = 0; i < ROZMIAR-1; i++)
    {
        for(int j = 0; j < ROZMIAR - (i+1); j++)
        {
            tmp = ( M[i+j+1][i] / M[i][i] );
            M[i+j+1] -= M[i] * tmp;
            Wynik[i+j+1] -= Wynik[i] * tmp;
        }
    }

    for(int i = 0; i < ROZMIAR-1; i++)
    {
        for(int j = 0; j < ROZMIAR - (i+1); j++)
        {
            tmp = ( M[(ROZMIAR-1)-(i+j+1)][(ROZMIAR-1)-i] / M[(ROZMIAR-1)-i][(ROZMIAR-1)-i] );

            M[ROZMIAR-i-j-2] -= M[ROZMIAR-i-1] * tmp;
            Wynik[ROZMIAR-i-j-2] -= Wynik[ROZMIAR-i-1] * tmp;
        }
    }

    for(int i = 0; i < ROZMIAR; i++)
    {
        Wynik[i] = Wynik[i]/M[i][i];
    }

    return Wynik;
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
