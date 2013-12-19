/****************************************************************************** 
	Fundamentos de Programaci�n
	Grado en Ingenier�a Inform�tica

	2013 - Ernesto Serrano Collado
	------------------------------
	El algoritmo del ejercicio 5 es muy ineficiente ya que requiere trasladar 
	muchas veces muchas posiciones. Proponer un algoritmo para resolver 
	eficientemente este problema e implementarlo.

******************************************************************************/
#include <iostream>   // Inclusi�n de los recursos de E/S

using namespace std; 

/*****************************************************************************/
//Definicion de la clase

class MiVectorCaracteres {
private:
    static const int TAMANIO = 50;
    char vector_privado[TAMANIO];
    int total_utilizados;
public:
    MiVectorCaracteres() : total_utilizados(0){
	}
    int TotalUtilizados() {
        return total_utilizados;
    }
    int Capacidad() {
        return TAMANIO;
    }
    void Aniade(char  nuevo) {
        if (total_utilizados < TAMANIO){
            vector_privado[total_utilizados] = nuevo;
            total_utilizados++;
		} 
	}
    char Elemento(int indice) {
        return vector_privado[indice];
    }
	/*********************************************************/
	//Esta funcion comprueba si el vector es pal�ndromo
	bool EsPalindromo() {

		//Por defecto asignamos el resultado como true
		bool es_palindromo = true;

		//Recorremos el vector, pero nos definimos i y j para tener iteradores en
		//los dos sentidos (ascendente y decreciente) asi queda mas result�n
		//que hacer la resta al indicar el indice a acceder
		for (int i = 0, j = total_utilizados-1; i < total_utilizados-1; i++,j--) {
		
			//Vamos comprobando cada vector con su inverso
			if (vector_privado[i] != vector_privado[j]) {
				es_palindromo = false;
				break; //Salimos del bucle para optimizar
			}

		}

		return es_palindromo;
	}
	/*********************************************************/
	//Esta funcion modifica un indice del vector
	void Modifica(int indice_componente, char nuevo) {
	
		//Comprobamos si ese �ndice est� usado en el vector
		if (total_utilizados > indice_componente) {
		
			//Sustituimos el valor
			vector_privado[indice_componente] = nuevo;

		}

	}
	/*********************************************************/
	//Esta funcion intercambia dos valores
	void IntercambiaComponentes(int indice1, int indice2) {
	
		//Comprobamos si ese �ndice est� usado en el vector
		if (total_utilizados > indice1 && total_utilizados > indice2) {
		
			//Nos guardamos la variable temporal
			char tmp = vector_privado[indice1];
			//Sustituimos el valor
			vector_privado[indice1] = vector_privado[indice2];
			vector_privado[indice2] = tmp;

		}

	}
	/*********************************************************/
	//Esta funcion invierte un vector
	void Invierte() {

		//Recorremos el vector, pero nos definimos i y j para tener iteradores en
		//los dos sentidos (ascendente y decreciente) asi queda mas result�n
		//que hacer la resta al indicar el indice a acceder
		//NOTA: Dividimos entre 2 porque solo hay que recorrer hasta la mitad
		for (int i = 0, j = total_utilizados-1; i < ((total_utilizados-1) / 2); i++,j--) {
		
			//Invertimos los valores
			IntercambiaComponentes(i,j);

		}

	}
	/*********************************************************/
	//Esta funcion elimina un indice de un vector
	void Elimina(int indice_componente) {

		//Comprobamos que el indice exista en la matriz
		if (total_utilizados > indice_componente) {

			//Recorremos el vector desde el superior al indice pasado
			for (int i = indice_componente+1; i < total_utilizados; i++) {

				//NOTA: Esto se resuelve as� porque no se pueden eliminar
				//elementos de un vector en c++ (de momento)

				//Vamos desplazando todos los valores un lugar a la izquierda
				vector_privado[i-1] = vector_privado[i];
			}
			
			//Decrementamos el contador de utilizados
			total_utilizados--;

		}
	}
	/*********************************************************/
	//Esta funcion elimina un indice de un vector eficientemente
	//NOTA: Con recursividad se podr�a optimizar esta funcion
	//pero con lo que sabemos hasta ahora no se me ocurre
	//como optimizarla sin hacerla demasiado compleja
	void EliminaEficiente(int indice_componente) {

		//Comprobamos que el indice exista en la matriz
		if (total_utilizados > indice_componente) {

			//Recorremos el vector desde el superior al indice pasado
			for (int i = indice_componente+1; i < total_utilizados; i++) {

				//NOTA: Esto se resuelve as� porque no se pueden eliminar
				//elementos de un vector en c++ (de momento)

				//Vamos desplazando todos los valores un lugar a la izquierda
				vector_privado[i-1] = vector_privado[i];
			}
			
			//Decrementamos el contador de utilizados
			total_utilizados--;

		}
	}
	/*********************************************************/
	//Esta funcion elimina un indice de un vector
	void EliminaMayusculas() {

		//Recorremos el vector
		for (int i = 0; i < total_utilizados; i++) {
		
			//Comprobamos si el elemento actual esta en min�sculas
			if ((vector_privado[i] >= 'A') && (vector_privado[i] <= 'Z')){

				//Lo eliminamos
				EliminaEficiente(i);

			}

		}
		
	}
};
/*****************************************************************************/
//Programa Principal 
int main(){    

	// Declara variables para guardar los datos   
	MiVectorCaracteres vc1;

	vc1.Aniade('S');
	vc1.Aniade('o');
	vc1.Aniade('Y');
	vc1.Aniade(' ');	
	vc1.Aniade('y');
	vc1.Aniade('O');

	cout << "Eliminar Mayusculas:\n";

	for (int i = 0; i < vc1.TotalUtilizados();i++){
		cout << vc1.Elemento(i);
	}
	cout << '\n';

	//Eliminamos las may�sculas
	vc1.EliminaMayusculas();

	for (int i = 0; i < vc1.TotalUtilizados();i++){
		cout << vc1.Elemento(i);
	}
	cout << '\n' << '\n';



	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");

}