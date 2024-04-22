#include "Header.h"

/*
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
El operador "->" en C simplifica el acceso a los miembros de una estructura o uni�n a trav�s de un puntero a esa estructura o uni�n.
Es especialmente �til cuando trabajamos con estructuras a trav�s de punteros, evitando la necesidad de usar la notaci�n de desreferenciaci�n (*) junto con la notaci�n de punto (.).
La sintaxis "lista->longitud" es m�s legible y se usa com�nmente en programas que hacen un uso intensivo de punteros a estructuras.
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
*/

// Funci�n para inicializar la lista
void inicializarLista(struct Lista *lista) {

    lista->longitud = 0;

}

//----------------------------------------------------------------------------------------------

// Funci�n para insertar un elemento al final de la lista
void insertar(struct Lista *lista, int valor) {

    if (lista->longitud < MAX_ELEMENTOS) {

        lista->elementos[lista->longitud] = valor;
        lista->longitud++;

        printf("Elemento insertado correctamente.\n");

    } else {

        printf("Error: La lista est� llena, no se puede insertar m�s elementos.\n");

    }
}

//----------------------------------------------------------------------------------------------

// Funci�n para imprimir todos los elementos de la lista
void imprimirLista(struct Lista *lista) {

    printf("Lista: ");

    for (int i = 0; i < lista->longitud; i++) {

        printf("%d -> ", lista->elementos[i]);

    }
    printf("NULL\n");
}
