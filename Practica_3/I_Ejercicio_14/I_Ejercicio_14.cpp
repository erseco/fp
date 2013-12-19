/* 
	2013 - Ernesto Serrano Collado
	------------------------------
	Programa que imprime el valor entero de una variable char.

	Necesita: Un carácter escrito directamente en el codigo.

	Devuelve: El valor entero de ese carácter.
*/

#include <iostream>   // Inclusión de los recursos de E/S

using namespace std; 

int main(){                    // Programa Principal
    int entero;          // Declara variables para guardar
    char caracter;

	//Obtenemos los datos necesarios
    caracter = '7';

	//Hacemos los cálculos
	entero = caracter;

	//Pintamos los valores en la consola
	cout << "\nEl valor del caracter " << caracter << " es " << entero << "\n\n" ;

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");
}
