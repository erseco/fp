/****************************************************************************** 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - Ernesto Serrano Collado
	------------------------------
	Reescribir la solución al ejercicio 3 de esta relación de problemas usando 
	como dato miembro de la clase Permutacion un objeto de la clase 
	MiVectorEnteros, en vez de un vector de la STL. Al constructor le seguimos 
	pasando un vector de la STL. Reemplazad los métodos privados que había 
	definidos dentro de Permutacion (como por ejemplo el método PosMax()) por 
	las correspondientes llamadas a los métodos de MiVectorEnteros.

******************************************************************************/
#include <iostream>	//Inclusión de los recursos de E/S
#include <string>	//Inclusión de los recursos de cadenas
#include <vector>	
#include <cstdlib>
#include <ctime>

using namespace std; 

/*****************************************************************************/
//Definicion de la clase MyRandom
#include <ctime>
class MyRandom {
private:
	int minVal;
	int maxVal;
	void InitMyRandom (void) {
		time_t t;
		srand ((int) time(&t));
	}
public:
	MyRandom (int el_minimo, int el_maximo) : minVal(el_minimo), maxVal(el_maximo) {
		InitMyRandom();
		
		Next(); // desecho el primero
	}
	int Next() {
		int rango = (maxVal - minVal)+1;
		int v1 = (int)(rango * (rand() / (RAND_MAX*1.0)));
		int v2 = (int)(minVal + (v1 % rango));
		return v2; 
	}
	int Min() {
		return minVal;
	}
	int Max() {
		return maxVal;
	}
};
/*****************************************************************************/
//Definicion de la clase MiVectorEnteros
class MiVectorEnteros {
private:
	static const int TAMANIO = 50;
	int vector_privado[TAMANIO];
	int total_utilizados;
public:
	/*****************************************************************/
	// Constructor sin argumentos
	MiVectorEnteros() {
		total_utilizados = 0;
	}
	/*****************************************************************/
	// Métodos de lectura (Get) de los datos individuales 
	int TotalUtilizados() {
		return total_utilizados;
	}
	int Capacidad() {
		return TAMANIO;
	}
	/*****************************************************************/
	// Añade un elemento al vector
	// PRE: hay espacio para el nuevo elemento.
	// Si no lo hay, no hace nada.
	void Aniade(int nuevo) {
		if (total_utilizados < TAMANIO){
			vector_privado[total_utilizados] = nuevo;
			total_utilizados++;
		}
	}
	/*****************************************************************/
	// Devuelve el elemento de la casilla "indice" 
	// PRE: la posición dada por "indice" es correcta.
	// Si no es correcta,el comportamiento no está definido.
	int Elemento(int indice) {
		return vector_privado[indice];
	}
	/*****************************************************************/
	// Sustituye la componente con índice "indice_componente" por el 
	// valor nuevo.
	// PRE: la posición dada por "indice_componente" es correcta.
	// Si no es correcta, no hace nada.
	void Modifica (int indice_componente, int nuevo) {
		if ((indice_componente >= 0)  &&  (indice_componente < total_utilizados))

			vector_privado[indice_componente] = nuevo;
	}		
	/*****************************************************************/
	//Esta función comprueba si el objeto pasado como parámetro es igual
	//al propio objeto
	bool EsIgualA (MiVectorEnteros otro) {

		//Por defecto decimos que es igual
		bool es_igual = true;

		//Si el tamaño de los vectores difiere...
		if (otro.TotalUtilizados() != TotalUtilizados()) {
		
			//...los objetos no son iguales
			es_igual = false;

		} else { //Si son iguales
			
			//Recorremos sus elementos comparándolos (esto es un while con
			//forma de for, en el momeno que no sea igual (es_igual == false) 
			//se saldría
			for (int i = 0; es_igual && i < TotalUtilizados(); i++) {
			
				//Si los dos elementos difieren...
				if (Elemento(i) != otro.Elemento(i)) {
				
					//..los objetos no son iguales
					es_igual = false;
				}
			
			}
		
		}

		//Devolvemos el resultado de la comparación
		return es_igual;
	}		

	/*****************************************************************/

};
/*****************************************************************************/
//Definicion de la clase Permutacion
class Permutacion {
private:
	MiVectorEnteros vector_privado;
public:

