/* 
	2013 - Ernesto Serrano Collado
	------------------------------
	Programa que dice si cualquiera de los dos valores indicados divide de forma entera al otro.
	
	Necesita: Dos valores numéricos.
	
	Devuelve:  Si uno de los dos valores es divisible por el otro.
*/

#include <iostream>   // Inclusión de los recursos de E/S

using namespace std; 

int main(){                    // Programa Principal
	int valor_1;               // Declara variables para guardar
	int valor_2;               

	//Obtenemos los datos necesarios
	cout << "Introduzca un valor (1): " ;
	cin >> valor_1;
	cout << "Introduzca un valor (2): ";
	cin >> valor_2;

	//Hacemos los cálculos
	if (valor_1 % valor_2 == 0 || valor_2 % valor_1 == 0) {
		//Pintamos los valores en la consola
		cout << "El valor 1 es divisible por el valor 2 o viceversa\n" ;
	} else {
		cout << "Ninguno de los dos valores es divisible por el otro\n" ;
	}

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");
}
