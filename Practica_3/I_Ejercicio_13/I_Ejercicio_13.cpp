/* 
	2013 - Ernesto Serrano Collado
	------------------------------
	Programa que convierte un caracter en mayúscula a minúscula.

	Necesita: Un carácter en mayúsucla.

	Devuelve: El mismo carácter convertido a minúscula.
*/

#include <iostream>   // Inclusión de los recursos de E/S

using namespace std; 

int main(){                    // Programa Principal
	char caracter;               // Declara variables para guardar

	//Obtenemos los datos necesarios
	cout << "Introduzca un caracter en mayuscula: " ;
	cin >> caracter;

	//Hacemos los cálculos
	caracter += 32; //Le sumamos 32 que es la diferencia en la tabla ascii de mayuscula a minuscula     

	//Pintamos los valores en la consola
	cout << "\nLa minuscula del caracter introducido es: " << caracter << "\n\n" ;

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");
}
