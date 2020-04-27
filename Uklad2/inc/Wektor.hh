#ifndef WEKTOR_HH
#define WEKTOR_HH
#include "rozmiar.h"
#include <iostream>
#include "LZespolona.hh"

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */

template<class Typ, int SWymiar>
class Wektor
{
Typ tab[SWymiar];
public:

Wektor();

Wektor(Typ  x,Typ  y,Typ  z);

Typ & operator[] (int index) ;

const Typ & operator[](int index) const ; 

Wektor<Typ,SWymiar> operator+ (const Wektor<Typ,SWymiar> &  W2) const ;

Wektor<Typ,SWymiar> operator- (const  Wektor<Typ,SWymiar> & W2) const ;

Typ operator* (const Wektor<Typ,SWymiar> & W2) const ;

Wektor<Typ,SWymiar> operator* (Typ l2) const ; 

Wektor<Typ,SWymiar> operator/ (Typ l2) const ; 

bool operator== (const Wektor<Typ,SWymiar> & W2) const;

bool operator!= (const Wektor<Typ,SWymiar> & W2) const;

};

template<typename Typ, int SWymiar>
std::istream& operator >> (std::istream &Strm, Wektor<Typ,SWymiar> &Wek);

template<typename Typ, int SWymiar>
std::ostream& operator << (std::ostream &Strm, const Wektor<Typ,SWymiar> &Wek);


#endif
