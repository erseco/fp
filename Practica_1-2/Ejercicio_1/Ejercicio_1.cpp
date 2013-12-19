/* 
	2013 - Ernesto Serrano Collado
	------------------------------
	Programa para calcular el voltaje seg�n la ley de Ohm
	Necesita: Intensidad y Resistencia.
	Calcula:  El Voltaje, calculado como
                voltaje = intensidad * resistencia
*/

#include <iostream>   // Inclusi�n de los recursos de E/S

using namespace std; 

int main(){                    // Programa Principal
	double intensidad;               // Declara variables para guardar
	double resistencia;               // intensidad, resistencia y voltaje
	double voltaje;   

	//Obtenemos los datos necesarios
	cout << "Introduzca la intensidad: " ;
	cin >> intensidad;
	cout << "Introduzca la resistencia: ";
	cin >> resistencia;

	//Hacemos los c�lculos
	voltaje = intensidad * resistencia;      

	//Pintamos los valores en la consola
	cout << "\nEl voltaje vale " << voltaje << "\n\n" ;

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");
}
