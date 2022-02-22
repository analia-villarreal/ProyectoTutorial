#include "Impuesto.h"
#include "Proveedor.h"
#include "PlanDeCuentas.h"
#include "rlutil.h"
#include "Funciones.h"

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <clocale>
#include <cstdio>

using namespace std;

using namespace rlutil;



Impuesto::Impuesto()
{
    //ctor
}

void Impuesto::setidImpuesto(int idImpuesto)
{
    _idImpuesto=idImpuesto;
}
void Impuesto::setTipo(int tipo )
{
    _tipo=tipo;
}
void Impuesto::setImpuesto(int imp)
{
    _impuesto=imp;
}
void Impuesto::setDescripcion (char* desc )
{
    strcpy(_descripcion,desc);
}
void Impuesto::setTasa(float tasa)
{
    _tasa=tasa;
}
void Impuesto::setMinNoImponible(float minNoImp)
{
    _minNoImponible=minNoImp;
}
int Impuesto::getIdImpuesto()
{
    return _idImpuesto;
}
int Impuesto::getTipo()
{
    return _tipo;
}
int Impuesto::getImpuesto()
{
    return _impuesto;
}
char * Impuesto::getDescripcion()
{
    return _descripcion;
}
float Impuesto::getTasa()
{
    return _tasa;
}
float Impuesto:: getMinNoImponible()
{
    return _minNoImponible;
}
void Impuesto::mostrar()
{
cout<<"  TABLA DE IMPUESTOS "<<endl;
cout<<"  ------------------ "<<endl;
cout<<"  CÓDIGO IMPUESTO    "<< _idImpuesto <<endl;
cout<<"  DESCRIPCION        "<< _descripcion <<endl;
}
bool Impuesto::leerDeDisco()
{
    bool lectura;
    FILE *p;
    p = fopen("impuestos.dat", "rb");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, sizeof(Impuesto), SEEK_SET);
    lectura = fread(this, sizeof(Impuesto), 1, p);
    fclose(p);
    return lectura;
}

        //int _idImpuesto;
        //int _tipo;
        //int _impuesto;
        //char _descripcion[30];
        //float _tasa;
        //float _minNoImponible;
void Impuesto::cargar()
{

    int id,tipo,impuesto;
    float tasa, minim;

    cout<<"  TABLA DE IMPUESTOS "<<endl;
    cout<<"---------------------"<<endl;
    cout<<"CODIGO IMPUESTO      "<<endl;
    cin>>id;
    cout<<"DESCRIPCION IMPUESTO "<<endl;
    cin.ignore();
    cin.getline(_descripcion,30);
    cout<<"TIPO DE IMPUESTO"     <<endl;
    cin>>tipo;
    cout<<"IMPUESTO             "<<endl;
    cin>>impuesto;
    cout<<"TASA                 "<<endl;
    cin>>tasa;
    cout<<"MINIMO NO IMPONIBLE  "<<endl;
    cin>>minim;

}
bool Impuesto::guardarEnDisco()
{
    bool guardo;
    FILE *p;
    p = fopen("impuestos.dat", "ab");
    if (p == NULL)
    {
        return false;
    }
    guardo = fwrite(this, sizeof(Impuesto), 1, p);
    fclose(p);
    return guardo;
}
void Impuesto::guardarEnDisco(int pos)
{
    bool guardo;
    FILE *p;
    p = fopen("impuestos.dat", "rb+");
    if (p == NULL){
        return;
    }
    fseek(p, sizeof(Impuesto)*pos, SEEK_SET);
    guardo = fwrite(this, sizeof(Impuesto), 1, p);
    fclose(p);
    return;
}
