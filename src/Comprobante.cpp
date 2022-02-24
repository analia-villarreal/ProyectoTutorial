#include <iostream>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <clocale>
#include <cstdio>
#include <iomanip>

#include "Comprobante.h"
#include "Impuesto.h"
#include "PlanDeCuentas.h"
#include "Proveedor.h"
#include "Funciones.h"
#include "rlutil.h"
#include "Fecha.h"
#include "Reportes.h"
#include "Mensaje.h"
#include "Login.h"
#include "OrdenDePago.h"
#include "MediosDePagos.h"

using namespace std;
using namespace rlutil;

Comprobante::Comprobante(){

}

Comprobante::Comprobante(int id, const char* letra, Fecha fechaConta, Fecha fechaComprobante, int tipo, int idProv, int pv, int numFac, int cuenta, int cant, float pu, float iva, float impTotal, int estado, const  char *userLog)
{
    _idComp=id;
    strcpy(_letra,letra);
    _fechaContabilizacion=fechaConta;
    _fechaComp=fechaComprobante;
    _tipo=tipo;
    _idProveedor=idProv;
    _pv=pv;
    _numFac=numFac;
    _cuentaContable=cuenta;
    _cantidad=cant;
    _PU=pu;
    _IVA=iva;
    _importeTotal=impTotal;
    _estado=estado;
    strcpy(_usuarioLogueado,userLog);

}

void Comprobante::setIdComp(int idComp)
{
    _idComp=idComp;
}
void Comprobante::setLetra(char* letra)
{
    strcpy(_letra,letra);
}

void Comprobante::setFechaContabilizacion(Fecha contabilizacion)
{
    _fechaContabilizacion=contabilizacion;
}

void Comprobante::setFechaFactura(Fecha factura)
{
    _fechaComp=factura;
}

void Comprobante::setTipo(int tipo)
{
   _tipo=tipo;
}

void Comprobante::setPv(int pv)
{

    if(pv<9999)
    {
        _pv=pv;
    }

}
void Comprobante::setNumFac(int numFac)
{
   if(numFac<99999999)
    {
        _numFac=numFac;
    }

}
void Comprobante::setCuentaContable(int cuenta)
{
    _cuentaContable=cuenta;
}
void Comprobante::setCantidad(int cant)
{
    _cantidad=cant;
}
void Comprobante::setPU(float pu)
{
    _PU=pu;
}
void Comprobante::setIVA(float iva)
{
    _IVA=iva;
}
void Comprobante::setImporteTotal(float importe)
{
    _importeTotal=importe;
}
void Comprobante::setEstado(int estado)
{
    _estado=estado;
}
void Comprobante::setUserLog(const char* user)
{
    strcpy(_usuarioLogueado,user);
}
int Comprobante::getIdComp()
{
    return _idComp;
}
const char * Comprobante::getLetra()
{
    return _letra;
}

Fecha Comprobante::getFechaContabilizacion()
{
    return _fechaContabilizacion;
}

Fecha Comprobante::getFechaFactura()
{
    return _fechaComp;
}
int Comprobante::getTipo()
{
    return _tipo;
}

int Comprobante::getIdProveedor()
{
    return _idProveedor;
}
int Comprobante::getPV()
{
    return _pv;
}
int Comprobante::getNumFac()
{
    return _numFac;
}
int Comprobante::getCuentaContable()
{
    return _cuentaContable;
}
int Comprobante::getCantidad()
{
    return _cantidad;
}
float Comprobante::getPU()
{
    return _PU;
}
float Comprobante::getIVA()
{
    return _IVA;
}

