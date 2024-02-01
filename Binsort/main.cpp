#include <iostream>

using namespace std;

void binSort(int arr[], int n) {
    // Encontrar el valor máximo en el arreglo
    int maxVal = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    // Crear los bins
    int* bins = new int[(maxVal + 1)]{0};

    // Contar la ocurrencia de cada elemento en el arreglo
    for (int i = 0; i < n; ++i) {
        bins[arr[i]]++;
    }

    // Sumar las frecuencias acumuladas
    for (int i = 1; i <= maxVal; ++i) {
        bins[i] += bins[i-1];
    }

    // Construir el arreglo resultante
    int* sortedArr = new int[n]{0};
    for (int i = n - 1; i >= 0; --i) {
        sortedArr[bins[arr[i]] - 1] = arr[i];
        bins[arr[i]]--;
    }

    // Copiar el arreglo resultante a arr[]
    for (int i = 0; i < n; ++i) {
        arr[i] = sortedArr[i];
    }

    delete [] bins;
    delete [] sortedArr;
}

int main() {
    int arr[] = {4, 2, 7, 1, 9, 5, 8};
    constexpr size_t N = sizeof(arr)/sizeof(*arr);

    cout << "Arreglo original: ";
    for (size_t i = 0; i < N; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    binSort(arr, N);

    cout << "Arreglo ordenado: ";
    for (size_t i = 0; i < N; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
