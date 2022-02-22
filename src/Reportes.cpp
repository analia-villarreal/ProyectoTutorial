#include "Reportes.h"
#include "Funciones.h"

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <clocale>
#include <cstdio>
#include <conio.h>
#include <ctime>
#include "Comprobante.h"
#include "Fecha.h"
#include "Impuesto.h"
#include "MediosDePagos.h"
#include "OrdenDePago.h"
#include "PlanDeCuentas.h"
#include "Proveedor.h"
#include "rlutil.h"


using namespace std;
using namespace rlutil;


//
//int contarComprobantes(){
//    int bytes, cr;
//    FILE *p;
//    p = fopen("comprobantes.dat", "rb");
//    if (p == NULL)
//    {
//        return 0;
//    }
//    fseek(p, 0, SEEK_END);
//    bytes = ftell(p);
//    cr = bytes / sizeof(Comprobante);
//    fclose(p);
//    return cr;
//}
//
//
//void leerComprobante(Comprobante *vec, int tam){
//    for(int i=0; i<tam; i++){
//        vec[i].leerDeDisco(i);
//    }
//}
//
//
//
//void ordenarComprobante(Comprobante *vec, int tam){
//    int i, j, posMax;
//
//    for(i=0; i<tam-1; i++){
//        posMax = i;
//        for(j=i+1; j<tam; j++){
//            if ( vec[j].getFechaContabilizacion().getMes() > vec[posMax].getFechaContabilizacion().getMes()){
//                posMax = j;
//            }
//        }
//        Comprobante aux = vec[i];
//        vec[i] = vec[posMax];
//        vec[posMax] = aux;
//    }
//}
//
////void listarOrdenadoFechaConta(){
////
////    Comprobante *vec;
////    int i;
////    int cant = contarComprobantes();
////    vec = new Comprobante[cant];
////    if (vec == NULL)
////        return;
////    leerComprobante(vec, cant);
////    ordenarComprobante(vec, cant);
////
////
////   char nom[45]={};
////
////
////
////    cout<< "--------------------------------------------------------------------------------------------------------------------------------------" << endl;
////    cout<< "                                                     LISTADO COMPROBANTES                                                             " << endl;
////    cout<< "--------------------------------------------------------------------------------------------------------------------------------------" << endl;
////
////    cout<< " FECHA CONT ; FECHA COMP ; CODIGO PROVEEDOR ; NOMBRE PROVEEDOR ; TIPO ; COMPROBANTE ; CUENTA CONTABLE ; IMPORTE NETO ; IMPORTE IVA;  TOTAL  "<<endl;
////
////    for (i=0 ;i< cant ; i++){
////
////        locate(1, 3+i);
////        vec[i].getFechaContabilizacion().mostrar();
////        locate(11, 3+i);
////        vec[i].getFechaFactura().mostrar();
////        locate(21, 3+i);
////        vec[i].getIdProveedor();
////        strcpy(nom,buscarNombProv2(vec[i].getIdProveedor()));
////        locate(26, 3+i);
////        cout<<nom;
////        locate(70, 3+i);
////        vec[i].getTipo();
////        locate(73, 3+i);
////        vec[i].getLetra();
////        locate(74, 3+i);
////        vec[i].getPV();
////        locate(78, 3+i);
////        vec[i].getNumFac();
////        locate(87, 3+i);
////        vec[i].getCuentaContable();
////        locate(91, 3+i);
////        float neto=vec[i].getImporteTotal()-vec[i].getIVA();
////        cout<<neto;
////        locate(99, 3+i);
////        vec[i].getIVA();
////        locate(110, 3+i);
////        vec[i].getImporteTotal();
////
////    }
////
////
////}
////
//
