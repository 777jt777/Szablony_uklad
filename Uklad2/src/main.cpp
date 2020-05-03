#include <iostream>
#include "Wektor.hh"
#include "LZespolona.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"
using namespace std;





int main()
{  


UkladRownanLiniowych<LZespolona,5> Ukl;
Macierz<LZespolona,5> mac;


cout << "Wpisz ukald rownan: "<<endl;
cin >> Ukl;
cout << Ukl;
Wektor<LZespolona,5> wynik= Ukl.Cramer(Ukl);
cout <<"Wynik: "<< endl << wynik;

}


