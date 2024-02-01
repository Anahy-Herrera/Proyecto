#include <iostream>
#include <vector>
using namespace std;

// Función para encontrar el máximo en el vector
int findMax(const vector<int>& arr) {
    int max = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Función para realizar el counting sort en el dígito específico (exp)
void countingSort(vector<int>& arr, int exp) {
    const int n = arr.size();
    vector<int> output(n, 0);
    vector<int> count(10, 0);

    // Contar la frecuencia de cada dígito
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Calcular la posición actual de cada dígito en el vector de salida
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Construir el vector de salida
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copiar el vector de salida al vector original
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Función principal de radix sort
void radixSort(vector<int>& arr) {
    int max1 = findMax(arr);
    int exp = 1;

    while (max1 / exp >= 1) {
        countingSort(arr, exp);
        exp *= 10;
    }
}

int main() {
    // Ingreso de datos por teclado
    int n;
    cout << "Ingrese el tamaño del vector: ";
    cin >> n;

    vector<int> vectorEntrada(n);
    cout << "Ingrese los elementos del vector separados por espacios: ";
    for (int i = 0; i < n; i++) {
        cin >> vectorEntrada[i];
    }

    cout << "Vector original: ";
    for (int i = 0; i < n; i++) {
        cout << vectorEntrada[i] << " ";
    }
    cout << endl;

    radixSort(vectorEntrada);

    cout << "Vector ordenado: ";
    for (int i = 0; i < n; i++) {
        cout << vectorEntrada[i] << " ";
    }
    cout << endl;

    return 0;
}
