#include "Funciones.h"

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <clocale>
#include <cstdio>
#include <conio.h>
#include <ctime>
#include <iomanip>
#include <fstream>

#include "Comprobante.h"
#include "Fecha.h"
#include "Impuesto.h"
#include "MediosDePagos.h"
#include "OrdenDePago.h"
#include "PlanDeCuentas.h"
#include "Proveedor.h"
#include "rlutil.h"
#include "Reportes.h"
#include "Mensaje.h"
#include "Login.h"


using namespace std;

using namespace rlutil;

void marco_comprobante(int x, int y, int ancho, int alto )
{

    setBackgroundColor(BLACK);
    //cls();
    setColor(LIGHTCYAN);
    int i;
    for(i=x; i<=x+ancho; i++)
    {
        setlocale(LC_ALL, "C");
        gotoxy(i,y);
        printf("\xdB");
        gotoxy(i,y+alto);
        printf("\xdB");
    }


    for(i=y; i<=y+alto; i++)
    {
        setlocale(LC_ALL, "C");
        gotoxy(x,i);
        printf("\xdB");
        gotoxy(x+ancho,i);
        printf("\xdB");


    }

}

const char* buscarNombreMedioDePago(int medio)
{
    MediosDePagos reg;

    int pos;

    pos=buscarPosMP(medio);

    reg.leerDeDisco(pos);

    cout<<" - "<<reg.getDescripcionMP()<<endl;

}

const char* buscarNombreCuentaContable(int cuentaCont)
{
    PlanDeCuentas reg;

    int pos;

    pos=buscarPosCuenta(cuentaCont);

    reg.leerDeDisco(pos);


    cout<<" - "<<reg.getDescripcionCuenta()<<endl;

}
int buscarPosMP(int medio)
{
    MediosDePagos reg;
    int i = 0;
    while(reg.leerDeDisco(i))
    {
        if ( medio == reg.getIdMedioPago())
        {
            return i;
        }
        i++;
    }
    return -1;

}


int buscarPosCuenta(int cuentaCont)
{
    PlanDeCuentas reg;
    int i = 0;
    while(reg.leerDeDisco(i))
    {
        if ( cuentaCont == reg.getCuentaContable())
        {
            return i;
        }
        i++;
    }
    return -1;

}
int contarProveedores()
{
    int bytes, cr;
    FILE *p;
    p = fopen("proveedores.dat", "rb");
    if (p == NULL)
    {
        return 0;
    }
    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    cr = bytes / sizeof(Proveedor);
    fclose(p);
    return cr;
}

int buscarPosProveedor(int idProveedor)
{
    Proveedor reg;
    int i = 0;
    while(reg.leerDeDisco(i))
    {
        if ( idProveedor == reg.getIdProveedor())
        {
            return i;
        }
        i++;
    }
    return -1;

}

bool buscarProveedor(int idProveedor)
{
    Proveedor reg;
    int i = 0;
    while(reg.leerDeDisco(i))
    {
        if ( idProveedor == reg.getIdProveedor())
        {
            return true;
        }
        i++;
    }
    return false;
}

char* buscarNombProv2(int idProveedor)
{
    Proveedor reg;

    int pos;

    pos=buscarPosProveedor(idProveedor);

    reg.leerDeDisco(pos);

    return reg.getRazonSocial();

}

void buscarNombProveedor(int idProveedor)
{
    Proveedor reg;

    int pos;

    pos=buscarPosProveedor(idProveedor);

    reg.leerDeDisco(pos);

    cout<<""<<reg.getRazonSocial()<<endl;


}

void buscarFacturasProveedor(int idProveedor)
{

    Comprobante reg;

    int i = 0;

    while(reg.leerDeDisco(i))
    {
        if ( idProveedor == reg.getIdProveedor())
        {
            if(reg.getNumFac()!=0)
            {

                gotoxy(12,21+i);
                cout<<reg.getPV()<<"-"<< reg.getNumFac()<<"="<<reg.getImporteTotal();
                cout<<endl;
            }
        }

        i++;
    }

}

bool sinRepetidos(int n, int vec[])
{

    for(int i=0; i<5; i++)
    {
        if(n == vec[i])
        {
            return true;
        }

    }
    return false;
}

bool sinRepetidosDiez(int n, int vec[])
{

    for(int i=0; i<10; i++)
    {
        if(n == vec[i])
        {
            return true;
        }

    }
    return false;
}

void rand_proveedores()
{

    int vecNum[5]= {};

    int prov;

    prov = contarProveedores();

    int i=0;
    int valor;

    while(i<5)
    {

        valor=rand()%prov+1;
        while(sinRepetidos(valor,vecNum)==false)
        {
            vecNum[i]=valor;
            i++;
        }

    }

    for(int j=0; j<5; j++)
    {
        Proveedor reg;

        int pos;

        pos=buscarPosProveedor(vecNum[j]);

        reg.leerDeDisco(pos);
        rlutil::locate(83, 26+j);
        cout<<vecNum[j]<<" - "<< reg.getRazonSocial()<<" - "<<reg.getCategoria()<<endl;

    }

}

void rand_proveedoresOP()
{

    int vecNum[10]= {};

    int prov;

    prov = contarProveedores();

    int i=0;
    int valor;

    while(i<10)
    {

        valor=rand()%prov+1;
        while(sinRepetidosDiez(valor,vecNum)==false)
        {
            vecNum[i]=valor;
            i++;
        }

    }

    for(int j=0; j<10; j++)
    {
        Proveedor reg;

        int pos;

        pos=buscarPosProveedor(vecNum[j]);

        reg.leerDeDisco(pos);
        rlutil::locate(85,26+j);
        cout<<vecNum[j]<<" - "<< reg.getRazonSocial()<<" - "<<reg.getCategoria()<<endl;

    }

}



void rand_cuentas_contables()
{



    int vecCuentas[31]={11244,11311,11321,12214,12221,12231,12241,12251,5333,5334,5351,5354,5363,5367,5369,53611,53610,5371,5384,5388,5389,53111,53112,53114,53115,53116,53117,53119,53125,53135,53139};


    for(int j=0; j<31; j++)
    {
        PlanDeCuentas reg;

        int pos;

        pos=buscarPosCuenta(vecCuentas[j]);

        reg.leerDeDisco(pos);
        rlutil::locate(83,36+j);
        cout<<vecCuentas[j]<<" - "<< reg.getDescripcionCuenta()<<endl;

    }



}

void listarProveedores()
{
    int i=0;
    Proveedor reg;

    cout << left;
    cout << setw(6)  << "CODIGO";
    cout << setw(50) << "   NOMBRE";
    cout << setw(30) << "CATEGORIA";
    cout << setw(33) << "ESTADO"<<endl;

    while(reg.leerDeDisco(i))
    {


        reg.mostrar();
        //cout << endl;
        i++;


    }
}
bool soloNumeros(const char *cadena)
{
    int i=0;
    while(cadena[i] != '\0')
    {
        if(!(cadena[i] >= '0' && cadena[i] <= '9'))
        {
            return false;
        }
        i++;
    }
    return true;
}

float buscarAlicuota(int idProveedor)
{

    Proveedor reg;

    int pos;

    int ali;

    pos=buscarPosProveedor(idProveedor);


    while(reg.leerDeDisco(pos))
    {


        int  ali=reg.getIVA();

        if(ali=1)
        {
            return 21;
        }
        if(ali=2)
        {
            return 10.5;
        }
        if(ali=3)
        {
            return 0;
        }

        if(ali=4)
        {
            return 27;
        }

    }
    return -1;
}

int buscarFacturasDarDeBaja(int num, int pv, int prov){

    Comprobante reg;

    int i=0;

    while(reg.leerDeDisco(i))
    {
        if(num == reg.getNumFac() && pv == reg.getPV() && prov == reg.getIdProveedor())
        {
            return i;
        }
        i++;
    }

    return -1;//NUNCA ENCONTRO EL REGISTRO

}

void menuComprobante()
{

    Comprobante reg;
    int opc;
    int num;
    int pv;
    int prov;
    int pos;
    while(true)
    {
        system("cls");
        gotoxy(40,5);cout << "-----MENU COMPROBANTES-----" << endl;
        gotoxy(40,6);cout << "---------------------------" << endl;
        gotoxy(40,7);cout << "1. ALTA COMPROBANTE"         << endl;
        gotoxy(40,8);cout << "2. BAJA COMPROBANTE"         << endl;
        gotoxy(40,9);cout << "3. LISTAR COMPROBANTES"      << endl;
        gotoxy(40,10);cout << "0. VOLVER AL MENU PRINCIPAL" << endl;
        gotoxy(40,11);cout << "- SELECCIONE UNA OPCION: - " << endl;
        gotoxy(40,12);cout << "---------------------------" << endl;
        gotoxy(40,13);cout<<" > ";cin>>opc;
        system("cls");
        switch(opc)
        {
        case 1:
            int tipoComp;
            Login user;
            gotoxy(40,5);
            cout << "Factura: 1  Nota de Crédito: 2"<< endl;
            gotoxy(40,6);
            cout<<" > ";
            cin>>tipoComp;
            system("cls");
            reg.cargar(tipoComp,user.getUsuarioChar());
            if(reg.getEstado()==true)
            {
                if(reg.guardarEnDisco()==true)
                {
                    gotoxy(4,55);
                    cout<<"REGISTRO GRABADO EN EL ARCHIVO"<<endl;
                    resetColor();
                }
                else
                {
                    gotoxy(4,55);
                    cout<<"NO SE PUDO GRABAR EL REGISTRO"<<endl;
                    resetColor();
                }
            }
            else
            {
                cout<<"ERROR DE DATOS";
            }
            gotoxy(4,56);
            system("pause");
            break;
        case 2:
            gotoxy(40,5);cout << "INGRESE CODIGO DE PROVEEDOR ,  PV y FACTURA A DAR DE BAJA: "<<endl;
            gotoxy(40,5);cout << "***********************************************************"<<endl;
            gotoxy(40,7);cout<<"CODIGO PROVEEDOR: "<<endl;
            gotoxy(60,7);cin >> prov;
            gotoxy(40,8);cout<<"PUNTO DE VENTA: "<<endl;
            gotoxy(60,8);cin >> pv ;
            gotoxy(40,9);cout<<"NUMERO FACTURA: "<<endl;
            gotoxy(60,9);cin >> num ;

            pos = buscarFacturasDarDeBaja(num,pv,prov);
            if(pos >= 0)
            {
                reg.leerDeDisco(pos);
                int estado;
                if(reg.getEstado()==1)
                {
                    gotoxy(40,10);cout << "ESTADO ACTUAL: ACTIVO" << endl;
                }
                else{
                    gotoxy(40,10);cout << "ESTADO ACTUAL: ANULADO" << endl;
                }
                gotoxy(40,12);cout << "DESEA DARLO DE BAJA? (1: NO / 2: SI) ";
                gotoxy(80,12);cin >> estado;
                reg.setEstado(estado);
                reg.guardarEnDisco(pos);
                gotoxy(40,13);cout << "REGISTRO DADO DE BAJA" << endl;

            }
            else
            {
                gotoxy(40,15);cout << "NO EXISTE LO BUSCADO" << endl;
            }
            system("pause");
            break;
        case 3:
            reg.listarComprobantes();
            system("pause");
            break;
        case 0:
            return;
            break;
        default:
            cout<<" OPCION INCORRECTA"<<endl;
            break;
        }
    }

}

void menuProveedor()
{
    Proveedor reg1;
    int opc;
    while(true)
    {
        system("cls");
        gotoxy(40,5);cout << "-----MENU PROVEEDOR--------" << endl;
        gotoxy(40,6);cout << "---------------------------" << endl;
        gotoxy(40,7);cout << "1. ALTA PROVEEDOR          " << endl;
        gotoxy(40,8);cout << "2. BAJA PROVEEDOR          " << endl;
        gotoxy(40,9);cout << "3. LISTAR PROVEDORES       " << endl;
        gotoxy(40,10);cout << "0. VOLVER AL MENU PRINCIPAL" << endl;
        gotoxy(40,11);cout << "- SELECCIONE UNA OPCION: - " << endl;
        gotoxy(40,12);cout << "---------------------------" << endl;
        gotoxy(40,13);cin>>opc;
        system("cls");
        switch(opc)
        {
        case 1:
            reg1.cargar();
            if(reg1.getEstadoProv()==true)
            {
                if(reg1.guardarEnDisco()==true)
                {
                    cout<<"REGISTRO GRABADO EN EL ARCHIVO"<<endl;
                }
                else
                {
                    cout<<"NO SE PUDO GRABAR EL REGISTRO"<<endl;
                }
            }
            else
            {
                cout<<"ERROR DE DATOS"<<endl;
            }
            system("pause");
            break;
        case 2:
            bajaProveedor();
            system("pause");
            break;
        case 3:
            listarProveedores();
            system("pause");
            break;
        case 0:
            return;
            break;
        default:
            cout<<" OPCION INCORRECTA"<<endl;
            break;
        }
    }

}

void menuPlandeCuentas()
{
    PlanDeCuentas obj;
    int opc;
    while(true)
    {
        system("cls");
        gotoxy(40,5);cout << "--------MENU PLAN DE CUENTAS--------" << endl;
        gotoxy(40,6);cout << "------------------------------------" << endl;
        gotoxy(40,7);cout << "1. ALTA CUENTA CONTABLE             " << endl;
        gotoxy(40,8);cout << "2. DESACTIVAR CUENTA CONTABLE       " << endl;
        gotoxy(40,9);cout << "3. LISTAR PLAN DE CUENTAS           " << endl;
        gotoxy(40,10);cout << "0. VOLVER AL MENU PRINCIPAL         " << endl;
        gotoxy(40,11);cout << "- SELECCIONE UNA OPCION: -          " << endl;
        gotoxy(40,12);cout << "------------------------------------" << endl;
        gotoxy(40,13);cout<<" >  ";cin>>opc;
        system("cls");
        switch(opc)
        {
        case 1:
            obj.cargar();
            if(obj.getEstadoPlan()==true)
            {
                if(obj.guardarEnDisco()==true)
                {
                    cout<<"REGISTRO GRABADO EN EL ARCHIVO"<<endl;
                }
                else
                {
                    cout<<"NO SE PUDO GRABAR EL REGISTRO"<<endl;
                }
            }
            else
            {
                cout<<"ERROR DE DATOS"<<endl;
            }
            system("pause");
            break;
        case 2:
        //BAJA PROVEEDOR;
        case 3:
            obj.listarPlanDeCuentas();
            system("pause");
            break;
        case 0:
            return;
            break;
        default:
            cout<<" OPCION INCORRECTA"<<endl;
            break;
        }
    }

}

