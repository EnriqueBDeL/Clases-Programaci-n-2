#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
//-----------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//|||||||||||||||||||||||||||||||||||
int Menu();
void Saludar (char nombre[100]);
void Definicion ();
//|||||||||||||||||||||||||||||||||||

/* (COMENTARIO)

    Es una buena pr�ctica definir las funciones en un archivo de encabezado (.h) utilizando prototipos de funci�n.

    Esto ayuda a proporcionar una interfaz clara y p�blica para las funciones,permitiendo que otros m�dulos
    conozcan c�mo usarlas correctamente sin necesidad de conocer los detalles de implementaci�n.

    Adem�s, incluir las declaraciones de funciones en un archivo de encabezado puede
    ayudar a evitar warnings y errores de compilaci�n relacionados con el enlace de funciones.

    Si las funciones se utilizan en varios archivos de c�digo fuente, definirlas en un archivo de encabezado
    promueve la coherencia y facilita el mantenimiento del c�digo

*/

//-----------------------------------------
#endif // MENU_H_INCLUDED
