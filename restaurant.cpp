#include "restaurant.h"

restaurant::restaurant()
{
    nr_mese_libere=nr_mese_total=0;
    cout<<"Dati numarul de mese al restaurantului\n";
    cin>>nr_mese_total;
    nr_mese_libere=nr_mese_total;
}

restaurant::~restaurant()
{
    if(nr_mese_total!=0)m.clear();
}
void restaurant::AdaugaMasa()
{
    masa a;
    m.push_back(a);
    a.Comanda();
    --nr_mese_libere;
}
void restaurant::AfisareComandaClient(int i,int j)
{
    m[i].ComandaClient(j);
}
void restaurant::AfisareNotaClient(int nr_masa,int nr_client)
{
    m[nr_masa].NotaClient(nr_client);
}
