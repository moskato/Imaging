#Algoritmo de reconstrucción TwIST en C++

El algoritmo "Two-step Iterative Shrinkage/Thresholding" (TwIST) es un algoritmo para resolver problemas lineales inversos.

Este algoritmo resuelve el siguiente problema de regularización:

                            arg min_x = 0.5*|| y - A x ||_2^2 + tau phi( x)

donde A es una matriz genérica y phi() es una función de regularización, tal que la solución del problema de eliminación de ruido es conocida:

                     Psi_tau(y) = arg min_x = 0.5*|| y - x ||_2^2 + tau \phi( x )

Toda la información relacionada a este algoritmo puede ser encontrada en:http://www.lx.it.pt/~bioucas/TwIST/TwIST.htm.

En este trabajo, el algoritmo de reconstrucción TwIST es implementado en lenguaje C++.



#Estructura

El proyecto se divide en 13 funciones descritas en la cabecera "functions.h". Funciones:
* Función AT: Realiza la  multiplicación de un vector x con  una matriz A dada.
* Función Af: Realiza la  multiplicación de un vector x con una matriz A transpuesta.
* Función diff: Estima la diferencia entre dos vectores.
* Función hadamard: Calcula el producto elemento a elemento entre dos vectores.
* Función non_zero: Calcula un vector booleano que registra los elementos diferentes de cero del vector de entrada x.
* Función phi_function: Calcula la norma l0 de un vector.
* Función prod_c_v: Calcula el producto de un escalar con un vector.
* Función psi_function: Se hace un umbral para cada valor del vector de entrada dependiendo del parámetro lambda.
* Función sum: Calcula la suma de los elementos de un vector.
* Función twist: Algoritmo de reconstrucción TwIST.
* Función vector_prod: Calcula el producto de dos vectores.
* Función vector_res: Calcula la resta de dos vectores.
* Función vector_sum: Calcula la suma de dos vectores.
