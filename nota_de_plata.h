#ifndef NOTA_DE_PLATA_H
#define NOTA_DE_PLATA_H
#include <iostream>
using namespace std;
template <class Zi, class Luna, class An >
class date
{ Zi a;
  Luna b;
  An c;
   public:
   date() {a=0;b=0;c=0;}
   date( Zi aa,Luna bb, An cc) {a=aa;b=bb;c=cc;}
   date (const date&aa) {a=aa.a;b=aa.b;c=aa.c;}
   date<Zi,Luna,An>& operator=(const date<Zi,Luna,An> &aa) {a=aa.a;b=aa.b;c=aa.c;return *this;}
   friend istream& operator>>(istream &in,date<Zi,Luna,An> &aa)
      { in>>aa.a;
        in>>aa.b;
        in>>aa.c;
        return in;
      }

    friend ostream& operator<<(ostream &out,const date <Zi,Luna,An> &aa)
     { out<<aa.a<<"/"<<aa.b<<"/"<<aa.c<<"\n"; return out;}
  Zi Getzi() {return a;}
  Luna Getluna() {return b;}
  An Getan() {return c;}
  void Set(Zi ziulica,Luna lun,An ann) {a=ziulica;b=lun;c=ann;}
};
class nota_de_plata
{
protected:
    float info;
    date<int,int,int> Data;
public:
    nota_de_plata();
    virtual void Set(float pret)=0;
    virtual void Print()=0;
};
class nota_de_plata_individuala:public nota_de_plata
{
public:
    void Set(float pret);
    void Print();
    float Get();
    void Scad(nota_de_plata_individuala);
};
class nota_de_plata_colectiva:public nota_de_plata
{
    public:
    void Set(float pret);
    void Print();
    void Scad(nota_de_plata_individuala x);
};

#endif // NOTA_DE_PLATA_H
