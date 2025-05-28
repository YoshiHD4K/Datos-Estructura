#include <iostream>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
using namespace std;

void invertir (int numeros[],int inicio, int fin);

int main(){
    int i,numeros[20],cantidad;
    bool continuar = true;
    
    do{
    cout << "Ingrese cuantos numeros desea agregar (0 para salir): ";
    while (!(cin >> cantidad)) {
        cout << "Introduzca un numero por favor: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    
    continuar = (cantidad != 0);
    if(continuar){
    for(i = 0; i < cantidad; i++){
        cout << "Digite el elemento " << i + 1 << ": ";
        while (!(cin >> numeros[i])) {
            cout << "Introduzca un numero por favor: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    invertir(numeros, 0 ,cantidad - 1);
    cout <<"\nArreglo invertido: ";
    for (i = 0; i < cantidad ; i++){
        cout << numeros[i]<< " ";
    }

    cout <<"\n";
    cout << "Presione cualquier tecla para continuar...";
    
    _getch();  
    system("cls");
    
}
}while(continuar);
    return 0;
}

void invertir (int numeros[],int inicio, int fin){
    if (inicio >= fin){
        return;
    }else {
        swap(numeros[inicio],numeros[fin]);
        invertir(numeros, inicio + 1, fin - 1);
    }
}

float capital_calculo(float capital, float interes, float anos)
{
    if (anos == 0)
    {
        return capital;
    }
    else
    {
        return capital_calculo(capital, interes, anos - 1) * (1 + interes);
    }
}