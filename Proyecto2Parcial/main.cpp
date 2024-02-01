#include <iostream>
#include <fstream>
#include <string>
#include <limits>


using namespace std;

const int MAX_ESTUDIANTES = 4;

struct Estudiante {
    string nombre;
    double notas[8];
};

struct Docente {
    string nombre;
    string cedula;
    string materia;
    string nrc;
    Estudiante estudiantes[MAX_ESTUDIANTES];
    int numEstudiantes;
};

void pedirDatosDocente(Docente &docente) {
    cout << "Ingrese su nombre: ";
    getline(cin, docente.nombre);

    cout << "Ingrese su cédula: ";
    getline(cin, docente.cedula);


    cout << "Ingrese la materia: ";
    getline(cin, docente.materia);


    cout << "Ingrese el NRC: ";
    getline(cin, docente.nrc);

}

void intercambiar(int &a, int &b) {
    int temp = a;
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
double findMax(const double arr[], int size) {
    double max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Función para realizar el counting sort en el dígito específico (exp)
void countingSort(int arr[], int n, int exp) {
    const int maxVal = 10; // Cambiar según el rango de los dígitos (0-9)
    int output[n];
    int count[maxVal];

    // Inicializar el arreglo de conteo
    for (int i = 0; i < maxVal; i++) {
        count[i] = 0;
    }

    // Contar la frecuencia de cada dígito
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Calcular la posición actual de cada dígito en el arreglo de salida
    for (int i = 1; i < maxVal; i++) {
        count[i] += count[i - 1];
    }

    // Construir el arreglo de salida
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copiar el arreglo de salida al arreglo original
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void radixSort(int arr[], int n) {
    int max1 = findMax(arr, n);
    int exp = 1;

    while (max1 / exp >= 1) {
        countingSort(arr, n, exp);
        exp *= 10;
    }
}

template<typename T>
void Shellsort(T a[], int n) {
    int salto = n / 2;

    while (salto > 0) {
        for (int i = salto; i < n; i++) {
            int j = i - salto;
            while (j >= 0) {
                if (a[j] <= a[j + salto]) {
                    break;
                } else {
                    intercambiar(a[j], a[j + salto]);
                    j = j - salto;
                }
            }
        }
        salto = salto / 2;
    }
}

template<typename T>
void ordBurbuja(T arreglo[], int longitud) {
    for (int i = 0; i < longitud - 1; i++) {
        for (int j = 0; j < longitud - i - 1; j++) {
            if (arreglo[j] > arreglo[j + 1]) {
                intercambiar(arreglo[j], arreglo[j + 1]);
            }
        }
    }
}

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

    delete[] bins;
    delete[] sortedArr;
}


void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[minIndex] > arr[j]) {
                minIndex = j;
            }
        }
        intercambiar(arr[i], arr[minIndex]);
    }
}


void limpiarBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void ingresarNotas(Docente &docente) {
    char respuesta;
    int index = 0;
    const int numNotas = 8; // Cambiar según el número deseado de notas

    do {
        cout << "Ingrese el nombre del estudiante: ";
        getline(cin, docente.estudiantes[index].nombre);
        limpiarBuffer();

        cout << "Ingrese las notas del estudiante:" << endl;
        for (int i = 0; i < numNotas; ++i) {
            cout << "Nota " << i + 1 << ": ";
            while (true) {
                if (cin >> docente.estudiantes[index].notas[i] &&
                    docente.estudiantes[index].notas[i] >= 0 &&
                    docente.estudiantes[index].notas[i] <= 10) {
                    limpiarBuffer();
                    break;
                } else {
                    cout << "Por favor, ingrese una nota válida entre 0 y 10." << endl;
                    cout << "Nota " << i + 1 << ": ";
                    limpiarBuffer();
                }
            }
        }

        index++;

        cout << "¿Desea agregar otro estudiante? (s/n): ";
        cin.ignore(); // Ignorar el salto de línea pendiente
        cin >> respuesta;
        limpiarBuffer(); // Limpiar el buffer después de leer la respuesta
    } while (respuesta == 's' || respuesta == 'S');

    // Actualizar el número total de estudiantes al final del bucle
    docente.numEstudiantes = index;
}


void mostrarContenidoArchivo(const string &nombreArchivo) {
    ifstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }

        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo '" << nombreArchivo << "'" << endl;
    }
}

void almacenarEnArchivo(const Docente &docente) {
    ofstream archivo("calificaciones.csv", ios::app);

    if (archivo.is_open()) {
        // Encabezados
        archivo << "Nombre,Notas" << endl;

        // Almacenar datos
        for (int i = 0; i < docente.numEstudiantes; ++i) {
            archivo << docente.estudiantes[i].nombre << ",";
            for (int j = 0; j < 8; ++j) {
                archivo << docente.estudiantes[i].notas[j];
                if (j < 7) {
                    archivo << ",";
                }
            }
            archivo << endl;
        }

        cout << "Datos almacenados en el archivo 'calificaciones.csv'" << endl;

        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo 'calificaciones.csv'" << endl;
    }
}

