#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

int main(){
	FILE *f_input = fopen("alcanos.txt","r");
	FILE *f_output = fopen("diagramas.txt","w");
	FILE *f_output2 = fopen("salida.txt","w");
	
	if(!f_input){
		puts("No se puede leer el archivo");
		return -1;
	}
	
	if(!f_output){
		puts("No se puede crear el archivo de salida");
		fclose(f_input);
		return -1;
	}
	
	if(!f_output2){
		puts("No se puede crear el archivo de salida");
		fclose(f_input);
		return -1;
	}
	int cont;
	Lista *l = crearLista();
	bool flag = false;
	bool flag2 = false;
	char c;
	while((c = fgetc(f_input)) != EOF){
		
		if(flag == true){
			if(flag2 == true){
				if(c != '\n'){
					insertarNodoFin(l,c); //Se guardan los elementos en una lista
				}else{
					//---------------------
					linea1(l, f_output); //Se imprime el diagrama con sus respectivas lineas
					med1(l, f_output);
					linea2(l, f_output);
					med2(l, f_output);
					linea3(l, f_output);
					//---------------------
					
					butil(l, f_output2); //Se imprime el nombre del respectivo alcano
					etil(l, f_output2);
					metil(l, f_output2);
					pentil(l, f_output2);
					propil(l, f_output2);
					
					cont = contApellido(l);
					apellido(f_output2, cont);
					
					eliminar(l);
					putc('\n', f_output);
				}
			}
			flag2 = true;
		}
		
		flag = true;
	}
	
	linea1(l, f_output);
	med1(l, f_output);
	linea2(l, f_output);
	med2(l, f_output);
	linea3(l, f_output);
	
	butil(l, f_output2);
	etil(l, f_output2);
	metil(l, f_output2);
	pentil(l, f_output2);
	propil(l, f_output2);
	
	cont = contApellido(l);
	apellido(f_output2, cont);
	
	eliminar(l);
	
	fclose(f_input);
	fclose(f_output);
	
	
	return 0;
}