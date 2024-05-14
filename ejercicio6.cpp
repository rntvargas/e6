#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

using namespace std;

int main() {
    ifstream archivo_entrada("C:/Users/renat/Desktop/ejercicio6/ejercicio6.txt");
    ofstream archivo_salida("C:/Users/renat/Desktop/ejercicio6/informe_horas.txt");

    if (!archivo_entrada.is_open()) {
        cerr << "No se pudo abrir el archivo de entrada." << endl;
        return 1;
    }

    if (!archivo_salida.is_open()) {
        cerr << "No se pudo abrir el archivo de salida." << endl;
        return 1;
    }

    map<string, int> horas_empleados;
    string linea, nombre;
    int horas;

    while (getline(archivo_entrada, linea)) {
        stringstream ss(linea);
        getline(ss, nombre, ',');
        ss >> horas;
        horas_empleados[nombre] += horas;
    }

    for (const auto& par : horas_empleados) {
        archivo_salida << par.first << ", Horas Totales: " << par.second << endl;
    }

    archivo_entrada.close();
    archivo_salida.close();
    cout << "El informe de horas totales trabajadas se ha generado y guardado en el archivo 'informe_horas.txt'." << endl;

    return 0;
}
