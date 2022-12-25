// Lista ligada

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Simbolo{ // estructura de un nodo
    char *nombre; // nombre del nodo
    struct Simbolo *sig;  // apuntador al siguiente nodo
};

struct Simbolo *crea_nodo(char *nombre, struct Simbolo *siguiente_nodo){ // crea un nodo con el nombre que se le pasa como parámetro y que apunte al siguiente nodo que se le pasa como parámetro
    struct Simbolo *nuevo_nodo = malloc(sizeof(struct Simbolo)); // crea un nuevo nodo
    nuevo_nodo->nombre = nombre; // asigna el nombre al nuevo nodo
    nuevo_nodo->sig = siguiente_nodo; // asigna el siguiente nodo al nuevo nodo
    return nuevo_nodo; // regresa el nuevo nodo
}

struct Simbolo *insertar_inicio(struct Simbolo *primer_nodo, char *nombre){ // inserta un nodo al inicio de la lista
    struct Simbolo *nuevo_nodo = crea_nodo(nombre, primer_nodo); // crea un nuevo nodo
    return nuevo_nodo; // regresa el nuevo nodo
}

struct Simbolo *insertar_medio(struct Simbolo *primer_nodo, char *nombre, int posicion){ // inserta un nodo en la posición que se le pasa como parámetro
    struct Simbolo *aux = primer_nodo; // auxiliar para recorrer la lista
    struct Simbolo *anterior = NULL; // auxiliar para guardar el nodo anterior
    int i = 0; // contador
    while(aux != NULL && i < posicion){ // mientras no sea el final de la lista y el contador sea menor a la posición
        anterior = aux; // guarda el nodo anterior
        aux = aux->sig; // avanza al siguiente nodo
        i++; // incrementa el contador
    }
    struct Simbolo *nuevo_nodo = crea_nodo(nombre, aux); // crea un nuevo nodo
    if(anterior == NULL){ // si es el primer nodo
        return nuevo_nodo; // regresa el nuevo nodo
    }
    anterior->sig = nuevo_nodo; // el nodo anterior apunta al nuevo nodo
    return primer_nodo; // regresa el primer nodo
}

struct Simbolo *insertar_final(struct Simbolo *primer_nodo, char *nombre){ // inserta un nodo al final de la lista
    struct Simbolo *aux = primer_nodo; // auxiliar para recorrer la lista
    struct Simbolo *anterior = NULL; // auxiliar para guardar el nodo anterior
    while(aux != NULL){ // mientras no sea el final de la lista
        anterior = aux; // guarda el nodo anterior
        aux = aux->sig; // avanza al siguiente nodo
    }
    struct Simbolo *nuevo_nodo = crea_nodo(nombre, NULL); // crea un nuevo nodo
    if(anterior == NULL){ // si es el primer nodo
        return nuevo_nodo; // regresa el nuevo nodo
    }
    anterior->sig = nuevo_nodo; // el nodo anterior apunta al nuevo nodo
    return primer_nodo; // regresa el primer nodo
}

int esta_vacia(struct Simbolo *primer_nodo){ // indica si la lista está vacía
    if(primer_nodo == NULL){ // si el primer nodo es NULL, la lista está vacía
        return 1; // regresa 1
    }
    return 0;  // regresa 0
}

void imprimir_tabla(struct Simbolo *primer_nodo){ // imprimir la lista
    struct Simbolo *aux = primer_nodo; // auxiliar para recorrer la lista
    while(aux != NULL){ // mientras no sea el final de la lista
        printf("%s ", aux->nombre);
        aux = aux->sig;
    }
    printf(" "); // imprime un espacio al final
}

struct Simbolo *eliminar_nodo(struct Simbolo *primer_nodo, char *nombre){ // eliminar un nodo por su nombre
    struct Simbolo *aux = primer_nodo; // auxiliar para recorrer la lista
    struct Simbolo *anterior = NULL; // auxiliar para guardar el nodo anterior
    while(aux != NULL){ // mientras no sea el final de la lista
        if(strcmp(aux->nombre, nombre) == 0){ // strcmp compara dos cadenas de caracteres
            if(anterior == NULL){ // si es el primer nodo
                primer_nodo = aux->sig; // el primer nodo apunta al siguiente nodo
            }else{ // si no es el primer nodo
                anterior->sig = aux->sig; // el nodo anterior apunta al siguiente nodo
            }
            free(aux); // libera la memoria del nodo
            return primer_nodo; // regresa el primer nodo
        }
        anterior = aux; // guarda el nodo anterior
        aux = aux->sig; // avanza al siguiente nodo
    }
    return primer_nodo; // si no se encuentra el nodo
}

struct Simbolo *buscar_nodo(struct Simbolo *primer_nodo, char *nombre){ // buscar un nodo por su nombre
    struct Simbolo *aux = primer_nodo; // auxiliar para recorrer la lista
    while(aux != NULL){ // mientras no sea el final de la lista
        if(strcmp(aux->nombre, nombre) == 0){ // strcmp compara dos cadenas de caracteres
            return aux; // regresa el nodo
        }
        aux = aux->sig; 
    }
}

int main(){
    struct Simbolo *primer_nodo = NULL; // NULL es equivalente a 0
    primer_nodo = insertar_inicio(primer_nodo, "a"); // inserta un nodo al inicio de la lista
    primer_nodo = insertar_inicio(primer_nodo, "b");  
    primer_nodo = insertar_inicio(primer_nodo, "c");
    primer_nodo = insertar_inicio(primer_nodo, "d");
    primer_nodo = insertar_inicio(primer_nodo, "e");
    imprimir_tabla(primer_nodo); 
    return 0;
}

//struct Simbolo *crea_nodo(char *nombre, struct Simbolo *siguiente_nodo);
//struct Simbolo *insertar_inicio(struct Simbolo *primer_nodo, char *nombre);
//int esta_vacia(struct Simbolo *primer_nodo);

//void imprimir_tabla(struct Nodo *primer_nodo);


