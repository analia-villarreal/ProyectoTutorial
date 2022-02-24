#include "MediosDePagos.h"
#include <iostream>
#include "Impuesto.h"
#include "Proveedor.h"
#include "PlanDeCuentas.h"
#include "rlutil.h"
#include "Funciones.h"
#include "OrdenDePago.h"

#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <clocale>
#include <cstdio>

using namespace std;

using namespace rlutil;

//MediosDePagos::MediosDePagos()
//{
//    //ctor
//}

void MediosDePagos::setIdMp(int id ){

    _idMp=id;

}
void MediosDePagos::setDescripcionMedioPago(const char* descrip){

    strcpy(_descripcionMedioPago,descrip);
}
int MediosDePagos::getIdMedioPago(){

    return _idMp;
}
void MediosDePagos::setEstadoMP(bool estado)
{
    _estadoMP=estado;
}
const char * MediosDePagos::getDescripcionMP(){

    return _descripcionMedioPago;
}
bool MediosDePagos::getEstadoMP()
{
    return _estadoMP;
}
bool MediosDePagos::cargar(){

    int mp;
    char desc[30];

    cout<<"CODIGO "<<endl;
    cin>>mp;
    setIdMp(mp);

    cout<<"DESCRIPCION    "<<endl;
    cin>> desc;
    strcpy(_descripcionMedioPago, desc);
    setEstadoMP(true);

}

void MediosDePagos::cargarMedios(){

    setIdMp(1);
    setDescripcionMedioPago("Transferencia Bancaria");
    guardarEnDisco();
    setIdMp(2);
    setDescripcionMedioPago("Cheque propio");
    guardarEnDisco();
    setIdMp(3);
    setDescripcionMedioPago("Cheque de terceros");
    guardarEnDisco();
    setIdMp(4);
    setDescripcionMedioPago("Tarjeta de Credito");
    guardarEnDisco();
    setIdMp(5);
    setDescripcionMedioPago("Caja chica");

    setEstadoMP(true);
    guardarEnDisco();

}


void MediosDePagos::mostrar(){

    //gotoxy(2,3);
    cout<< _idMp <<" - ";

    //gotoxy(25,3);
    cout<<_descripcionMedioPago;

}

void MediosDePagos::listarMediosDePagos(){

    int i=0;
    gotoxy(85,4);cout<<"CODIGO ";
    gotoxy(93,4);cout<<"DESCRIPCION";
    cout<<endl;
    while(leerDeDisco(i))
    {
        gotoxy(85,50+i);cout<<_idMp;
        gotoxy(93,50+i);cout<<_descripcionMedioPago;
        cout << endl;
        i++;
    }

}
bool MediosDePagos::guardarEnDisco(){

    bool guardo;
    FILE *p;
    p = fopen("mediosdepago.dat", "ab");
    if (p == NULL)
    {
        return false;
    }
    guardo = fwrite(this, sizeof(MediosDePagos), 1, p);
    fclose(p);
    return guardo;
}

bool MediosDePagos::leerDeDisco(int pos){

    bool lectura;
    FILE *p;
    p = fopen("mediosdepago.dat", "rb");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, sizeof(MediosDePagos)*pos, SEEK_SET);
    lectura = fread(this, sizeof(MediosDePagos), 1, p);
    fclose(p);
    return lectura;

}
