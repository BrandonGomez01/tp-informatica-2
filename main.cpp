#include "...\libreria\LIBRERIA_H.h"


int main() 
{
    datos_t config; // estructura donde va a estar los datos que necesita la maquina 
    estados_t estado = okay; //inicializo la maquina 
    estados_t (*fsm[])(datos_t) = {f_espera, f_desconexion};/* Declaro el vector puntero a funciones */
    config=f_inicio(); // Llamo a la funcion inicio 
    while(1)
    {
	    estado = (*fsm[estado])(config);
    }
	return 0;
}
