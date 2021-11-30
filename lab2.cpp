#include <CL/sycl.hpp>
#include <iostream>
using namespace sycl;
   
int main(){
	constexpr int size = 16;

	std::vector<int> A(size);
    std::vector<int> B(size);
    std::vector<int> C(size);
    int innerProd = 0;

    // Inicializar vectores
    for (int i = 0; i < size; i++) {
        A[i] = (rand() % 100) + 1;
        B[i] = (rand() % 100) + 1;
    }

	queue q;

	// Creación del buffer
	buffer buffA(A);
    buffer buffB(B);
    buffer buffC(C);
    // Buffer para resultado final de producto interno
	buffer<int, 1> buffSum(&innerProd, 1);

	/***
	 * Agregue kernel(s) aquí
	 * 
	 * 
	 ***/


	// Mostrar resultados finales
	host_accessor buffC_host(buffC);
	host_accessor innerProd_result(buffSum);

	for(int i=0; i < size; i++)
	    std::cout << "C[" << i << "] = " << buffC_host[i]  << std::endl;
	std::cout << "Resultado producto interno: " << innerProd  << std::endl;
	return 0;
}