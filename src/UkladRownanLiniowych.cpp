#include "UkladRownanLiniowych.hh"


/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy UkladRownanLiniowych, ktore zawieraja
 *  wiecej kodu niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */
const Macierz & UkladRownanLiniowych::get_A() const
{
    return this->A;
}

const Wektor & UkladRownanLiniowych::get_b() const
{
    return this->b;
}

Macierz & UkladRownanLiniowych::get_A()
{
    return this->A;
}

Wektor & UkladRownanLiniowych::get_b()
{
    return this->b;
}

void UkladRownanLiniowych::set_A(const Macierz & AA)
{
    this->A = AA;
}

void UkladRownanLiniowych::set_b(const Wektor & bb)
{
    this->b = bb;
}

Wektor UkladRownanLiniowych::oblicz() const
{
    return this->A.odwrotna() * this->b;
}

Wektor UkladRownanLiniowych::blad() const
{
    return ( this->A * (this->oblicz()) - this->b );
}

std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown)
{
    Strm >> UklRown.get_A() >> UklRown.get_b();
    return Strm;
}

std::ostream& operator << ( std::ostream &Strm, const UkladRownanLiniowych &UklRown)
{
    for(int i = 0; i < ROZMIAR; i++)
    {
        Strm << "| ";
        for(int j = 0; j < ROZMIAR; j++)
        {
            Strm << UklRown.get_A()[i][j] << " ";
        }
        Strm << "|";

        Strm << "| x_" << i+1 << " |";

        if( i == (int)(ROZMIAR/2) )
        {
            Strm << " = ";
        }
        else
        {
            Strm << "   ";
        }
        Strm << "| " << UklRown.get_b()[i] << " |\n";
    }

    return Strm;
}



