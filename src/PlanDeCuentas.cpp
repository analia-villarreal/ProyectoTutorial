#include <iostream>
#include <cstring>
#include <cstdlib>
#include <clocale>
#include <cstdio>
#include <conio.h>
#include <ctime>
#include <iomanip>

#include "Comprobante.h"
#include "Fecha.h"
#include "Impuesto.h"
#include "MediosDePagos.h"
#include "OrdenDePago.h"
#include "PlanDeCuentas.h"
#include "Proveedor.h"
#include "rlutil.h"
#include "Funciones.h"
#include "Reportes.h"


using namespace std;
using namespace rlutil;

PlanDeCuentas::PlanDeCuentas(){

}

PlanDeCuentas::PlanDeCuentas(int codigo,const char* nombre,int tipo,bool estado){

    _cuentaContable=codigo;
    strcpy(_descripcionCuenta,nombre);
    _tipoCuenta=tipo;
    _estadoPlan=estado;

}
void PlanDeCuentas::setCuentaContable(int cuenta)
{
    _cuentaContable=cuenta;
}
void PlanDeCuentas::setDescripcionCuenta(const char* descCuenta)
{
    strcpy(_descripcionCuenta,descCuenta);
}
void PlanDeCuentas::setTipoCuenta(int tipo)
{
    _tipoCuenta=tipo;
}
void PlanDeCuentas::setEstado(bool estado)
{
    _estadoPlan=estado;

}
int PlanDeCuentas::getCuentaContable()
{
    return _cuentaContable;
}
const char *PlanDeCuentas::getDescripcionCuenta()
{
    return _descripcionCuenta;
}
int PlanDeCuentas::getTipoCuenta()
{
    return _tipoCuenta;
}
bool PlanDeCuentas::getEstadoPlan()
{
    return _estadoPlan;
}
void PlanDeCuentas::cargar()
{
    int cuenta;
    char desc[30];

    cout<<"CUENTA CONTABLE"<<endl;
    cin>>cuenta;
    setCuentaContable(cuenta);

    cout<<"DESCRIPCION    "<<endl;
    cin>> desc;
    strcpy(_descripcionCuenta, desc);
    setTipoCuenta(2);
    setEstado(true);
}
void PlanDeCuentas::mostrar()
{
    cout << left;
    cout<< setw(0) <<"  ";
    cout<< setw(13) << _cuentaContable;
    cout<< setw(33) <<_descripcionCuenta;
    cout<< setw(4) <<_tipoCuenta;
    cout<<endl;


}

bool PlanDeCuentas::guardarEnDisco()
{
    bool guardo;
    FILE *p;
    p = fopen("plandecuentas.dat", "ab");
    if (p == NULL)
    {
        return false;
    }
    guardo = fwrite(this, sizeof(PlanDeCuentas), 1, p);
    fclose(p);
    return guardo;
}

bool PlanDeCuentas::guardarEnDiscoReset()
{
    bool guardo;
    FILE *p;
    p = fopen("plandecuentas.dat", "wb");
    if (p == NULL)
    {
        return false;
    }
    guardo = fwrite(this, sizeof(PlanDeCuentas), 1, p);
    fclose(p);
    return guardo;
}
bool PlanDeCuentas::leerDeDisco(int pos)
{
    bool lectura;
    FILE *p;
    p = fopen("plandecuentas.dat", "rb");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, sizeof(PlanDeCuentas)*pos, SEEK_SET);
    lectura = fread(this, sizeof(PlanDeCuentas), 1, p);
    fclose(p);
    return lectura;
}


void PlanDeCuentas::listarPlanDeCuentas()
{


    cout << left;
    cout << setw(13)  << "CODIGO CUENTA";
    cout << setw(30) << "DESCRIPCION CUENTA";
    cout << setw(4) << "ESTADO"<<endl;
    cout<<endl;
    int pos=0;
    while(leerDeDisco(pos)==true)
    {
        if(getEstadoPlan()==true){
          mostrar();
        }

        pos++;
    }
    //cout<<endl;
}

void PlanDeCuentas::guardarEnDisco(int pos)
{

    bool guardo;
    FILE *p;
    p = fopen("plandecuentas.dat", "rb+");
    if (p == NULL){
        return;
    }
    fseek(p, sizeof(PlanDeCuentas)*pos, SEEK_SET);
    guardo = fwrite(this, sizeof(PlanDeCuentas), 1, p);
    fclose(p);
    return;

}
