#ifndef FECHA_H
#define FECHA_H

#include <time.h>

class Fecha
{
    private:
        int _dia;
        int _mes;
        int _anio;
    public:
        Fecha(int, int, int);
        Fecha();
        Fecha(const char aux_fec[9]){      /// FECHA POR CADENA
        _dia=((int)aux_fec[0]-48)*10+((int)aux_fec[1]-48);
        _mes=((int)aux_fec[3]-48)*10+((int)aux_fec[4]-48);
        _anio=((int)aux_fec[6]-48)*1000+((int)aux_fec[7]-48)*100+((int)aux_fec[8]-48)*10+((int)aux_fec[9]-48);
        if (_dia<0 || _dia>31){_dia=0; _mes=0; _anio=0;}
        if (_mes<0 || _mes>12){_dia=0; _mes=0; _anio=0;}
        if (_anio<0){_dia=0; _mes=0; _anio=0;}
        };
        void setDia(int d){if (d>0&&d<32)_dia=d;else{_dia=0;}}
        void setMes(int m){if (m>0&&m<13)_mes=m;else{_mes=0;}}
        void setAnio(int a){if (a>1900)_anio=a;else{_anio=0;}}
        int getDia(){return _dia;}
        int getMes(){return _mes;}
        int getAnio(){return _anio;}
        void cargar();
        void mostrar();

};

#endif // FECHA_H
