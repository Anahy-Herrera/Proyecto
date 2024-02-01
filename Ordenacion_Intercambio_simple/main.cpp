//Metodo de ordenacion por intercambio simple
#include <iostream>

using namespace std;

template<typename T>
void intercambiar(T &a, T &b){
    T aux;
    aux = a;
    a = b;
    b = aux;
}
template<typename T>
void imprimirPasadas(T arreglo[], int longitud, int pasada){
    cout << "Pasada "<<"("<<pasada<<"): ";
    for (int i = 0; i < longitud; i++) {
        cout << arreglo[i] << " ";
    }
}

template<typename T>
void imprimirArregloOrdenado(T arreglo[], int longitud){
    cout << "Arreglo ordenado: ";
    for (int i = 0; i < longitud; i++) {
        cout << arreglo[i] << " ";
    }
    cout << "\n";
}
template<typename T>
void ordIntercambio(T arreglo[], int longitud){
    int i, j;
    for(i = 0; i < longitud-1; i++){
        for(j = i+1; j < longitud; j++){
            if(arreglo[i] > arreglo[j]){
               intercambiar(arreglo[i], arreglo[j]);
                imprimirPasadas(arreglo, longitud, i+1);
               cout << "\n";
            }
        }
    }
}

template<typename T>
void imprimirArregloOriginal(T arreglo[], int longitud){
    cout << "Arreglo original: ";
    for (int i = 0; i < longitud; i++) {
        cout << arreglo[i] << " ";
    }
    cout << "\n";
}

int main(){
    //char arreglo[] = {'i', 'e', 'o', 'u', 'a'};
    //char arreglo[] = {'f', 'k', 'p', 'c', 'l'};
    int arreglo[] = {64, 25, 12, 22, 11};
    //float arreglo[] = {64.65, 25.22, 12.75, 22.14, 11.64};
    int longitud = sizeof(arreglo)/sizeof(arreglo[0]);

    imprimirArregloOriginal(arreglo, longitud);
    cout << "\n";

    ordIntercambio(arreglo, longitud);
    cout << "\n";

    imprimirArregloOrdenado(arreglo, longitud);

    return 0;
}
