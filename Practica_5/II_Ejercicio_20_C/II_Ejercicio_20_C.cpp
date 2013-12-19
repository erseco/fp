/* 
	Fundamentos de Programaci�n
	Grado en Ingenier�a Inform�tica

	2013 - Ernesto Serrano Collado
	------------------------------
	Programa que calcula una progresi�n geom�trica usando un bucle for.

	Necesita: r, a1 y k.

	Devuelve: El total.
*/
#include <iostream>   // Inclusi�n de los recursos de E/S
#include <cmath> //Inclusi�n de las funciones matem�ticas

using namespace std; 

int main(){                    // Programa Principal 
	// Declara variables para guardar los datos
	double r;
	double a1;
	int k;
	double total = 0;

	//Obtenemos los datos
	cout << "\nIntroduzca el valor r: ";
	cin >> r;
	cout << "\nIntroudzca el valor del primer elemento a1: ";
	cin >> a1;
	cout << "\nIntroudzca el valor k (tope): ";
	cin >> k;

	for (int n = 2; n <= k; n++) {

		//Hacemos los calculos
		total = total + (a1 * pow(r, n-1));		

	
	}

	//Pintamos los valores en la consola
	cout << "\nEl total es: " << total << "\n\n";

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");
}
