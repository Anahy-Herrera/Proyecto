#include <iostream>
#include <vector>
using namespace std;

// Funci�n para encontrar el m�ximo en el vector
int findMax(const vector<int>& arr) {
    int max = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Funci�n para realizar el counting sort en el d�gito espec�fico (exp)
void countingSort(vector<int>& arr, int exp) {
    const int n = arr.size();
    vector<int> output(n, 0);
    vector<int> count(10, 0);

    // Contar la frecuencia de cada d�gito
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Calcular la posici�n actual de cada d�gito en el vector de salida
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

// Funci�n principal de radix sort
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
    cout << "Ingrese el tama�o del vector: ";
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
