#include <iostream>
#include <cstring>
#include <cstdlib>
#include <clocale>
#include <cstdio>
#include <conio.h>
#include <ctime>
#include <iomanip>
#include "Comprobante.h"
#include "Fecha.h"
#include "Impuesto.h"
#include "MediosDePagos.h"
#include "OrdenDePago.h"
#include "PlanDeCuentas.h"
#include "Proveedor.h"
#include "rlutil.h"
#include "Funciones.h"
#include "Reportes.h"
#include "Mensaje.h"
#include "Login.h"

using namespace std;

using namespace rlutil;





int main()
{
    setColor(WHITE);
    setlocale(LC_ALL, "Spanish");
    srand(time(NULL));
    int opcion;

    //ediosDePagos obj;

    //obj.cargarMedios();

    system("cls");

    menuIngreso();

    return 0;


}
