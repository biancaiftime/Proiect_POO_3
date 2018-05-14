#ifndef NOTA_DE_PLATA_H
#define NOTA_DE_PLATA_H
using namespace std;
class nota_de_plata
{
protected:
    float info;
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
