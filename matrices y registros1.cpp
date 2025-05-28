#include <iostream>
#include <locale.h>

using namespace std;

int matriz[20][5];

int main(){
    setlocale(LC_ALL, "Spanish");

    int i, j;

    while (i<=20){

        while (j<=4)
        {
            matriz[i][j] = 0;
            j++;
        }
        i++;
        j = 0;
    }

    

}