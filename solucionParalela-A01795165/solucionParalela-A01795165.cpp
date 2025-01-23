// solucionParalela-A01795165.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

#ifdef _OPENMP
#include <omp.h>
#else
#define omp_get_thread_num() 0
#endif

#define array_size 1000 // Definimos el tamano de los arrays
#define chunk_size 100 // Definimos el tamano del chunk
#define show_num 20 // Definimos el numero de elementos a mostrar

void print_arrays(int *d);

int main()
{
	// Iniciamos la semilla para generar valores random
	std::srand(static_cast<unsigned int>(std::time(0)));

	int i;

	// Creamos los arrays
	int array_a[array_size];
	int array_b[array_size];
	int array_c[array_size];

	// Llenamos los arrays a y b con valores random
	for (i = 0; i < array_size; i++)
	{
		array_a[i] = std::rand() % 100 + 1;
		array_b[i] = std::rand() % 100 + 1;
	}



	std::cout << "Suma de arreglos con una solucion paralela.\n";
	std::cout << "Alumno A01795165.\n";



	// Sumamos los arrays a y b y guardamos el resultado en el array c usando paralelismo para mejorar el rendimiento
#pragma omp parallel for shared(array_a, array_b, array_c) private(i) schedule(static, chunk_size)
	for (i = 0; i < array_size; i++)
	{
		array_c[i] = array_a[i] + array_b[i];
	}

	//Mostramos el array_a
	std::cout << "Imprimiendo los primeros " << show_num << " valores del array_a: " << std::endl;
	print_arrays(array_a);
	//Mostramos el array_b
	std::cout << "Imprimiendo los primeros " << show_num << " valores del array_b: " << std::endl;
	print_arrays(array_b);
	//Mostramos el array_c
	std::cout << "Imprimiendo los primeros " << show_num << " valores del array_c: " << std::endl;
	print_arrays(array_c);

}

// Funcion para imprimir los elementos de un array
void print_arrays(int *d)
{
	for (int i = 0; i < show_num; i++)
	{
		std::cout << d[i] << " - ";
	}
	std::cout << std::endl;
}

