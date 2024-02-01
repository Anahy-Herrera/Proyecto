#include <iostream>

using namespace std;

template<typename T>
void intercambiar(T &a, T &b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template<typename T>
void quicksort(T a[], int primero, int ultimo) {
    if (primero < ultimo) {
        int i, j, central;
        T pivote;
        central = (primero + ultimo) / 2;
        pivote = a[central];
        i = primero;
        j = ultimo;

        do {
            while (a[i] < pivote) {
                i++;
            }
            while (a[j] > pivote) {
                j--;
            }
            if (i <= j) {
                intercambiar(a[i], a[j]);
                i++;
                j--;
            }
        } while (i <= j);
        if (primero < j) {
            quicksort(a, primero, j);
        }
        if (i < ultimo) {
            quicksort(a, i, ultimo);
        }
    }
}

int main() {
    int n;
    cout<<"Ingrese el tamaño del vector: ";
    cin>>n;
    int arreglo[n];


    for (int i = 0; i < n; i++) {
        cout << "Ingrese el numero (" <<i+1<<"):";
        cin>>arreglo[i];
    }

    quicksort(arreglo, 0, n - 1);

    cout << "\nArreglo ordenado mediante QUICKSORT:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arreglo[i] << " ";
    }

    return 0;
}


