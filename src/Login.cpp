#include "Login.h"

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
#include "Reportes.h"
#include "Mensaje.h"
#include "Funciones.h"



using namespace std;

using namespace rlutil;

/*
int Login::setCodigoUser(string user){

    Login reg;
    int i = 0;
    while(reg.leerDeDisco(i))
    {
        if (user.compare(reg.getUsuario()) == 0)
        {
           reg.getCodigoUser()=i;
        }
        i++;
    }
    return -1

}
*/
string Login::getUsuario(){

    string user = _usuario;
    return _usuario;

}
const char *Login::getUsuarioChar(){

    return _usuario;

}
string Login::getPassword(){

    string pass = _password;
    return _password;

}

const char *Login::getPasswordChar(){

    return _password;

}


string Login::getEmail(){

    string email = _email;
    return _email;

}

void Login::setCodigoUser(int cod){

    _codigoUser=cod;

}
void Login::setUsuario(string user){

  strcpy(_usuario, user.c_str());

}
void Login::setPassword(string pass){

   strcpy(_password, pass.c_str());

}
void Login::setEmail(string email){

  strcpy(_email, email.c_str());

}

void Login::setEstado(bool estado){

  _estado=estado;

}
void Login::cargar(){

    string user;
    cin.ignore();
    getline(cin,user);

    gotoxy(40,14);cout << "INGRESE EL MAIL: ";

    string email;
    cin.ignore();
    getline(cin,email);


    gotoxy(40,15);cout << "INGRESE EL PASSWORD (CONTRASENIA): ";
    string password;
    cin.ignore();
    getline(cin,password);

    gotoxy(40,16);cout << "              **              ";
    gotoxy(40,17);cout << "------------------------------";

    setUsuario(user);
    setPassword(password);
    setEmail(email);
    setEstado(true);



}
void Login::mostrar(){






}
bool Login::guardarEnDisco(){
    FILE *p;
    p = fopen("usuarios.dat", "ab");
    if (p == NULL){
        return false;
    }
    bool ok;
    ok = fwrite(this, sizeof(Login), 1, p);
    fclose(p);
    return ok;


}

bool Login::leerDeDisco(int pos){

    FILE *p;
    p = fopen("usuarios.dat", "rb");
    if (p == NULL){
        return false;
    }
    fseek(p, pos * sizeof(Login), SEEK_SET);
    bool ok;
    ok = fread(this, sizeof(Login), 1, p);
    fclose(p);
    return ok;

}
