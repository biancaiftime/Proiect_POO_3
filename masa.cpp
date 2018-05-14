#include "masa.h"

masa::masa()
{
    nr_persoane=0;
    nota_c.Set(0);
    cout<<"Dati numarul de persoane:\n";
    cin>>nr_persoane;
    client *c;
    int i;
    for(i=0;i<nr_persoane;++i)
    {
        c=new client;
        pers.push_back(c);
    }
}

masa::~masa()
{
    if(nr_persoane!=0)pers.clear();
}
void masa::Comanda()
{
    int i;
    for(i=0;i<nr_persoane;++i)
        pers[i]->Meniu();
}
void masa::NotaClient(int i)
{
    pers[i]->GetNota(nota_c);
}
void masa::ComandaClient(int i)
{
    pers[i]->PrintComanda();
}
masa &masa::operator =(const masa &m)
{
    pers.clear();
    pers=m.pers;
    nr_persoane=m.nr_persoane;
    nota_c=m.nota_c;
    return *this;
}
