/* 
	2013 - Ernesto Serrano Collado
	------------------------------
	Programa que lee un caracter y si es mayúscula lo convierte a minúscula.

	Necesita: Un carácter.
	
  Devuelve:  El caracter en minúscula si el introducido es mayúscula, 
            si no devuelve el mismo caracter introducido.
*/

#include <iostream>   // Inclusión de los recursos de E/S

using namespace std; 

int main(){                    // Programa Principal
	char letra_original;               // Declara variables para guardar datos
	char letra_convertida;


	//Obtenemos los datos necesarios
	cout << "Introduzca una letra: " ;
	cin >> letra_original;


	//Hacemos los cálculos
	if (letra_original >= 'A' && letra_original <= 'Z') { //En la tabla ASCII 65 es A y 90 es Z
		//Es mayúscula
		letra_convertida = letra_original + 32; //Le sumamos 32 para que sea minúscula 
	} else {
		letra_convertida = letra_original;
	}

	//Pintamos los valores en la consola
	cout << "La letra convertida es: " << letra_convertida << "\n\n" ;

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");
}
