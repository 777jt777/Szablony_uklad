#include "Wektor.hh"
#include <iostream>
#include <cmath>
#include "LZespolona.hh"
using namespace std;
/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Wektor, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */


template<class Typ, int SWymiar>
Wektor<Typ,SWymiar>::Wektor(Typ  xx,Typ  yy,Typ  zz)
{
tab[0]=xx;
tab[1]=yy;
tab[2]=zz;
}


template<class Typ, int SWymiar>
Wektor<Typ,SWymiar>::Wektor()
{
tab[0]=0;
tab[1]=0;
tab[2]=0;  
}



template<class Typ, int SWymiar>
Typ & Wektor<Typ,SWymiar>::operator[](int index) 
{
 if (index < 0 || index >= SWymiar) 
 {
      cerr << "poza zakresem" << endl;
      exit(1);      
 }
 return tab[index];
}


template<class Typ, int SWymiar>
const Typ & Wektor<Typ,SWymiar>::operator[](int index) const
{
 if (index < 0 || index >= SWymiar) 
 {
      cerr << "poza zakresem" << endl;
      exit(1);      
 }
 return tab[index];
}


template<class Typ, int SWymiar>
Wektor<Typ,SWymiar> Wektor<Typ,SWymiar>::operator+ (const Wektor<Typ,SWymiar> & W2) const // Operacja dodawania wektorow
{
Wektor Wynik;
int i;
for(i=0;i<SWymiar;i++)
{
Wynik[i]=W2[i]+tab[i];
}
return Wynik;
}

template<class Typ, int SWymiar>
Wektor<Typ,SWymiar> Wektor<Typ,SWymiar>::operator- (const Wektor<Typ,SWymiar> & W2) const // Operacja odejmowania wektorow
{
Wektor Wynik;
int i;
for(i=0;i<SWymiar;i++)
{
Wynik[i]=tab[i]-W2[i];
}
return Wynik;
}

template<class Typ, int SWymiar>
Typ Wektor<Typ,SWymiar>::operator* (const Wektor<Typ,SWymiar> & W2) const // Operacja mnozenia wektorow
{
Typ Wynik;
Wynik=0;
int i;
for(i=0;i<SWymiar;i++)
{
Wynik=Wynik+tab[i]*W2[i];
} 
return Wynik;
}

template<class Typ, int SWymiar>
Wektor<Typ,SWymiar> Wektor<Typ,SWymiar>::operator* (Typ l2) const // Operacja mnozenia wektora przez liczbe
{
Wektor <Typ,SWymiar> Wynik;
int i;
for(i=0;i<SWymiar;i++)
Wynik[i]=tab[i]*l2;
return Wynik;
}

template<class Typ, int SWymiar>
bool Wektor<Typ,SWymiar>::operator==(const Wektor<Typ,SWymiar> & W2) const  // Operator sprawdzenia rownosci
{
double epsilon=0.000000001;
int i;
for(i=0;i<SWymiar;i++)
{
if(abs(tab[i]-W2[i])>epsilon)
return false;
}
return true;
}   

template<> bool Wektor<LZespolona,5>::operator==(const Wektor<LZespolona,5> & W2) const
{
Wektor<LZespolona,5> Wynik;
double epsilon=0.00000001;
int i;
for(i=0;i<5;i++)
if(abs(tab[i].modul2()-W2[i].modul2())>epsilon)
return false;
return true;
}


template<class Typ, int SWymiar>
Wektor<Typ,SWymiar> Wektor<Typ,SWymiar>::operator/ (Typ l2) const  // Operacja dzielenia wektora przez liczbe
{
Wektor<Typ,SWymiar> Wynik;
int i;
if(l2==0)
{
cerr<< "Dzielenie przez 0!";
exit(1);
}
else
{
for(i=0;i<ROZMIAR;i++)
{
    {   
Wynik[i]=tab[i]/l2;
    }
}
 }
return Wynik;
}


template<> Wektor<LZespolona,5> Wektor<LZespolona,5>::operator/(LZespolona l2) const
{
Wektor<LZespolona,5> Wynik;
LZespolona LZ;
LZ.re=0.0;
LZ.im=0.0;
int i;
if(l2==LZ)
{
cerr<< "Dzielenie przez 0!";
exit(1);
}
else
{
for(i=0;i<ROZMIAR;i++)
{
    {   
Wynik[i]=tab[i]/l2;
    }
}
 }
return Wynik;
}

template<class Typ, int SWymiar>
bool Wektor<Typ,SWymiar>::operator!= (const Wektor<Typ,SWymiar> & W2) const // Operator sprawdzenia nierownosci
{
return !(*this==W2);
}

template<class Typ, int SWymiar>
std::istream& operator >> (std::istream &Strm, Wektor<Typ,SWymiar> &Wek) //przeciazenie operatora wejscia wektora
{
int i;
for(i=0;i<SWymiar;i++)
{
Strm>>Wek[i];
}

return Strm;
}    
template<class Typ, int SWymiar>
std::ostream& operator << (std::ostream &Strm, const Wektor<Typ,SWymiar> &Wek) //przeciazenie operatora wyjscia wektora
{
int i;
cout <<" ";
Strm << "[";
for(i=0;i<SWymiar;i++)
{
Strm<<Wek[i];
cout <<" ";
}
Strm << "]";
return Strm;
}    






