//---------------------------------------------------------------------------------------------------------------------
// En este c�digo aprender�s a configurar la localizaci�n para que el programa pueda mostrar caracteres especiales.
//---------------------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <locale.h> // librer�a que maneja la configuraci�n regional.

int main() {

    setlocale(LC_ALL, ""); // permite que tu programa utilice la configuraci�n regional del sistema.

    printf("�Hola!\n\nAqu� est�n las letras con acentos: �, �, �, � y �\nAqu� est� la letra e�e: �\n\n");

    return 0;
}
