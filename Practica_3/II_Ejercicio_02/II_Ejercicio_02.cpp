/* 
	2013 - Ernesto Serrano Collado
	------------------------------
	Programa para calcular los ingresos en base a la edad, si es un jubilado 
	con unos ingresos inferiores a 300 euros se le incrementará un 5%

	Necesita: Edad e Ingresos.

	Devuelve:  Los ingresos finales, y si se puede aplicar una subida en base a la edad.
*/

#include <iostream>   // Inclusión de los recursos de E/S

using namespace std; 

int main(){                    // Programa Principal
	int edad;               // Declara variables para guardar datos
	double ingresos;              

	//Obtenemos los datos necesarios
	cout << "Introduzca una edad: " ;
	cin >> edad;
	cout << "Introduzca unos ingresos: ";
	cin >> ingresos;

	//Hacemos los cálculos
	if (edad > 65 && ingresos < 300) {
		//Subimos los ingresos un 5%
		ingresos = ingresos * 1.05;
	} else {
		//Si no queremos hacer un cout desde dentro de la condicion creariamos 
		//una variable bool que luego volveriamos a comprobar para hacer dicho cout
		cout << "No es aplicable la subida\n" ;
	}

	//Pintamos los valores en la consola
	cout << "Los ingresos son de: " << ingresos << " Euros\n\n" ;

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");
}