void menuOP()
{
    OrdenDePago regis;
    int opc;
    while(true)
    {
        system("cls");
        gotoxy(40,5);cout << "-----MENU ORDENES DE PAGO -----" << endl;
        gotoxy(40,6);cout << "-------------------------------" << endl;
        gotoxy(40,7);cout << "1. ALTA                        " << endl;
        gotoxy(40,8);cout << "2. BAJA                        " << endl;
        gotoxy(40,9);cout << "3. LISTAR                      " << endl;
        gotoxy(40,10);cout << "0. VOLVER AL MENU PRINCIPAL   " << endl;
        gotoxy(40,11);cout << "- SELECCIONE UNA OPCION: -    " << endl;
        gotoxy(40,12);cout << "------------------------------" << endl;
        gotoxy(40,13);cout<<" > ";cin>>opc;
        system("cls");

        switch(opc)
        {
        case 1:
            int tipoOP;
            gotoxy(40,5);
            cout << "REALIZAR PAGOS "<< endl;
            gotoxy(40,5);
            cout << "PAGOS VARIOS : 1  PAGO A PROVEEDOR: 2"<< endl;
            gotoxy(40,6);
            cout<<" > ";
            cin>>tipoOP;
            system("cls");
            regis.cargar(tipoOP);
            if(regis.getEstadoOP()==true)
            {
                if(regis.guardarEnDisco()==true)
                {
                    gotoxy(4,41);
                    cout<<"REGISTRO GRABADO EN EL ARCHIVO"<<endl;
                    resetColor();
                }
                else
                {
                    gotoxy(4,41);
                    cout<<"NO SE PUDO GRABAR EL REGISTRO"<<endl;
                    resetColor();
                }
            }
            else
            {
                cout<<"ERROR DE DATOS"<<endl;
            }
            gotoxy(4,42);
            system("pause");
            break;
        case 2:
            //BAJA COMPROBANTE;
            MediosDePagos obj;
        case 3:
            obj.listarMediosDePagos();
            system("pause");
            break;
        case 0:
            return;
            break;
        default:
            cout<<" OPCION INCORRECTA"<<endl;
            break;
        }
    }

}

void bajaProveedor()
{

    int i=0, idProv, opc;
    char *cpynombre;

    cout << "------------- LISTA DE PROVEEDORES A DAR DE BAJA ---------------" << endl;

    listarProveedores();

    cout << "SELECCIONE EL CODIGO DEL PROVEEDOR QUE DESEE DAR DE BAJA: ";

    cin >> idProv;

    //while(idProv > contarProveedores()){
    //    cout << "EL CODIGO DEL PROVEEDOR NO EXISTE." << endl;
    //    cout << "POR FAVOR INGRESE OTRO CODIGO DE PROVEEDOR: ";
    //    cin >> idProv;
    //}

    char nom[45]= {};
    strcpy(nom,buscarNombProv2(idProv));

    cout << "EL PROVEEDOR " << nom << " SE ESTA POR DAR DE BAJA. ESTA SEGURO? ";
    cout << " 1 / SI  --  2 / NO" << endl;
    cin >> opc;
    Proveedor reg2;
    if(opc == 1)
    {

        int pos;
        pos=buscarPosProveedor(idProv);
        reg2.leerDeDisco(pos);
        reg2.setEstadoProv(false);
        reg2.guardarEnDisco(pos);

        cout << "EL PROVEEDOR SE DIO DE BAJA" << endl;


    }
    else return;

}


void menuPrincipal(){

    setColor(WHITE);
    setlocale(LC_ALL, "Spanish");
    int opcion;

    //ediosDePagos obj;

    //obj.cargarMedios();

    system("cls");

    do
    {
        gotoxy(40,5);cout << "----PAGO A PROVEEDORES--------"<< endl;
        gotoxy(40,6);cout << "--EMPECEMOS A PRACTICAR-------"<< endl;
        gotoxy(40,7);cout << "------------------------------"<< endl;
        gotoxy(40,8);cout << "1. MENU COMPROBANTE          "<< endl;
        gotoxy(40,9);cout << "2. MENU PROVEEDOR            "<< endl;
        gotoxy(40,10);cout << "3. MENU PLAN DE CUENTAS      "<< endl;
        gotoxy(40,11);cout <<"4. MENU ORDENES DE PAGO       "<< endl;
        gotoxy(40,12);cout <<"5. MENU LISTADOS Y CONSULTAS "<< endl;
        gotoxy(40,13);cout <<"6. RESETEAR DATOS            "<< endl;
        gotoxy(40,14);cout <<"0. FIN DEL PROGRAMA          "<< endl;
        gotoxy(40,15);cout <<"- SELECCIONE UNA OPCION: -   "<< endl;
        gotoxy(40,16);cout <<"------------------------------"<< endl;
        gotoxy(40,17);cout<<" > ";cin>>opcion;


        system("cls");

        switch(opcion)
        {
        case 1:menuComprobante();
            break;
        case 2:menuProveedor();
            break;
        case 3:menuPlandeCuentas();
            break;
        case 4:menuOP();
            break;
        case 5:listarProveedores();
            break;
        case 6:resetTablas();
            break;
        }
        system("pause");
        system("cls");


    }
    while(opcion != 0);

}

void menuIngreso(){

    setColor(WHITE);
    setlocale(LC_ALL, "Spanish");
    int opcion;

    system("cls");

    do
    {
        gotoxy(40,5);cout << "--------CAPACITAR--------------"<< endl;
        gotoxy(40,6);cout << "--CREA UN USUARIO Y LOGUEATE---"<< endl;
        gotoxy(40,7);cout << "-------------------------------"<< endl;
        gotoxy(40,8);cout << "1. REGISTRARSE                 "<< endl;
        gotoxy(40,9);cout << "2. LOGUEARSE                   "<< endl;
        gotoxy(40,10);cout <<"0. FIN DEL PROGRAMA            "<< endl;
        gotoxy(40,12);cout <<"- SELECCIONE UNA OPCION: -     "<< endl;
        gotoxy(40,13);cout <<"-------------------------------"<< endl;
        gotoxy(40,14);cout<<" > ";cin>>opcion;


        system("cls");

        switch(opcion)
        {
        case 1:crearUsuario();
            break;
        case 2:ingresarUsuario();
            break;
        }
        system("pause");
        system("cls");
    }
    while(opcion != 0);


}

void crearUsuario(){

    Login log;
    bool repetido=false;
    int  i=0;
    char usuario[25];

    gotoxy(40,5);cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
    setColor(RED);
    gotoxy(40,6);cout << "NOTA: EL CODIGO Y EL USUARIO !!NO¡¡ SE PODRA MODIFICAR EN UN FUTURO";
    setColor(WHITE);
    gotoxy(40,7);cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
    gotoxy(40,8);cout << "-----------------------------------------------";
    gotoxy(40,9);cout << "----------CREANDO UN USUARIO-------------------";
    gotoxy(40,10);cout << "              **              ";
    gotoxy(40,11);cout << "INGRESE NOMBRE DE USUARIO (SIN ESPACIOS):    ";

    cin >> usuario;

    while(log.leerDeDisco(i)){
            if(strcmp(log.getUsuarioChar(),usuario)== 0){
                system("cls");
                gotoxy(40,12); cout << "LO SENTIMOS. EL USUARIO YA SE ENCUENTRA EN USO.";
                repetido = true;
                system("pause");
                return;
            }
        i++;
    }
    if(repetido == false){

        log.setUsuario(usuario);
        log.cargar();
        log.guardarEnDisco();
        system("cls");
        gotoxy(40,15);cout << "USUARIO GUARDADO EXITOSAMENTE!!" << endl;

    }

    log.setCodigoUser(crearCodigoUsuario(log.getUsuarioChar()));
}

int crearCodigoUsuario(const char *user){

    Login reg;
    int codigo;
    int i = 0;
    while(reg.leerDeDisco(i))
    {
        if (strcmp(reg.getUsuarioChar(),user) == 0)
        {
           codigo=i;
           reg.setCodigoUser(codigo);
        }
        i++;
    }
    return -1;

}

void ingresarUsuario()
{
    system("cls");

    Login log;
    int i = 0;
    bool si;
    char usuario[15], contrasenia[15];

    gotoxy(40,20);cout<<"INGRESE USUARIO: ";
    cin.ignore();
    cin.getline(usuario, 15);
    gotoxy(41,22);cout<<"INGRESE CONTRASENIA: ";
    //claveOculta(contrasenia);
    cin.ignore();
    cin.getline(contrasenia, 15);

        while(log.leerDeDisco(i)){

                if((strcmp(usuario,log.getUsuarioChar())==0) && (strcmp(contrasenia,log.getPasswordChar())==0)){

                    system("cls");
                    si = true;
                    gotoxy(80,23);cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
                    gotoxy(98,25);cout << "BIENVENIDO !! ** "<< log.getUsuario() << " **"<< endl;
                    gotoxy(80,27);cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
                    anykey();
                    menuPrincipal();
                }

            if(si == false){

                system("cls");
                gotoxy(85,23);cout << "INCORRECTO. INTENTELO NUEVAMENTE." << endl;
            }
            i++;
        }
}

