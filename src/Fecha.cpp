#include "Fecha.h"

#include "Proveedor.h"
#include "Impuesto.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "rlutil.h"
#include <cstdio>
#include <conio.h>
#include <iomanip>

using namespace std;

using namespace rlutil;

Fecha::Fecha()
{
}


Fecha::Fecha(int d, int m, int a)
{
    if (d<0 || d>31 || m<0 || m>12 || a<0)
    {
        _dia=0;
        _mes=0;
        _anio=0;
    }
    else
    {
        _dia=d;
        _mes=m;
        _anio=a;
    }
}


void Fecha::cargar()
{
    int d,m,a;
    cout<<"DIA"<<endl;
    cin>>d;
    while (d <0 || d >32)
    {
        cout << "iNGRESE UN DIA ENTRE 1 Y 31" << endl;
        cout << "DIA: " << endl;
        cin >> d;
    }
    setDia(d);
    cout<<"MES"<<endl;
    cin>>m;
    while (m <0 || m >13)
    {
        cout << "iNGRESE UN MES ENTRE 1 Y 12" << endl;
        cout << "MES: " << endl;
        cin >> m;
    }
    setMes(m);
    cout<<"AÑO"<<endl;
    cin>>a;

    while (a<1990)
    {
        cout << "iNGRESE UN AÑO MAYOR A 1990" << endl;
        cout << "AÑO: " << endl;
        cin >> a;
    }
    setAnio(a);

}
void Fecha::mostrar()
{

    cout << _dia << "/" << _mes << "/" << _anio;

}
