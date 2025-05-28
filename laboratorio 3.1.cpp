/*  1. Utilizando solo 1 arreglo. Y dada la siguiente definición de la estructura 
Typedef divisor = array [n] of integer;
Elabore un algoritmo en C, que almacene en esa estructura y solo en esa los números que 
ingresan por teclado y sus 5 primeros divisores*/

#include <iostream>
using namespace std;

int divisor[5], numero, contadorDivisores;
char continuar;

int main()
{   
    do
    {
        
        cout << "Ingrese un numero natural: ";
        cin >> numero;        
        divisor[0] = numero;       
        contadorDivisores = 1;

        for (int i = 1; i <= numero and contadorDivisores <= 5; i++)
        {
            if (numero % i == 0)
            {
                divisor[contadorDivisores] = i;
                contadorDivisores++;
            }
        }
        
        cout << "Numero ingresado: " << divisor[0] << endl;
        for (int i = 1; i < 6; i++)
        {
            cout << "Divisor " << i << ": " << divisor[i] << endl;
        }
        cout << endl;

        cout << "¿Desea ingresar otro numero? (s/n): ";
        cin >> continuar;
    } while (continuar == 's' || continuar == 'S');

    return 0;
}