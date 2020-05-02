#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
using namespace std;
#include <iostream>
/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
  

  LZespolona();
  LZespolona(double real, double imag);
  LZespolona &operator=(double i) ;
  LZespolona &operator=(int i) ;
  double modul2() const;
};


/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */

LZespolona dzielenie(LZespolona Skl1, double x);

LZespolona sprzezenie(LZespolona LZ);

double modul(LZespolona LZ);

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona  operator * (LZespolona  Skl1,double  l);

LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona  operator / (LZespolona  Skl1,double l);

LZespolona  operator += (LZespolona  Skl1,  LZespolona  Skl2);

bool operator == (LZespolona  Skl1,  LZespolona  Skl2);

bool operator == (LZespolona  Skl1, double l);

bool operator != (LZespolona  Skl1,  LZespolona  Skl2);

double  abs(LZespolona Skl1);

std::istream & operator >>(std::istream & strm, LZespolona & Skl);

std::ostream & operator << (std::ostream & strm, const LZespolona & Skl);

#endif
