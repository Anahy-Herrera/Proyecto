#include <iostream>

using namespace std;

template<typename T>
void Intercambio(T &a, T &b) {
    int temp = a;
    a = b;
    b = temp;
}

template<typename T>
void Shellsort(T a[], T n) {
    int salto = n / 2;

    while (salto > 0) {
        // Para dividir la lista en grupos y clasificar cada grupo se anida este código
        for (int i = salto; i < n; i++) {
            int j = i - salto;
            while (j >= 0) {
                int k = j + salto;
                if (a[j] <= a[k]) {
                    j = -1;
                } else {
                    Intercambio(a[j], a[j + 1]);
                    j = j - salto;
                }
            }
        }
        salto = salto / 2;
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

    Shellsort(arreglo, n);

    cout << "\nArreglo ordenado mediante SHELLSORT:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arreglo[i] << " ";
    }

    return 0;

    return 0;
}
