#include "Header.h"

// Crea un �rbol vac�o
P_NODO_ARBOL crearArbol() {
    return NULL;
}

// Comprueba si el �rbol est� vac�o
int esVacio(P_NODO_ARBOL a) {
    return (a == NULL);
}

// Reserva memoria para un nuevo nodo
P_NODO_ARBOL alojar_nodo_arbol() {
    return ((P_NODO_ARBOL)malloc(sizeof(NODO_ARBOL)));
}

// Inserta un coche en el �rbol binario
P_NODO_ARBOL insertar(P_NODO_ARBOL arbol, COCHE coche) {
    P_NODO_ARBOL p;

    if (arbol == NULL) {
        p = alojar_nodo_arbol();  // Reservamos memoria
        p->izq = p->der = NULL;  // Inicializamos hijos a NULL
        p->coche = coche;        // Almacenar el coche
        return p;
    }

    if (arbol->coche.ano == coche.ano)  // Si el a�o es el mismo, no insertamos (no duplicados)
        return arbol;

    if (arbol->coche.ano > coche.ano)  // Inserta a la izquierda si es menor
        arbol->izq = insertar(arbol->izq, coche);
    else  // Inserta a la derecha si es mayor
        arbol->der = insertar(arbol->der, coche);

    return arbol;
}

// Encuentra el nodo que contiene un coche con el a�o especificado
P_NODO_ARBOL encontrar(P_NODO_ARBOL arbol, int ano) {
    if (arbol == NULL)  // Si el �rbol est� vac�o
        return NULL;

    if (arbol->coche.ano == ano)  // Encontrado
        return arbol;
    else if (arbol->coche.ano > ano)  // Buscar a la izquierda
        return encontrar(arbol->izq, ano);
    else  // Buscar a la derecha
        return encontrar(arbol->der, ano);
}

// Eliminar un coche del �rbol binario
P_NODO_ARBOL eliminar(P_NODO_ARBOL arbol, int ano) {
    if (arbol == NULL)
        return NULL;

    if (arbol->coche.ano > ano)  // Buscar a la izquierda
        arbol->izq = eliminar(arbol->izq, ano);
    else if (arbol->coche.ano < ano)  // Buscar a la derecha
        arbol->der = eliminar(arbol->der, ano);
    else {
        if (arbol->izq == NULL) {  // Si solo tiene hijo derecho
            P_NODO_ARBOL temp = arbol->der;
            free(arbol);
            return temp;
        } else if (arbol->der == NULL) {  // Si solo tiene hijo izquierdo
            P_NODO_ARBOL temp = arbol->izq;
            free(arbol);
            return temp;
        }

        // Si tiene dos hijos, encontrar el nodo m�nimo del sub�rbol derecho
        P_NODO_ARBOL temp = arbol->der;
        while (temp->izq != NULL)
            temp = temp->izq;

        arbol->coche = temp->coche;  // Copiar el valor del nodo m�nimo

        // Eliminar el nodo m�nimo
        arbol->der = eliminar(arbol->der, temp->coche.ano);
    }

    return arbol;
}

// InOrder traversal para listar coches
void inOrder(P_NODO_ARBOL a) {
    if (!esVacio(a)) {
        inOrder(a->izq);
        printf("Marca: %s | Modelo: %s | A�o: %d\n", a->coche.marca, a->coche.modelo, a->coche.ano);
        inOrder(a->der);
    }
}
