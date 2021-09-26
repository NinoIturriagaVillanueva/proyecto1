#ifndef LIST_H_
#define LIST_H_
#include <stdbool.h>
typedef struct Lista Lista;
typedef struct Nodo Nodo;

struct Lista{
	Nodo *head;
	int n;
};

struct Nodo{
	char info;
	Nodo *sig;
};

//Operaciones:

Lista *crearLista();
void insertarNodoFin(Lista *, char);
void recorrerLista(Lista *);

void linea1(Lista *, FILE *);
void med1(Lista *, FILE *);
void linea2(Lista *, FILE *);
void med2(Lista *, FILE *);
void linea3(Lista *, FILE *);

Nodo *ultimo(Lista *);
void eliminar(Lista *);

int contApellido(Lista *l);
void apellido(FILE *, int);

void butil(Lista *, FILE *);
void etil(Lista *, FILE *);
void metil(Lista *, FILE *);
void pentil(Lista *, FILE *);
void propil(Lista *, FILE *);
#endif