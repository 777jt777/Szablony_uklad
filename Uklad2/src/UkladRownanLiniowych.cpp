#include "UkladRownanLiniowych.hh"
#include <iostream>
using namespace std;

/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy UkladRownanLiniowych, ktore zawieraja 
 *  wiecej kodu niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */






  Macierz & UkladRownanLiniowych::get_A() 
 {
     return A;
 }
 Wektor & UkladRownanLiniowych::get_B() 
 {
     return B;
 }
 void UkladRownanLiniowych::set_A(Macierz & N) const
{
    N=A;
}
 void UkladRownanLiniowych::set_B(Wektor & N) const
{
    N=B;
}



const Macierz UkladRownanLiniowych::zamien(int i, Macierz A, Wektor B) const
{
A=A.transponuj();
A[i]=B;
A=A.transponuj();
return A;
}

const Wektor UkladRownanLiniowych::Cramer(UkladRownanLiniowych Ukl) const
{
Wektor Wynik;
int ilosc_zer=0;
double wyzn;
int i;

wyzn=A.wyznacznik_sarrusa();
for(i=0;i<ROZMIAR;i++)
  {                 
Wynik[i]=zamien(i,A,B).wyznacznik_sarrusa();
if(Wynik[i]==0) 
ilosc_zer++;
  }
if(wyzn==0 && ilosc_zer==ROZMIAR)
{
cout <<"Rownanie ma nieskonczenie wiele rozwiazan"<<endl;   
exit(0);
}
if(wyzn==0 && ilosc_zer!=ROZMIAR)
      {
cout <<"Rownanie nie ma rozwiazan"<<endl; 
exit(0);  
      }
for(i=0;i<ROZMIAR;i++)
Wynik[i]/=wyzn;
return Wynik;  
}


const void UkladRownanLiniowych::blad(UkladRownanLiniowych Ukl, Wektor Wynik) const {
cout <<"Wektor bledu:"<<endl<< (A*Wynik-B)<<endl;
cout <<"Dlugosc wektora bledu:"<<endl<< (A*Wynik-B).dlugosc()<<endl;
}


std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown)
{
Strm>>UklRown.get_A()>>UklRown.get_B();
return Strm;
}
std::ostream& operator << (std::ostream &Strm, const UkladRownanLiniowych &UklRown)
{
Macierz mac;
Wektor wek;     
UklRown.set_A(mac);
UklRown.set_B(wek);
return Strm<<"Macierz"<<endl<<mac<<"Wektor"<<endl<<wek;
}









