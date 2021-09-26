#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

Lista *crearLista(){
	Lista *l = (Lista *)malloc(sizeof(Lista));
	l->head = NULL;
	l->n = 0;
	return l;
}

void insertarNodoFin(Lista *l, char x){
	Nodo *n = (Nodo *)malloc(sizeof(Nodo));
	if(n != NULL){
		n->info = x;
		n->sig = NULL;
		if(l->head == NULL){
			l->head = n;
		}else{
			Nodo *aux = ultimo(l);
			aux->sig = n;
		}
	}else{
		printf("Error en memoria\n");
	}
	(l->n)++;
}

void recorrerLista(Lista *l){
	Nodo *n;
	n = l->head;
	while(n != NULL){
		printf("%d ", n->info);
		n = n->sig;
	}
	printf("\n");
}

//---------------------------------

void linea1(Lista *l, FILE *f_output){ //LINEA DE +
	Nodo *a;
	a = l->head;
	while(a != NULL){
		int cont = 0;
		if(a->info == '+'){
			a = a->sig;
			if(a->info == '-'){
				a = a->sig->sig;
				while(a->info != '#'){
					if(a->info == '2'){
						fputs("CH2", f_output);
						cont++;
					}else{
						fputs("CH3", f_output);
						cont++;
					}
					a = a->sig;
				}
				a = a->sig->sig;
				while(a->info != '#'){
					a=a->sig;
				}
				int i = 0;
				while(i < cont){
					a = a->sig;
					i++;
				}
				putc(' ', f_output);
			}else{
				a = a->sig;
				while(a->info != '#'){
					if(a->info == '2'){
						fputs("CH2", f_output);
						cont++;
					}else{
						fputs("CH3", f_output);
						cont++;
					}
					a = a->sig;
				}
				int i = 0;
				while(i < cont){
					a = a->sig;
					i++;
				}
				putc(' ', f_output);
			}
		}
		
		if(a->info == '-'){
			a = a->sig->sig;
			while(a->info != '#'){
				a = a->sig;
			}
		}
		
		if(a->info == '2' || a->info == '3'){
			fputs("   ", f_output);
		}
		a = a->sig;
	}
	putc('\n', f_output);
}

void med1(Lista *l, FILE *f_output){
	Nodo *a;
	a = l->head;
	while(a != NULL){
		if(a->info == '+'){
			a = a->sig;
			if(a->info == '-'){
				a = a->sig->sig;
				while(a->info != '#'){
					a = a->sig;
				}
				a = a->sig->sig;
				while(a->info != '#'){
					a=a->sig;
				}
				putc('|', f_output);
			}else{
				a = a->sig;
				while(a->info != '#'){
					a = a->sig;
				}
				fputs("| ", f_output);
			}
		}
		
		if(a->info == '-'){
			a = a->sig->sig;
			while(a->info != '#'){
				a = a->sig;
			}
			fputs("  ", f_output);
		}
		
		if(a->info == '2' || a->info == '3'){
			fputs("   ", f_output);
		}
		a = a->sig;
	}
	putc('\n', f_output);
}

void linea2(Lista *l, FILE *f_output){
	Nodo *a;
	a = l->head;
	bool flag = false;
	while(a != NULL){
		if(a->info == '#'){
			flag = true;
		}
		while(flag != false){
			a = a->sig;
			if(a->info == '#'){
				flag = false;
			}
		}
		if(a->info == '2'){
			fputs("CH2", f_output);
		}else if(a->info == '3'){
			fputs("CH3", f_output);
		}else if(a->info == '+'){
			if(a->sig->info == '-'){
				putc('C', f_output);
				a = a->sig;
			}else{
				fputs("CH", f_output);
			}
		}else if(a->info == '-'){
			fputs("CH", f_output);
		}
		a = a->sig;
	}
	putc('\n', f_output);
}

void med2(Lista *l, FILE *f_output){
	Nodo *a;
	a = l->head;
	while(a != NULL){
		if(a->info == '+'){
			a = a->sig;
			if(a->info == '-'){
				a = a->sig->sig;
				while(a->info != '#'){
					a = a->sig;
				}
				a = a->sig->sig;
				while(a->info != '#'){
					a = a->sig;
				}
				putc('|', f_output);
			}else{
				a = a->sig;
				while(a->info != '#'){
					a = a->sig;
				}
				fputs("   ", f_output);
			}
		}
		
		if(a->info == '-'){
			a = a->sig->sig;
			while(a->info != '#'){
				a = a->sig;
			}
			fputs("| ", f_output);
		}
		
		if(a->info == '2' || a->info == '3'){
			fputs("   ", f_output);
		}
		a = a->sig;
	}
	putc('\n', f_output);
}

