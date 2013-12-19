/* 
	Fundamentos de Programaci�n
	Grado en Ingenier�a Inform�tica

	2013 - Ernesto Serrano Collado
	------------------------------
	Programa que pinta una pir�mide en pantalla con los numeros del
	1 al 6.

	Devuelve: Una pir�mide.
*/
#include <iostream>   // Inclusi�n de los recursos de E/S

using namespace std; 

int main(){                    // Programa Principal

	//Hacemos los c�lculos

	for (int i = 0; i < 7; i++){

		//Anidamos otro for donde el iterador comenzara en i+1
		for (int h = i + 1; h < 7; h++) {

			/*	
				NOTA: Lo correcto seria no escribir aqui el resultado, si no
				almacenarlo en una variable temporal stringstream y luego pintarla 
			*/
		
			//Pintamos los valores en la consola
			cout << h << " ";

		}

		//Pintamos un salto de linea
		cout << "\n";

	}

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");
}
