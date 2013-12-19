/* 
	2013 - Ernesto Serrano Collado
	------------------------------
	Programa para intercambiar las variables x, y, z
*/

#include <iostream>   // Inclusión de los recursos de E/S

using namespace std; 

int main(){                    // Programa Principal
	int x = 10;               // Declara variables para guardar
	int y = 20;           // los valores
	int z = 30;   
	int aux;
 
	//Pintamos los valores en la consola
	cout << "Valores: x = " << x << ", y = " << y << ", z = " << z << "\n";

	//Hacemos los cálculos     
	aux = z;
	z = y;
	y = x;
	x = aux;

	//Pintamos los valores en la consola
	cout << "Valores intercambiados: x = " << x << ", y = " << y << ", z = " << z << "\n";

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");
}