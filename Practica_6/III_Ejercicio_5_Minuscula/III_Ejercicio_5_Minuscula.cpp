/* 
	Fundamentos de Programaci�n
	Grado en Ingenier�a Inform�tica

	2013 - Ernesto Serrano Collado
	------------------------------
	Programa que convierte a may�scula un caracter
	utilizando funciones.
*/
#include <iostream>   // Inclusi�n de los recursos de E/S

using namespace std; 



//Funcion que comprueba si una letra es minuscula
bool EsMinuscula (char una_letra){

	bool resultado = true;

	//Comprobamos si esta fuera del rango a-z
	if ((una_letra < 'a') || (una_letra > 'z')) {
		resultado = false;
	}

	//Devolvemos el valor
	return resultado;
}

//Funcion que convierte una letra a may�scula
char Convierte_a_Mayuscula (char caracter){

	char resultado;

	//Nos definimos la diferencia en una constante
	const int DIF_MAY_MIN = 'a' - 'A';

	//Comprobamos si es min�scula
	if (EsMinuscula(caracter)) {
		resultado = caracter - DIF_MAY_MIN; 
	}else{
		resultado = caracter;
	}
	//Devolvemos el valor
	return caracter;
}

//Programa Principal
int main(){                    

	//Declaramos variables donde almacenar los datos
	char caracter = 'b';

	//Obtenemos los datos necesarios
	caracter = Convierte_a_Mayuscula(caracter);

	//Pintamos los valores en la consola
	cout << "El caracter convertido es " << caracter << "\n\n";

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");
}