void resetTablas(){

Proveedor reg1(1,"2MS",30708909382,902,"Buenos Aires","EX",1,0,1,1);
Proveedor reg2(2,"A MUTZ Y CIA SOC ANONIMA",30633340494,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg3(3,"ABBOUD MARCELO BANAIOT",23167297269,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg4(4,"ACG AIRE S.R.L",30715224913,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg5(5,"ACQUATRON S A",30686422174,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg6(6,"AEROPUERTOS ARGENTINA 2000 SA",30696170580,901,"C.A.B.A.","RI",1,1,1,1);
Proveedor reg7(7,"AIR LIQUIDE ARGENTINA",30500852131,902,"Buenos Aires","EX",1,0,1,1);
Proveedor reg8(8,"AKRIBIS S.R.L",30708510978,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg9(9,"AL EQUIPOS Y SERVICIOS S.R.L.",30714403431,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg10(10,"ALBORNOZ DOMINGO ANATOLIO",20218121102,902,"Buenos Aires","MT",0,0,3,1);
Proveedor reg11(11,"ALEJANDRO RODRIGUEZ ERAÑA",23165817389,902,"Buenos Aires","EX",1,0,1,1);
Proveedor reg12(12,"ALLIANZ ARGENTINA SEGUROS",30500037217,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg13(13,"AMERICAN EXPRESS ARGENTINA SA",30574816870,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg14(14,"ANADELIA S.A.",30655114226,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg15(15,"ANGEL LARREINA S.A.C.I.F.I.A.",30515694087,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg16(16,"ANPAS SA",30646331389,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg17(17,"ANSAL REFRIGERACION SA",30516712593,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg18(18,"AQUAREP SRL",30712022368,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg19(19,"ARFILTER S.A.",30712028188,901,"C.A.B.A.","RI",1,1,1,1);
Proveedor reg20(20,"ARGIMED SRL",30708072822,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg21(21,"ARGONTECH SRL",30684968218,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg22(22,"ARIAS PABLO GERARDO",20222641137,901,"C.A.B.A.","EX",1,0,1,1);
Proveedor reg23(23,"ARISTOBULO GOMEZ RUNCREZ SA",30602846063,901,"C.A.B.A.","RI",1,1,1,1);
Proveedor reg24(24,"ARQUETIPONET S.R.L.",30711751994,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg25(25,"ARVITEC SRL",30636922621,924,"Tucuman","RI",1,1,1,1);
Proveedor reg26(26,"ASISTHOS S.R.L.",30652873274,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg27(27,"ASC CIVIL DE PROF PARA LA EQUIDAD ASPPE",30710846797,902,"Buenos Aires","EX",1,0,3,1);
Proveedor reg28(28,"ASPRIUS TECHNOLOGY ARGENTINA S.A.",33708055889,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg29(29,"ATLAS COPCO ARGENTINA S.A.",30515666148,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg30(30,"AySA SA",30709565075,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg31(31,"B M WEB S.A.",30715012835,901,"C.A.B.A.","RI",1,1,1,1);
Proveedor reg32(32,"BALSEIRO DANIEL EMILIO",20139330588,901,"C.A.B.A.","EX",1,0,1,1);
Proveedor reg33(33,"Bamay Construcciones SRL",30716854961,901,"C.A.B.A.","RI",1,1,1,1);
Proveedor reg34(34,"BANCO CREDICOOP",30571421352,902,"Buenos Aires","RI",1,1,2,1);
Proveedor reg35(35,"BANCO GALICIA",30500001735,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg36(36,"BANCO MERIDIAN",30534487491,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg37(37,"BANCO SUPERVIELLE",33500005179,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg38(38,"BARREDA JUAN MANUEL",20284886918,902,"Buenos Aires","EX",1,0,1,1);
Proveedor reg39(39,"BBTEL  BROADBANDTECH S.A.",30707291768,902,"Buenos Aires","RI",1,1,4,1);
Proveedor reg40(40,"BEZRUK VALERIA DEBORA",27318278283,901,"C.A.B.A.","RI",1,1,1,1);
Proveedor reg41(41,"BIO ESANCO SA",30708496096,901,"C.A.B.A.","RI",1,1,1,1);
Proveedor reg42(42,"BIO FUCAL S.A",30709120243,901,"C.A.B.A.","RI",1,1,1,1);
Proveedor reg43(43,"BIOARTIS S.R.L.",30696703058,901,"C.A.B.A.","RI",1,1,1,1);
Proveedor reg44(44,"Biomicro, s.a.",33710843819,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg45(45,"BIONDI ALBERTO LUCIANO",20112511521,902,"Buenos Aires","EX",1,0,1,1);
Proveedor reg46(46,"BIOSAFE SRL",30694602947,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg47(47,"BIOTECHNO PHARMA SA",30709594512,902,"Buenos Aires","RI",1,1,3,1);
Proveedor reg48(48,"BITZER COMPRESSORES S.A.",30691167603,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg49(49,"BLUE SOLUTION S.R.L.",30711505454,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg50(50,"BLUES WATER SRL",30710189184,901,"C.A.B.A.","RI",1,1,1,1);
Proveedor reg51(51,"BOREX S.R.L.",30715533800,901,"C.A.B.A.","RI",1,1,1,1);
Proveedor reg52(52,"BRAVER HERNAN",20257708781,901,"C.A.B.A.","MT",1,0,1,1);
Proveedor reg53(53,"BRIGHINA LAURA SILVIA",20224566507,901,"C.A.B.A.","EX",1,0,1,1);
Proveedor reg54(54,"BSD SUR S.A.",30715833359,901,"C.A.B.A.","RI",1,1,1,1);
Proveedor reg55(55,"BUMERAN.COM ARGENTINA SA",30706053812,901,"C.A.B.A.","RI",1,1,1,1);
Proveedor reg56(56,"BURCET NANNETTE MARCELA",27190559802,901,"C.A.B.A.","RI",1,1,1,1);
Proveedor reg57(57,"BYMAR TRANSFORWARDING SRL",30714084433,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg58(58,"CALVET CELIA ALICIA",27133043077,902,"Buenos Aires","EX",1,0,1,1);
Proveedor reg59(59,"CAMARA DE EXPO DE LA REPUBLICA ARGENTINA",30525522454,902,"Buenos Aires","EX",1,0,3,1);
Proveedor reg60(60,"CAÑOS PLAZA SRL",30504817381,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg61(61,"CAROSIO ROSANA BEATRIZ",23168773684,901,"C.A.B.A.","RI",1,1,1,1);
Proveedor reg62(62,"CARPE SCHEIDER Y CIA S.A",30624460444,901,"C.A.B.A.","RI",1,1,1,1);
Proveedor reg63(63,"CARTOBOX S.R.L.",30597048617,901,"C.A.B.A.","RI",1,1,1,1);
Proveedor reg64(64,"CARUBELLO MARISA ALEJANDRA",27221473596,901,"C.A.B.A.","MT",1,0,1,1);
Proveedor reg65(65,"CAS ANALITICA SRL",30711698171,901,"C.A.B.A.","RI",1,1,1,1);
Proveedor reg66(66,"CASIBA SA",30502893188,901,"C.A.B.A.","RI",1,1,1,1);
Proveedor reg67(67,"CAUSA NICOLAS",20280815552,901,"C.A.B.A.","MT",1,0,1,1);
Proveedor reg68(68,"CAUSA RAUL",20045297307,901,"C.A.B.A.","MT",0,0,1,1);
Proveedor reg69(69,"CAVALA SRL",30715913859,901,"C.A.B.A.","RI",1,1,1,1);
Proveedor reg70(70,"CENCOSUD S.A",30590360763,901,"C.A.B.A.","RI",1,1,1,1);
Proveedor reg71(71,"CENTRAL QUIMICA ARGENTINA S.A",30636174439,901,"C.A.B.A.","RI",1,1,1,1);
Proveedor reg72(72,"CHARTER LINK LOGISTICS S.A.",30716299909,901,"C.A.B.A.","RI",1,1,1,1);
Proveedor reg73(73,"CHEMIT ARGENTINA S.R.L.",30707509356,901,"C.A.B.A.","RI",1,1,1,1);
Proveedor reg74(74,"CHUTRAU S A C I F",33566734589,901,"C.A.B.A.","RI",1,1,1,1);
Proveedor reg75(75,"CITILAN ARGENTINA S.A",30707135596,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg76(76,"CITY MEDICAL SERVICE S.A.",30610770432,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg77(77,"CLEANTECH SA",30703846447,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg78(78,"CLIMATIZACION INTEGRAL SRL",30707938753,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg79(79,"Clinica Nano S.A.",33710144309,905,"Cordoba","RI",1,1,1,1);
Proveedor reg80(80,"CLOVER TEAM S.A.",33709901449,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg81(81,"COLORCON SA",30691187809,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg82(82,"CONDOLEO DIEGO MARTIN",20259876428,902,"Buenos Aires","MT",1,0,1,1);
Proveedor reg83(83,"COOPERALA",30541078181,916,"Rio Negro","EX",0,0,1,1);
Proveedor reg84(84,"COOPERATIVA DE TRABAJO TER BARRACAS LTD",30716550059,902,"Buenos Aires","EX",1,0,1,1);
Proveedor reg85(85,"CORONADO MARIANA",27254405561,902,"Buenos Aires","EX",1,0,1,1);
Proveedor reg86(86,"CRODA ARGENTINA S.A.",30701019268,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg87(87,"CROSSRACER INTERNATIONAL SA",30656182152,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg88(88,"D AMICO SISTEMAS SA",30687806324,916,"Rio Negro","RI",1,1,1,1);
Proveedor reg89(89,"DACHER ARGENTINA SA",33707955959,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg90(90,"DE ARACIL JOEL ERNESTO",20386143863,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg91(91,"DE LEO ANA MARIA",27127099745,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg92(92,"DELESCABE CLAUDIO DANIEL",20146209492,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg93(93,"DEVOTO MATIAS MARTIN",20251274674,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg94(94,"DF OFFICE S.R.L.",30711275106,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg95(95,"DHL EXPRESS ARGENTINA S.A",30580111315,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg96(96,"DI PULIZIA S.A.",30715812777,905,"Cordoba","RI",1,1,1,1);
Proveedor reg97(97,"DIFFERENT FOODS COMPANY S.A.",30714524433,905,"Cordoba","RI",1,1,1,1);
Proveedor reg98(98,"DIMPACK SRL",30713141409,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg99(99,"DINORTE INSTRUMENTAL S.A.",30715080962,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg100(100,"DISPROFARMA SA",30589508072,916,"Rio Negro","RI",1,1,1,1);
Proveedor reg101(101,"DOLZ HNOS SRL",30504603446,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg102(102,"DOMINGUEZ OMAR ANTONIO",20180786105,902,"Buenos Aires","MT",1,0,1,1);
Proveedor reg103(103,"DONATI CLAUDIO FABIAN",20145644683,902,"Buenos Aires","MT",1,0,1,1);
Proveedor reg104(104,"DONATO ZURLO Y CIA S.R.L.",30503381407,916,"Rio Negro","RI",0,1,1,1);
Proveedor reg105(105,"DONOLO CARLOS",20076050555,902,"Buenos Aires","MT",1,0,3,1);
Proveedor reg106(106,"DORWIL",30578695717,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg107(107,"DROGUERIA BEIRÓ S.R.L",30557794855,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg108(108,"ECOPEL SRL",30709718270,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg109(109,"ECOTEC CONSULTORES S.A.",30686203324,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg110(110,"EDENOR",30655116202,902,"Buenos Aires","RI",1,1,4,1);
Proveedor reg111(111,"EDGAR FEDERICO PAPALEO",20312271800,905,"Cordoba","RI",1,1,1,1);
Proveedor reg112(112,"ELECTRO FLEMING SRL",33711211379,905,"Cordoba","RI",1,1,1,1);
Proveedor reg113(113,"ELECTRO POINT",20359718765,905,"Cordoba","RI",1,1,1,1);
Proveedor reg114(114,"EMAKI LOGISTICA",20332482328,902,"Buenos Aires","MT",1,0,1,1);
Proveedor reg115(115,"EMF S.R.L.",30710369980,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg116(116,"EMIVA SOLUTIONS S.A",30714452092,916,"Rio Negro","RI",1,1,1,1);
Proveedor reg117(117,"ENDOLAB S.A.",30715419382,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg118(118,"ENVASES DEL PLATA S A",30680823185,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg119(119,"ENVITAP S.A.",30582618409,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg120(120,"EQUIFAX ARGENTINA S.A",30519739115,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg121(121,"ESCRIBANIA NARDELLI MIRA",20167679480,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg122(122,"ESTRUCTURAS CIENTIFICAS S.A.",30710881363,916,"Rio Negro","RI",1,1,1,1);
Proveedor reg123(123,"ESTUDIO SALVOCHEA ABOGADOS SRL",30710994559,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg124(124,"ETICOR SA",30698355464,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg125(125,"ETILFARMA S.A",30618289318,905,"Cordoba","RI",1,1,1,1);
Proveedor reg126(126,"EUROLAB",30645887111,905,"Cordoba","EX",1,0,1,1);
Proveedor reg127(127,"F.P. CLINICAL PHARMA SRL",33707614469,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg128(128,"FACULTAD DE FARMACIA Y BIOQUIM",30546666561,902,"Buenos Aires","EX",1,0,3,1);
Proveedor reg129(129,"FAMIQ SRL",30538068841,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg130(130,"FARMA PACKING S.A",30708926716,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg131(131,"FARMALINK SA",30683107677,916,"Rio Negro","RI",1,1,1,1);
Proveedor reg132(132,"FARMAWALL S.R.L.",30714380393,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg133(133,"FEDAGUSMARSAN S.R.L.",30712169660,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg134(134,"FEDERAL EXPRESS CORPORATION",30594494187,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg135(135,"FEDERICO ESTEBAN HERNANDEZ",23205855459,902,"Buenos Aires","EX",1,0,1,1);
Proveedor reg136(136,"FEENSTRA EDUARDO F.",20100875919,902,"Buenos Aires","EX",1,0,1,1);
Proveedor reg137(137,"FERNANDEZ CONTE MACARENA SOLEDAD",27315264605,902,"Buenos Aires","EX",1,0,1,1);
Proveedor reg138(138,"FERNANDEZ PABLO AGUSTIN",27310004605,916,"Rio Negro","MT",0,0,3,1);
Proveedor reg139(139,"FERRETERIA INDUSTRIAL TC S.R.L",30709985961,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg140(140,"FERROMET SA",33519697969,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg141(141,"FLEKENSTEIN ANGELINA INES",27140903588,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg142(142,"FONTANA GUIDO ERNESTO",20217102287,916,"Rio Negro","MT",0,0,3,1);
Proveedor reg143(143,"FORINTRA SA",30663507709,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg144(144,"FRADEALCO S.A.",30602608790,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg145(145,"FRANZ ROBERTO CARLOS",23105183119,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg146(146,"FRESCHI SRL",30707926127,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg147(147,"FULL MARK S.A.",30707370471,905,"Cordoba","RI",1,1,1,1);
Proveedor reg148(148,"FUNDACION CIENCIAS EXACTAS Y NATURALES",30653281540,905,"Cordoba","EX",0,0,3,1);
Proveedor reg149(149,"GABRIEL GRILLO",20238334862,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg150(150,"GABRIEL IRIARTE SRL",30709347000,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg151(151,"GALENO ARGENTINA SA",30522428163,902,"Buenos Aires","RI",1,1,3,1);
Proveedor reg152(152,"GARBINI MARIA ANDREA",27134304028,902,"Buenos Aires","MT",1,0,1,1);
Proveedor reg153(153,"GARCIA EDUARDO ROBERTO",20122764975,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg154(154,"GARCIA NESTOR MAXIMILIANO",20304598485,916,"Rio Negro","RI",0,1,1,1);
Proveedor reg155(155,"GAS NATURAL BAN SA",30657864117,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg156(156,"GASES NORDELTA S.A.",30707529896,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg157(157,"GEA GROUP S.R.L",30710360258,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg158(158,"GEMINIS FARMACEUTICA S.A.",30657674296,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg159(159,"GEOPRINTER",20299512305,905,"Cordoba","RI",1,1,1,1);
Proveedor reg160(160,"GERARDO RAMON Y CIA S A I C",30500781986,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg161(161,"GIAMPIETRI GABRIEL OSCAR",20254756416,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg162(162,"GIMENEZ NORBERTO FRANCISCO",20077494465,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg163(163,"GOBBI NOVAG S.A.",30503270230,916,"Rio Negro","RI",0,1,1,1);
Proveedor reg164(164,"GONZALEZ MYRIAM AMALIA",27239028468,902,"Buenos Aires","MT",1,0,1,1);
Proveedor reg165(165,"GORA SA",30504716380,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg166(166,"GRAFICA BASSANO",30716616300,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg167(167,"GRAFIMAG SRL",30710364814,916,"Rio Negro","RI",1,1,1,1);
Proveedor reg168(168,"GRANDINETTI PABLO PATRICIO ALFRE",20230282766,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg169(169,"GREXSE S.A.",30709463272,905,"Cordoba","RI",1,1,1,1);
Proveedor reg170(170,"GRUPO ASAP S.R.L.",30715855816,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg171(171,"GRUPO DIAZAR S.R.L.",30716048043,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg172(172,"GRUPO FELIPA SAS",30716373475,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg173(173,"GRUPO INDUSER SRL",30707887008,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg174(174,"GRUPO LINDE GAS ARGENTINA SA",30501395389,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg175(175,"GRUPO OPERADORES SA",30710814836,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg176(176,"GRUPOS INTEGRADOS S.A.",30710373414,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg177(177,"GULMEZ HARUTUN",20174236764,916,"Rio Negro","RI",0,1,1,1);
Proveedor reg178(178,"GUZNER GUSTAVO VALERIO",20107058665,902,"Buenos Aires","MT",1,0,1,1);
Proveedor reg179(179,"HANDYWAY CARGO SA",30711164932,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg180(180,"HARSANYI EUGENIO CARLOS",23285195039,902,"Buenos Aires","MT",1,0,3,1);
Proveedor reg181(181,"HERRAJES PATRICIOS SA",30687829669,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg182(182,"HIPPO CARGAS S.A.",30715195123,905,"Cordoba","RI",1,1,1,1);
Proveedor reg183(183,"HIXWER ARGENTINA S.A.",30715152920,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg184(184,"HOTEL SAN ISIDRO ALTO S. R. L.",30714641545,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg185(185,"IDENOR INGENIERIA SRL",33584584179,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg186(186,"IMPORT VELEZ SRL",30608100985,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg187(187,"IMPRENTA SEGBER SA",30688995384,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg188(188,"INDUSTRIA SEGUTEK S.A.",30710950470,916,"Rio Negro","RI",1,1,1,1);
Proveedor reg189(189,"Industrial Print & Labels Arg",30708325232,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg190(190,"INDUSTRIAS BELLMOR S.A.",30707741321,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg191(191,"INDUSTRIAS HOGNER",30515579687,905,"Cordoba","RI",1,1,1,1);
Proveedor reg192(192,"INFOSAN S.R.L",30708215860,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg193(193,"INNOVA T",30663170364,902,"Buenos Aires","EX",0,0,1,1);
Proveedor reg194(194,"INSTITUTO ANALITICO ESPECIALIZADO SRL",30707472738,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg195(195,"INSTRUMENTACION CIENTIFICA S.A.",30641708174,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg196(196,"INTELIGENCIA Y TECNOLOGIA S.A.",30709252239,905,"Cordoba","RI",1,1,1,1);
Proveedor reg197(197,"INTERCHEMISTRY S.A",30647359023,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg198(198,"INTERNATIONAL CARGO SA",30706051836,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg199(199,"IRIA FLAVIA SA",30709262048,916,"Rio Negro","RI",1,1,1,1);
Proveedor reg200(200,"ISIDORE PATRICIO ANDRES",20288153427,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg201(201,"JENCK S.A.",30632884385,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg202(202,"JORGE ALBERTO MARCONI",20124792208,902,"Buenos Aires","MT",1,0,1,1);
Proveedor reg203(203,"JORGE RICARDO ODIERNA",20078692384,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg204(204,"JOSE CURI ANTUN E HIJOS SA",30711625875,905,"Cordoba","RI",1,1,1,1);
Proveedor reg205(205,"LA CASA DE LOS MIL ENVASES",30534958680,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg206(206,"LA PLATA OFF SHORE S.A.",30691281015,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg207(207,"LABORATORIO DE CONTROL S.A",33707271499,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg208(208,"LABORATORIO ECZANE PHARMA S.A",30697736154,916,"Rio Negro","RI",1,1,1,1);
Proveedor reg209(209,"LABORATORIO VARIFARMA SA",30682667709,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg210(210,"LABORATORIOS ARGENPACK S.A",30691025450,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg211(211,"LABORATORIOS BIOMIC SRL",30711005966,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg212(212,"LABORATORIOS DUNCAN SA",30520581258,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg213(213,"LABORATORIOS OLIVIERI SRL",30710225636,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg214(214,"LADISLAO BERKES S.A.",30712129677,905,"Cordoba","RI",1,1,1,1);
Proveedor reg215(215,"LAPTOP AID S.R.L.",30714760951,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg216(216,"LASARTE HNOS SRL",30646938755,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg217(217,"LAURETTI MARCELO HERNAN",20240834740,902,"Buenos Aires","MT",1,0,1,1);
Proveedor reg218(218,"LEE TOURS",30716208202,902,"Buenos Aires","RI",1,1,2,1);
Proveedor reg219(219,"LENOR S.R.L.",30702968808,916,"Rio Negro","RI",1,1,1,1);
Proveedor reg220(220,"LETCHER PABLO GERMAN",20285896267,902,"Buenos Aires","MT",1,0,1,1);
Proveedor reg221(221,"LIBRERIA DEL SUR SH",30708287055,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg222(222,"LIBRERIA HELIOS S.R.L.",30696604580,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg223(223,"LINCE SEGURIDAD LTDA",30643445510,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg224(224,"LOBOV Y CIA. SA",30541677220,905,"Cordoba","RI",1,1,1,1);
Proveedor reg225(225,"LOGEXPOR SRL",30707985263,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg226(226,"LUBE SEGURIDAD INDUSTRIAL S.R.L.",30710911602,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg227(227,"LUIS FAZIO E HIJOS SRL",30694562392,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg228(228,"LUIS PASTEUR",30558325557,924,"Tucuman","RI",1,1,1,1);
Proveedor reg229(229,"LUSON SEGURIDAD SA",30709327360,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg230(230,"MACKINZE JORGE",20083209047,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg231(231,"MAGEL S.A",30550106430,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg232(232,"MANTOVANO MARIA CECILIA",27134321941,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg233(233,"MARQUES ROMINA GISELLE",27270888505,902,"Buenos Aires","MT",1,0,1,1);
Proveedor reg234(234,"MARTIN S. KALOGHLIAN Y SUSANA .",30708402113,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg235(235,"MARTINEZ ADRIANA NOEMI",23183040774,924,"Tucuman","MT",0,0,1,1);
Proveedor reg236(236,"MATEC MEDICION SRL",30709916331,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg237(237,"MATERIALES YRIGOYEN S.R.L.",30605015707,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg238(238,"MC METODOS DE CONTROL SA",30663018392,905,"Cordoba","RI",1,1,1,1);
Proveedor reg239(239,"MCF SERVICE SRL",30709144509,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg240(240,"MEDICATEC S.R.L.",30624950468,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg241(241,"MEDICINA INTEGRALFITZ ROY S.A",30707842330,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg242(242,"MEGA OFFICE SRL",30714380210,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg243(243,"MEMOTEC SA",30608398445,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg244(244,"MERCADOS TRANSPARENTES S.A.",30702014111,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg245(245,"MERCK QUIMICA ARGENTINA S.A.IC",30503832565,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg246(246,"META KLEAN S.A.",30716112140,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg247(247,"MICHEL PABLO RODOLFO",20169526533,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg248(248,"MICROCLAR S.A",30707170014,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg249(249,"MIL RUEDAS S.R.L.",30708482680,905,"Cordoba","RI",1,1,1,1);
Proveedor reg250(250,"MIX-57 S.A.S",30715851896,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg251(251,"MONZON VICTOR DIEGO",20185583024,902,"Buenos Aires","MT",1,0,1,1);
Proveedor reg252(252,"MOVISTAR",30678814357,902,"Buenos Aires","RI",1,1,4,1);
Proveedor reg253(253,"MR PHARMA SA",30707199454,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg254(254,"MULTI GARMENT SRL",30679515523,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg255(255,"MULTIMATERIALES SRL",30711945500,905,"Cordoba","RI",1,1,1,1);
Proveedor reg256(256,"MUNSER",33649148339,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg257(257,"MUÑOZ DACHSEL ELIANA RAQUEL",27954162082,902,"Buenos Aires","MT",1,0,3,1);
Proveedor reg258(258,"MYCE S.R.L.",30716553724,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg259(259,"NESTLE ARGENTINA S.A.",30546764040,924,"Tucuman","RI",1,1,1,1);
Proveedor reg260(260,"NETAWAY",20251274569,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg261(261,"NO BAJAR LOS BRAZOS SRL",30710796838,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg262(262,"NOBEL SERVICE GROUP SRL",30714316547,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg263(263,"NOVELLA MARIA LUJAN",27263115991,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg264(264,"NUEVO MILENIO MULTIPRODUCTOS S.R.L.",30714545708,905,"Cordoba","RI",1,1,1,1);
Proveedor reg265(265,"NUÑEZ GRACIELA ADRIANA",27168240703,902,"Buenos Aires","MT",1,0,3,1);
Proveedor reg266(266,"OCA LOG S.A.",30717024393,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg267(267,"ODIERNA JORGE RICARDO",20078692384,913,"Mendoza","RI",0,1,1,1);
Proveedor reg268(268,"OLEODINAMICOS S.A.",30707927328,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg269(269,"OMNILAB S.R.L",30691236494,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg270(270,"ONE LAB SOLUTIONS S.A.",30714946915,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg271(271,"ONECLOUD S.R.L.",30716059959,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg272(272,"ORGANIZACION COORDINADORA ARGENTINA S R L",30536259194,913,"Mendoza","RI",1,1,1,1);
Proveedor reg273(273,"ORGANIZACIÓN RAFER S.R.L.",30562659125,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg274(274,"ORTELLI Y COMPAÑIA S.R.L.",30501668601,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg275(275,"ORTIZ ELIZABETH MYRIAM",27206827454,902,"Buenos Aires","MT",1,0,3,1);
Proveedor reg276(276,"OSDE",30546741253,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg277(277,"PABLO ALEJANDRO COCUZZO",20226451553,902,"Buenos Aires","MT",1,0,1,1);
Proveedor reg278(278,"PAGNOTTA ADRIANA IRENE",27106058755,902,"Buenos Aires","MT",1,0,3,1);
Proveedor reg279(279,"PALERMO MIGUEL ANGEL",20263289251,913,"Mendoza","MT",0,0,1,1);
Proveedor reg280(280,"PALL TECHNOLOGIES S.A.",30589610233,913,"Mendoza","RI",1,1,1,1);
Proveedor reg281(281,"PANARIO JUAN FRANCISCO",20295982048,913,"Mendoza","MT",0,0,3,1);
Proveedor reg282(282,"PANZITTA ALICIA NOEMI",27126672891,902,"Buenos Aires","MT",0,0,1,1);
Proveedor reg283(283,"PARRELLA ALEJANDRO HUNBERTO",20172013342,902,"Buenos Aires","MT",1,0,3,1);
Proveedor reg284(284,"PATERNAL SRL",30641121521,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg285(285,"PATIÑO LOPEZ IRMA",27940754734,916,"Rio Negro","MT",0,0,1,1);
Proveedor reg286(286,"PINO ALBERTO CLAUDIO",20223398260,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg287(287,"PINTO LEONEL EMILIANO",20325657988,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg288(288,"PINTURERIA DEL FONDO SA",30646127064,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg289(289,"PIRAGINE HNOS SRL",30714239348,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg290(290,"PM CHEMISTRY S.R.L.",30711163561,916,"Rio Negro","RI",1,1,1,1);
Proveedor reg291(291,"POLINORTE S.A.",30646811062,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg292(292,"PORMATIC S.A",30709690643,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg293(293,"POROPAT CARLOS ALBERTO",20201867836,913,"Mendoza","RI",0,1,1,1);
Proveedor reg294(294,"PRECINTER S.R.L.",30707446982,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg295(295,"PREMEK S.A.",30707650938,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg296(296,"PROLABOR SRL INDUSTRIAL Y COMERCIAL",30608951381,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg297(297,"PROLAP SRL",30708913355,913,"Mendoza","RI",1,1,1,1);
Proveedor reg298(298,"Q&T TRADE SRL",30710399812,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg299(299,"QUIMICA ARISTON SAIC",30501257954,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg300(300,"QUIMICA EL REGRESO SRL",30705445148,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg301(301,"QUIMICA FENIX S.A.",30702955285,913,"Mendoza","RI",1,1,1,1);
Proveedor reg302(302,"QUIMICA OESTE SOCIEDAD ANONIMA",30517345039,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg303(303,"RAFFO JAVIER RODRIGO",20211738570,913,"Mendoza","RI",0,1,1,1);
Proveedor reg304(304,"RAHOLIN SRL",30703256275,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg305(305,"RCBM - RIVEIRO, CONDOLEO & ASO",30713909404,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg306(306,"REAGENTS S.A.",30707215697,916,"Rio Negro","RI",1,1,1,1);
Proveedor reg307(307,"REBOREDO JORGE",20143752675,916,"Rio Negro","RI",0,1,1,1);
Proveedor reg308(308,"REBUFFI JUAN PABLO",20234726324,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg309(309,"RED COMERCIAL SRL",30689670624,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg310(310,"REFRIGERACION MARTIN DE CHAKIRIAN",30716747855,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg311(311,"REINER S.A.",30715636243,913,"Mendoza","RI",1,1,1,1);
Proveedor reg312(312,"RESEARCH & DEVELOPMENT",20937010177,902,"Buenos Aires","MT",1,0,3,1);
Proveedor reg313(313,"RESEARCH AG SA",30709588830,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg314(314,"RESISTACK S.A.",30694166551,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg315(315,"RESISTENCIAS ELECTROARGENTINAS",30709797030,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg316(316,"RETAIL BUSINESS INC.",20183536665,916,"Rio Negro","RI",0,1,1,1);
Proveedor reg317(317,"RICCATO GABRIEL LUIS",20248664283,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg318(318,"RIVA S.A.",33504596309,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg319(319,"RIVAS DAMIAN HUGO",20300677135,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg320(320,"RODRIGUEZ HERMANOS TRANSPORTES S.A.",30712155694,913,"Mendoza","RI",1,1,1,1);
Proveedor reg321(321,"ROL - PEL S.R.L.",30709530549,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg322(322,"ROVETTA MARIANO",20319414747,902,"Buenos Aires","MT",1,0,3,1);
Proveedor reg323(323,"RULEMANES MUNRO S.C.A.",30542031340,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg324(324,"RUMAPEL SRL",30657474580,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg325(325,"RWILDE S.A.",30709832189,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg326(326,"S.I.M.E. ARGENTINA SH",30701136884,913,"Mendoza","RI",1,1,1,1);
Proveedor reg327(327,"SACCONE CELINA",27182271344,902,"Buenos Aires","MT",1,0,3,1);
Proveedor reg328(328,"SAETECH SA",30662937904,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg329(329,"SALAMERO ADRIAN RUBEN",20182086445,913,"Mendoza","RI",0,1,1,1);
Proveedor reg330(330,"SANCHEZ DELIA HAYDEE",27252204038,902,"Buenos Aires","MT",1,0,1,1);
Proveedor reg331(331,"SANCHEZ JULIO ALBERTO",20116359236,902,"Buenos Aires","MT",1,0,1,1);
Proveedor reg332(332,"SANSANO MARIANA",27267089952,916,"Rio Negro","MT",0,0,3,1);
Proveedor reg333(333,"SANTA FE COMERCIAL SRL",30586172308,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg334(334,"SARTORIUS ARGENTINA SA",30695116884,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg335(335,"SCARANO HUGO SALVADOR",20211540754,916,"Rio Negro","RI",0,1,1,1);
Proveedor reg336(336,"SCHOTT",30710853777,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg337(337,"SCHVARTZ NICOLAS BRIAN",20343584351,916,"Rio Negro","RI",0,1,1,1);
Proveedor reg338(338,"SCI PHARMA S.R.L.",30711906424,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg339(339,"SEGUROS SURA S.A",30500000127,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg340(340,"SEIDOR CONSULTING SA",30686512394,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg341(341,"SELLOSMEC Y BOMBASCEN ARGENTINA S.A",30716987341,916,"Rio Negro","RI",1,1,1,1);
Proveedor reg342(342,"SIGMA ALDRICH DE ARGENTINA SA",30693136802,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg343(343,"SILICON ARGENTINA SRL",30539166774,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg344(344,"SISTEMAS ARGENTINOS DE I TERMICO S.A",30708578696,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg345(345,"SOKOLOWSKI MIROSLAW",20187615950,916,"Rio Negro","RI",0,1,1,1);
Proveedor reg346(346,"SOLUCIONES DE ARCHIVOS SA",30711130426,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg347(347,"SOLUCIONES GRAFICAS S.A.",30708756780,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg348(348,"SOUTH AMERICAN CARGO SA",30650444740,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg349(349,"SOUTH PHARM S.R.L.",30715327461,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg350(350,"SOUTHATLANTIC MARITIME SA",30643748688,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg351(351,"SPORT CLUB",30708784660,916,"Rio Negro","RI",1,1,1,1);
Proveedor reg352(352,"SUPERMERCADOS MAYORISTAS MAKRO S.A.",30589621499,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg353(353,"T C P Consulting S.R.L.",30709673986,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg354(354,"TAGLIAFICO PABLO NICOLAS",20277714095,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg355(355,"TALLERES NORTE SA",30676653496,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg356(356,"TCA SA",30711164932,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg357(357,"TEC INSTRUMENTAL S.A.",30641504579,916,"Rio Negro","RI",1,1,1,1);
Proveedor reg358(358,"TECNICAS FERROVIARIAS ARGENTINAS S.A,",30657138661,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg359(359,"TECNO SAN MARTIN SRL",30522043997,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg360(360,"TECNODINAMIA FUNDAL S.A.",30583768986,916,"Rio Negro","RI",1,1,1,1);
Proveedor reg361(361,"TELECENTRO SA",30640897267,902,"Buenos Aires","RI",1,1,4,1);
Proveedor reg362(362,"TELECOM ARGENTINA S.A",30639453738,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg363(363,"TELECTRÓNICA CODIFICACIÓN S.A.",30707329072,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg364(364,"TERRY PLAST SRL",30708708611,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg365(365,"TESTLAB SOCIEDAD DE RESPONSABILIDAD LIMITADA",30618854570,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg366(366,"TETRAQUIMICA S.A.",30522683732,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg367(367,"TODO SEGURIDAD",20338116978,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg368(368,"TRANCANELLA MARIA ASUNCION",23168447604,916,"Rio Negro","RI",0,1,1,1);
Proveedor reg369(369,"TRANE AIRE ACONDICIONADO",30662102292,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg370(370,"TRANSPORTES ECOLOGICOS S.R.L",30712323775,916,"Rio Negro","RI",1,1,1,1);
Proveedor reg371(371,"TRAPEXIUM S.A.",30716711788,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg372(372,"TREND CHEMICAL SRL",30631947758,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg373(373,"TRIQUIM S.A.",30614751750,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg374(374,"TRULY NOLEN ARGENTINA SA",30612251904,916,"Rio Negro","RI",1,1,1,1);
Proveedor reg375(375,"TURBO GREEN SRL",30714787310,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg376(376,"UNIFARMA S.A.",30568282090,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg377(377,"UNION ARGENTINA DE PROVEEDORES DEL ESTADO",30539732923,902,"Buenos Aires","EX",1,0,1,1);
Proveedor reg378(378,"VALAM S.A.I.C.",33539882819,916,"Rio Negro","RI",1,1,1,1);
Proveedor reg379(379,"VALDEZ MERELES ANALIA MABEL",27958169073,902,"Buenos Aires","MT",1,0,1,1);
Proveedor reg380(380,"VALVES SYSTEMS SRL",33710713699,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg381(381,"VARITEL INGENIERIA ELECTRONICA",30708222417,916,"Rio Negro","RI",1,1,1,1);
Proveedor reg382(382,"VC SOLUCIONES SRL",30716416891,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg383(383,"VERNET COMPUTERS S.R.L.",30707970231,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg384(384,"VICROFER SRL",30625046455,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg385(385,"VICTOR M FUSCO y CIA SRL",30641278684,916,"Rio Negro","RI",1,1,1,1);
Proveedor reg386(386,"VICTOR MASSON TRANSPORTES CRUZ DEL SUR S A",30556565798,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg387(387,"VILLANEDA ALEJANDRO JAVIER",20267675873,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg388(388,"VILLAR JUAN JOSE",20299598935,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg389(389,"Vittal - Socorro Medico Provado S.A",30612213417,916,"Rio Negro","RI",1,1,1,1);
Proveedor reg390(390,"VUELTA JORGE FERNANDO",20145904626,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg391(391,"WASSER SERVICIOS INDUSTRIALES",33710004779,916,"Rio Negro","RI",1,1,1,1);
Proveedor reg392(392,"WEST PHARMACEUTICAL SERVICES A",33505427039,902,"Buenos Aires","RI",1,1,1,1);
Proveedor reg393(393,"ZANONI FRANCO MARIO",20118357532,902,"Buenos Aires","MT",1,0,1,1);
Proveedor reg394(394,"ZEITUNE MAYRA NAHIR",23329834654,902,"Buenos Aires","MT",1,0,3,1);
Proveedor reg395(395,"ZELIAN SOCIEDAD ANONIMA",30709591149,902,"Buenos Aires","RI",1,1,1,1);

reg1.guardarEnDiscoReset();
reg2.guardarEnDisco();
reg3.guardarEnDisco();
reg4.guardarEnDisco();
reg5.guardarEnDisco();
reg6.guardarEnDisco();
reg7.guardarEnDisco();
reg8.guardarEnDisco();
reg9.guardarEnDisco();
reg10.guardarEnDisco();
reg11.guardarEnDisco();
reg12.guardarEnDisco();
reg13.guardarEnDisco();
reg14.guardarEnDisco();
reg15.guardarEnDisco();
reg16.guardarEnDisco();
reg17.guardarEnDisco();
reg18.guardarEnDisco();
reg19.guardarEnDisco();
reg20.guardarEnDisco();
reg21.guardarEnDisco();
reg22.guardarEnDisco();
reg23.guardarEnDisco();
reg24.guardarEnDisco();
reg25.guardarEnDisco();
reg26.guardarEnDisco();
reg27.guardarEnDisco();
reg28.guardarEnDisco();
reg29.guardarEnDisco();
reg30.guardarEnDisco();
reg31.guardarEnDisco();
reg32.guardarEnDisco();
reg33.guardarEnDisco();
reg34.guardarEnDisco();
reg35.guardarEnDisco();
reg36.guardarEnDisco();
reg37.guardarEnDisco();
reg38.guardarEnDisco();
reg39.guardarEnDisco();
reg40.guardarEnDisco();
reg41.guardarEnDisco();
reg42.guardarEnDisco();
reg43.guardarEnDisco();
reg44.guardarEnDisco();
reg45.guardarEnDisco();
reg46.guardarEnDisco();
reg47.guardarEnDisco();
reg48.guardarEnDisco();
reg49.guardarEnDisco();
reg50.guardarEnDisco();
reg51.guardarEnDisco();
reg52.guardarEnDisco();
reg53.guardarEnDisco();
reg54.guardarEnDisco();
reg55.guardarEnDisco();
reg56.guardarEnDisco();
reg57.guardarEnDisco();
reg58.guardarEnDisco();
reg59.guardarEnDisco();
reg60.guardarEnDisco();
reg61.guardarEnDisco();
reg62.guardarEnDisco();
reg63.guardarEnDisco();
reg64.guardarEnDisco();
reg65.guardarEnDisco();
reg66.guardarEnDisco();
reg67.guardarEnDisco();
reg68.guardarEnDisco();
reg69.guardarEnDisco();
reg70.guardarEnDisco();
reg71.guardarEnDisco();
reg72.guardarEnDisco();
reg73.guardarEnDisco();
reg74.guardarEnDisco();
reg75.guardarEnDisco();
reg76.guardarEnDisco();
reg77.guardarEnDisco();
reg78.guardarEnDisco();
reg79.guardarEnDisco();
reg80.guardarEnDisco();
reg81.guardarEnDisco();
reg82.guardarEnDisco();
reg83.guardarEnDisco();
reg84.guardarEnDisco();
reg85.guardarEnDisco();
reg86.guardarEnDisco();
reg87.guardarEnDisco();
reg88.guardarEnDisco();
reg89.guardarEnDisco();
reg90.guardarEnDisco();
reg91.guardarEnDisco();
reg92.guardarEnDisco();
reg93.guardarEnDisco();
reg94.guardarEnDisco();
reg95.guardarEnDisco();
reg96.guardarEnDisco();
reg97.guardarEnDisco();
reg98.guardarEnDisco();
reg99.guardarEnDisco();
reg100.guardarEnDisco();
reg101.guardarEnDisco();
reg102.guardarEnDisco();
reg103.guardarEnDisco();
reg104.guardarEnDisco();
reg105.guardarEnDisco();
reg106.guardarEnDisco();
reg107.guardarEnDisco();
reg108.guardarEnDisco();
reg109.guardarEnDisco();
reg110.guardarEnDisco();
reg111.guardarEnDisco();
reg112.guardarEnDisco();
reg113.guardarEnDisco();
reg114.guardarEnDisco();
reg115.guardarEnDisco();
reg116.guardarEnDisco();
reg117.guardarEnDisco();
reg118.guardarEnDisco();
reg119.guardarEnDisco();
reg120.guardarEnDisco();
reg121.guardarEnDisco();
reg122.guardarEnDisco();
reg123.guardarEnDisco();
reg124.guardarEnDisco();
reg125.guardarEnDisco();
reg126.guardarEnDisco();
reg127.guardarEnDisco();
reg128.guardarEnDisco();
reg129.guardarEnDisco();
reg130.guardarEnDisco();
reg131.guardarEnDisco();
reg132.guardarEnDisco();
reg133.guardarEnDisco();
reg134.guardarEnDisco();
reg135.guardarEnDisco();
reg136.guardarEnDisco();
reg137.guardarEnDisco();
reg138.guardarEnDisco();
reg139.guardarEnDisco();
reg140.guardarEnDisco();
reg141.guardarEnDisco();
reg142.guardarEnDisco();
reg143.guardarEnDisco();
reg144.guardarEnDisco();
reg145.guardarEnDisco();
reg146.guardarEnDisco();
reg147.guardarEnDisco();
reg148.guardarEnDisco();
reg149.guardarEnDisco();
reg150.guardarEnDisco();
reg151.guardarEnDisco();
reg152.guardarEnDisco();
reg153.guardarEnDisco();
reg154.guardarEnDisco();
reg155.guardarEnDisco();
reg156.guardarEnDisco();
reg157.guardarEnDisco();
reg158.guardarEnDisco();
reg159.guardarEnDisco();
reg160.guardarEnDisco();
reg161.guardarEnDisco();
reg162.guardarEnDisco();
reg163.guardarEnDisco();
reg164.guardarEnDisco();
reg165.guardarEnDisco();
reg166.guardarEnDisco();
reg167.guardarEnDisco();
reg168.guardarEnDisco();
reg169.guardarEnDisco();
reg170.guardarEnDisco();
reg171.guardarEnDisco();
reg172.guardarEnDisco();
reg173.guardarEnDisco();
reg174.guardarEnDisco();
reg175.guardarEnDisco();
reg176.guardarEnDisco();
reg177.guardarEnDisco();
reg178.guardarEnDisco();
reg179.guardarEnDisco();
reg180.guardarEnDisco();
reg181.guardarEnDisco();
reg182.guardarEnDisco();
reg183.guardarEnDisco();
reg184.guardarEnDisco();
reg185.guardarEnDisco();
reg186.guardarEnDisco();
reg187.guardarEnDisco();
reg188.guardarEnDisco();
reg189.guardarEnDisco();
reg190.guardarEnDisco();
reg191.guardarEnDisco();
reg192.guardarEnDisco();
reg193.guardarEnDisco();
reg194.guardarEnDisco();
reg195.guardarEnDisco();
reg196.guardarEnDisco();
reg197.guardarEnDisco();
reg198.guardarEnDisco();
reg199.guardarEnDisco();
reg200.guardarEnDisco();
reg201.guardarEnDisco();
reg202.guardarEnDisco();
reg203.guardarEnDisco();
reg204.guardarEnDisco();
reg205.guardarEnDisco();
reg206.guardarEnDisco();
reg207.guardarEnDisco();
reg208.guardarEnDisco();
reg209.guardarEnDisco();
reg210.guardarEnDisco();
reg211.guardarEnDisco();
reg212.guardarEnDisco();
reg213.guardarEnDisco();
reg214.guardarEnDisco();
reg215.guardarEnDisco();
reg216.guardarEnDisco();
reg217.guardarEnDisco();
reg218.guardarEnDisco();
reg219.guardarEnDisco();
reg220.guardarEnDisco();
reg221.guardarEnDisco();
reg222.guardarEnDisco();
reg223.guardarEnDisco();
reg224.guardarEnDisco();
reg225.guardarEnDisco();
reg226.guardarEnDisco();
reg227.guardarEnDisco();
reg228.guardarEnDisco();
reg229.guardarEnDisco();
reg230.guardarEnDisco();
reg231.guardarEnDisco();
reg232.guardarEnDisco();
reg233.guardarEnDisco();
reg234.guardarEnDisco();
reg235.guardarEnDisco();
reg236.guardarEnDisco();
reg237.guardarEnDisco();
reg238.guardarEnDisco();
reg239.guardarEnDisco();
reg240.guardarEnDisco();
reg241.guardarEnDisco();
reg242.guardarEnDisco();
reg243.guardarEnDisco();
reg244.guardarEnDisco();
reg245.guardarEnDisco();
reg246.guardarEnDisco();
reg247.guardarEnDisco();
reg248.guardarEnDisco();
reg249.guardarEnDisco();
reg250.guardarEnDisco();
reg251.guardarEnDisco();
reg252.guardarEnDisco();
reg253.guardarEnDisco();
reg254.guardarEnDisco();
reg255.guardarEnDisco();
reg256.guardarEnDisco();
reg257.guardarEnDisco();
reg258.guardarEnDisco();
reg259.guardarEnDisco();
reg260.guardarEnDisco();
reg261.guardarEnDisco();
reg262.guardarEnDisco();
reg263.guardarEnDisco();
reg264.guardarEnDisco();
reg265.guardarEnDisco();
reg266.guardarEnDisco();
reg267.guardarEnDisco();
reg268.guardarEnDisco();
reg269.guardarEnDisco();
reg270.guardarEnDisco();
reg271.guardarEnDisco();
reg272.guardarEnDisco();
reg273.guardarEnDisco();
reg274.guardarEnDisco();
reg275.guardarEnDisco();
reg276.guardarEnDisco();
reg277.guardarEnDisco();
reg278.guardarEnDisco();
reg279.guardarEnDisco();
reg280.guardarEnDisco();
reg281.guardarEnDisco();
reg282.guardarEnDisco();
reg283.guardarEnDisco();
reg284.guardarEnDisco();
reg285.guardarEnDisco();
reg286.guardarEnDisco();
reg287.guardarEnDisco();
reg288.guardarEnDisco();
reg289.guardarEnDisco();
reg290.guardarEnDisco();
reg291.guardarEnDisco();
reg292.guardarEnDisco();
reg293.guardarEnDisco();
reg294.guardarEnDisco();
reg295.guardarEnDisco();
reg296.guardarEnDisco();
reg297.guardarEnDisco();
reg298.guardarEnDisco();
reg299.guardarEnDisco();
reg300.guardarEnDisco();
reg301.guardarEnDisco();
reg302.guardarEnDisco();
reg303.guardarEnDisco();
reg304.guardarEnDisco();
reg305.guardarEnDisco();
reg306.guardarEnDisco();
reg307.guardarEnDisco();
reg308.guardarEnDisco();
reg309.guardarEnDisco();
reg310.guardarEnDisco();
reg311.guardarEnDisco();
reg312.guardarEnDisco();
reg313.guardarEnDisco();
reg314.guardarEnDisco();
reg315.guardarEnDisco();
reg316.guardarEnDisco();
reg317.guardarEnDisco();
reg318.guardarEnDisco();
reg319.guardarEnDisco();
reg320.guardarEnDisco();
reg321.guardarEnDisco();
reg322.guardarEnDisco();
reg323.guardarEnDisco();
reg324.guardarEnDisco();
reg325.guardarEnDisco();
reg326.guardarEnDisco();
reg327.guardarEnDisco();
reg328.guardarEnDisco();
reg329.guardarEnDisco();
reg330.guardarEnDisco();
reg331.guardarEnDisco();
reg332.guardarEnDisco();
reg333.guardarEnDisco();
reg334.guardarEnDisco();
reg335.guardarEnDisco();
reg336.guardarEnDisco();
reg337.guardarEnDisco();
reg338.guardarEnDisco();
reg339.guardarEnDisco();
reg340.guardarEnDisco();
reg341.guardarEnDisco();
reg342.guardarEnDisco();
reg343.guardarEnDisco();
reg344.guardarEnDisco();
reg345.guardarEnDisco();
reg346.guardarEnDisco();
reg347.guardarEnDisco();
reg348.guardarEnDisco();
reg349.guardarEnDisco();
reg350.guardarEnDisco();
reg351.guardarEnDisco();
reg352.guardarEnDisco();
reg353.guardarEnDisco();
reg354.guardarEnDisco();
reg355.guardarEnDisco();
reg356.guardarEnDisco();
reg357.guardarEnDisco();
reg358.guardarEnDisco();
reg359.guardarEnDisco();
reg360.guardarEnDisco();
reg361.guardarEnDisco();
reg362.guardarEnDisco();
reg363.guardarEnDisco();
reg364.guardarEnDisco();
reg365.guardarEnDisco();
reg366.guardarEnDisco();
reg367.guardarEnDisco();
reg368.guardarEnDisco();
reg369.guardarEnDisco();
reg370.guardarEnDisco();
reg371.guardarEnDisco();
reg372.guardarEnDisco();
reg373.guardarEnDisco();
reg374.guardarEnDisco();
reg375.guardarEnDisco();
reg376.guardarEnDisco();
reg377.guardarEnDisco();
reg378.guardarEnDisco();
reg379.guardarEnDisco();
reg380.guardarEnDisco();
reg381.guardarEnDisco();
reg382.guardarEnDisco();
reg383.guardarEnDisco();
reg384.guardarEnDisco();
reg385.guardarEnDisco();
reg386.guardarEnDisco();
reg387.guardarEnDisco();
reg388.guardarEnDisco();
reg389.guardarEnDisco();
reg390.guardarEnDisco();
reg391.guardarEnDisco();
reg392.guardarEnDisco();
reg393.guardarEnDisco();
reg394.guardarEnDisco();
reg395.guardarEnDisco();

PlanDeCuentas regis1(1,"ACTIVO",1,0);
PlanDeCuentas regis2(11,"ACTIVO CORRIENTE",1,0);
PlanDeCuentas regis3(111,"DISPONIBILIDADES",1,0);
PlanDeCuentas regis4(1111,"CAJA",1,0);
PlanDeCuentas regis5(11111,"Caja en Pesos",4,1);
PlanDeCuentas regis6(11112,"Caja en Dolares",4,1);
PlanDeCuentas regis7(11113,"Caja en Euros",4,1);
PlanDeCuentas regis8(1112,"FONDO FIJO",1,0);
PlanDeCuentas regis9(11121,"Fondo fijo",4,1);
PlanDeCuentas regis10(1113,"BANCOS",1,0);
PlanDeCuentas regis11(11131,"Banco Meridian",4,1);
PlanDeCuentas regis12(11132,"Banco Credicoop",4,1);
PlanDeCuentas regis13(11133,"Banco Supervielle",4,1);
PlanDeCuentas regis14(11134,"Banco Provincia",4,1);
PlanDeCuentas regis15(11135,"Banco Credicoop DOLARES",4,1);
PlanDeCuentas regis16(11136,"Banco Galicia",4,1);
PlanDeCuentas regis17(1114,"VALORES DE TERCEROS",1,0);
PlanDeCuentas regis18(11141,"Cheques en Cartera",4,1);
PlanDeCuentas regis19(11142,"Cheques Rechazados",4,1);
PlanDeCuentas regis20(112,"CREDITOS",1,0);
PlanDeCuentas regis21(1121,"CREDITOS POR VENTAS",1,0);
PlanDeCuentas regis22(11211,"Deudores por Ventas en Pesos",4,1);
PlanDeCuentas regis23(11212,"Deudores por Vtas en Dolares",4,1);
PlanDeCuentas regis24(11213,"Otros deudores varios",4,1);
PlanDeCuentas regis25(1122,"CREDITOS FISCALES y SOCIALES",1,0);
PlanDeCuentas regis26(11221,"I.Ganancias - Retenciones",4,1);
PlanDeCuentas regis27(11222,"I.Ganancias - Percepciones",4,1);
PlanDeCuentas regis28(11223,"I.Ganancias - Anticipos",4,1);
PlanDeCuentas regis29(11224,"I.Ganancias - Saldo a Favor",4,1);
PlanDeCuentas regis30(11225,"I. Ganancias Metodo Diferido",4,1);
PlanDeCuentas regis31(11226,"IVA - Credito Fiscal",4,1);
PlanDeCuentas regis32(11227,"IVA - Retenciones Sufridas",4,1);
PlanDeCuentas regis33(11228,"IVA - Percerpciones Sufridas",4,1);
PlanDeCuentas regis34(11229,"IVA - Saldo Tecnico a Favor",4,1);
PlanDeCuentas regis35(11230,"IVA - Sdo. Lib. Disponibilidad",4,1);
PlanDeCuentas regis36(11231,"II.BB. SIRCREB",4,1);
PlanDeCuentas regis37(11232,"II.BB. Saldo a Favor",4,1);
PlanDeCuentas regis38(11233,"II.BB. Ret. Sufr. Prov. BsAs",4,1);
PlanDeCuentas regis39(11234,"II.BB. Perc. Sufr. Prov. BsAs",4,1);
PlanDeCuentas regis40(1123,"CREDITOS LABORALES",1,0);
PlanDeCuentas regis41(11231,"Adelantos al Personal",4,1);
PlanDeCuentas regis42(11232,"Prestamos al Personal",4,1);
PlanDeCuentas regis43(1124,"OTROS CREDITOS",1,0);
PlanDeCuentas regis44(11241,"Depositos en Garantia",4,1);
PlanDeCuentas regis45(11242,"Anticipos a proveedores",4,1);
PlanDeCuentas regis46(11243,"Adelantos a Rendir",4,1);
PlanDeCuentas regis47(11244,"Seguros pagados a Devengar",2,1);
PlanDeCuentas regis48(11245,"Gastos a Refacturar",4,1);
PlanDeCuentas regis49(11246,"Otros Creditos",4,1);
PlanDeCuentas regis50(113,"BIENES DE CAMBIO",1,0);
PlanDeCuentas regis51(1131,"MATERIAS PRIMAS",1,0);
PlanDeCuentas regis52(11311,"Materias primas nacionales",2,1);
PlanDeCuentas regis53(11312,"Materias primas importadas",4,1);
PlanDeCuentas regis54(1132,"MATERIAL EMPAQUE",1,0);
PlanDeCuentas regis55(11321,"Material empaque nacional",2,1);
PlanDeCuentas regis56(11322,"Material empaque importado",4,1);
PlanDeCuentas regis57(1133,"PRODUCTO TERMINADO",1,0);
PlanDeCuentas regis58(11331,"Producto Terminado Nacional",4,1);
PlanDeCuentas regis59(11332,"Producto Terminado Importado",4,1);
PlanDeCuentas regis60(12,"ACTIVO NO CORRIENTE",1,0);
PlanDeCuentas regis61(121,"CREDITOS",1,0);
PlanDeCuentas regis62(1211,"CREDITOS FISCALES y SOCIALES",1,0);
PlanDeCuentas regis63(12111,"Credito por Imp. a las gananc.",4,1);
PlanDeCuentas regis64(122,"BIENES DE USO",1,0);
PlanDeCuentas regis65(1221,"INMUEBLES",1,0);
PlanDeCuentas regis66(12211,"Terreno",4,1);
PlanDeCuentas regis67(12212,"Inmuebles",4,1);
PlanDeCuentas regis68(12213,"Amortizacion Acumul. Inmuebles",4,1);
PlanDeCuentas regis69(12214,"Mejoras en Inmuebles",2,1);
PlanDeCuentas regis70(12215,"Amort. Acum. Mejoras Inmuebles",4,1);
PlanDeCuentas regis71(1222,"MAQUINAS Y EQUIPOS",1,0);
PlanDeCuentas regis72(12221,"Maquinas y equipos - V Origen",2,1);
PlanDeCuentas regis73(12222,"Amortizac. Ac. Maq. y Equipos",4,1);
PlanDeCuentas regis74(1223,"RODADOS",1,0);
PlanDeCuentas regis75(12231,"Rodados - Valor Origen",2,1);
PlanDeCuentas regis76(12232,"Amortizacion Acumulada Rodados",4,1);
PlanDeCuentas regis77(1224,"MUEBLES UTILES E INSTALACS",1,0);
PlanDeCuentas regis78(12241,"M. y Utiles - Valor Origen",2,1);
PlanDeCuentas regis79(12242,"Amortizacion Ac.. M. y Utiles",4,1);
PlanDeCuentas regis80(1225,"EQUIPOS DE COMPUTACIÓN",1,0);
PlanDeCuentas regis81(12251,"Eq. de Computación - V. Origen",2,1);
PlanDeCuentas regis82(12252,"Amortizacion Ac. Eq. Computac",4,1);
PlanDeCuentas regis83(2,"PASIVO",1,0);
PlanDeCuentas regis84(21,"PASIVO CORRIENTE",1,0);
PlanDeCuentas regis85(211,"DEUDAS COMERCIALES",1,0);
PlanDeCuentas regis86(2111,"PROVEEDORES NACIONALES",1,0);
PlanDeCuentas regis87(21111,"Proveedores nac. en pesos",4,1);
PlanDeCuentas regis88(21112,"Proveedores nac. en dolares",4,1);
PlanDeCuentas regis89(21113,"Cheques diferidos",4,1);
PlanDeCuentas regis90(21114,"Anticipo de Clientes",4,1);
PlanDeCuentas regis91(21115,"Facturas a recibir prov. nac.",4,1);
PlanDeCuentas regis92(2112,"PROVEEDORES DEL EXTERIOR",1,0);
PlanDeCuentas regis93(21121,"Proveedores del exterior",4,1);
PlanDeCuentas regis94(212,"DEUDAS FINANCIERAS",1,0);
PlanDeCuentas regis95(2121,"BANCARIAS",1,0);
PlanDeCuentas regis96(21211,"Prestamos bancarios",4,1);
PlanDeCuentas regis97(21212,"Prestamos de accionistas",4,1);
PlanDeCuentas regis98(21213,"Otros prestamos recibidos",4,1);
PlanDeCuentas regis99(213,"DEUDAS LABORALES",1,0);
PlanDeCuentas regis100(2131,"DEUDAS POR SUELDOS",1,0);
PlanDeCuentas regis101(21311,"Sueldos a Pagar",3,1);
PlanDeCuentas regis102(21312,"SAC a Pagar",3,1);
PlanDeCuentas regis103(21313,"Vacaciones a pagar",3,1);
PlanDeCuentas regis104(21314,"Seguros de vida a devolver",3,1);
PlanDeCuentas regis105(2132,"DEUDAS POR CARGAS SOCIALES",1,0);
PlanDeCuentas regis106(21321,"SUSS a Pagar",3,1);
PlanDeCuentas regis107(21322,"Obra Social Fatsa a Pagar",3,1);
PlanDeCuentas regis108(21323,"Sindicato FATSA a Pagar",3,1);
PlanDeCuentas regis109(21324,"Embargos a depositar",3,1);
PlanDeCuentas regis110(214,"DEUDAS FISCALES",1,0);
PlanDeCuentas regis111(2141,"IMPUESTOS AFIP",1,0);
PlanDeCuentas regis112(21411,"Ganancias a pagar",4,1);
PlanDeCuentas regis113(21412,"Retenciones IGcias Efectuadas",4,1);
PlanDeCuentas regis114(21413,"IVA Debito Fiscal",4,1);
PlanDeCuentas regis115(21414,"IVA a pagar",3,1);
PlanDeCuentas regis116(21415,"Perc. IIBB Res.01/2004 PBA",3,1);
PlanDeCuentas regis117(21416,"RETENC A PROV IIBB BAS AS OP",3,1);
PlanDeCuentas regis118(2142,"RENTAS",1,0);
PlanDeCuentas regis119(21421,"Ingresos brutos a Pagar",3,1);
PlanDeCuentas regis120(21421,"IMP.INMOBILIARIO A PAGAR",3,1);
PlanDeCuentas regis121(2143,"MUNICIPALES",1,0);
PlanDeCuentas regis122(21431,"Seguridad e Hig. a pagar",3,1);
PlanDeCuentas regis123(21432,"Tasa Agua a Pagar",3,1);
PlanDeCuentas regis124(215,"OTROS PASIVOS",1,0);
PlanDeCuentas regis125(2151,"DEPOSITOS EN GARANTIA",1,0);
PlanDeCuentas regis126(21511,"Deposito en garantia clientes",4,1);
PlanDeCuentas regis127(216,"PROVISIONES Y PREVISIONES",1,0);
PlanDeCuentas regis128(2161,"PROVISIONES",1,0);
PlanDeCuentas regis129(21611,"Provision Fact. a recibir",4,1);
PlanDeCuentas regis130(21612,"Provision por SAC",4,1);
PlanDeCuentas regis131(21613,"Provision Vacaciones",4,1);
PlanDeCuentas regis132(2162,"PREVISIONES",1,0);
PlanDeCuentas regis133(21621,"Prevision para Incobrables",4,1);
PlanDeCuentas regis134(21622,"Prevision para Despidos",4,1);
PlanDeCuentas regis135(3,"CAPITAL SOCIAL",1,0);
PlanDeCuentas regis136(31,"CAPITAL SOCIAL",1,0);
PlanDeCuentas regis137(311,"Capital integrado",4,0);
PlanDeCuentas regis138(312,"Ajuste de Capital",4,0);
PlanDeCuentas regis139(313,"Aportes Irrevocables",4,0);
PlanDeCuentas regis140(314,"Prima de Emision de Acciones",4,0);
PlanDeCuentas regis141(32,"RESERVAS",1,0);
PlanDeCuentas regis142(321,"Reserva Legal",4,0);
PlanDeCuentas regis143(33,"RESULTADOS",1,0);
PlanDeCuentas regis144(331,"Resultados Acumulados",4,0);
PlanDeCuentas regis145(332,"Resultado del ejercicio",4,0);
PlanDeCuentas regis146(333,"Ajuste Result. Ej. Anterior.",4,0);
PlanDeCuentas regis147(4,"INGRESOS",1,0);
PlanDeCuentas regis148(41,"INGRESOS POR VENTAS",1,0);
PlanDeCuentas regis149(411,"VENTAS DIRECTAS",1,0);
PlanDeCuentas regis150(4111,"Ventas en Pesos",4,0);
PlanDeCuentas regis151(4112,"Ventas en ME",4,0);
PlanDeCuentas regis152(42,"OTROS INGRESOS",1,0);
PlanDeCuentas regis153(421,"INGRESOS OPERATIVOS",1,0);
PlanDeCuentas regis154(4211,"Ingresos por Alquileres",4,0);
PlanDeCuentas regis155(4212,"Ingresos por licencias",4,0);
PlanDeCuentas regis156(422,"INGRESOS VARIOS",1,0);
PlanDeCuentas regis157(4221,"Ingresos Varios",4,0);
PlanDeCuentas regis158(4222,"Ingresos Varios ME",4,0);
PlanDeCuentas regis159(423,"INGRESOS FINANCIEROS",1,0);
PlanDeCuentas regis160(4231,"INGRESOS POR OP. BANCARIAS",1,0);
PlanDeCuentas regis161(4231,"Intereses Cobrados en operaciones bancarias",4,0);
PlanDeCuentas regis162(4232,"Diferencia de Cambio Positivas",4,0);
PlanDeCuentas regis163(5,"EGRESOS",1,0);
PlanDeCuentas regis164(51,"COSTO DE VENTAS",1,0);
PlanDeCuentas regis165(511,"COSTO DE VENTAS DIRECTAS",1,0);
PlanDeCuentas regis166(5111,"Costo de Vtas. Directas Pesos",4,0);
PlanDeCuentas regis167(5112,"Costo de Vtas Directas ME",4,0);
PlanDeCuentas regis168(52,"DESCUENTOS",1,0);
PlanDeCuentas regis169(521,"DESCUENTOS COMERCIALES",1,0);
PlanDeCuentas regis170(5211,"Descuentos Com. Vtas. Directas",4,0);
PlanDeCuentas regis171(5212,"Descuentos Com. Vtas. Distrib.",4,0);
PlanDeCuentas regis172(53,"GASTOS POR AREA",1,0);
PlanDeCuentas regis173(531,"SUELDOS Y JORNALES",1,0);
PlanDeCuentas regis174(5311,"Sueldos y Jornales",4,0);
PlanDeCuentas regis175(5312,"Horas Extras",4,0);
PlanDeCuentas regis176(5313,"Vacaciones",4,0);
PlanDeCuentas regis177(5314,"Sueldo A. Complementario",4,0);
PlanDeCuentas regis178(5315,"Indemnizaciones",4,1);
PlanDeCuentas regis179(532,"CARGAS SOCIALES",1,0);
PlanDeCuentas regis180(5321,"Cargas Sociales Sueldos",4,0);
PlanDeCuentas regis181(5322,"Cargas Sociales SAC",4,0);
PlanDeCuentas regis182(5323,"Cargas Sociales Vacaciones",4,0);
PlanDeCuentas regis183(533,"OTROS GS. EN PERSONAL",1,0);
PlanDeCuentas regis184(5331,"Premios",4,0);
PlanDeCuentas regis185(5332,"Atenciones al personal",4,1);
PlanDeCuentas regis186(5333,"Almuerzo y comedor",2,1);
PlanDeCuentas regis187(5334,"Ropa de Trabajo",2,1);
PlanDeCuentas regis188(5335,"Medicina laboral",4,1);
PlanDeCuentas regis189(5336,"Consumos del personal",4,1);
PlanDeCuentas regis190(5337,"Cocheras",4,1);
PlanDeCuentas regis191(5338,"Guarderias",4,1);
PlanDeCuentas regis192(5339,"Otros Gs. en Personal",4,1);
PlanDeCuentas regis193(534,"AMORTIZACIONES Dir",1,0);
PlanDeCuentas regis194(5341,"Amortizacion Inmueble",4,0);
PlanDeCuentas regis195(5342,"Amort. Maq. Y Equipos",4,0);
PlanDeCuentas regis196(5343,"Amortizacion Rodados",4,0);
PlanDeCuentas regis197(5344,"Amortizacion M. y Utiles",4,0);
PlanDeCuentas regis198(5345,"Amortizacion Mejoras Inmuebles",4,0);
PlanDeCuentas regis199(5346,"Amort. Bienes Intangibles",4,0);
PlanDeCuentas regis200(5347,"Amortizacion de Eq. de Computa",4,0);
PlanDeCuentas regis201(535,"HONORARIOS.",1,0);
PlanDeCuentas regis202(5351,"Selección de Personal",2,1);
PlanDeCuentas regis203(5352,"Honorarios directores",4,1);
PlanDeCuentas regis204(5353,"Honorarios Seg. e Higiene",4,1);
PlanDeCuentas regis205(5354,"Honorarios auditoria",2,1);
PlanDeCuentas regis206(5355,"Honorarios asesoria legal",4,1);
PlanDeCuentas regis207(5356,"Honorarios seguridad",4,1);
PlanDeCuentas regis208(5357,"Honorarios liq. haberes",4,1);
PlanDeCuentas regis209(5358,"Honorarios escribanos",4,1);
PlanDeCuentas regis210(5359,"Honorarios tercerizaciones",4,1);
PlanDeCuentas regis211(5360,"Otros Honorarios varios",4,1);
PlanDeCuentas regis212(536,"MANTENIMIENTO",1,0);
PlanDeCuentas regis213(5361,"Analisis de efluentes",4,1);
PlanDeCuentas regis214(5362,"Analisis de aguas",4,1);
PlanDeCuentas regis215(5363,"Materiales mantenimiento",2,1);
PlanDeCuentas regis216(5364,"Repuestos",4,1);
PlanDeCuentas regis217(5365,"Servicios de mantenimiento",4,1);
PlanDeCuentas regis218(5366,"Mano de obra mantenimiento",4,1);
PlanDeCuentas regis219(5367,"Servicio de limpieza",2,1);
PlanDeCuentas regis220(5368,"Elementos seg. Industrial",4,1);
PlanDeCuentas regis221(5369,"Insumos de limpieza y otros",2,1);
PlanDeCuentas regis222(53610,"Lavanderia de Ropa",2,1);
PlanDeCuentas regis223(53611,"Residuos especiales",2,1);
PlanDeCuentas regis224(537,"SEGUROS",1,0);
PlanDeCuentas regis225(5371,"Seguro Autos",2,1);
PlanDeCuentas regis226(5372,"Seguro incendio",4,1);
PlanDeCuentas regis227(5373,"Seguro de vida",4,1);
PlanDeCuentas regis228(5374,"Seguro accidente trabajo",4,1);
PlanDeCuentas regis229(5375,"Otros Seguros",4,1);
PlanDeCuentas regis230(538,"VIATICOS Y MOVILIDAD",1,0);
PlanDeCuentas regis231(5381,"Movilidad",4,1);
PlanDeCuentas regis232(5382,"Gastos de Kilometraje",4,1);
PlanDeCuentas regis233(5383,"Gastos de representacion",4,1);
PlanDeCuentas regis234(5384,"Gastos de comida",2,1);
PlanDeCuentas regis235(5385,"Gastos de Giras",4,1);
PlanDeCuentas regis236(5386,"Pasajes al exterior",4,1);
PlanDeCuentas regis237(5387,"Pasajes locales",4,1);
PlanDeCuentas regis238(5388,"Viaticos y remises",2,1);
PlanDeCuentas regis239(5389,"Motomensajeria",2,1);
PlanDeCuentas regis240(5390,"Otros fletes",4,1);
PlanDeCuentas regis241(5391,"Combustible",4,1);
PlanDeCuentas regis242(5392,"Estacionamiento",4,1);
PlanDeCuentas regis243(539,"GS PROMOC y COMERCIALES",1,0);
PlanDeCuentas regis244(5391,"Regalias pagadas",4,1);
PlanDeCuentas regis245(5392,"Entregas sin cargo",4,1);
PlanDeCuentas regis246(5393,"Publicidad institucional",4,1);
PlanDeCuentas regis247(5394,"Desarrollo nuevos prod.",4,1);
PlanDeCuentas regis248(5395,"Diseño campañas publicidad",4,1);
PlanDeCuentas regis249(5396,"Avisos publicitarios",4,1);
PlanDeCuentas regis250(5397,"Material promocional",4,1);
PlanDeCuentas regis251(5398,"Arte y diseño mat. Empaque",4,1);
PlanDeCuentas regis252(5399,"Otros gastos comerciales varios",4,1);
PlanDeCuentas regis253(5400,"Comisiones comerciales",4,1);
PlanDeCuentas regis254(5310,"IMPUESTOS",1,0);
PlanDeCuentas regis255(53101,"Impuesto a las ganancias",4,0);
PlanDeCuentas regis256(53102,"Imp. Seguridad e Higiene",4,1);
PlanDeCuentas regis257(53103,"Impuesto a los sellos",4,1);
PlanDeCuentas regis258(53104,"Imp. Ingresos Brutos",4,0);
PlanDeCuentas regis259(53105,"IVA No computable",4,1);
PlanDeCuentas regis260(53106,"Imp. Ley 25413",4,1);
PlanDeCuentas regis261(53107,"Tasas diversas",4,1);
PlanDeCuentas regis262(53108,"Impuestos diversos",4,1);
PlanDeCuentas regis263(53109,"Intereses resarcitorios",4,1);
PlanDeCuentas regis264(53110,"Intereses moratorias",4,1);
PlanDeCuentas regis265(5311,"GASTOS COMP. Y OFICINA",1,0);
PlanDeCuentas regis266(53111,"Correos",2,1);
PlanDeCuentas regis267(53112,"Telefonos fijos",2,1);
PlanDeCuentas regis268(53113,"Telefonos celulares",4,1);
PlanDeCuentas regis269(53114,"Gas",2,1);
PlanDeCuentas regis270(53115,"Fuerza motriz",2,1);
PlanDeCuentas regis271(53116,"Agua",2,1);
PlanDeCuentas regis272(53117,"Librería y art. Oficina",2,1);
PlanDeCuentas regis273(53118,"Insumos computacion",4,1);
PlanDeCuentas regis274(53119,"Servicios computacion",2,1);
PlanDeCuentas regis275(53120,"Gastos Varios Oficina",4,1);
PlanDeCuentas regis276(5312,"GASTOS PRODUCTIVOS",1,0);
PlanDeCuentas regis277(53121,"Conservacion de productos",4,1);
PlanDeCuentas regis278(53122,"Materiales de produccion",4,1);
PlanDeCuentas regis279(53123,"Agua desmineralizada",4,1);
PlanDeCuentas regis280(53124,"Materiales descartables",4,1);
PlanDeCuentas regis281(53125,"Materiales control calidad",2,1);
PlanDeCuentas regis282(53126,"Mater.analisis y reactivos",4,1);
PlanDeCuentas regis283(53127,"Otros consumos productivos",4,1);
PlanDeCuentas regis284(53128,"Materiales de Empaque",4,1);
PlanDeCuentas regis285(53129,"Validaciones",4,1);
PlanDeCuentas regis286(53130,"Calificaciones",4,1);
PlanDeCuentas regis287(53131,"Calibraciones",4,1);
PlanDeCuentas regis288(5313,"GASTOS FINANCIEROS",1,0);
PlanDeCuentas regis289(53131,"Intereses por prestamos",4,1);
PlanDeCuentas regis290(53132,"Intereses por cargas sociales",4,1);
PlanDeCuentas regis291(53133,"Difer. de cambio negativas",4,1);
PlanDeCuentas regis292(53134,"Ajuste cuentas corrientes",4,1);
PlanDeCuentas regis293(53135,"Comisiones y gs. Bancarios",2,1);
PlanDeCuentas regis294(53136,"IDC LEY 25.413 S/DEBITOS",4,1);
PlanDeCuentas regis295(53137,"Deudores Incobrables",4,1);
PlanDeCuentas regis296(53138,"Diferencia de Inventarios",4,1);
PlanDeCuentas regis297(53139,"Gtos y Comis Tarjetas",2,1);
PlanDeCuentas regis298(53140,"Intereses varios",4,1);
PlanDeCuentas regis299(53141,"Otros gastos financieros",4,1);
PlanDeCuentas regis300(53142,"RECPAM",4,1);


regis1.guardarEnDiscoReset();
regis2.guardarEnDisco();
regis3.guardarEnDisco();
regis4.guardarEnDisco();
regis5.guardarEnDisco();
regis6.guardarEnDisco();
regis7.guardarEnDisco();
regis8.guardarEnDisco();
regis9.guardarEnDisco();
regis10.guardarEnDisco();
regis11.guardarEnDisco();
regis12.guardarEnDisco();
regis13.guardarEnDisco();
regis14.guardarEnDisco();
regis15.guardarEnDisco();
regis16.guardarEnDisco();
regis17.guardarEnDisco();
regis18.guardarEnDisco();
regis19.guardarEnDisco();
regis20.guardarEnDisco();
regis21.guardarEnDisco();
regis22.guardarEnDisco();
regis23.guardarEnDisco();
regis24.guardarEnDisco();
regis25.guardarEnDisco();
regis26.guardarEnDisco();
regis27.guardarEnDisco();
regis28.guardarEnDisco();
regis29.guardarEnDisco();
regis30.guardarEnDisco();
regis31.guardarEnDisco();
regis32.guardarEnDisco();
regis33.guardarEnDisco();
regis34.guardarEnDisco();
regis35.guardarEnDisco();
regis36.guardarEnDisco();
regis37.guardarEnDisco();
regis38.guardarEnDisco();
regis39.guardarEnDisco();
regis40.guardarEnDisco();
regis41.guardarEnDisco();
regis42.guardarEnDisco();
regis43.guardarEnDisco();
regis44.guardarEnDisco();
regis45.guardarEnDisco();
regis46.guardarEnDisco();
regis47.guardarEnDisco();
regis48.guardarEnDisco();
regis49.guardarEnDisco();
regis50.guardarEnDisco();
regis51.guardarEnDisco();
regis52.guardarEnDisco();
regis53.guardarEnDisco();
regis54.guardarEnDisco();
regis55.guardarEnDisco();
regis56.guardarEnDisco();
regis57.guardarEnDisco();
regis58.guardarEnDisco();
regis59.guardarEnDisco();
regis60.guardarEnDisco();
regis61.guardarEnDisco();
regis62.guardarEnDisco();
regis63.guardarEnDisco();
regis64.guardarEnDisco();
regis65.guardarEnDisco();
regis66.guardarEnDisco();
regis67.guardarEnDisco();
regis68.guardarEnDisco();
regis69.guardarEnDisco();
regis70.guardarEnDisco();
regis71.guardarEnDisco();
regis72.guardarEnDisco();
regis73.guardarEnDisco();
regis74.guardarEnDisco();
regis75.guardarEnDisco();
regis76.guardarEnDisco();
regis77.guardarEnDisco();
regis78.guardarEnDisco();
regis79.guardarEnDisco();
regis80.guardarEnDisco();
regis81.guardarEnDisco();
regis82.guardarEnDisco();
regis83.guardarEnDisco();
regis84.guardarEnDisco();
regis85.guardarEnDisco();
regis86.guardarEnDisco();
regis87.guardarEnDisco();
regis88.guardarEnDisco();
regis89.guardarEnDisco();
regis90.guardarEnDisco();
regis91.guardarEnDisco();
regis92.guardarEnDisco();
regis93.guardarEnDisco();
regis94.guardarEnDisco();
regis95.guardarEnDisco();
regis96.guardarEnDisco();
regis97.guardarEnDisco();
regis98.guardarEnDisco();
regis99.guardarEnDisco();
regis100.guardarEnDisco();
regis101.guardarEnDisco();
regis102.guardarEnDisco();
regis103.guardarEnDisco();
regis104.guardarEnDisco();
regis105.guardarEnDisco();
regis106.guardarEnDisco();
regis107.guardarEnDisco();
regis108.guardarEnDisco();
regis109.guardarEnDisco();
regis110.guardarEnDisco();
regis111.guardarEnDisco();
regis112.guardarEnDisco();
regis113.guardarEnDisco();
regis114.guardarEnDisco();
regis115.guardarEnDisco();
regis116.guardarEnDisco();
regis117.guardarEnDisco();
regis118.guardarEnDisco();
regis119.guardarEnDisco();
regis120.guardarEnDisco();
regis121.guardarEnDisco();
regis122.guardarEnDisco();
regis123.guardarEnDisco();
regis124.guardarEnDisco();
regis125.guardarEnDisco();
regis126.guardarEnDisco();
regis127.guardarEnDisco();
regis128.guardarEnDisco();
regis129.guardarEnDisco();
regis130.guardarEnDisco();
regis131.guardarEnDisco();
regis132.guardarEnDisco();
regis133.guardarEnDisco();
regis134.guardarEnDisco();
regis135.guardarEnDisco();
regis136.guardarEnDisco();
regis137.guardarEnDisco();
regis138.guardarEnDisco();
regis139.guardarEnDisco();
regis140.guardarEnDisco();
regis141.guardarEnDisco();
regis142.guardarEnDisco();
regis143.guardarEnDisco();
regis144.guardarEnDisco();
regis145.guardarEnDisco();
regis146.guardarEnDisco();
regis147.guardarEnDisco();
regis148.guardarEnDisco();
regis149.guardarEnDisco();
regis150.guardarEnDisco();
regis151.guardarEnDisco();
regis152.guardarEnDisco();
regis153.guardarEnDisco();
regis154.guardarEnDisco();
regis155.guardarEnDisco();
regis156.guardarEnDisco();
regis157.guardarEnDisco();
regis158.guardarEnDisco();
regis159.guardarEnDisco();
regis160.guardarEnDisco();
regis161.guardarEnDisco();
regis162.guardarEnDisco();
regis163.guardarEnDisco();
regis164.guardarEnDisco();
regis165.guardarEnDisco();
regis166.guardarEnDisco();
regis167.guardarEnDisco();
regis168.guardarEnDisco();
regis169.guardarEnDisco();
regis170.guardarEnDisco();
regis171.guardarEnDisco();
regis172.guardarEnDisco();
regis173.guardarEnDisco();
regis174.guardarEnDisco();
regis175.guardarEnDisco();
regis176.guardarEnDisco();
regis177.guardarEnDisco();
regis178.guardarEnDisco();
regis179.guardarEnDisco();
regis180.guardarEnDisco();
regis181.guardarEnDisco();
regis182.guardarEnDisco();
regis183.guardarEnDisco();
regis184.guardarEnDisco();
regis185.guardarEnDisco();
regis186.guardarEnDisco();
regis187.guardarEnDisco();
regis188.guardarEnDisco();
regis189.guardarEnDisco();
regis190.guardarEnDisco();
regis191.guardarEnDisco();
regis192.guardarEnDisco();
regis193.guardarEnDisco();
regis194.guardarEnDisco();
regis195.guardarEnDisco();
regis196.guardarEnDisco();
regis197.guardarEnDisco();
regis198.guardarEnDisco();
regis199.guardarEnDisco();
regis200.guardarEnDisco();
regis201.guardarEnDisco();
regis202.guardarEnDisco();
regis203.guardarEnDisco();
regis204.guardarEnDisco();
regis205.guardarEnDisco();
regis206.guardarEnDisco();
regis207.guardarEnDisco();
regis208.guardarEnDisco();
regis209.guardarEnDisco();
regis210.guardarEnDisco();
regis211.guardarEnDisco();
regis212.guardarEnDisco();
regis213.guardarEnDisco();
regis214.guardarEnDisco();
regis215.guardarEnDisco();
regis216.guardarEnDisco();
regis217.guardarEnDisco();
regis218.guardarEnDisco();
regis219.guardarEnDisco();
regis220.guardarEnDisco();
regis221.guardarEnDisco();
regis222.guardarEnDisco();
regis223.guardarEnDisco();
regis224.guardarEnDisco();
regis225.guardarEnDisco();
regis226.guardarEnDisco();
regis227.guardarEnDisco();
regis228.guardarEnDisco();
regis229.guardarEnDisco();
regis230.guardarEnDisco();
regis231.guardarEnDisco();
regis232.guardarEnDisco();
regis233.guardarEnDisco();
regis234.guardarEnDisco();
regis235.guardarEnDisco();
regis236.guardarEnDisco();
regis237.guardarEnDisco();
regis238.guardarEnDisco();
regis239.guardarEnDisco();
regis240.guardarEnDisco();
regis241.guardarEnDisco();
regis242.guardarEnDisco();
regis243.guardarEnDisco();
regis244.guardarEnDisco();
regis245.guardarEnDisco();
regis246.guardarEnDisco();
regis247.guardarEnDisco();
regis248.guardarEnDisco();
regis249.guardarEnDisco();
regis250.guardarEnDisco();
regis251.guardarEnDisco();
regis252.guardarEnDisco();
regis253.guardarEnDisco();
regis254.guardarEnDisco();
regis255.guardarEnDisco();
regis256.guardarEnDisco();
regis257.guardarEnDisco();
regis258.guardarEnDisco();
regis259.guardarEnDisco();
regis260.guardarEnDisco();
regis261.guardarEnDisco();
regis262.guardarEnDisco();
regis263.guardarEnDisco();
regis264.guardarEnDisco();
regis265.guardarEnDisco();
regis266.guardarEnDisco();
regis267.guardarEnDisco();
regis268.guardarEnDisco();
regis269.guardarEnDisco();
regis270.guardarEnDisco();
regis271.guardarEnDisco();
regis272.guardarEnDisco();
regis273.guardarEnDisco();
regis274.guardarEnDisco();
regis275.guardarEnDisco();
regis276.guardarEnDisco();
regis277.guardarEnDisco();
regis278.guardarEnDisco();
regis279.guardarEnDisco();
regis280.guardarEnDisco();
regis281.guardarEnDisco();
regis282.guardarEnDisco();
regis283.guardarEnDisco();
regis284.guardarEnDisco();
regis285.guardarEnDisco();
regis286.guardarEnDisco();
regis287.guardarEnDisco();
regis288.guardarEnDisco();
regis289.guardarEnDisco();
regis290.guardarEnDisco();
regis291.guardarEnDisco();
regis292.guardarEnDisco();
regis293.guardarEnDisco();
regis294.guardarEnDisco();
regis295.guardarEnDisco();
regis296.guardarEnDisco();
regis297.guardarEnDisco();
regis298.guardarEnDisco();
regis299.guardarEnDisco();
regis300.guardarEnDisco();


//Comprobante regist1(1,"A","02/03/2020","29/08/2019",1,198,8,9249,11311,1,21103,56,4431,76,25535,32,1,"ADMIN");


//regist1.guardarEnDiscoReset();


}
