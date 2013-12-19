/* 	
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - Ernesto Serrano Collado
	------------------------------
	Programa que convierte un caracter en mayúscula a minúscula.

	Necesita: Un carácter en mayuscula.

	Devuelve: El mismo carácter convertido a minúscula.
*/

#include <iostream>   // Inclusión de los recursos de E/S
#include <string>   // Inclusión de los recursos de cadenas

using namespace std; 

int main(){                    // Programa Principal
	char caracter;               // Declara variables para guardar
	const string MENSAJE_INTRODUCCION = "\nIntroduzca un caracter en mayuscula: "; 
	const int DIFERENCIA_CARACTER = 'a' - 'A';

	//Obtenemos los datos necesarios
	do {	
		cout << MENSAJE_INTRODUCCION;
		cin >> caracter;
	} while (caracter < 'A' || caracter > 'Z' ); //Comprobamos que el número sea positivo
	//Obtenemos los datos necesarios


	//Hacemos los cálculos
	caracter += DIFERENCIA_CARACTER; //Le sumamos la diferencia     

	//Pintamos los valores en la consola
	cout << "\nLa minuscula del caracter introducido es: " << caracter << "\n\n" ;

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");
}
