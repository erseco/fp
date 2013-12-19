/* 
	2013 - Ernesto Serrano Collado
	------------------------------
	Programa que imprime el resultado de algunas expresiones lógicas.

	Necesita: Una letra, una edad y un año.

	Devuelve: Si la letra es minúscula, si la edad es menor a 18 o mayor a 65 y si el año es bisiesto.
*/

#include <iostream>   // Inclusión de los recursos de E/S

using namespace std; 

int main(){                    // Programa Principal
	char letra;               // Declara variables para guardar datos
	int edad;             
	int bisiesto;  

	bool es_minuscula;
	bool es_mayoredad;
	bool es_bisiesto;

	//Obtenemos los datos necesarios
	cout << "Introduzca una letra: " ;
	cin >> letra;
	cout << "Introduzca una edad: ";
	cin >> edad;
	cout << "Introduzca un año: ";
	cin >> bisiesto;

	//Hacemos los cálculos (asignamos los resultados lógicos directamente a las variables)
	es_minuscula = letra >= 'a' && letra <= 'z';   
	es_mayoredad = edad < 18 || edad > 65;
	es_bisiesto = (bisiesto % 100 == 0 && bisiesto % 4 > 0) || bisiesto % 400 == 0;

	//Pintamos los valores en la consola
	cout << "La letra es minúscula? " << es_minuscula << "\n";
	cout << "La edad es menor 18 o mayor que 65? " << es_mayoredad << "\n";
	cout << "El año es bisiesto? " << es_bisiesto << "\n";

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");
}
