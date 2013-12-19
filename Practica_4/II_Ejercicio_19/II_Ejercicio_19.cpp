/* 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - Ernesto Serrano Collado
	------------------------------
	Programa que calcula una progresión geométrica.

	Necesita: r, a1 y k.

	Devuelve: El total.
*/
#include <iostream>   // Inclusión de los recursos de E/S

using namespace std; 

int main(){                    // Programa Principal 
	// Declara variables para guardar los datos
	double r;
	double a1;
	int k;
	double total = 0;
	int i = 0;

	//Obtenemos los datos
	cout << "\nIntroduzca el valor r: ";
	cin >> r;
	cout << "\nIntroudzca el valor del primer elemento a1: ";
	cin >> a1;
	cout << "\nIntroudzca el valor k (tope): ";
	cin >> k;

	while (i < k) {

		//Hacemos los calculos
		total += (a1 + i) * r;
	
		//Incrementamos el iterador
		i++;
	}

	//Pintamos los valores en la consola
	cout << "\nEl total es: " << total << "\n\n";

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");
}
