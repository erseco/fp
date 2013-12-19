/* 
	2013 - Ernesto Serrano Collado
	------------------------------
	Programa que separa un valor entero en partes.

	Necesita: Un entero de 3 dígitos.

	Devuelve: Los digitos separados.
*/

#include <iostream>   // Inclusión de los recursos de E/S

using namespace std; 

int main(){                    // Programa Principal
	int entero;               // Declara variables para guardar

	int pos_1;
	int pos_2;
	int pos_3;

	//Obtenemos los datos necesarios
	cout << "Introduzca un entero de 3 digitos: " ;
	cin >> entero;
	
	//Hacemos los cálculos matemáticos para separar los dígitos
	pos_1 = entero / 100; 		//Dividimos entre 100, al hacer el redondeo nos dará solo la parte entera
	pos_2 = (entero / 10) % 10; //Dividimos entre 10 y obtenemos el resto de volver a dividir entre 10
	pos_3 = (entero % 10); 		//Obtenemos el resto de dividir entre 10


	//Pintamos los valores en la consola
	cout << "\nLos valores son: " << pos_1 << " " << pos_2 << " " << pos_3 << "\n\n" ;

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");
}
