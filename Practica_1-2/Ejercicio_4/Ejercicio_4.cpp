/*	
	2013 - Ernesto Serrano Collado
	------------------------------
	Programa para calcular el área del círculo y la longitud
	de la circuferencia
	Necesita: Pi y el radio.
	Calcula: El área y la longitud segun las siguientes fórmulas
                long. circunf = 2πr 
				área circ = πr2
*/

#include <iostream>   // Inclusión de los recursos de E/S

using namespace std; 

int main(){                    // Programa Principal
	const double PI = 3.14159;	// Declara la constante de Pi
	int radio;					// Declara variables para guardar los valores
	double area; 
	double longitud; 

	//Obtenemos los datos necesarios
	cout << "Introduzca el radio: ";
	cin >> radio;
   
	//Hacemos los cálculos   
	area = PI * (radio ^ 2 );	
	longitud = 2 * PI * radio;      

	//Pintamos los valores en la consola
	cout << "El área vale " << area << "\n" ;
	cout << "La longitud vale " << longitud << "\n\n" ;

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");
}