	/*****************************************************************/
	//Comprueba si el valor existe previamente en la permutación. 
	bool Contiene(int valor) {

		//Declaracion de variables
		bool contiene = false;

		//Recorremos el vector hasta el final o hasta encontrar valor
		for (int i = 0; !contiene && i < (int)vector_privado.TotalUtilizados(); i++) {
		
			//Si valor existe...
			if (vector_privado.Elemento(i) == valor) {
			
				//...decaramos esta variable a true
				contiene = true;

			}

		}

		//Devolvemos el resultado
		return contiene;
	}	
	/*****************************************************************/
	//Agrega un valor a la permutacion. 
	void Aniade(int valor) {
		vector_privado.Aniade(valor);
	}
	/*****************************************************************/
	//Pinta la permutacion concatenada en la salida estandar. 
	void PintarPermutacion() {
		
		for (int i = 0; i < (int)vector_privado.TotalUtilizados(); i++) {
		
			cout << vector_privado.Elemento(i) << ",";

		}

		cout << "\n";

	}
	/*****************************************************************/
	// Devuelve el número de elementos de la permutación. 
	int NumElementos() {
		return (vector_privado.TotalUtilizados());
	}
	/*****************************************************************/
	// Devuelve el mínimo de la permutación. 
	// PRE: al menos hay un elemento 
	int Minimo() {
		int min = vector_privado.Elemento(0);
		int tope = (int)vector_privado.TotalUtilizados();

		for (int i=1; i<tope; i++) 
			if (vector_privado.Elemento(i) < min) 
				min = vector_privado.Elemento(i);

		return (min);
	}
	/*****************************************************************/
	// Devuelve el máximo de la permutación. 
	// PRE: al menos hay un elemento 
	int Maximo() {
		int max = vector_privado.Elemento(0);
		int tope = vector_privado.TotalUtilizados();

		for (int i=1; i<tope; i++) 
			if (vector_privado.Elemento(i) > max) 
				max = vector_privado.Elemento(i);

		return (max);
	}
	/*****************************************************************/
	// Devuelve el elemento de la casilla "indice" 
	// PRE: la posición dada por "indice" es correcta.
	int Elemento(int indice) {
		return vector_privado.Elemento(indice);
	}

	/*********************************************************/
	//Esta función devuelve el numero de lecturas que necesitamos hacer para leer
	//todos los numeros del vector.
	int NumeroLecturas() {

		//Declaracion de variables

		//En este contador iremos almacenando el numero de lecturas
		int n_lecturas = 0;
		//En este contador almacenamos los leidos tiene que llegar a vector_privado.TotalUtilizados()
		int n_leidos = 1; 

		//Bucle while con forma de for, recorrerá el vector hasta que esten todos los numeros leidos
		for (int i = 0; n_leidos < (int)vector_privado.TotalUtilizados() && i < (int)vector_privado.TotalUtilizados(); i++) {

			//Recorremos el vector para leer los numeros inferiores al actual
			for (int h = i+1; h < (int)vector_privado.TotalUtilizados(); h++) {

				//Si el valor es inferior al actual...
				if (vector_privado.Elemento(i) > vector_privado.Elemento(h)) {

					//...incrementamos el contador de leidos
					n_leidos++;

				}

			}

			//Incrementamos el contador de lecturas
			n_lecturas++;

		}

		//Devolvemos el numero de lecturas
		return n_lecturas;
	}

};
/*****************************************************************************/
//Definicion de la clase GeneradorPermutaciones
class GeneradorPermutaciones {
public:

	/*********************************************************/
	//Esta función genera una permutacion de los numeros entre primero y ultimo
	Permutacion Genera(int primero, int ultimo) {

		//Declaramos las variables necesarias
		Permutacion perm;

		MyRandom generador_aleatorio(primero+1, ultimo-1);
		perm.Aniade(primero);
		bool permutacion_completa = false;

		//No terminamos hasta que la permutacion esté completa
		while (!permutacion_completa) {
	
			//Generamos un nuevo valor aleatorio
			int valor = generador_aleatorio.Next();

			//Si valor es distinto del ultimo y no esta en la lista...
			if (valor != ultimo && !perm.Contiene(valor)) {
			
				//..añadimos el valor
				perm.Aniade(valor);

			}

			//Comprobamos si la permutacion esta completa (el tamaño tien que ser el mismo
			if (perm.NumElementos() == ultimo - primero) {
			
				permutacion_completa = true;
			}

		}


		//Añadimos el ultimo
		perm.Aniade(ultimo);

		//Devolvemos la permutación
		return perm;



	}
};
/*****************************************************************************/
//Programa Principal 
int main() {    

	//Declara variables para guardar los datos   
	GeneradorPermutaciones generador;
	Permutacion perm;
	//Hacemos los calculos
	perm = generador.Genera(4,20);


	//Pintamos los valores en la consola
	cout << "Ha generado la permutacion: \n";
	perm.PintarPermutacion();
	cout << "\n";

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");

}