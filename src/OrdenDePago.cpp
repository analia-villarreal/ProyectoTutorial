#include "OrdenDePago.h"

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


using namespace std;

using namespace rlutil;

//OrdenDePago::OrdenDePago()
//{
//    //ctor
//}

void OrdenDePago::setIdOP(int idOP)
{

    _idOP=idOP;
}
void OrdenDePago::setFechaContabilizacion(Fecha conta)
{

    _fechaContabilizacion=conta;
}
void OrdenDePago::setTipoOP(int tipo)
{
    _tipoOP=tipo;
}
void OrdenDePago::setIdProveedor(int prov)
{
    _idProveedor=prov;
}
void OrdenDePago::setRetIIBB(float retiibb)
{

    _retIIBB=retiibb;
}
void OrdenDePago::setRetGanancias(float retGanan)
{
    _retGanancias=retGanan;
}
void OrdenDePago::setCuentaContable(int cuenta)
{
    _cuentaContable=cuenta;
}
void OrdenDePago::setImporteAPagar(float importe)
{

    _importeAPagar=importe;
}
void OrdenDePago::setImporteTotal(float importeTotal)
{

    _importeTotal=importeTotal;
}
void OrdenDePago::setFormaDePago(int formaPago)
{

    _formDePago=formaPago;
}
void OrdenDePago::setEstadoOP(bool estado)
{

    _estadoOP=estado;
}
int OrdenDePago::getIdOP()
{

    return _idOP;
}
Fecha OrdenDePago::getFechaContabilizacion()
{

    return _fechaContabilizacion;
}
int OrdenDePago::getTipoOP()
{

    return _tipoOP;
}
int OrdenDePago::getIdProveedor()
{

    return _idProveedor;
}

