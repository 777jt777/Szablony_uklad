#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include <iostream>
#include "Wektor.hh"

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Macierz 
{
Wektor tab1[ROZMIAR];
public:

Macierz(Wektor w1,Wektor w2,Wektor w3);

Macierz();

Wektor & operator[](int index);

const Wektor & operator[](int index) const;

const Wektor operator *(const Wektor & w1) const; //macierz razy wektor

const Macierz operator *( Macierz  B) const ; //Macierz razy macierz

const Macierz operator +(Macierz  B) const;

const Macierz operator -(Macierz  B) const;

const Macierz operator *(double B) const; 

const Macierz operator /(double B) const; 

const Macierz transponuj()const;

const double wyznacznik_sarrusa() const;

const bool operator== (const Macierz & W2) const;

};

std::ostream& operator << (std::ostream &Strm, const  Macierz &Mac);

std::istream& operator >> (std::istream &Strm, Macierz &Mac);


#endif
