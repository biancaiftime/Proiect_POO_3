#include "client.h"
#include <iostream>
using namespace std;
client::client()
{
    int i;
    for(i=0;i<5;++i)mancare[i]=NULL;
    bautura=NULL;
    nota.Set(0);
    nr_feluri_mancare=0;
}

client::~client()
{
    if(bautura!=NULL)delete bautura;
    int i;
    for(i=0;i<5;++i)
        if(mancare[i]!=NULL)delete mancare[i];
}
void client::Meniu()
{
    cin.get();
    char s[100];
    cout<<"De baut va aduc ceva?\n";
    cin.getline(s,100);
    if(strcmp(s,"Nu")==0) bautura=NULL;
    else
    {
        cout<<"Vin,bere sau apa?\n";
        cin.getline(s,100);
        if(strcmp(s,"Vin")==0)bautura=comanda_bauturiFactory::GetBautura(VIN);
        else if(strcmp(s,"Bere")==0)bautura=comanda_bauturiFactory::GetBautura(BERE);
        else bautura=comanda_bauturiFactory::GetBautura(APA);
        nota.Set(bautura->pret);
    }
    cout<<"Doriti ciorba?\n";
    cin.getline(s,100);
    if(strcmp(s,"Da")==0)
    {
        mancare[nr_feluri_mancare]=comanda_mancareFactory::GetComanda(CIORBA);
        nota.Set(mancare[nr_feluri_mancare]->pret);
        ++nr_feluri_mancare;
    }
    cout<<"Doriti fel principal?\n";
    cin.getline(s,100);
    if(strcmp(s,"Da")==0)
    {
        cout<<"De pui sau de vita?\n";
        cin.getline(s,100);
        if(strcmp(s,"De pui")==0)
            mancare[nr_feluri_mancare]=comanda_mancareFactory::GetComanda(FEL_PRINCIPAL_DE_PUI);
        else mancare[nr_feluri_mancare]=comanda_mancareFactory::GetComanda(FEL_PRINCIPAL_DE_VITA);
        nota.Set(mancare[nr_feluri_mancare]->pret);
        ++nr_feluri_mancare;
    }
    cout<<"Doriti garnitura?\n";
    cin.getline(s,100);
    if(strcmp(s,"Da")==0)
    {
        mancare[nr_feluri_mancare]=comanda_mancareFactory::GetComanda(GARNITURA);
        nota.Set(mancare[nr_feluri_mancare]->pret);
        ++nr_feluri_mancare;
    }
    cout<<"Doriti desert?\n";
    cin.getline(s,100);
    if(strcmp(s,"Da")==0)
    {
        mancare[nr_feluri_mancare]=comanda_mancareFactory::GetComanda(DESERT);
        nota.Set(mancare[nr_feluri_mancare]->pret);
        ++nr_feluri_mancare;
    }

}
void client::GetNota(nota_de_plata_colectiva&x)
{
    x.Scad(nota);
    nota.Print();
}
void client::PrintComanda()
{
    int i;
    for(i=0;i<nr_feluri_mancare;++i)
        mancare[i]->Print();
    if(bautura!=NULL)bautura->Print();
}
client &client::operator=(const client &c)
{
    nr_feluri_mancare=c.nr_feluri_mancare;
    (*bautura)=*(c.bautura);
    nota=c.nota;
    int i;
    for(i=0;i<nr_feluri_mancare;++i)*(mancare[i])=*(c.mancare[i]);
    return *this;
}