int OrdenDePago::getNumComp()
{

    return _numComp;
}
float OrdenDePago::getRetIIBB()
{

    return _retIIBB;
}
float OrdenDePago::getRetGanancias()
{

    return _retGanancias;
}
int OrdenDePago::getCuentaContable()
{
    return _cuentaContable;
}
float OrdenDePago::getImporteAPagar()
{

    return _importeAPagar;
}
float OrdenDePago::getImporteTotal()
{

    return _importeTotal;
}
bool OrdenDePago::getEstadoOP()
{

    return _estadoOP;
}
void OrdenDePago::cargar(int tipoOP)
{

    marco_comprobante(1,2,80,55);

    setlocale(LC_ALL, "Spanish");
    int x;
    setTipoOP(tipoOP);

    if(getTipoOP()==1)
    {
        gotoxy(10,3);
        cout<<"PAGOS VARIOS" <<endl;
        gotoxy(10,5);
        cout<<"FECHA CONTABILIZACIÓN"<<endl;

        int d,m,a;
        gotoxy(10,6);
        cout<<"DIA: "<<endl;
        gotoxy(15,6);
        cin>>d;
        while (d <= 0 || d >32)
        {
            gotoxy(10,7);
            cout << "Ingrese un dia entre 1 y 31" << endl;
            gotoxy(11,8);
            cout << "DIA: " << endl;
            gotoxy(15,8);
            cin >> d;
        }

        gotoxy(10,9);
        cout<<"MES: "<<endl;
        gotoxy(15,9);
        cin>>m;
        while (m <=0 || m >13)
        {
            gotoxy(11,10);
            cout << "Ingrese un mes entre 1 Y 12" << endl;
            gotoxy(11,11);
            cout << "MES: " << endl;
            gotoxy(15,11);
            cin >> m;
        }

        gotoxy(10,12);
        cout<<"AÑO: "<<endl;
        gotoxy(15,12);
        cin>>a;

        while (a<1990)
        {
            gotoxy(11,13);
            cout << "iNGRESE UN AÑO MAYOR A 1990" << endl;
            gotoxy(11,14);
            cout << "AÑO: " << endl;
            gotoxy(15,14);
            cin >> a;
        }


        _fechaContabilizacion.setDia(d);
        _fechaContabilizacion.setMes(m);
        _fechaContabilizacion.setAnio(a);


        rand_cuentas_contables_OP();

        int cuenta;
        //marco_comprobante(10,16,50,10);
        gotoxy(10,15);cout<<"Cuenta a imputar: "<< endl;

        gotoxy(30,15);cin>> cuenta;

        setCuentaContable(cuenta);

        gotoxy(36,15);buscarNombreCuentaContable(cuenta);

        gotoxy(10,20);cout<<" Importe: "<< endl;

        float imp;

        gotoxy(20,20);cin>> imp;

        setImporteAPagar(imp);
        setImporteTotal(imp);

        MediosDePagos obj;

        obj.listarMediosDePagos();

        gotoxy(10,25);cout<<"Forma de pago: "<< endl;

        int medio;

        gotoxy(27,25);cin>>medio;

        setFormaDePago(medio);

        gotoxy(31,25);buscarNombreMedioDePago(medio);


    }
    if(getTipoOP()==2)
    {
        gotoxy(10,3);
        cout<<"PAGOS PROVEEDOR" <<endl;
        gotoxy(10,5);
        cout<<"FECHA CONTABILIZACIÓN"<<endl;

        int d,m,a;
        gotoxy(10,6);
        cout<<"DIA: "<<endl;
        gotoxy(15,6);
        cin>>d;
        while (d <= 0 || d >32)
        {
            gotoxy(10,7);
            cout << "Ingrese un dia entre 1 y 31" << endl;
            gotoxy(11,8);
            cout << "DIA: " << endl;
            gotoxy(15,8);
            cin >> d;
        }

        gotoxy(10,9);
        cout<<"MES: "<<endl;
        gotoxy(15,9);
        cin>>m;
        while (m <=0 || m >13)
        {
            gotoxy(11,10);
            cout << "Ingrese un mes entre 1 Y 12" << endl;
            gotoxy(11,11);
            cout << "MES: " << endl;
            gotoxy(15,11);
            cin >> m;
        }

        gotoxy(10,12);
        cout<<"AÑO: "<<endl;
        gotoxy(15,12);
        cin>>a;

        while (a<1990)
        {
            gotoxy(11,13);
            cout << "iNGRESE UN AÑO MAYOR A 1990" << endl;
            gotoxy(11,14);
            cout << "AÑO: " << endl;
            gotoxy(15,14);
            cin >> a;
        }

        _fechaContabilizacion.setDia(d);
        _fechaContabilizacion.setMes(m);
        _fechaContabilizacion.setAnio(a);

        //gotoxy(10,17);cout<<"PROVEEDOR"<<endl;

        rand_proveedoresOP();

        int idProv;

        gotoxy(10,19);cout<<"ELIGE UN PROVEEDOR: "<<endl;
        gotoxy(30,19);cin>> idProv;
        setIdProveedor(idProv);

        marco_comprobante(10,23,50,10);


        gotoxy(12,22);cout<<"FACTURAS PENDIENTES: "<<endl;
        buscarFacturasProveedor(idProv);

        int numfac;
        int pv;
        int pos;

        gotoxy(10,35);cout<<"INGREGAR PV Y NUMERO DE FACTURA A PAGAR: "<<endl;
        gotoxy(55,35);cin>> pv;
        gotoxy(65,35);cin>> numfac;

        Comprobante reg;

        pos=buscarFacturasDarDeBaja(numfac,pv,idProv);

        if(pos >= 0)
        {
            reg.leerDeDisco(pos);
            int estado;
            if(reg.getEstado()==1)
            {
                gotoxy(12,37);cout << "ESTADO ACTUAL: ACTIVO" << endl;
            }
            else{
                gotoxy(12,37);cout << "ESTADO ACTUAL: ANULADO" << endl;
            }
            gotoxy(12,39);cout << "DESEA PAGAR ESTA FACTURA? (1: NO / 3: SI) ";
            gotoxy(52,39);cin >> estado;
            reg.setEstado(estado);
            reg.guardarEnDisco(pos);
        }

        Comprobante reg1;

        reg1.leerDeDisco(pos);

        //gotoxy(15,44);cout<< "Importe a pagar" << reg1.getImporteTotal();

        setImporteTotal(reg1.getImporteTotal());

        float retenGanan=0;

        retenGanan=(((reg1.getImporteTotal())*3)/100);

        float retenIIBB=0;

        retenIIBB=(((reg1.getImporteTotal())*2)/100);
        cout << fixed;
        gotoxy(17,45);cout<<" RETENCION IMPUESTOS A LAS GANANCIAS: "<< setprecision(2) << retenGanan <<endl;
        cout << fixed;
        gotoxy(17,46);cout<<" RETENCION IIBB BUENOS AIRES: "<< setprecision(2) << retenIIBB <<endl;

        setRetGanancias(retenGanan);
        setRetIIBB(retenIIBB);

        //setImporteAPagar(imp);
        //setImporteTotal(imp);
        //SETEAR EL COMPROBANTE COMO PAGO.

        MediosDePagos obj;

        obj.listarMediosDePagos();

        gotoxy(20,48);cout<<"Forma de pago: "<< endl;

        int medio;

        gotoxy(45,48);cin>>medio;

        setFormaDePago(medio);

        gotoxy(50,48);buscarNombreMedioDePago(medio);

        setImporteAPagar((reg1.getImporteTotal())-retenGanan-retenIIBB);


    }

    setEstadoOP(1);
    resetColor();

}

