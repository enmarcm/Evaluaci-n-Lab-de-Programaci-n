//Examen 1 Laboratorio de Programacion I - Enmanuel Colina
#include <iostream>

int main(){
int nota;
//EN LA LINEA 6 DECLARO E INICIALIZO PARA EVITAR ERRORES AL MOMENTO DE USAR +=
int sobresaliente = 0, muyBueno = 0, bueno = 0, regular = 0, mejorable = 0, deficiente = 0;
int aprobados, reprobados, selector;
float estudiantes, promedio, auxNotas = 0;
	
int i = 1;
do{//Este Do-While sería para preguntarle al usuario cuantos estudiantes desea añadir. Tambien se podría usar for, pero me parecio más practico así
	do{//Este en su defecto puede considerarse un manejo de excepciones, evitando que el usuario añada notas por debajo de 0 y/o por encima de 20
	
	selector = 0; //Reiniciamos el selector
	printf("Ingrese las notas (numero entero) del estudiante %d: ", i);
	scanf("%d", &nota);
	
	if(nota < 0 || nota > 20){ //Este If se encarga de validar el valor de la nota, si no cumple los parametros muestra que es invalida y el do while repite la iteracion
		printf("Ingrese una nota valida (entre 0 y 20)\n");
	}else{ //De ser un numero valido, procede a guardar la nota y a indicar a que pertenece
	auxNotas += nota;
	switch(nota){
		case 19 ... 20:
			printf("El estudiante %d obtuvo una nota SOBRESALIENTE\n\n", i);	
			sobresaliente++;
		break;
		
		case 16 ... 18:
			printf("El estudiante %d obtuvo una nota MUY BUENA\n\n", i);
			muyBueno++;

		break;
		
		case 13 ... 15:
			printf("El estudiante %d obtuvo una nota BUENA\n\n", i);
			bueno++;
		break;
		
		case 10 ... 12:
			printf("El estudiante %d obtuvo una nota REGULAR\n\n", i);
			regular++;
		break;
		
		case 6 ... 9:
			printf("El estudiante %d obtuvo una nota MEJORABLE\n\n", i);
			mejorable++;
		break;
		
		default:
			printf("El estudiante %d obtuvo una nota DEFICIENTE\n\n", i); //No hace falta colocar break en el default
			deficiente++;
		}
	printf("------------------------\n");
	printf("Desea evaluar otro alumno?\n");
	printf("Ingrese 1 si es asi\n");
	printf("------------------------\n");
	scanf("%d", &selector);
	printf("\n");
		if(selector == 1){
			i++;
		}
	}
	}while(nota < 0 || nota > 20);
}while(selector == 1);

estudiantes = i; //La informacion de i sera la cantidad de estudiantes que se tengan
aprobados = sobresaliente + muyBueno + bueno + regular; //Los aprobados son todos aquellos con nota mayor o igual a 10
reprobados = mejorable + deficiente; //Reprobados notas por debajo de 10 
promedio = auxNotas/estudiantes; // Hacemos uso de dos variables float para determinar el promedio;

printf("El total de estudiantes de la seccion es de %.0f\n", estudiantes);
printf("El total de aprobados es de %d\n", aprobados);
printf("El total de reprobados es de %d\n", reprobados);
printf("El promedio de la seccion es %.2f\n", promedio);


system("pause");
return 0;
	
}
