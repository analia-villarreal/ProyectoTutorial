#ifndef COMPROBANTE_H
#define COMPROBANTE_H

#include "Fecha.h"
#include "Impuesto.h"
#include "Proveedor.h"

class Comprobante
{
    private:
        int _idComp;
        char _letra[1];
        Fecha _fechaContabilizacion;
        Fecha _fechaComp;
        int _tipo;
        int _idProveedor;
        int _pv;
        int _numFac;
        int _cuentaContable;
        int _cantidad;
        float _PU;
        float _IVA;
        float _importeTotal;
        int  _estado;
           // 1	ABIERTO
           // 2	ANULADO
           // 3	PAGADO
        char _usuarioLogueado[25];
    public:
        Comprobante();
        Comprobante(int,const char*,Fecha,Fecha,int,int,int,int,int,int,float,float,float,int,const char*);
        void setIdComp(int);
        void setLetra(char*);
        void setFechaContabilizacion(Fecha);
        void setFechaFactura(Fecha);
        void setFecha(Fecha);
        void setTipo(int);
        void setPv(int);
        void setNumFac(int);
        void setCuentaContable(int);
        void setCantidad(int);
        void setPU(float);
        void setIVA(float);
        void setImporteTotal(float);
        void setEstado(int);
        void setUserLog(const char*);
        int getIdComp();
        const char * getLetra();
        Fecha getFechaContabilizacion();
        Fecha getFechaFactura();
        int getTipo();
        int getIdProveedor();
        Proveedor getRazonSocial(int);
        int getPV();
        int getNumFac();
        int getCuentaContable();
        int getCantidad();
        float getPU();
        float getIVA();
        float getImporteTotal();
        int getEstado();
        const char * getUsuarioLog();
        void cargar(int,const char*);
        void mostrar();
        bool leerDeDisco(int);
        bool guardarEnDisco();
        bool guardarEnDiscoReset();
        void guardarEnDisco(int);
        void listarComprobantes();
        void listarOrdenadoFechaConta();
};

#endif // COMPROBANTE_H
