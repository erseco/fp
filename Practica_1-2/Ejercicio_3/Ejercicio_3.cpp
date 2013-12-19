/*
	2013 - Ernesto Serrano Collado
	------------------------------
	Programa para intercambiar el valor de dos variables
	Necesita: edad_Pedro y edad_Juan.
	Imprime:  Los valores de las variables intercambiados
*/

#include <iostream>   // Inclusión de los recursos de E/S

using namespace std; 

int main(){                    // Programa Principal
	int edad_Pedro;               // Declara variables para guardar
	int edad_Juan;               // los valores de las edades
	int edad_Temporal;   /* Necesitamos una variable temporal, puesto 
						 que antes de asignar el valor de una variable 
						 a otra hay que guardar su valor previo. */

	//Obtenemos los datos necesarios
	cout << "Introduzca la edad de Juan: ";
	cin >> edad_Juan;
	cout << "Introduzca la edad de Pedro: " ;
	cin >> edad_Pedro;

	//Pintamos algo de información en la consola
	cout << "Juan tiene " << edad_Juan << " años.\n" ;
	cout << "Pedro tiene " << edad_Pedro << " años.\n\n" ;
	cout << "Intercambiamos sus valores... \n\n";

	edad_Temporal = edad_Pedro;   //Intercambiamos los valores haciendo uso de
	edad_Pedro = edad_Juan;       //una variable temporal
	edad_Juan = edad_Temporal;

	//Pintamos los valores en la consola
	cout << "Juan tiene ahora " << edad_Juan << " años.\n" ;
	cout << "Pedro tiene ahora " << edad_Pedro << " años.\n\n" ;

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");
}