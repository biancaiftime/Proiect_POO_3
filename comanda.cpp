#include "comanda.h"
#include<cstring>
comanda_mancare::comanda_mancare()
{
    pret=0;
}
ciorba::ciorba()
{
    char sir[100];
    cout<<"De care?De burta,de legume sau de ciuperci?\n";
    cin.getline(sir,100);
    if(strcmp(sir,"De burta")==0) { tip=DE_BURTA; pret=10.5;}
    if(strcmp(sir,"De legume")==0) { tip=DE_LEGUME; pret=11.5;}
    if(strcmp(sir,"De burta")==0||strcmp(sir,"De legume")==0)
    {
        cout<<"Cu sau fara smantana?\n";
        cin.getline(sir,100);
        if(strcmp(sir,"Cu")==0)pret+=2;
        cout<<"Cu sau fara ardei?\n";
        cin.getline(sir,100);
        if(strcmp(sir,"Cu")==0)pret+=2;
    }
    if(strcmp(sir,"De ciuperci")==0) { tip=DE_CIUPERCI; pret=12;}
}
fel_principal_de_pui::fel_principal_de_pui()
{
    char s[100];
    cout<<"Frigarui sau Tocana?\n";
    cin.getline(s,100);
    if(strcmp(s,"Frigarui")==0){tip=FRIGARUI; pret=18;}
    else
    {
        tip=TOCANA;
        pret=20;
    }
}
fel_principal_de_vita::fel_principal_de_vita()
{
    char s[100];
    int cant;
    cout<<"Chateaubriand,stroganoff sau file?\n";
    cin.getline(s,100);
    if(strcmp(s,"Chateaubriand")==0)
    {
        pret=10.2;
        tip=CHATEAUBRIAND;
        cout<<"Cat de bine facut sa fie?\n";
        cin.getline(s,100);
        if(strcmp(s,"In sange")==0)grad=SANGE;
        if(strcmp(s,"Mediu")==0)grad=MEDIU;
        else grad=FACUT;
    }
    if(strcmp(s,"stroganoff")==0)
    {
        tip=STROGANOFF;
        pret=8.3;
    }
    else
    {
        tip=FILE;
        pret=9.4;
    }
    cout<<"Ce cantitate doriti?\n";
    cin>>cant;
    cin.get();
    pret*=cant;

}
garnitura::garnitura()
{
    char s[100];
    cout<<"Ce fel de garnitura doriti? Cartofi prajiti, piure sau orez sarbesc?\n";
    cin.getline(s,100);
    if(strcmp(s,"Cartofi prajiti")==0){ tip=Cartofi_prajiti; pret=10;}
    if(strcmp(s,"Cartofi piure")==0){ tip=Cartofi_piure; pret=8;}
    else { tip=Orez_sarbesc; pret=9;}
}
desert::desert()
{
    char s[100];
    cout<<"Inghetata sau tort krantz?\n";
    cin>>s;
    if(strcmp(s,"Inghetata")==0)
    {
        tip=INGHETATA;
        cout<<"Cate cupe doriti?\n";
        cin>>nr_cupe;
        pret=nr_cupe*4;
    }
    else
    {
        tip=TORT_KRANTZ;
        pret=16;
    }
}
bere::bere()
{
    char s[100];
    cout<<"Cu alcool sau fara?\n";
    cin.getline(s,100);
    if(strcmp(s,"Cu alcool")==0) tip=ALCOOL;
    else tip=FARA_ALCOOL;
    pret=10;
}
vin::vin()
{
    char s[100];
    int cant;
    cout<<"La pahar sau la sticla?\n";
    cin.getline(s,100);
    if(strcmp(s,"La pahar")==0)
    {
        cout<<"Cati ml?\n";
        cin>>cant;
        cin.get();
        cout<<"Rosu sau alb?\n";
        cin.getline(s,100);
        if(strcmp(s,"Rosu")==0)tip=PAHAR_ROSU;
        else tip=PAHAR_ALB;
        pret=cant*5;
    }
    else
    {
        cout<<"Bordeux sau Castel Bolovanu?\n";
        cin.getline(s,100);
        if(strcmp(s,"Bordeux")==0)
        {
            tip=BORDEUX_1996;
            pret=250;
        }
        else
        {
            tip=CASTEL_BOLOVANU_2004;
            pret=150;
        }
    }
}
apa::apa()
{
    pret=6;
}
ostream &operator<<(ostream &out,fel_principal_de_vita f)
{
    out<<"FEL PRINCIPAL DE VITA: ";
    if(f.tip==2)out<<"CHATEAUBRIAND";
    else if(f.tip==4)out<<"FILE";
    else out<<"STROGANOFF";
    out<<"\n";
    return out;
}
ostream &operator<<(ostream &out,fel_principal_de_pui f)
{
    out<<"FEL PRINCIPAL DE PUI: ";
    if(f.tip==0)out<<"FRIGARUI";
    out<<"TOCANA";
    out<<"\n";
    return out;
}
ostream &operator<<(ostream &out,ciorba c)
{
    out<<"CIORBA ";
    if(c.tip==0)out<<"DE BURTA";
    if(c.tip==1)out<<"DE LEGUME";
    else out<<"DE CIUPERCI";
    out<<"\n";
    return out;
}
ostream &operator<<(ostream &out,garnitura g)
{
    out<<"GARNITURA: ";
    if(g.tip==1)out<<"CARTOFI PIURE\n";
    else if(g.tip==0)out<<"CARTOFI PRAJITI\n";
    else out<<"OREZ SARBESC\n";
    return out;
}
ostream &operator<<(ostream &out,desert d)
{
    out<<"DESERT: ";
    if(d.tip==0)out<<"INGHETATA "<<d.nr_cupe<<" CUPE\n";
    else out<<"TORT KRANTZ\n";
    return out;
}
ostream &operator<<(ostream &out,vin v)
{
    out<<"VIN ";
    if(v.tip==2)out<<"BORDEUX 1996\n";
    else if(v.tip==0)out<<"LA PAHAR ALB\n";
    else if(v.tip==1)out<<"LA PAHAR ROSU\n";
    else out<<"CASTEL BOLOVANU 2004\n";
    return out;
}
ostream &operator<<(ostream &out,bere b)
{
    out<<"BERE ";
    if(b.tip==0)out<<"CU ALCOOL\n";
    else out<<"FARA ALCOOL\n";
    return out;
}
ostream &operator<<(ostream &out,apa a)
{
    out<<"APA";
    return out;
}
void ciorba::Print()
{
    cout<<(*this);
}
void fel_principal_de_pui::Print()
{
    cout<<(*this);
}
void fel_principal_de_vita::Print()
{
    cout<<(*this);
}
void garnitura::Print()
{
    cout<<(*this);
}
void desert::Print()
{
    cout<<(*this);
}
void vin::Print()
{
    cout<<(*this);
}
void bere::Print()
{
    cout<<(*this);
}
void apa::Print()
{
    cout<<(*this);
}
