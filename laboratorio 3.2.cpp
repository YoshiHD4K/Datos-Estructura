/*Dada la siguiente definición de la estructura arreglo
Typedef cola = array [n] of interger;
Integer fin,inicio;
Escriba un algoritmo en C, que simule la atención de una cola en una taquilla
bancaria, cuya capacidad máxima es de 8 personas resuelva las colisiones (cuando no haya
espacio) y controle cuando la cola está llena o vacía*/

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <locale.h>

using namespace std;

int cola[8];
int inicio = 0;
int fin = 0;

void eliminarcola();

void agregarcola(int valor)
{
    if (inicio == fin and cola[inicio] != 0) //Cola llena?
    {
        eliminarcola();
        return;
    }
    cola[fin] = valor;
    fin++;
    if (fin == 8)
    {
        fin = 0;
    }
    cout << "Agregado a la cola: " << valor << endl;
}

void eliminarcola()
{
    if (inicio == fin and cola[fin] == 0) //Cola vacia?
    {
        agregarcola(rand() % 10 + 1);
        return;
    }
    cout << "Eliminado de la cola: " << cola[inicio] << endl;
    cola[inicio] = 0;
    inicio++;
    if (inicio == 8)
    {
        inicio = 0;
    }
}

int main()
{
    setlocale(LC_ALL, "Spanish");
    cout << "Simulador de cola bancaria" << endl;
    cout << "Presione 'q' para salir." << endl
         << endl;
    Sleep(1000);
    do
    {
        if (kbhit())
        {
            char tecla = getch();
            if (tecla == 'q')
            {
                break; // Salir del bucle si se presiona 'q'
            }
        }
        switch (rand() % 2)
        {
            {
            case 0:
                agregarcola(rand() % 10 + 1);
                break;
            case 1:
                eliminarcola();
                break;
            }
        }
        Sleep(2000);
    } while (true);
    cout << endl;
    cout << "Fin de la simulación." << endl;
    return 0;
}