#include <iostream>
#include <cstdlib>
#include "rlutil.h"
#include "Mensaje.h"

using namespace rlutil;

using namespace std;

Mensaje::Mensaje(string mensaje, TipoMensaje tipoMensaje, int x, int y)
{
    _mensaje=mensaje;
    _tipoMensaje=tipoMensaje;
    _x=x;
    _y=y;
}

void Mensaje::mostrar()
{

    int color;

    switch(_tipoMensaje)
    {

    case TipoMensaje::Info: // Info
        color = rlutil::YELLOW;
        break;
    case TipoMensaje::Exito: // Éxito
        color = rlutil::LIGHTGREEN;
        break;
    case TipoMensaje::Error: // Error
        color = rlutil::LIGHTRED;
        break;

    }

    rlutil::setColor(color);
    rlutil::locate(_x, _y);
    cout << _mensaje;

}

