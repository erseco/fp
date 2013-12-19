/*	
	2013 - Ernesto Serrano Collado
	------------------------------
	Programa para calcular el resultado de una función matemática
	Necesita: coeficientes reales μ, σ y un valor de abscisa (x)
	Calcula: El resultado de la función según la fórmula, se 
	podrá comprobar el resultado aquí: http://www.danielsoper.com/statcalc/calc54.aspx
*/

#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>   // Inclusión de las funciones matemáticas

using namespace std; 

int main(){                    // Programa Principal
	const double PI = 3.1416;   // Declara las constantes
	double esperanza;				// Declara variables para guardar los valores
	double desviacion;
	double abscisa;
	double resultado; 

	//Obtenemos los datos necesarios
	cout << "Introduzca la esperanza: ";
	cin >> esperanza;
	cout << "Introduzca la desviación típica: ";
	cin >> desviacion;
	cout << "Introduzca la abscisa: ";
	cin >> abscisa;

	//Hacemos los cálculos (se podría poner en varias etapas)   
	resultado = ( 1 / ( desviacion * sqrt( 2 * PI ) ) ) * exp( -0.5 * pow( (abscisa-esperanza) / desviacion , 2 ) );

	//Pintamos los valores en la consola
	cout << "El resultado es:" << resultado << "\n" ;

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");
}
