#include <iostream>

int main() {

    int i=0;

    Mostrar: std::cout << "Tengo que Programar "<< i+1 << std::endl;
    i=i+1;
    if (i<200)
    {
        goto Mostrar;
    }
}