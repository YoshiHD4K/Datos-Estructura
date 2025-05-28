#include <iostream>

using namespace std;

struct Divisor
{
    int numero;
    int Divisores[5];

    void limpiar()
    {
        int i=0;
        while (i < 5)
        {
            Divisores[i] = 0;
            i++;
        }
    }

    void generardivisores()
    {
        int i = 1, j=0;
        while (i <= numero)
        {
            if (numero % i == 0)
            {
                Divisores[j]=i;
                j++;
            }
            if (j == 5)
            {
                return;
            }
            i++;
        }
    }

    void imprimirdivisores()
    {
        cout << "Numero: " << numero << " - Divisores: ";
        int i = 0;
        while (i < 5)
        {
            cout << Divisores[i] << (i < 4 ? ", " : ".");
            i++;
        }
    }
};

int main()
{
    Divisor numeros[20];

    int i=0, num;

    while (i < 20)
    {
        do
        {
            cout << "Ingrese un Numero mayor a 50: ";
            cin >> num;

            if (num < 50)
            {
                cout << endl
                     << endl
                     << "El numero ingresado es menor a 50. Intente nuevamente" << endl;
            }
            cout << endl;
        } while (num < 50);
        numeros[i].numero = num;
        numeros[i].limpiar();
        numeros[i].generardivisores();
        numeros[i].imprimirdivisores();
        i++;
    }

    return 0;
}