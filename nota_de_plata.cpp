#include "nota_de_plata.h"
#include <iostream>
using namespace std;
nota_de_plata::nota_de_plata()
{
    info=0;
}
void nota_de_plata_colectiva::Set(float pret)
{
    info+=pret;
}
void nota_de_plata_colectiva::Print()
{
    cout<<"Aveti de platit: "<<info<<"\n";
    info=0;
}
void nota_de_plata_individuala::Set(float pret)
{
    info+=pret;
}
void nota_de_plata_individuala::Print()
{
    cout<<"Nota dumneavoastra de plata este: "<<info<<"\n";
}
float nota_de_plata_individuala::Get()
{
    return info;
}
void nota_de_plata_colectiva::Scad(nota_de_plata_individuala x)
{
    info-=x.Get();
}
void nota_de_plata_individuala::Scad(nota_de_plata_individuala x)
{
    info-=x.Get();
}
