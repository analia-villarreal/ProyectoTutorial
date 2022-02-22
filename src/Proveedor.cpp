#include "Proveedor.h"
#include "MediosDePagos.h"
#include "OrdenDePago.h"
#include "Comprobante.h"
#include "Fecha.h"
#include "Impuesto.h"
#include "PlanDeCuentas.h"
#include "rlutil.h"
#include "Funciones.h"
#include "Reportes.h"


#include <iomanip>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <conio.h>
#include <clocale>


using namespace std;

using namespace rlutil;

Proveedor::Proveedor()
{
    //ctor
}

Proveedor::Proveedor(int idPro,const char* razon,int cuit ,int jur,const char* nombJur,const char* categoria,bool retIIBB,bool retGanan,int iva,bool estado)
{
    _idProveedor=idPro;
    strcpy(_razonSocial,razon);
    _CUIT=cuit;
    _juridiccion=jur;
    strcpy(_nombJuridiccion,nombJur);
    strcpy(_categoria,categoria);
    _retIIBB=retIIBB;
    _retGanancias=retGanan;
    _IVA=iva;
    _estadoProveedor=estado;
}
void Proveedor::setIdProveedor(int idProv)
{
    _idProveedor=idProv;
}
void Proveedor::setRazonSocial(char* razon)
{
    strcpy(_razonSocial,razon);
}
void Proveedor::setCUIT(int cuit)
{
    _CUIT=cuit;
}
void Proveedor::setJuridiccion(int jur)
{
    _juridiccion=jur;
}
void Proveedor::setNombJu(char* nombJur)
{
    strcpy(_nombJuridiccion,nombJur);
}
void Proveedor::setCategoria(char* categoria)
{
    strcpy(_categoria,categoria);
}
void Proveedor::setRetIIBB(bool retIIBB)
{
    _retIIBB=retIIBB;// sisi que no sea objeto impuesto ok y es solo un ID ok
}
void Proveedor::setRetGanancias(bool retGanancias)
{
    _retGanancias=retGanancias;
}
void Proveedor::setIVA(int iva)
{
    _IVA=iva;
}
void Proveedor::setEstadoProv(bool estado)
{
    _estadoProveedor=estado;
}
int Proveedor::getIdProveedor()
{
    return _idProveedor;
}
char * Proveedor::getRazonSocial()
{
    return _razonSocial;
}
int Proveedor::getCUIT()
{
    return _CUIT;
}
int Proveedor::getJuridiccion()
{
    return _juridiccion;
}
char * Proveedor::getNombJur()
{
    return _nombJuridiccion;
}
char * Proveedor::getCategoria()
{
    return _categoria;
}
bool Proveedor::getRetIIBB()
{
    return _retIIBB;
}
bool Proveedor::getRetGanancias()
{
    return _retGanancias;
}
int Proveedor::getIVA()
{
    return _IVA;
}
bool Proveedor::getEstadoProv()
{
    return _estadoProveedor;
}


// int _idProveedor;
//  char _razonSocial[45];
//  int _CUIT;
//  int _juridiccion;
//  char _nombJuridiccion[20];
//  char _categotia[2];
// Impuesto _retIIBB;
// Impuesto _retGanancias;
// Impuesto _IVA;
bool Proveedor::cargar()
{
    int idProv;
    bool repetido;
    cout<<" CREAR PROVEEDOR    "<<endl;
    cout<<"-----------------   "<<endl;
    cout<<" CODIGO PROVEEDOR   "<<endl;
    cin>> idProv;

    repetido = buscarProveedor(idProv);

    if(repetido==true)
    {
        cout<<"El Código esta repetido ingrese un numero diferente"<<endl;
        return false;
    }
    setIdProveedor(idProv);
    cout<<" NOMBRE PROVEEDOR   "<<endl;
    cin.ignore();
    cin.getline(_razonSocial,45);
    cout<<" CUIT               "<<endl;
    cin>>_CUIT;
    cout<<" JURIDICCION        "<<endl;
    cin>>_juridiccion;
    cout<<" NOMBRE JURIDICCION "<<endl;
    cin.ignore();
    cin.getline(_nombJuridiccion,45);
    cout<<"CATEGORIA           "<<endl;
    //cin.ignore();
    cin.getline(_categoria,3);
    cout<<"si retiene IIBB BA ingrese 1 sino 0"<<endl;
    cin>> _retIIBB;
    cout<<"si retiene Imp. a las ganancias ingrese 1 sino 0"<<endl;
    cin>> _retGanancias;
    cout<<"Ingrese la condición de IVA 21%:1 10.5%:2  0%:3"<<endl;
    cin>> _IVA;
    setEstadoProv(true);

}
void Proveedor::mostrar()
{
    cout << left;
    cout<< setw(6) <<_idProveedor;
    cout<< setw(50) <<_razonSocial;
    cout<< setw(30) <<_categoria;
    cout<< setw(33) <<_estadoProveedor;
    cout<<endl;
}
bool Proveedor::guardarEnDisco()
{
    bool guardo;
    FILE *p;
    p = fopen("proveedores.dat", "ab");
    if (p == NULL)
    {
        return false;
    }
    guardo = fwrite(this, sizeof(Proveedor), 1, p);
    fclose(p);
    return guardo;
}
bool Proveedor::guardarEnDiscoReset()
{
    bool guardo;
    FILE *p;
    p = fopen("proveedores.dat", "wb");
    if (p == NULL)
    {
        return false;
    }
    guardo = fwrite(this, sizeof(Proveedor), 1, p);
    fclose(p);
    return guardo;
}



void Proveedor::guardarEnDisco(int pos)
{
    bool guardo;
    FILE *p;
    p = fopen("proveedores.dat", "rb+");
    if (p == NULL)
    {
        return;
    }
    fseek(p, sizeof(Proveedor)*pos, SEEK_SET);
    guardo = fwrite(this, sizeof(Proveedor), 1, p);
    fclose(p);
    return;
}



bool Proveedor::leerDeDisco(int pos)
{
    bool lectura;
    FILE *p;
    p = fopen("proveedores.dat", "rb");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, sizeof(Proveedor)*pos, SEEK_SET);
    lectura = fread(this, sizeof(Proveedor), 1, p);
    fclose(p);
    return lectura;
}