void OrdenDePago::mostrar()
{
        char nom[45]={};
        strcpy(nom,buscarNombProv2(_idProveedor));
        cout << left;
        cout<< setw(0) <<"  ";
        cout << setw(2)<<_idOP;
        _fechaContabilizacion.mostrar();
        cout << setw(2)<< _tipoOP;
        cout << setw(4)<< _idProveedor;
        cout <<setw(30)<< nom;
        cout <<setw(9)<<  _numComp;
        cout <<setw(9)<<  _retIIBB;
        cout <<setw(9)<< _retGanancias;
        cout <<setw(6)<<  _cuentaContable;
        cout <<setw(9)<< _importeAPagar;
        cout <<setw(9)<< _importeTotal;
        cout <<setw(3)<< _formDePago;
        cout <<setw(2)<<  _estadoOP;
        cout<<endl;


}


void OrdenDePago::listarOrdenesDePago()
{


    cout << left;
    cout << setw(6)  << "CODIGO";
    cout << setw(12) << "FECHA CONTA";
    cout << setw(2) << "TIPO";
    cout << setw(35) << "PROVEEDOR";
    cout << setw(9) << "FACTURA";
    cout << setw(9) << "RETENCION IIBB";
    cout << setw(9) << "RETENCION GANAN";
    cout << setw(6) << "CUENTA";
    cout << setw(9) << "IMPORTE A PAGAR";
    cout << setw(9) << "IMPORTE TOTAL";
    cout << setw(4) << "FORMA DE PAGO";
    cout<<endl;

    int pos=0;
    while(leerDeDisco(pos)==true)
    {
        if(getEstadoOP()==true){
          mostrar();
        }

        pos++;
    }
    //cout<<endl;
}
bool OrdenDePago::leerDeDisco(int pos)
{

    bool lectura;
    FILE *p;
    p = fopen("ordenesdepago.dat", "rb");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, sizeof(OrdenDePago)*pos, SEEK_SET);
    lectura = fread(this, sizeof(OrdenDePago), 1, p);
    fclose(p);
    return lectura;
}
bool OrdenDePago::guardarEnDisco()
{

    bool guardo;
    FILE *p;
    p = fopen("ordenesdepago.dat", "ab");
    if (p == NULL)
    {
        return false;
    }
    guardo = fwrite(this, sizeof(OrdenDePago), 1, p);
    fclose(p);
    return guardo;

}
void OrdenDePago::guardarEnDisco(int pos)
{
    bool guardo;
    FILE *p;
    p = fopen("comprobantes.dat", "rb+");
    if (p == NULL)
    {
        return;
    }
    fseek(p, sizeof(OrdenDePago)*pos, SEEK_SET);
    guardo = fwrite(this, sizeof(OrdenDePago), 1, p);
    fclose(p);
    return;;

}

