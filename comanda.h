#ifndef COMANDA_H
#define COMANDA_H
#include <iostream>
using namespace std;
class comanda_mancare
{
   public:
       comanda_mancare();
       float pret;
       virtual void Print()=0;
       virtual ~comanda_mancare()=default;
};
class comanda_bauturi
{
public:
    comanda_bauturi()=default;
    float pret;
    virtual void Print()=0;
    virtual ~comanda_bauturi()=default;
};
class ciorba:public comanda_mancare
{
protected:
    enum t
    {
        DE_BURTA,
        DE_LEGUME,
        DE_CIUPERCI
    }tip;
 public:
     ciorba();
     void Print();
     friend ostream &operator<<(ostream&,ciorba);
};
class fel_principal:public comanda_mancare
{
protected:
    enum t
    {
        FRIGARUI,
        TOCANA,
        CHATEAUBRIAND,
        STROGANOFF,
        FILE
    }tip;
public:
    fel_principal():comanda_mancare(){};
};
class fel_principal_de_pui:public fel_principal
{
public:
    fel_principal_de_pui();
    void Print();
    friend ostream &operator<<(ostream &,fel_principal_de_pui);
};
class fel_principal_de_vita:public fel_principal
{
protected:
    int gramaj;
    enum gr
    {
        SANGE,
        MEDIU,
        FACUT
    }grad;
public:
    fel_principal_de_vita();
    void Print();
    friend ostream &operator<<(ostream &,fel_principal_de_vita);
};
class garnitura:public comanda_mancare
{
protected:
     enum t
     {
         Cartofi_prajiti,
         Cartofi_piure,
         Orez_sarbesc
     }tip;
public:
    garnitura();
    void Print();
    friend ostream &operator<<(ostream&,garnitura);
};
class desert:public comanda_mancare
{
protected:
    enum t
    {
        INGHETATA,
        TORT_KRANTZ
    }tip;
    int nr_cupe;
  public:
      desert();
      void Print();
      friend ostream &operator<<(ostream&,desert);
};
class vin:public comanda_bauturi
{
protected:
    enum t
    {
        PAHAR_ALB,
        PAHAR_ROSU,
        BORDEUX_1996,
        CASTEL_BOLOVANU_2004
    }tip;
public:
    vin();
    void Print();
    friend ostream &operator<<(ostream&,vin);
};
class bere:public comanda_bauturi
{
protected:
    enum t
    {
        ALCOOL,
        FARA_ALCOOL
    }tip;
public:
    bere();
    void Print();
    friend ostream &operator<<(ostream &,bere);
};
class apa:public comanda_bauturi
{
public:
    apa();
    void Print();
    friend ostream &operator<<(ostream &,apa);
};
enum tip_mancare
{
    CIORBA,
    FEL_PRINCIPAL_DE_PUI,
    FEL_PRINCIPAL_DE_VITA,
    GARNITURA,
    DESERT
};
class comanda_mancareFactory
{
public:
    static comanda_mancare* GetComanda(tip_mancare a)
    {
        comanda_mancare *b;
    switch(a)
   {
       case CIORBA:
        b=new ciorba;
        break;
       case FEL_PRINCIPAL_DE_PUI:
        b=new fel_principal_de_pui;
        break;
       case FEL_PRINCIPAL_DE_VITA:
        b=new fel_principal_de_vita;
        break;
       case GARNITURA:
        b=new garnitura;
        break;
       case DESERT:
        b=new desert;
   }
        return b;
    }
};
enum tip_bautura
{
    VIN,
    BERE,
    APA
};
class comanda_bauturiFactory
{
public:
    static comanda_bauturi* GetBautura(tip_bautura a)
    {
        comanda_bauturi *b;
        switch(a)
        {
        case VIN:
            b=new vin;
            break;
        case BERE:
            b=new bere;
            break;
        case APA:
            b=new apa;
            break;
        }
        return b;
    }
};
#endif // COMANDA_H
