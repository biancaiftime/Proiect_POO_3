#ifndef CLIENT_H
#define CLIENT_H
#include <cstring>
#include "comanda.h"
#include "nota_de_plata.h"
class client
{
    public:
        client();
        ~client();
        void Meniu();
        void GetNota(nota_de_plata_colectiva&x);
        void PrintComanda();
        client &operator=(const client&);
    protected:
        nota_de_plata_individuala nota;
        int nr_feluri_mancare;
        comanda_mancare *mancare[5];
        comanda_bauturi *bautura;
};

#endif // CLIENT_H
