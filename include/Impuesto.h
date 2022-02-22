#ifndef IMPUESTO_H
#define IMPUESTO_H


class Impuesto
{
    private:
        int _idImpuesto;
        int _tipo;
        int _impuesto;
        char _descripcion[30];
        float _tasa;
        float _minNoImponible;

        //Impuesto:--> ingresos brutos --- ganancias---iva
        // retencion percepcion

        // diferente por impuesto va a ser siempre
        // no lo puedo cargar directo en el proveedor...

        //iibb
        //ganan
        //iva 10.5 iva =0 porque no aplica
        //iva 21
        //iva 0

        //si siis eso entiendo

        // si eso no aplica hago herencia-- no es tan complicado creo solo IVA
        // no no depende el tipo de proveedor


    public:
        Impuesto();
        void setidImpuesto(int);
        void setTipo(int);
        void setImpuesto(int);
        void setDescripcion (char*);
        void setTasa(float);
        void setMinNoImponible(float);
        int getIdImpuesto();
        int getTipo();
        int getImpuesto();
        char *getDescripcion();
        float getTasa();
        float getMinNoImponible();
        void mostrar();
        bool leerDeDisco();
        void cargar();
        bool guardarEnDisco();
        void guardarEnDisco(int);




};

#endif // IMPUESTO_H
