#ifndef MASA_H
#define MASA_H
#include <vector>
#include <iostream>
#include "client.h"
class masa
{
    public:
        masa();
        virtual ~masa();
        void Comanda();
        void NotaClient(int i);
        void ComandaClient(int i);
        masa &operator=(const masa&);
    protected:
        int nr_persoane;
        vector<client*>pers;
        nota_de_plata_colectiva nota_c;
};

#endif // MASA_H
