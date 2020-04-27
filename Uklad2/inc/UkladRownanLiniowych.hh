#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class UkladRownanLiniowych {
Macierz A;
Wektor B;
public:
UkladRownanLiniowych() {};

UkladRownanLiniowych(Macierz _A ,Wektor _B) : A(_A), B(_B) {};

 Macierz & get_A() ;

 Wektor & get_B() ;

void set_A(Macierz & N) const;

void set_B(Wektor & N) const;

const Macierz zamien(int i, Macierz A, Wektor B) const ; //zamiana kolumny wektorow

const Wektor Cramer(UkladRownanLiniowych Ukl) const ; //rozwiazanie ukladu

const void blad(UkladRownanLiniowych Ukl, Wektor Wynik) const; //obliczanie bledu 
};




std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown);


std::ostream& operator << ( std::ostream &Strm,const UkladRownanLiniowych &UklRown);


#endif
