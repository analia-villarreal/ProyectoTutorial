#ifndef PLANDECUENTAS_H
#define PLANDECUENTAS_H

#include "Funciones.h"

class PlanDeCuentas
{
    private:
        int _cuentaContable;
        char _descripcionCuenta[30];
        int _tipoCuenta;
        // 1	RUBRO
        // 2	IMPUTABLE
        // 3	PAGOS VARIOS
        // 4	AUXILIARES
        bool _estadoPlan;

    public:
        PlanDeCuentas();
        PlanDeCuentas(int,const char*,int,bool);
        void setCuentaContable(int);
        void setDescripcionCuenta(const char*);
        void setTipoCuenta(int);
        void setEstado(bool);
        int getCuentaContable();
        const char *getDescripcionCuenta();
        int getTipoCuenta();
        bool getEstadoPlan();
        void cargar();
        void mostrar();
        bool guardarEnDisco();
        void guardarEnDisco(int);
        bool guardarEnDiscoReset();
        bool leerDeDisco(int);
        void listarPlanDeCuentas();

};

#endif // PLANDECUENTAS_H
