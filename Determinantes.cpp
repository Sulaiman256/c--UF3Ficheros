#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Determinante {
    int organizacion;
    int matriz[3][3];
    };

int main(void) {
    void genera(struct Determinante *det);
    void muestra(struct Determinante *det);
    int calcula(struct Determinante *det);

    struct Determinante det;

    for (;;) {
        printf("Introduce el orden del determinante 2 o 3: ");
        scanf("%i", &det.organizacion);

        if (det.organizacion == 2 || det.organizacion == 3) {
            break;
        } else {
            printf("Por favor, introduce un orden valido 2 o 3.\n");
        }
    }

    genera(&det);

    printf("Matriz generada:\n");
    muestra(&det);

    int resultado = calcula(&det);
    printf("Resultado del determinante: %i\n", resultado);

    return 0;
}

void genera(struct Determinante *det) {
    int i, j;

    printf("¿Quieres introducir manualmente los elementos del determinante? (0: No, 1: Si): ");
    int opcion;
    scanf("%i", &opcion);

    if (opcion) {
        printf("Introduce los elementos del determinante:\n");
        for (i = 0; i < det->organizacion; i++) {
            for (j = 0; j < det->organizacion; j++) {
                printf("elemento [%i][%i]: ", i, j);
                scanf("%i", &det->matriz[i][j]);
            }
        }
    } else {
        srand(time(NULL));
        for (i = 0; i < det->organizacion; i++) {
            for (j = 0; j < det->organizacion; j++) {
                det->matriz[i][j] = rand() % 20 - 10;
            }
        }
    }
}

void muestra(struct Determinante *det) {
    int i, j;
    for (i = 0; i < det->organizacion; i++) {
        for (j = 0; j < det->organizacion; j++) {
            printf("%i\t", det->matriz[i][j]);
        }
        printf("\n");
    }
}

int calcula(struct Determinante *det) {
    int determinanteResultado = 0;

    if (det->organizacion == 2) {
        determinanteResultado = det->matriz[0][0] * det->matriz[1][1] - det->matriz[0][1] * det->matriz[1][0];
    } else if (det->organizacion == 3) {
        determinanteResultado = det->matriz[0][0] * det->matriz[1][1] * det->matriz[2][2] +
                                det->matriz[0][1] * det->matriz[1][2] * det->matriz[2][0] +
                                det->matriz[0][2] * det->matriz[1][0] * det->matriz[2][1] -
                                det->matriz[0][2] * det->matriz[1][1] * det->matriz[2][0] -
                                det->matriz[0][0] * det->matriz[1][2] * det->matriz[2][1] -
                                det->matriz[0][1] * det->matriz[1][0] * det->matriz[2][2];
    }
    return determinanteResultado;
}