void borrarTodosLosDatos(const string &nombreArchivo) {
    ofstream archivo(nombreArchivo, ios::trunc);

    if (archivo.is_open()) {
        cout << "Todos los datos han sido borrados del archivo '" << nombreArchivo << "'" << endl;
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo '" << nombreArchivo << "'" << endl;
    }
}

void borrarDatosPorTipo(const string &nombreArchivo, const string &tipoABorrar) {
    ifstream archivoEntrada(nombreArchivo);
    ofstream archivoSalida("temp.csv");

    if (archivoEntrada.is_open() && archivoSalida.is_open()) {
        string linea;
        bool borrado = false;

        while (getline(archivoEntrada, linea)) {
            if (linea.find(tipoABorrar) != string::npos != string::npos) {
                cout << "Se ha borrado la línea: " << linea << endl;
                borrado = true;
            } else {
                archivoSalida << linea << endl;
            }
        }

        archivoEntrada.close();
        archivoSalida.close();

        if (borrado) {
            remove(nombreArchivo.c_str());
            rename("temp.csv", nombreArchivo.c_str());
        } else {
            remove("temp.csv");
        }
    } else {
        cout << "No se pudo abrir el archivo '" << nombreArchivo << "'" << endl;
    }
}

int main() {
    int opcion;
    Docente docente;
    pedirDatosDocente(docente);

    do {
        cout << "Ingrese una opcion: " << endl;
        cout << "(1) Ingresar datos" << endl;
        cout << "(2) Mostrar datos" << endl;
        cout << "(3) Borrar todos los datos" << endl;
        cout << "(4) Borrar seleccion" << endl;
        cout << "(5) Ordenar datos" << endl;
        cout << "(0) Salir" << endl;

        // Manejo de errores al ingresar la opción
        while (!(cin >> opcion)) {
            cout << "Error: Ingrese un valor entero válido." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (opcion) {
            case 1: {
                ingresarNotas(docente);
                almacenarEnArchivo(docente);
                break;
            }

            case 2: {
                mostrarContenidoArchivo("calificaciones.csv");
                break;
            }

            case 3: {
                cout << "Borrar todo el contenido del archivo" << endl;
                borrarTodosLosDatos("calificaciones.csv");
                break;
            }

            case 4: {
                string tipoABorrar;
                cout << "Ingrese el tipo a borrar: ";
                cin >> tipoABorrar;
                borrarDatosPorTipo("calificaciones.csv", tipoABorrar);
                break;
            }

            case 5: {
                int opcionOrdenamiento;
                cout << "Ordenar los datos" << endl;
                cout << "Ingrese la opción del método con el que desea ordenar los datos: ";
                cout << "Opción: ";
                cin >> opcionOrdenamiento;
                do {
                    cout << "Ingrese una opción para ordenar el vector:" << endl;
                    cout << "(1) Quicksort" << endl;
                    cout << "(2) Radixsort" << endl;
                    cout << "(3) Shellsort" << endl;
                    cout << "(4) Burbuja" << endl;
                    cout << "(5) Binsort" << endl;
                    cout << "(6) Selección" << endl;
                    cout << "(0) Volver al menú principal" << endl;

                    // Manejo de errores al ingresar la opción
                    while (!(cin >> opcionOrdenamiento)) {
                        cout << "Error: Ingrese un valor entero válido." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

                    if (opcionOrdenamiento != 0) {
                        // Utilizar el arreglo de notas de los estudiantes para el ordenamiento
                        int* vectorParaOrdenar = new int[docente.numEstudiantes];
                        for (int i = 0; i < docente.numEstudiantes; ++i) {
                            vectorParaOrdenar[i] = static_cast<int>(docente.estudiantes[i].notas);
                        }

                        ordenarArreglo(vectorParaOrdenar, docente.numEstudiantes, opcionOrdenamiento);

                        cout << "Vector ordenado:" << endl;
                        imprimirArreglo(vectorParaOrdenar, docente.numEstudiantes);

                        // Liberar la memoria asignada para el arreglo dinámico
                        delete[] vectorParaOrdenar;
                    }
                } while (opcionOrdenamiento != 0);
                break;
            }

            case 0: {
                // Salir del programa
                break;
            }

            default: {
                cout << "Opción no válida. Por favor, ingrese una opción válida." << endl;
                break;
            }
        }
    } while (opcion != 0);

    cout << "Programa terminado." << endl;

    return 0;
}
