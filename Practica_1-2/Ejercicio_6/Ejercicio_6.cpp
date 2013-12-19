/* 
	2013 - Ernesto Serrano Collado
	------------------------------
	Programa para calcular las ganancias de los fabricantes y 
	el diseñador de un producto
	Necesita: Ganancias totales.
	Calcula:  Las 4 ganancias sin repetir cálculos
*/

#include <iostream>   // Inclusión de los recursos de E/S

using namespace std; 

int main(){                    // Programa Principal
	double ganancia_Disenador;        // Declara variables para guardar
	double ganancia_Minima;           // los valores
	double ganancia_Total;

	//Obtenemos los datos necesarios
	cout << "Introduzca la ganancia total: " ;
	cin >> ganancia_Total;

	//Hacemos los cálculos     
	ganancia_Minima = ganancia_Total / 5;  //La ganancia mínima será igual a lo que cobra cada uno de los fabricantes
	ganancia_Disenador = ganancia_Minima * 2;

	//Pintamos los valores en la consola
	cout << "El diseñador gana " << ganancia_Disenador << " €\n" ;
	cout << "Los fabricantes ganan " << ganancia_Minima << " € cada uno\n" ;

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");
}