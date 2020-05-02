#include "UkladRownanLiniowych.hh"
#include "LZespolona.hh"
#include <iostream>
#include <cmath>
using namespace std;

/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy UkladRownanLiniowych<Typ,SWymiar>, ktore zawieraja 
 *  wiecej kodu niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */





template<class Typ, int SWymiar>
const Macierz<Typ,SWymiar> & UkladRownanLiniowych<Typ,SWymiar>::get_A() const 
 {
     return A;
 }

template<class Typ, int SWymiar>
const Wektor<Typ,SWymiar> & UkladRownanLiniowych<Typ,SWymiar>::get_B() const
 {
     return B;
 }

template<class Typ, int SWymiar>
void UkladRownanLiniowych<Typ,SWymiar>::set_A(Macierz<Typ,SWymiar> & N) 
{
    A=N;
}

template<class Typ, int SWymiar>
void UkladRownanLiniowych<Typ,SWymiar>::set_B(Wektor<Typ,SWymiar> & N) 
{
    B=N;
}



template<class Typ, int SWymiar>
const Macierz<Typ,SWymiar> UkladRownanLiniowych<Typ,SWymiar>::zamien(int i, Macierz<Typ,SWymiar> A, Wektor<Typ,SWymiar> B) const
{
A=A.transponuj();
A[i]=B;
A=A.transponuj();
return A;
}

template<class Typ, int SWymiar>
const Wektor<Typ,SWymiar> UkladRownanLiniowych<Typ,SWymiar>::Cramer(UkladRownanLiniowych<Typ,SWymiar> Ukl) const
{
Wektor<Typ,SWymiar> Wynik;
int ilosc_zer=0;
Typ wyzn;
int i;
wyzn=A.wyznacznik_1();
for(i=0;i<SWymiar;i++)
  {                 
Wynik[i]=zamien(i,A,B).wyznacznik_1();
if(Wynik[i]==0.0) 
ilosc_zer++;
  }
if(wyzn==0 && ilosc_zer==SWymiar)
{
cout <<"Rownanie ma nieskonczenie wiele rozwiazan"<<endl;   
exit(0);
}
if(wyzn==0 && ilosc_zer!=SWymiar)
      {
cout <<"Rownanie nie ma rozwiazan"<<endl; 
exit(0);  
      }
for(i=0;i<SWymiar;i++)
Wynik[i]=Wynik[i]/wyzn;
return Wynik;  
}


template<class Typ, int SWymiar>
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych<Typ,SWymiar> &UklRown)
{
Macierz<Typ,SWymiar> C;
Wektor<Typ,SWymiar> D;
Strm >> C >> D;
UklRown.set_A(C);
UklRown.set_B(D);
return Strm;
}


template<class Typ, int SWymiar>
std::ostream& operator << (std::ostream &Strm, const UkladRownanLiniowych<Typ,SWymiar> &UklRown)
{
Macierz<Typ,SWymiar> C = UklRown.get_A();
Wektor<Typ,SWymiar> D = UklRown.get_B();
for(int i =0 ; i<SWymiar; i++)
{
Strm<<C[i]<<"["<<D[i]<<"]"<<endl;
}
return Strm;
}









