#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_MESES 12
#define NUM_INSUMOS 30
#define MAX_NOMBRE_INSUMO 50
void generarDatosAleatorios(int registros[NUM_INSUMOS][NUM_MESES][2], char nombresInsumos[NUM_INSUMOS][MAX_NOMBRE_INSUMO]) {
    srand(time(NULL));
    char nombres[][MAX_NOMBRE_INSUMO] = {
        "Jeringas",
        "Vendas",
        "Guantes médicos",
        "Termómetros",
        "Alcohol",
        "Gasas estériles",
        "Medicamentos",
        "ropa de protección no textil",
        "bombas de uso médico",
        "Antisépticos",
        "aparatos de ozonoterapia",
        "medicamentos de uso humano oncólogo y VIH",
        "reactivos",
        "pruebas de laboratorio",
        "empaques especiales",
        "químicos",
        "Sillas de ruedas"
        "Recipientes y distintos productos de aseo",
        "Analgésicos",
        "Medidores de glucosa",
        "Glucómetros",
        "Tomógrafos",
        "Agujas",
        "Camas hospitalarias",
        "Equipos de rayos X",
        "Equipos de resonancia magnética",
        "Antivirales",
        "Antipiréticos",
        "Tubos de ensayo",
        "Microscopios",
        
        
    };

    for (int insumo = 0; insumo < NUM_INSUMOS; ++insumo) {
        // Asignar nombre de cosmético o producto aleatorio
        int indiceNombre = rand() % (sizeof(nombres) / sizeof(nombres[0]));
        snprintf(nombresInsumos[insumo], MAX_NOMBRE_INSUMO, "%s", nombres[indiceNombre]);

        for (int mes = 0; mes < NUM_MESES; ++mes) {
            registros[insumo][mes][0] = rand() % 1000;  // Ingresos aleatorios
            registros[insumo][mes][1] = rand() % 500;   // Egresos aleatorios
        }
    }
}
