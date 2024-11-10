#include <stdio.h>
#include <stdlib.h>

typedef struct s_mapa {
    char *text;
    char **map;
    int height;
    int width;
    int i;
    int element;
    int start_i;
    int start_j;
    int j;
    int x;
    int y;
    int size_x;
    int size_y;
    int exit;
    int player_x;
    int player_y;
    int exit_x;
    int exit_y;
    int player;
    int colectables;
    int finish;
    unsigned int pasos;
    void *background_img;
    void *mlx;
    void *win;
    struct s_imagenes *imagenes;
} t_mapa;

void exit_error(const char *message) {
    fprintf(stderr, "%s\n", message);
    exit(EXIT_FAILURE);
}

void check_borders(t_mapa *mapa) {
    int idx;

    // Verificar la primera y última fila
    idx = 0;
    while (idx < mapa->width) {
        if (mapa->map[0][idx] != '1' || mapa->map[mapa->height - 1][idx] != '1') {
            exit_error("Error: El borde superior o inferior no está cerrado.");
        }
        idx++;
    }

    // Verificar la primera y última columna
    idx = 0;
    while (idx < mapa->height) {
        if (mapa->map[idx][0] != '1' || mapa->map[idx][mapa->width - 1] != '1') {
            exit_error("Error: El borde izquierdo o derecho no está cerrado.");
        }
        idx++;
    }
}

int main() {
    // Ejemplo de mapa (asignación dinámica o inicialización en el programa real)
    char *mapa_ejemplo[] = {
        "1111111111111111",
        "100P110010011001",
        "100010001100000000",
        "1000100000C00001",
        "1000000E00000001",
        "1000110110000001",
        "1111111111111111"
    };

    t_mapa mapa;
    mapa.map = mapa_ejemplo;
    mapa.height = 7;  // Número de filas del mapa
    mapa.width = 16;  // Número de columnas del mapa

    // Llamada a la función para verificar los bordes
    check_borders(&mapa);

    printf("El mapa está correctamente rodeado por paredes.\n");
    return 0;
}
