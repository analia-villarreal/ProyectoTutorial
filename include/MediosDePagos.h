#ifndef MEDIOSDEPAGOS_H
#define MEDIOSDEPAGOS_H


class MediosDePagos
{
    private:
        int _idMp;
        char _descripcionMedioPago[45];
        bool _estadoMP;


    public:
        //MediosDePagos();
        void setIdMp(int);
        void setDescripcionMedioPago(const char*);
        void setEstadoMP(bool);
        int getIdMedioPago();
        const char * getDescripcionMP();
        bool getEstadoMP();
        bool cargar();
        void cargarMedios();
        void mostrar();
        void listarMediosDePagos();
        bool guardarEnDisco();
        bool leerDeDisco(int);



};

#endif // MEDIOSDEPAGOS_H
