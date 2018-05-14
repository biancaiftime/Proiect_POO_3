#ifndef RESTAURANT_H
#define RESTAURANT_H
#include "masa.h"

class restaurant
{
    public:
        restaurant();
        virtual ~restaurant();
        void AdaugaMasa();
        void AfisareComandaClient(int i);
    protected:
        int nr_mese_libere;
        int nr_mese_total;
        vector<masa>m;

    private:
};

#endif // RESTAURANT_H
