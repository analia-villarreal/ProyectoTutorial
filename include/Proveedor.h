#ifndef PROVEEDOR_H
#define PROVEEDOR_H

#include "Impuesto.h"

class Proveedor
{

    private:
        int _idProveedor;
        char _razonSocial[45];
        int _CUIT;
        int _juridiccion;
        char _nombJuridiccion[20];
        char _categoria[3];
        bool _retIIBB;
        bool _retGanancias; //sisi iva 0 es exento
        int _IVA;
        bool _estadoProveedor;
        // tiene distintos impuestos
        // en una factura tomo el IVA
        // en un orden de pago tomo los codigos de retenciones
        // cargarles id de impuestos que despues calculo en la factura y OP
        // sisisi no me dijeron nada de que no podia hacerlo...

        //las clases asi
        // solo voy a hacer comprobante y proveedor cargar una factura y cargar un proveedor... para la semana que viene..
    public:
        Proveedor();
        Proveedor(int,const char*,int,int,const char*,const char*,bool,bool,int,bool);
        void setIdProveedor(int);
        void setRazonSocial(char*);
        void setCUIT(int);
        void setJuridiccion(int);
        void setNombJu(char*);
        void setCategoria(char*);
        void setRetIIBB(bool);
        void setRetGanancias(bool);
        void setIVA(int);
        void setEstadoProv(bool);
        int getIdProveedor();
        char * getRazonSocial();
        int getCUIT();
        int getJuridiccion();
        char * getNombJur();
        char * getCategoria();
        bool getRetIIBB();
        bool getRetGanancias();
        int  getIVA();//switch cuento entro
        bool getEstadoProv();
        bool cargar();
        void mostrar();
        bool guardarEnDisco();
        void guardarEnDisco(int);
        bool guardarEnDiscoReset();
        bool leerDeDisco();
        bool leerDeDisco(int);

};

#endif // PROVEEDOR_H
