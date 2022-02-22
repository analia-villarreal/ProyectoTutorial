#include "OrdenDePago.h"
#include "Impuesto.h"
#include "Proveedor.h"
#include "PlanDeCuentas.h"
#include "rlutil.h"
#include "Funciones.h"
#include "MediosDePagos.h"

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <clocale>
#include <cstdio>

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

    marco_comprobante(1,2,80,48);

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

        PlanDeCuentas reg;

        reg.listarPlanDeCuentas();

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


        gotoxy(10,22);cout<<"FACTURAS PENDIENTES: "<<endl;
        buscarFacturasProveedor(idProv);

        int numfac;

        gotoxy(10,35);cout<<"FACTURA A PAGAR: "<<endl;
        gotoxy(30,35);cin>> numfac;

        //setImporteAPagar(imp);
        //setImporteTotal(imp);
        //SETEAR EL COMPROBANTE COMO PAGO.

        MediosDePagos obj;

        obj.listarMediosDePagos();

        gotoxy(10,37);cout<<"Forma de pago: "<< endl;

        int medio;

        gotoxy(27,37);cin>>medio;

        setFormaDePago(medio);

        gotoxy(31,37);buscarNombreMedioDePago(medio);

    }
    /*
    gotoxy(4,5);
    cout<<"FECHA CONTABILIZACIÓN"<<endl;

    int d,m,a;
    gotoxy(4,6);
    cout<<"DIA: "<<endl;
    gotoxy(9,6);
    cin>>d;
    while (d <= 0 || d >32)
    {
        gotoxy(5,7);
        cout << "Ingrese un dia entre 1 y 31" << endl;
        gotoxy(5,8);
        cout << "DIA: " << endl;
        gotoxy(10,8);
        cin >> d;
    }

    gotoxy(4,9);
    cout<<"MES: "<<endl;
    gotoxy(9,9);
    cin>>m;
    while (m <=0 || m >13)
    {
        gotoxy(5,10);
        cout << "Ingrese un mes entre 1 Y 12" << endl;
        gotoxy(5,11);
        cout << "MES: " << endl;
        gotoxy(9,11);
        cin >> m;
    }

    gotoxy(4,12);
    cout<<"AÑO: "<<endl;
    gotoxy(9,12);
    cin>>a;

    while (a<1990)
    {
        gotoxy(5,13);
        cout << "iNGRESE UN AÑO MAYOR A 1990" << endl;
        gotoxy(5,14);
        cout << "AÑO: " << endl;
        gotoxy(9,14);
        cin >> a;
    }


    _fechaContabilizacion.setDia(d);
    _fechaContabilizacion.setMes(m);
    _fechaContabilizacion.setAnio(a);

    gotoxy(4,15);
    cout<<"FECHA COMPROBANTE"<<endl;

    int dd,mm,aa;
    gotoxy(4,16);
    cout<<"DIA: "<<endl;
    gotoxy(9,16);
    cin>>dd;
    while (dd <= 0 || dd >32)
    {
        gotoxy(4,17);
        cout << "Ingrese un dia entre 1 Y 31" << endl;
        gotoxy(4,18);
        cout << "DIA: " << endl;
        gotoxy(9,18);
        cin >> dd;
    }

    gotoxy(4,19);
    cout<<"MES: "<<endl;
    gotoxy(9,19);
    cin>>mm;
    while (mm <=0 || mm >13)
    {
        gotoxy(4,20);
        cout << "Ingrese el mes de  1 Y 12" << endl;
        gotoxy(4,21);
        cout << "MES: "<< endl;
        gotoxy(9,21);
        cin >> mm;
    }

    gotoxy(4,22);
    cout<<"AÑO: "<<endl;
    gotoxy(9,22);
    cin>>aa;

    while (aa<1990)
    {
        gotoxy(4,23);
        cout << "Ingrese un año mayor a 1990" << endl;
        gotoxy(4,24);
        cout << "AÑO: "<< endl;
        gotoxy(9,24);
        cin >> aa;
    }

    _fechaComp.setDia(dd);
    _fechaComp.setMes(mm);
    _fechaComp.setAnio(aa);

    gotoxy(4,25);
    cout<<"PROVEEDOR"<<endl;

    gotoxy(4,26);
    rand_proveedores();

    // llamar a la funcion randomProveedor() --> Mostrar un random de 5 proveedores con su categoria
    gotoxy(4,32);
    cout<<"ELIGE UN PROVEEDOR"<<endl;
    gotoxy(4,33);
    cin>> _idProveedor;

    gotoxy(4,35);
    buscarNombProveedor(_idProveedor);

    gotoxy(4,36);
    cout<<"LETRA: "<<endl;
    gotoxy(11,36);
    cin>> _letra;
    // Mostrar opciones
    gotoxy(13,36);
    cout<<"PV: "<<endl;
    gotoxy(17,36);
    cin>> _pv;
    gotoxy(19,36);
    cout<<"NUMERO: "<<endl;
    gotoxy(27,36);
    cin>> _numFac;
    //cuenta contable del proveedor
    gotoxy(4,37);
    cout<<"CUENTA CONTABLE"<<endl;
    //gotoxy(4,38);
    gotoxy(4,39);
    cout<<"CANTIDAD: "<<endl;
    gotoxy(14,39);
    cin >> _cantidad;
    gotoxy(20,39);
    cout<<"PRECIO: $ "<<endl;
    gotoxy(30,39);
    cin >> _PU;
    float tasa;
    tasa=buscarAlicuota(_idProveedor);
    float IVA;

    IVA=(((_PU*_cantidad)*tasa)/100);
    setIVA(IVA);
    cout << fixed;
    gotoxy(37,39);
    cout<<"IVA: $  "<< setprecision(2) <<getIVA()<<endl;

    _importeTotal=(_PU*_cantidad)+IVA;
    cout << fixed;
    gotoxy(60,39);
    cout<<"TOTAL: $ "<< setprecision(2) <<_importeTotal<< endl;

    */
    setEstadoOP(1);
    resetColor();



}

void OrdenDePago::mostrar()
{




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
void OrdenDePago::listarOrdenesDePago()
{


}
void OrdenDePago::listarOrdenadoFechaConta()
{


}
