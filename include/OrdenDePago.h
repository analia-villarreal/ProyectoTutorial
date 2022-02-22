#ifndef ORDENDEPAGO_H
#define ORDENDEPAGO_H

#include "Fecha.h"
#include "Impuesto.h"
#include "Proveedor.h"
#include "MediosDePagos.h"


class OrdenDePago
{
    private:
       // OrdenDePago();
        int _idOP;
        Fecha _fechaContabilizacion;
        int _tipoOP;
        int _idProveedor;
        char _razonSocial[45];
        int _numComp;
        float _retIIBB;
        float _retGanancias;
        int _cuentaContable;
        float _importeAPagar;
        float _importeTotal;
        int  _formDePago;
        bool _estadoOP;



    public:

        void setIdOP(int);
        void setFechaContabilizacion(Fecha);
        void setTipoOP(int);
        void setIdProveedor(int);
        void setRetIIBB(float);
        void setRetGanancias(float);
        void setCuentaContable(int);
        void setImporteAPagar(float);
        void setImporteTotal(float);
        void setFormaDePago(int);
        void setEstadoOP(bool);
        int getIdOP();
        int getTipoOP();
        Fecha getFechaContabilizacion();
        int getIdProveedor();
        Proveedor getRazonSocial(int);
        int getNumComp();
        float getRetIIBB();
        float getRetGanancias();
        int getCuentaContable();
        float getImporteAPagar();
        float getImporteTotal();
        bool getEstadoOP();
        void cargar(int);
        void mostrar();
        bool leerDeDisco(int);
        bool guardarEnDisco();
        void guardarEnDisco(int);
        void listarOrdenesDePago();
        void listarOrdenadoFechaConta();
};

#endif // ORDENDEPAGO_H