float Comprobante::getImporteTotal()
{
    return _importeTotal;
}
int  Comprobante::getEstado()
{
    return _estado;
}
const char * Comprobante::getUsuarioLog()
{
    return _usuarioLogueado;
}
void Comprobante::cargar(int tipo,const char *usuario)
{
    marco_comprobante(1,2,80,68);

    setlocale(LC_ALL, "Spanish");
    int x;
    setTipo(tipo);
    resetColor();
    Mensaje msjs("GENIAL!!!", Mensaje::TipoMensaje::Info,83,4);

    msjs.mostrar();
    resetColor();
    if(getTipo()==1){
        gotoxy(4,3);cout<<"ESTA CARGANDO UNA FACTURA" <<endl;
    }
    if(getTipo()==2){
        gotoxy(4,3);cout<<"ESTA CARGANDO UNA NOTA DE CREDITO"<<endl;
    }

    gotoxy(4,5);cout<<"FECHA CONTABILIZACIÓN"<<endl;

    int d,m,a;
    gotoxy(4,6);cout<<"DIA: "<<endl;
    gotoxy(9,6);cin>>d;
    while (d <= 0 || d >32)
    {
        gotoxy(5,7);cout << "Ingrese un dia entre 1 y 31" << endl;
        gotoxy(5,8);cout << "DIA: " << endl;
        gotoxy(10,8);cin >> d;
    }
    Mensaje msj1("SE REGISTRA PARA ESTA FECHA EL DIA DE HOY", Mensaje::TipoMensaje::Exito,83,7);

    msj1.mostrar();
    resetColor();

    gotoxy(4,9);cout<<"MES: "<<endl;
    gotoxy(9,9);cin>>m;
    while (m <=0 || m >13)
    {
       gotoxy(5,10);cout << "Ingrese un mes entre 1 Y 12" << endl;
       gotoxy(5,11);cout << "MES: " << endl;
       gotoxy(9,11);cin >> m;
    }



    gotoxy(4,12);cout<<"AÑO: "<<endl;
    gotoxy(9,12);cin>>a;

    while (a<1990)
    {
        gotoxy(5,13);cout << "iNGRESE UN AÑO MAYOR A 1990" << endl;
        gotoxy(5,14);cout << "AÑO: " << endl;
        gotoxy(9,14);cin >> a;
    }


    _fechaContabilizacion.setDia(d);
    _fechaContabilizacion.setMes(m);
    _fechaContabilizacion.setAnio(a);

    Mensaje msj6("SE REGISTRA PARA ESTA FECHA EL DIA DEL COMPROBANTE FISICO", Mensaje::TipoMensaje::Exito,83,14);
    msj6.mostrar();
    resetColor();

    Mensaje msj7("--TIP---", Mensaje::TipoMensaje::Exito,83,17);
    Mensaje msj3("SEGUN CADA COMPAÑIA SI ES NECESARIO CARGAR IVA CREDITO FISCAL,", Mensaje::TipoMensaje::Exito,83,17);
    Mensaje msj4("LOS PRIMEROS DIAS DEL MES SE USA COMO FECHA DE CONTABILIZACION" , Mensaje::TipoMensaje::Exito,83,18);
    Mensaje msj5("EL ULTIMO DIA DEL MES ANTERIOR, SIEMPRE SE PUEDE PREGUNTAR A EL RESPONSABLE A CARGO =)", Mensaje::TipoMensaje::Exito,83,19);
    Mensaje msj11("SU CONSULTA NO MOLESTA!", Mensaje::TipoMensaje::Exito,83,20);
    msj7.mostrar();
    msj3.mostrar();
    msj4.mostrar();
    msj5.mostrar();
    msj11.mostrar();
    resetColor();
    gotoxy(4,15);cout<<"FECHA COMPROBANTE"<<endl;

    int dd,mm,aa;
    gotoxy(4,16);cout<<"DIA: "<<endl;
    gotoxy(9,16);cin>>dd;
    while (dd <= 0 || dd >32)
    {
        gotoxy(4,17);cout << "Ingrese un dia entre 1 Y 31" << endl;
        gotoxy(4,18);cout << "DIA: " << endl;
        gotoxy(9,18);cin >> dd;
    }

    gotoxy(4,19);cout<<"MES: "<<endl;
    gotoxy(9,19);cin>>mm;
    while (mm <=0 || mm >13)
    {
        gotoxy(4,20);cout << "Ingrese el mes de  1 Y 12" << endl;
        gotoxy(4,21);cout << "MES: "<< endl;
        gotoxy(9,21);cin >> mm;
    }

    gotoxy(4,22);cout<<"AÑO: "<<endl;
    gotoxy(9,22);cin>>aa;

    while (aa<1990)
    {
        gotoxy(4,23);cout << "Ingrese un año mayor a 1990" << endl;
        gotoxy(4,24);cout << "AÑO: "<< endl;
        gotoxy(9,24);cin >> aa;
    }

    _fechaComp.setDia(dd);
    _fechaComp.setMes(mm);
    _fechaComp.setAnio(aa);

    Mensaje msjx("TE DAMOS UNA LISTA DE PROVEEDORES PARA QUE PUEDAR SEGUIR!!", Mensaje::TipoMensaje::Exito,83,24);

    msjx.mostrar();
    resetColor();

    gotoxy(4,25);cout<<"PROVEEDOR"<<endl;

    rand_proveedores();

    // llamar a la funcion randomProveedor() --> Mostrar un random de 5 proveedores con su categoria
    gotoxy(4,32);cout<<"ELIGE UN PROVEEDOR"<<endl;
    gotoxy(4,33);cin>> _idProveedor;

    gotoxy(4,35);buscarNombProveedor(_idProveedor);

    Mensaje msjd1("RECORDA:  ", Mensaje::TipoMensaje::Exito,83,34);
    Mensaje msjd2("A o B-> PARA RESPONSABLE INSCRIPTO SEGUN SI DISCRIMINA IVA O NO", Mensaje::TipoMensaje::Exito,83,35);
    Mensaje msjd3("C -> PARA MONOTRIBUTISTA ", Mensaje::TipoMensaje::Exito,83,36);
    Mensaje msjd4("M -> PARA RESPONSABLE INSCRIPTO CON FACTURA M ", Mensaje::TipoMensaje::Exito,83,37);
    msjd1.mostrar();
    msjd2.mostrar();
    msjd3.mostrar();
    msjd4.mostrar();
    resetColor();

    gotoxy(13,38);cout<<"LETRA: "<<endl;
    gotoxy(21,38);cin>> _letra;


    // Mostrar opciones
    gotoxy(13,40);cout<<"PV: "<<endl;
    gotoxy(17,40);cin>> _pv;
    gotoxy(22,40);cout<<"NUMERO: "<<endl;
    gotoxy(32,40);cin>> _numFac;

    Mensaje msj8("TE DAMOS UNA LISTA DE CUENTAS A IMPUTAR!!", Mensaje::TipoMensaje::Exito,83,39);

    msj8.mostrar();
    resetColor();
    //cuenta contable del proveedor
    gotoxy(4,45);cout<<"CUENTA CONTABLE: "<<endl;
    rand_cuentas_contables();
    gotoxy(25,45);cin>> _cuentaContable;
    gotoxy(4,47);cout<<"CANTIDAD: "<<endl;
    gotoxy(14,47);cin >> _cantidad;

    Mensaje msjx2("TIP!! SI SON ARTICULOS INVENTARIABLES LA CANTIDAD ES IMPORTANTE A TENERLO EN CUENTA", Mensaje::TipoMensaje::Error,83,32);
    msjx2.mostrar();
    resetColor();

    gotoxy(4,52);cout<<"PRECIO: $ "<<endl;
    gotoxy(15,52);cin >> _PU;
    float tasa;
    tasa=buscarAlicuota(_idProveedor);
    float IVA;
    if(buscarProveedorCategoria(_idProveedor)==true){

        tasa=0;
    }
    else{

      IVA=(((_PU*_cantidad)*tasa)/100);
    }
    setIVA(IVA);
    cout << fixed;
    gotoxy(37,52);cout<<"IVA: $  "<< setprecision(2) <<getIVA()<<endl;

    _importeTotal=(_PU*_cantidad)+IVA;
    cout << fixed;
    gotoxy(60,52);cout<<"TOTAL: $ "<< setprecision(2) <<_importeTotal<< endl;

    setEstado(1);
    setUserLog(usuario);
    resetColor();

}

