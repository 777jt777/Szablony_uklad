#ifndef MACIERZ_HH
#define MACIERZ_HH

#include <iostream>
#include "Wektor.hh"


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */



template<class Typ, int SWymiar>
class Macierz
{
Wektor<Typ,SWymiar> tab1[SWymiar];
public:

Macierz();

Wektor<Typ,SWymiar> & operator[](int index);

const Wektor<Typ,SWymiar> & operator[](int index) const;

 Wektor<Typ,SWymiar> operator *(const Wektor<Typ,SWymiar>  & w1) const; //macierz razy wektor

 Macierz<Typ,SWymiar> operator *(Macierz<Typ,SWymiar>  B) const ; //Typ razy macierz

 Macierz<Typ,SWymiar> operator +(Macierz<Typ,SWymiar> B) const;

 Macierz<Typ,SWymiar> operator -(Macierz<Typ,SWymiar>  B) const;

 Macierz<Typ,SWymiar> operator *(Typ B) const; 

 Macierz<Typ,SWymiar> operator /(Typ B) const; 

 Macierz<Typ,SWymiar> transponuj() const;

 Macierz<Typ,SWymiar> zamien_wiersz() const;

 Typ wyznacznik_sarrusa() const;

 Typ wyznacznik_1() const;

 bool operator== (const Macierz<Typ,SWymiar> & W2) const;

 bool operator!= (const Macierz<Typ,SWymiar> & W2) const;

};

template<class Typ, int SWymiar>
std::ostream& operator << (std::ostream &Strm, const  Macierz<Typ,SWymiar> &Mac);

template<class Typ, int SWymiar>
std::istream& operator >> (std::istream &Strm, Macierz<Typ,SWymiar> &Mac);


#endif
