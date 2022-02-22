#ifndef LOGIN_H
#define LOGIN_H
#include <string>

using namespace std;


class Login
{

    private:
        int _codigoUser;
        char _usuario[25];
        char _password[20];
        char _email[20];
        bool _estado;


    public:
        int getCodigoUser();
        string getUsuario();
        const char * getUsuarioChar();
        string getPassword();
        const char * getPasswordChar();
        string getEmail();
        bool getEstado();

        void setCodigoUser(int);
        void setUsuario(string);
        void setPassword(string);
        void setEmail(string);
        void setEstado(bool);

        void crearUsuario();
        void ingresarUsuario();
        void cargar();
        void mostrar();
        bool guardarEnDisco();
        bool leerDeDisco(int);


};

#endif // LOGIN_H
