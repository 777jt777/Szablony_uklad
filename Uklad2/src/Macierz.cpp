#include "Macierz.hh"
#include "Wektor.hh"
#include "LZespolona.hh"

using namespace std;
/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Macierz<Typ,SWymiar>, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

template<class Typ, int SWymiar>  
Macierz <Typ,SWymiar>::Macierz() //konstruktor domyslny
{
Wektor<Typ,SWymiar> a;    
tab1[0]=a;
tab1[1]=a;
tab1[2]=a;
}

template<class Typ, int SWymiar>
Wektor<Typ,SWymiar> & Macierz<Typ,SWymiar>::operator[](int index) 
{
 if (index < 0 || index >= SWymiar) 
 {
      cerr << "poza zakresem" << endl;
      exit(1);      
 }
 return tab1[index];
}
template<class Typ, int SWymiar>
const Wektor<Typ,SWymiar> & Macierz <Typ,SWymiar>::operator[](int index) const
{
 if (index < 0 || index >= SWymiar) 
 {
      cerr << "poza zakresem" << endl;
      exit(1);      
 }
 return tab1[index];
}

template<class Typ, int SWymiar>
 Macierz<Typ,SWymiar> Macierz<Typ,SWymiar>::transponuj() const //transpozycja Macierz<Typ,SWymiar>y
{
Macierz<Typ,SWymiar> mac;

int i;
int j;
for(i=0;i<SWymiar;i++)
{
for(j=0;j<SWymiar;j++)
   {
mac[i][j]=tab1[j][i];
    }
}
return mac;
}

template<class Typ, int SWymiar>
Wektor<Typ,SWymiar> Macierz<Typ,SWymiar>::operator*(const Wektor<Typ,SWymiar> & w1) const // operator Macierz<Typ,SWymiar> razy wektor
{
Wektor<Typ,SWymiar> wekt;
int i;
for(i=0;i<=2;i++)
{
wekt[i]=tab1[i]*w1;
}
return wekt;
}

template<class Typ, int SWymiar>
Macierz<Typ,SWymiar> Macierz<Typ,SWymiar>::operator *(Macierz<Typ,SWymiar>  B) const // operator Macierz<Typ,SWymiar> razy Macierz<Typ,SWymiar>
{
Macierz<Typ,SWymiar> mac2;
Macierz<Typ,SWymiar> mac;
int i;
mac2=*this;
mac2=mac2.transponuj();
for(i=0;i<SWymiar;i++)
     {
mac[i]=mac2*B[i];
     }
return mac;              
}

template<class Typ, int SWymiar>
Typ Macierz<Typ,SWymiar>::wyznacznik_sarrusa() const
{
Typ Wynik;
Wynik=tab1[0][0]*tab1[1][1]*tab1[2][2]+tab1[0][1]*tab1[1][2]*tab1[2][0]+tab1[0][2]*tab1[1][0]*tab1[2][1]-tab1[2][0]*tab1[1][1]*tab1[0][2]-tab1[2][1]*tab1[1][2]*tab1[0][0]-tab1[2][2]*tab1[1][0]*tab1[0][1];
return Wynik;
}

template<class Typ, int SWymiar>
Typ Macierz<Typ,SWymiar>::wyznacznik_1() const
{
    Typ a;
    Typ Wynik;
    a=0;
    Wynik=1;
    Macierz <Typ,SWymiar> mac = (*this);
    for ( int i = 0; i < SWymiar; ++i){
        for ( int j = i+1; j < SWymiar; ++j){
            a = mac[j][i]/mac[i][i];
            for ( int k = i; k < SWymiar; ++k){
                mac[j][k]=mac[j][k] - a*mac[i][k];
            }
        }
    }
    for ( int g = 0; g < SWymiar; ++g){
        Wynik = mac[g][g]*Wynik;
    }
    return Wynik;   
}

template<class Typ, int SWymiar>
 Macierz<Typ,SWymiar> Macierz<Typ,SWymiar>::operator +(Macierz<Typ,SWymiar> B) const // operator dodawania Macierz<Typ,SWymiar>y

{
Macierz<Typ,SWymiar> mac;
int i;
for(i=0;i<SWymiar;i++)
{
mac[i]=tab1[i]+B[i];
}
return mac;
}
template<class Typ, int SWymiar>
 Macierz<Typ,SWymiar> Macierz<Typ,SWymiar>::operator -(Macierz<Typ,SWymiar>  B) const // operator odejmowania Macierz<Typ,SWymiar>y

{
Macierz<Typ,SWymiar> mac;
int i;
for(i=0;i<SWymiar;i++)
{
mac[i]=tab1[i]-B[i];
}
return mac;
}

template<class Typ, int SWymiar>
Macierz<Typ,SWymiar> Macierz<Typ,SWymiar>::operator *(Typ B) const // operator mnozenia Macierz<Typ,SWymiar>y przez liczbe

{
Macierz<Typ,SWymiar> mac;
int i;
for(i=0;i<SWymiar;i++)
{
mac[i]=tab1[i]*B;
}
return mac;
}

/*
template<class Typ, int SWymiar>
const Macierz<Typ,SWymiar> Macierz<Typ,SWymiar>::operator /(Typ B) const // operator dzielenia Macierz<Typ,SWymiar>y przez liczbe
{
Macierz<Typ,SWymiar> mac;
int i;
if(B!=0)
   {
for(i=0;i<SWymiar;i++)
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
*/

template<class Typ, int SWymiar>
 bool Macierz<Typ,SWymiar>::operator== (const Macierz<Typ,SWymiar> & W2) const //porownanie Macierz<Typ,SWymiar>y
{
int i;
for(i=0;i<SWymiar;i++){
W2[i]==tab1[i];
return true;
}
return false;
}


template<class Typ, int SWymiar>
bool Macierz<Typ,SWymiar>::operator!= (const Macierz<Typ,SWymiar> & W2) const // Operator sprawdzenia nierownosci
{
return !(*this==W2);
}

template<class Typ, int SWymiar>
std::istream& operator >> (std::istream &Strm, Macierz<Typ,SWymiar> &Mac) // przeciazenie wejscia Macierz<Typ,SWymiar>y
{
int i;
for(i=0;i<SWymiar;i++)
{
Strm>>Mac[i];
}

return Strm;
}     
template<class Typ, int SWymiar>
std::ostream& operator << (std::ostream &Strm, const Macierz<Typ,SWymiar> &Mac) // przeciazenie wyjscia Macierz<Typ,SWymiar>y
{
int i;
cout <<" ";
Strm << "[";
for(i=0;i<SWymiar;i++)
{
Strm<<Mac[i];
cout <<" ";
}
Strm << "]";
return Strm;
}