void linea3(Lista *l, FILE *f_output){ //LINEA DE -
	Nodo *a;
	a = l->head;
	while(a != NULL){
		int cont = 0;
		if(a->info == '+'){
			a = a->sig;
			if(a->info == '-'){
				a = a->sig->sig;
				while(a->info != '#'){
					a = a->sig;
				}
				a = a->sig->sig;
				while(a->info != '#'){
					if(a->info == '2'){
						fputs("CH2", f_output);
						cont++;
					}else{
						fputs("CH3", f_output);
						cont++;
					}
					a = a->sig;
				}
				int i = 0;
				while(i < cont){
					a = a->sig;
					i++;
				}
				putc(' ', f_output);
			}else{
				a = a->sig;
				while(a->info != '#'){
					a = a->sig;
				}
			}
		}
		
		if(a->info == '-'){
			a = a->sig->sig;
			while(a->info != '#'){
				if(a->info == '2'){
					fputs("CH2", f_output);
					cont++;
				}else{
					fputs("CH3", f_output);
					cont++;
				}
				a = a->sig;
			}
			int i=0;
			while(i < cont){
				a = a->sig;
				i++;
			}
			putc(' ', f_output);
		}
		
		if(a->info == '2' || a->info == '3'){
			fputs("   ", f_output);
		}
		a = a->sig;
	}
	putc('\n', f_output);
}

Nodo *ultimo(Lista *l){
	Nodo *a;
	a = l->head;
	while(a->sig != NULL){
		a = a->sig;
	}
	return a;
}

void eliminar(Lista *l){
	Nodo *a;
	if(l->head == NULL){
		
	}else{
		while(l->head != NULL){
			a = l->head;
			l->head = a->sig;
			free(a);
			(l->n)--;
		}
	}
}

void butil(Lista *l, FILE *f_output2){
	int n1 = 0;
	int n4 = 0;
	Nodo *a;
	a = l->head;
	bool flag = false;
	while(a != NULL){
		int contador = 0;
		if(a->info == '#'){
			flag = true;
		}
		while(flag != false){
			a = a->sig;
			if(a->info == '#'){
				flag = false;
			}
			contador++;
		}
		contador--;
		
		if(a->info == '2'){
			n1++;
		}else if(a->info == '3'){
			n1++;
		}else if(a->info == '+'){
			if(a->sig->info == '-'){
				n1++;
				a = a->sig;
			}else{
				n1++;
			}
		}else if(a->info == '-'){
			n1++;
		}
		if(contador == 4){
			char m = n1 + '0';
			putc(' ', f_output2);
			putc(m, f_output2);
			fputs(",", f_output2);
			n4++;
		}
		a = a->sig;
	}
	if(n4 == 4) fputs("-tetrabutil", f_output2);
	if(n4 == 3) fputs("-tributil", f_output2);
	if(n4 == 2) fputs("-dibutil", f_output2);
	if(n4 == 1) fputs("-butil", f_output2);
}

void etil(Lista *l, FILE *f_output2){
	int n1 = 0;
	int n2 = 0;
	Nodo *a;
	a = l->head;
	bool flag = false;
	while(a != NULL){
		int contador = 0;
		if(a->info == '#'){
			flag = true;
		}
		while(flag != false){
			a = a->sig;
			if(a->info == '#'){
				flag = false;
			}
			contador++;
		}
		contador--;
		
		if(a->info == '2'){
			n1++;
		}else if(a->info == '3'){
			n1++;
		}else if(a->info == '+'){
			if(a->sig->info == '-'){
				n1++;
				a = a->sig;
			}else{
				n1++;
			}
		}else if(a->info == '-'){
			n1++;
		}
		if(contador == 2){
			char m = n1 + '0';
			putc(' ', f_output2);
			putc(m, f_output2);
			fputs(",", f_output2);
			n2++;
		}
		a = a->sig;
	}
	if(n2 == 4) fputs("-tetraetil", f_output2);
	if(n2 == 3) fputs("-trietil", f_output2);
	if(n2 == 2) fputs("-dietil", f_output2);
	if(n2 == 1) fputs("-etil", f_output2);
}

void metil(Lista *l, FILE *f_output2){
	int n1 = 0;
	int n = 0;
	Nodo *a;
	a = l->head;
	bool flag = false;
	while(a != NULL){
		int contador = 0;
		if(a->info == '#'){
			flag = true;
		}
		while(flag != false){
			a = a->sig;
			if(a->info == '#'){
				flag = false;
			}
			contador++;
		}
		contador--;
		
		if(a->info == '2'){
			n1++;
		}else if(a->info == '3'){
			n1++;
		}else if(a->info == '+'){
			if(a->sig->info == '-'){
				n1++;
				a = a->sig;
			}else{
				n1++;
			}
		}else if(a->info == '-'){
			n1++;
		}
		if(contador == 1){
			char m = n1 + '0';
			putc(' ', f_output2);
			putc(m, f_output2);
			fputs(",", f_output2);
			n++;
		}
		a = a->sig;
	}
	if(n == 4) fputs("-tetrametil", f_output2);
	if(n == 3) fputs("-trimetil", f_output2);
	if(n == 2) fputs("-dimetil", f_output2);
	if(n == 1) fputs("-metil", f_output2);
}

