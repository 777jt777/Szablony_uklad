#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */


template<class Typ, int SWymiar>
class UkladRownanLiniowych {
    
Macierz<Typ,SWymiar> A;
Wektor<Typ,SWymiar> B;
public:

UkladRownanLiniowych() {};

UkladRownanLiniowych(Macierz<Typ,SWymiar> _A ,Wektor<Typ,SWymiar> _B) : A(_A), B(_B) {};

const Macierz<Typ,SWymiar> & get_A() const ;

const Wektor<Typ,SWymiar> & get_B() const ;

void set_A(Macierz<Typ,SWymiar> & N) ;

void set_B(Wektor<Typ,SWymiar> & N) ;

const Macierz<Typ,SWymiar> zamien(int i, Macierz<Typ,SWymiar> A, Wektor<Typ,SWymiar> B) const ; //zamiana kolumny wektorow

const Wektor<Typ,SWymiar> Cramer(UkladRownanLiniowych<Typ,SWymiar> Ukl) const ; //rozwiazanie ukladu


};



template<class Typ, int SWymiar>
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych<Typ,SWymiar> &UklRown);

template<class Typ, int SWymiar>
std::ostream& operator << ( std::ostream &Strm,const UkladRownanLiniowych<Typ,SWymiar> &UklRown);


#endif
