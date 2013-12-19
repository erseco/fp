/******************************************************************************
	Fundamentos de Programaci�n
	Grado en Ingenier�a Inform�tica

	2013 - Ernesto Serrano Collado
	------------------------------
	Programa para calcular las ganancias de los fabricantes y 
	el dise�ador de un producto
	Necesita: Ganancias totales.
	Calcula:  Las 4 ganancias sin repetir c�lculos

******************************************************************************/
#include <iostream>   // Inclusi�n de los recursos de E/S

using namespace std; 

/*****************************************************************************/
//Definicion de la clase
class Salario {

private: 

	//Atributos
	double beneficio;

public:
/*****************************************************************************/
	//Constructor
	Salario(double pBeneficio) {
		
		//Asignamos los atributos
		beneficio = pBeneficio;

	}
/*****************************************************************************/
	//M�todos
	double SalarioNetoDisenador(double retencion) {
		return	(2 * beneficio/5) - retencion;
	}
/*****************************************************************************/
	double SalarioNetoFabricante(double retencion) {
		return (beneficio/5) - retencion;
	}

};
/*****************************************************************************/
//Programa Principal 
int main(){    

	//Declara variables para guardar los valores
	double beneficio; 	// Dato de entrada
	double ganancia_fabricante;
	double ganancia_diseniador;

	double retencion_fabricante;
	double retencion_diseniador;
	
	//Obtenemos los datos necesarios
	cout << "\nIntroduzca beneficio obtenido: ";
	cin >> beneficio;
	cout << "\nIntroduzca la retencion del fabricante: ";
	cin >> retencion_fabricante;
	cout << "\nIntroduzca la retencion del dise�ador: ";
	cin >> retencion_diseniador;

	Salario salario(beneficio);

	//Llamamos a las funciones pasandole la cantidad a retener para cada uno
	ganancia_fabricante = salario.SalarioNetoFabricante(retencion_fabricante);
	ganancia_diseniador = salario.SalarioNetoDisenador(retencion_diseniador);

	 
	cout << "\nGanancia de cada fabricante: " << ganancia_fabricante; 
	cout << "\nGanancia del dise�ador: " << ganancia_diseniador;  
	cout << "\n\n";


	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");

}