/* 
	2013 - Ernesto Serrano Collado
	------------------------------
	Programa para calcular la media aritmética y la desviacion típica.
	Necesita: Tres edades.
	Calcula:  La desviación estandar y la media aritmética.
*/

#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>   // Inclusión de los recursos de E/S

using namespace std; 

int main(){                    // Programa Principal
	double media;               // Declara variables para guardar
	double desviacion;           // los valores
	double edad1;
	double edad2;
	double edad3;

	//Obtenemos los datos necesarios
	cout << "Introduzca la edad de la 1ª persona: " ;
	cin >> edad1;
	cout << "Introduzca la edad de la 2ª persona: " ;
	cin >> edad2;
	cout << "Introduzca la edad de la 3ª persona: " ;
	cin >> edad3;

	//Hacemos los cálculos     
	media = (edad1 + edad2 + edad3) / 3;

	desviacion = sqrt(  (pow(edad1-media,2) + pow(edad2-media,2) +pow(edad3-media,2)  ) / (3-1)  );


	//Pintamos los valores en la consola
	cout << "La media de edad es: " << media << "\n";
	cout << "La desviación típica es: " << desviacion << "\n\n" ;

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");
}