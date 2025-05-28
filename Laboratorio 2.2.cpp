/*Utilizando una Pila escriba un programa en C++ que evalue una expresión algebraica ingresada
 y determine si los separadores se encuentran debidamente balanceado*/

#include <iostream>
#include <string>
#include <stack>
#include <locale.h>

using namespace std;

string expresion;
char opcion, c;
int posicion;

int main()
{
    
    do
    {
        
        cout << "Ingrese una expresión matemática: ";
        getline(cin, expresion);

        // Mostrar la expresión ingresada
        system("cls");
        cout << "La expresión ingresada es: " << expresion << endl;

        stack<size_t> pila; // Pila que almacena solo las posiciones

        // Procesar la expresión
        int i = 0;
        for (i = 0; i < expresion.length(); i++){

            c = expresion[i];
            if (c == '(' or c == '{' or c == '['){
                pila.push(i); // Almacenar posición de apertura
            }
            else if (c == ')' || c == '}' || c == ']')
            {
                if (!pila.empty() and 
                        (
                            ( c == ')' and expresion[pila.top()] == '(' ) or
                            ( c == '}' and expresion[pila.top()] == '{') or
                            ( c == ']' and expresion[pila.top()] == '[')
                        )
                    )
                {
                    pila.pop(); // Eliminar la posición del par coincidente
                }
                else
                {
                    pila.push(i); // Almacenar posición de cierre sin apertura
                }
            }
            
        }

        // Verificar el balanceo
        if (pila.empty())
        {
            cout << "La expresión está balanceada." << endl;
        }
        else
        {
            cout << "La expresión no está balanceada." << endl;

            // Mostrar las posiciones que no tienen pareja
            while (!pila.empty())
            {
                posicion = pila.top();
                pila.pop();
                cout << "Carácter sin pareja en posición: " << posicion << " (' " << expresion[posicion] << " ')" << endl;
            }
        }

        // Preguntar al usuario si desea continuar
        cout << "¿Desea ingresar una nueva expresión? (s/n): ";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer de entrada
        system("cls");
    } while (opcion == 's' || opcion == 'S');

    return 0;
}