void Comprobante::mostrar()
{
    float importeNeto=0;
    char nom[45]={};
    strcpy(nom,buscarNombProv2(_idProveedor));
    importeNeto=_importeTotal-getIVA();
    cout << left;
    _fechaContabilizacion.mostrar();
    _fechaComp.mostrar();
    cout<< setw(6) <<  _idProveedor;
    cout<< setw(40) << nom;
    cout<< setw(6) << _tipo;
    cout<< setw(5) << _pv;
    cout<< setw(13) << _numFac;
    cout<< setw(16) << _cuentaContable;
    cout<< setw(14) << importeNeto;
    cout<< setw(10) << getIVA();
    cout<< setw(10) << _importeTotal;
    cout << endl;

}

void Comprobante::listarComprobantes()
{
    int i=0;
    cout << left;
    cout<< "--------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout<< "                                                                              LISTADO COMPROBANTES                                  " << endl;
    cout<< "---------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    cout<< setw(13) <<" FECHA CONTA ";
    cout<< setw(15) <<" FECHA COMP ";
    cout<< setw(6) <<"  PROVEEDOR ";
    cout<< setw(30) <<"  ";
    cout<< setw(6) << " TIPO ";
    cout<< setw(4) << " PV ";
    cout<< setw(13) << " COMPROBANTE ";
    cout<< setw(16) <<" CUENTA CONTABLE ";
    cout<< setw(14) <<" IMPORTE NETO ";
    cout<< setw(10) <<" IVA ";
    cout<< setw(10) <<" TOTAL ";
    cout << endl;

    while(leerDeDisco(i))
    {
        if(_estado!=2){mostrar();}
        i++;
    }
    cout << endl;
}

bool Comprobante::guardarEnDisco()
{
    bool guardo;
    FILE *p;
    p = fopen("comprobantes.dat", "ab");
    if (p == NULL)
    {
        return false;
    }
    guardo = fwrite(this, sizeof(Comprobante), 1, p);
    fclose(p);
    return guardo;
}
bool Comprobante::guardarEnDiscoReset()
{
    bool guardo;
    FILE *p;
    p = fopen("comprobantes.dat", "wb");
    if (p == NULL)
    {
        return false;
    }
    guardo = fwrite(this, sizeof(Comprobante), 1, p);
    fclose(p);
    return guardo;
}
bool Comprobante::leerDeDisco(int pos)
{
    bool lectura;
    FILE *p;
    p = fopen("comprobantes.dat", "rb");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, sizeof(Comprobante)*pos, SEEK_SET);
    lectura = fread(this, sizeof(Comprobante), 1, p);
    fclose(p);
    return lectura;
}

void Comprobante::guardarEnDisco(int pos)
{

    bool guardo;
    FILE *p;
    p = fopen("comprobantes.dat", "rb+");
    if (p == NULL){
        return;
    }
    fseek(p, sizeof(Comprobante)*pos, SEEK_SET);
    guardo = fwrite(this, sizeof(Comprobante), 1, p);
    fclose(p);
    return;
}

