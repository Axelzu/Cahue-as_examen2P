#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_MESES 12
#define NUM_INSUMOS 30
#define MAX_NOMBRE_INSUMO 50
void generarDatosAleatorios(int registros[NUM_INSUMOS][NUM_MESES][2], char nombresInsumos[NUM_INSUMOS][MAX_NOMBRE_INSUMO]) {
    srand(time(NULL));
    //aqui ya esta prea asignado los nombres de cada cosmetico o producto
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
//esto es para imrpimir con detalle los registros de ingreso y egresos
void imprimirDetalle(int registros[NUM_INSUMOS][NUM_MESES][2], char nombresInsumos[NUM_INSUMOS][MAX_NOMBRE_INSUMO]) {
    printf("\nDetalle de ingresos y egresos por mes y por insumo:\n");
    for (int insumo = 0; insumo < NUM_INSUMOS; ++insumo) {
        printf("\nInsumo: %s\n", nombresInsumos[insumo]);
        for (int mes = 0; mes < NUM_MESES; ++mes) {
            printf("Mes %d: Ingresos: %d, Egresos: %d\n", mes + 1, registros[insumo][mes][0], registros[insumo][mes][1]);
        }
    }
}
//aqui se calulan y se mostraran los totales de ingresos y egresos 
void calcularTotales(int registros[NUM_INSUMOS][NUM_MESES][2], char nombresInsumos[NUM_INSUMOS][MAX_NOMBRE_INSUMO]) {
    printf("\nTotales de ingresos y egresos por insumo en todo el año:\n");
    for (int insumo = 0; insumo < NUM_INSUMOS; ++insumo) {
        int totalIngresos = 0, totalEgresos = 0;
        for (int mes = 0; mes < NUM_MESES; ++mes) {
            totalIngresos += registros[insumo][mes][0];
            totalEgresos += registros[insumo][mes][1];
        }
        printf("%d. %s: Total Ingresos: %d, Total Egresos: %d\n", insumo + 1, nombresInsumos[insumo], totalIngresos, totalEgresos);
    }
}
int main() {
    int registros[NUM_INSUMOS][NUM_MESES][2] = {0};
    char nombresInsumos[NUM_INSUMOS][MAX_NOMBRE_INSUMO];

    generarDatosAleatorios(registros, nombresInsumos);

    int opcion;
    do {
        printf("\nOpciones:\n");
        printf("1) Imprimir detalle de ingresos y egresos por mes y por insumo\n");
        printf("2) Obtener total de ingresos y egresos por insumo en todo el año\n");
        printf("0) Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                imprimirDetalle(registros, nombresInsumos);
                break;
            case 2:
                calcularTotales(registros, nombresInsumos);
                break;
            case 0:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida. Inténtelo de nuevo.\n");
        }
    } while (opcion != 0);

    return 0;
}