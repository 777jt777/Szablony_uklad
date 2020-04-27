#include "Macierz.hh"
#include "Wektor.hh"

using namespace std;
/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Macierz, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */
Macierz::Macierz(Wektor x,Wektor y,Wektor z) //konstruktor macierzy
{

tab1[0]=x;
tab1[1]=y;
tab1[2]=z;

}    
Macierz::Macierz() //konstruktor domyslny
{
Wektor a;    
tab1[0]=a;
tab1[1]=a;
tab1[2]=a;
}


Wektor & Macierz::operator[](int index) 
{
 if (index < 0 || index >= ROZMIAR) 
 {
      cerr << "poza zakresem" << endl;
      exit(1);      
 }
 return tab1[index];
}

const Wektor & Macierz::operator[](int index) const
{
 if (index < 0 || index >= ROZMIAR) 
 {
      cerr << "poza zakresem" << endl;
      exit(1);      
 }
 return tab1[index];
}


const Macierz Macierz::transponuj() const //transpozycja macierzy
{
Macierz mac;

int i;
int j;
for(i=0;i<ROZMIAR;i++)
{
for(j=0;j<ROZMIAR;j++)
   {
mac[i][j]=tab1[j][i];
    }
}
return mac;
}

const Wektor Macierz::operator*(const Wektor & w1) const // operator macierz razy wektor
{
Wektor wekt;
int i;
for(i=0;i<=2;i++)
{
wekt[i]=tab1[i]*w1;
}
return wekt;
}

const Macierz Macierz::operator *(Macierz  B) const // operator macierz razy macierz
{
Macierz mac2;
Macierz mac;
int i;
mac2=*this;
mac2=mac2.transponuj();
for(i=0;i<ROZMIAR;i++)
     {
mac[i]=mac2*B[i];
     }
return mac;              
}


 const double Macierz::wyznacznik_sarrusa() const
{
double Wynik;
Wynik=tab1[0][0]*tab1[1][1]*tab1[2][2]+tab1[0][1]*tab1[1][2]*tab1[2][0]+tab1[0][2]*tab1[1][0]*tab1[2][1]-tab1[2][0]*tab1[1][1]*tab1[0][2]-tab1[2][1]*tab1[1][2]*tab1[0][0]-tab1[2][2]*tab1[1][0]*tab1[0][1];
return Wynik;
}

/*  PROBA ZAIMPLEMENTOWANIA DLA N WYMIAROWEJ MACIERZY(nie dziala gdy na przekatnej jest 0)
double Macierz::wyznacznik_1 ()                       (tylko wersja robocza)
{
double Wynik;
int j;
double b=1;
for(j=0;j<ROZMIAR-1;j++)   
     {
b*=tab1[j][j];
tab1[j]=tab1[j]/tab1[j][j];
tab1[j+1]=tab1[j+1]-tab1[j]*tab1[j+1][j];
if(j==0)
{
tab1[j+2]=tab1[j+2]-tab1[j]*tab1[j+2][j];
}
     }           
Wynik=tab1[0][0]*tab1[1][1]*tab1[2][2]*b;
return Wynik;
}

Macierz Macierz::zamien() Funkcja zamieniania wierszy miejscami,potrzebna dla algorytmu dla n macierzy
{                               (tylko wersja robocza)
Macierz mac=*this;
int i;
for(i=1;i<=2;i++)
{
if(mac[0][0] || mac[1][1] || mac[2][2])
{
mac[0]=mac[i];
}
else
exit(1);
}
return mac;
}
*/


const Macierz Macierz::operator +(Macierz B) const // operator dodawania macierzy

{
Macierz mac;
int i;
for(i=0;i<ROZMIAR;i++)
{
mac[i]=tab1[i]+B[i];
}
return mac;
}

const Macierz Macierz::operator -(Macierz  B) const // operator odejmowania macierzy

{
Macierz mac;
int i;
for(i=0;i<ROZMIAR;i++)
{
mac[i]=tab1[i]-B[i];
}
return mac;
}

const Macierz Macierz::operator *(double B) const // operator mnozenia macierzy przez liczbe

{
Macierz mac;
int i;
for(i=0;i<ROZMIAR;i++)
{
mac[i]=tab1[i]*B;
}
return mac;
}

const Macierz Macierz::operator /(double B) const // operator dzielenia macierzy przez liczbe
{
Macierz mac;
int i;
if(B!=0)
   {
for(i=0;i<ROZMIAR;i++)
{
mac[i]=tab1[i]/B;
}
   }
else
{
     cerr<< "Dzielenie przez 0!";
     exit(1);
}
return mac;
}


const bool Macierz::operator== (const Macierz & W2) const //porownanie macierzy
{
int i;
for(i=0;i<ROZMIAR;i++){
W2[i]==tab1[i];
return true;
}
return false;
}



std::istream& operator >> (std::istream &Strm,  Macierz &Mac) // przeciazenie wejscia macierzy
{
Strm>>Mac[0]>>Mac[1]>>Mac[2];
return Strm;
}     
std::ostream& operator << (std::ostream &Strm, const Macierz &Mac) // przeciazenie wyjscia macierzy
{
return Strm<<Mac[0]<<endl<<Mac[1]<<endl<<Mac[2]<<endl; 
}