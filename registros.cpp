#include <iostream>
#include <string>
using namespace std;

// Definición de la estructura para el registro de estudiantes
struct Estudiante {
    int id;
    string nombre;
    float promedio;
};

// Funciones para operaciones con registros
void agregarEstudiante(Estudiante estudiantes[], int &n) {
    if (n >= 10) {
        cout << "No se pueden agregar más estudiantes (límite alcanzado)." << endl;
        return;
    }
    Estudiante nuevo;
    cout << "Ingrese ID del estudiante: ";
    cin >> nuevo.id;
    cin.ignore();
    cout << "Ingrese nombre del estudiante: ";
    getline(cin, nuevo.nombre);
    cout << "Ingrese promedio del estudiante: ";
    cin >> nuevo.promedio;
    estudiantes[n] = nuevo;
    n++;
    cout << "Estudiante agregado exitosamente." << endl;
}

void mostrarEstudiantes(const Estudiante estudiantes[], int n) {
    if (n == 0) {
        cout << "No hay estudiantes para mostrar." << endl;
        return;
    }
    cout << "Lista de estudiantes:\n";
    for (int i = 0; i < n; i++) {
        cout << "ID: " << estudiantes[i].id
             << ", Nombre: " << estudiantes[i].nombre
             << ", Promedio: " << estudiantes[i].promedio << endl;
    }
}

void buscarEstudiante(const Estudiante estudiantes[], int n) {
    int id;
    cout << "Ingrese el ID del estudiante a buscar: ";
    cin >> id;
    bool encontrado = false;
    for (int i = 0; i < n; i++) {
        if (estudiantes[i].id == id) {
            cout << "Estudiante encontrado: " << endl;
            cout << "ID: " << estudiantes[i].id
                 << ", Nombre: " << estudiantes[i].nombre
                 << ", Promedio: " << estudiantes[i].promedio << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "Estudiante no encontrado." << endl;
    }
}

void editarEstudiante(Estudiante estudiantes[], int n) {
    int id;
    cout << "Ingrese el ID del estudiante a editar: ";
    cin >> id;
    bool encontrado = false;
    for (int i = 0; i < n; i++) {
        if (estudiantes[i].id == id) {
            cout << "Editando estudiante con ID " << id << ":\n";
            cout << "Ingrese nuevo nombre: ";
            cin.ignore();
            getline(cin, estudiantes[i].nombre);
            cout << "Ingrese nuevo promedio: ";
            cin >> estudiantes[i].promedio;
            cout << "Estudiante editado exitosamente." << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "Estudiante no encontrado." << endl;
    }
}

void eliminarEstudiante(Estudiante estudiantes[], int &n) {
    int id;
    cout << "Ingrese el ID del estudiante a eliminar: ";
    cin >> id;
    bool encontrado = false;
    for (int i = 0; i < n; i++) {
        if (estudiantes[i].id == id) {
            for (int j = i; j < n - 1; j++) {
                estudiantes[j] = estudiantes[j + 1];
            }
            n--;
            cout << "Estudiante eliminado exitosamente." << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "Estudiante no encontrado." << endl;
    }
}

// Función para calcular el promedio general de todos los estudiantes
void calcularPromedioGeneral(const Estudiante estudiantes[], int n) {
    if (n == 0) {
        cout << "No hay estudiantes para calcular el promedio general." << endl;
        return;
    }
    float suma = 0;
    for (int i = 0; i < n; i++) {
        suma += estudiantes[i].promedio;
    }
    float promedioGeneral = suma / n;
    cout << "El promedio general de todos los estudiantes es: " << promedioGeneral << endl;
}

// Función para mostrar el estudiante con el mejor promedio
void mostrarEstudianteMejorPromedio(const Estudiante estudiantes[], int n) {
    if (n == 0) {
        cout << "No hay estudiantes para evaluar." << endl;
        return;
    }
    Estudiante mejor = estudiantes[0];
    for (int i = 1; i < n; i++) {
        if (estudiantes[i].promedio > mejor.promedio) {
            mejor = estudiantes[i];
        }
    }
    cout << "Estudiante con el mejor promedio:\n";
    cout << "ID: " << mejor.id << ", Nombre: " << mejor.nombre << ", Promedio: " << mejor.promedio << endl;
}

// Función para mostrar el estudiante con el peor promedio
void mostrarEstudiantePeorPromedio(const Estudiante estudiantes[], int n) {
    if (n == 0) {
        cout << "No hay estudiantes para evaluar." << endl;
        return;
    }
    Estudiante peor = estudiantes[0];
    for (int i = 1; i < n; i++) {
        if (estudiantes[i].promedio < peor.promedio) {
            peor = estudiantes[i];
        }
    }
    cout << "Estudiante con el peor promedio:\n";
    cout << "ID: " << peor.id << ", Nombre: " << peor.nombre << ", Promedio: " << peor.promedio << endl;
}

// Función para listar estudiantes con promedio superior a un valor dado
void listarEstudiantesConPromedioMayor(const Estudiante estudiantes[], int n) {
    if (n == 0) {
        cout << "No hay estudiantes para evaluar." << endl;
        return;
    }
    float limite;
    cout << "Ingrese el promedio límite: ";
    cin >> limite;
    bool encontrado = false;
    cout << "Estudiantes con promedio mayor a " << limite << ":\n";
    for (int i = 0; i < n; i++) {
        if (estudiantes[i].promedio > limite) {
            cout << "ID: " << estudiantes[i].id << ", Nombre: " << estudiantes[i].nombre << ", Promedio: " << estudiantes[i].promedio << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No hay estudiantes con promedio superior a " << limite << endl;
    }
}

// Menú principal
int main() {
    Estudiante estudiantes[10];
    int n = 0;
    int opcion;

    do {
        cout << "\nMenú de opciones:\n";
        cout << "1. Agregar estudiante\n";
        cout << "2. Mostrar estudiantes\n";
        cout << "3. Buscar estudiante por ID\n";
        cout << "4. Editar estudiante\n";
        cout << "5. Eliminar estudiante\n";
        cout << "6. Calcular promedio general\n";
        cout << "7. Mostrar estudiante con mejor promedio\n";
        cout << "8. Mostrar estudiante con peor promedio\n";
        cout << "9. Listar estudiantes con promedio superior a un valor\n";
        cout << "10. Salir\n";
        cout << "Selecciona una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: agregarEstudiante(estudiantes, n); break;
            case 2: mostrarEstudiantes(estudiantes, n); break;
            case 3: buscarEstudiante(estudiantes, n); break;
            case 4: editarEstudiante(estudiantes, n); break;
            case 5: eliminarEstudiante(estudiantes, n); break;
            case 6: calcularPromedioGeneral(estudiantes, n); break;
            case 7: mostrarEstudianteMejorPromedio(estudiantes, n); break;
            case 8: mostrarEstudiantePeorPromedio(estudiantes, n); break;
            case 9: listarEstudiantesConPromedioMayor(estudiantes, n); break;
            case 10: cout << "Saliendo del programa...\n"; break;
            default: cout << "Opción no válida, intenta nuevamente.\n"; break;
        }
    } while (opcion != 10);

    return 0;
}