void pentil(Lista *l, FILE *f_output2){
	int n1 = 0;
	int n5 = 0;
	Nodo *a;
	a = l->head;
	bool flag = false;
	while(a != NULL){
		int contador = 0;
		if(a->info == '#'){
			flag = true;
		}
		while(flag != false){
			a = a->sig;
			if(a->info == '#'){
				flag = false;
			}
			contador++;
		}
		contador--;
		
		if(a->info == '2'){
			n1++;
		}else if(a->info == '3'){
			n1++;
		}else if(a->info == '+'){
			if(a->sig->info == '-'){
				n1++;
				a = a->sig;
			}else{
				n1++;
			}
		}else if(a->info == '-'){
			n1++;
		}
		if(contador == 5){
			char m = n1 + '0';
			putc(' ', f_output2);
			putc(m, f_output2);
			fputs(",", f_output2);
			n5++;
		}
		a = a->sig;
	}
	if(n5 == 4) fputs("-tetrapentil", f_output2);
	if(n5 == 3) fputs("-tripentil", f_output2);
	if(n5 == 2) fputs("-dipentil", f_output2);
	if(n5 == 1) fputs("-pentil", f_output2);
}

void propil(Lista *l, FILE *f_output2){
	int n1 = 0;
	int n3 = 0;
	Nodo *a;
	a = l->head;
	bool flag = false;
	while(a != NULL){
		int contador = 0;
		if(a->info == '#'){
			flag = true;
		}
		while(flag != false){
			a = a->sig;
			if(a->info == '#'){
				flag = false;
			}
			contador++;
		}
		contador--;
		
		if(a->info == '2'){
			n1++;
		}else if(a->info == '3'){
			n1++;
		}else if(a->info == '+'){
			if(a->sig->info == '-'){
				n1++;
				a = a->sig;
			}else{
				n1++;
			}
		}else if(a->info == '-'){
			n1++;
		}
		if(contador == 3){
			char m = n1 + '0';
			putc(' ', f_output2);
			putc(m, f_output2);
			fputs(",", f_output2);
			n3++;
		}
		a = a->sig;
	}
	if(n3 == 4) fputs("-tetrapropil", f_output2);
	if(n3 == 3) fputs("-tripropil", f_output2);
	if(n3 == 2) fputs("-dipropil", f_output2);
	if(n3 == 1) fputs("-propil", f_output2);
}

int contApellido(Lista *l){
	int contador = 0;
	Nodo *a;
	a = l->head;
	bool flag = false;
	while(a != NULL){
		if(a->info == '#'){
			flag = true;
		}
		while(flag != false){
			a = a->sig;
			if(a->info == '#'){
				flag = false;
			}
		}
		if(a->info == '2'){
			contador++;
		}else if(a->info == '3'){
			contador++;
		}else if(a->info == '+'){
			if(a->sig->info == '-'){
				contador++;
				a = a->sig;
			}else{
				contador++;
			}
		}else if(a->info == '-'){
			contador++;
		}
		a = a->sig;
	}
	return contador;
}

void apellido(FILE *f_output2, int n){
	if(n == 1) fputs("metano\n", f_output2);
	if(n == 2) fputs("etano\n", f_output2);
	if(n == 3) fputs("propano\n", f_output2);
	if(n == 4) fputs("butano\n", f_output2);
	if(n == 5) fputs("pentano\n", f_output2);
	if(n == 6) fputs("hexano\n", f_output2);
	if(n == 7) fputs("heptano\n", f_output2);
	if(n == 8) fputs("octano\n", f_output2);
	if(n == 9) fputs("nonano\n", f_output2);
	if(n == 10) fputs("decano\n", f_output2);
	if(n == 11) fputs("undecano\n", f_output2);
	if(n == 12) fputs("dodecano\n", f_output2);
	if(n == 13) fputs("tridecano\n", f_output2);
	if(n == 14) fputs("tetradecano\n", f_output2);
	if(n == 15) fputs("pentadecano\n", f_output2);
	if(n == 16) fputs("hexadecano\n", f_output2);
	if(n == 17) fputs("heptadecano\n", f_output2);
	if(n == 18) fputs("octadecano\n", f_output2);
	if(n == 19) fputs("nonadecano\n", f_output2);
	if(n == 20) fputs("eicosano\n", f_output2);
}
