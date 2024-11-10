#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

// Estructura de datos para almacenar información del mapa
typedef struct {
    int x; // Coordenada x del personaje
    int y; // Coordenada y del personaje
    int colectables; // Contador de coleccionables
    int height; // Altura del mapa (número de filas)
    int width; // Ancho del mapa (número de columnas)
    char **map; // Mapa como una matriz de cadenas
} t_mapa;

// Función para abrir el archivo y procesarlo
void leer_mapa(const char *ruta, t_mapa *data) {
    int fd = open(ruta, O_RDONLY);  // Abre el archivo de mapa en modo solo lectura
    if (fd == -1) {
        perror("Error al abrir el archivo"); // Imprime el error si no puede abrir el archivo
        exit(1); // Sale si no se puede abrir el archivo
    }

    // Convertimos el descriptor de archivo a un puntero FILE * para usar con getline
    FILE *file = fdopen(fd, "r");
    if (!file) {
        perror("Error al convertir el descriptor de archivo");
        exit(1);
    }

    // Variables auxiliares
    char *linea = NULL;
    size_t len = 0;
    ssize_t nread;
    data->colectables = 0; // Inicializa el contador de coleccionables
    data->x = -1; // Inicializa la posición del personaje (P)
    data->y = -1;

    // Leemos el archivo línea por línea
    data->height = 0;  // Inicializa el número de filas
    while ((nread = getline(&linea, &len, file)) != -1) {
        data->height++;  // Incrementa el número de filas
        data->width = nread;  // Anota el ancho de la línea (en este caso, la longitud de la cadena)

        // Procesamos cada carácter de la línea
        for (int i = 0; i < nread; i++) {
            char c = linea[i];

            if (c == 'P' && data->x == -1 && data->y == -1) {
                // Si encontramos la 'P' y aún no la hemos registrado, guardamos su posición
                data->x = i;
                data->y = data->height - 1;
                printf("Posición inicial de P encontrada: (%d, %d)\n", data->y, data->x);
            } else if (c == 'C') {
                // Contamos los coleccionables
                data->colectables++;
            }
        }

        // Almacenamos la línea en el mapa
        data->map[data->height - 1] = strdup(linea);
    }

    // Completamos el mapa con un puntero nulo al final para indicar el fin
    data->map[data->height] = NULL;

    // Liberamos la memoria de la línea
    free(linea);

    // Cerramos el archivo
    fclose(file);  // Usamos fclose porque ahora estamos trabajando con un FILE * y no con un descriptor de archivo
}

// Función para imprimir el mapa (para depuración)
void imprimir_mapa(t_mapa *data) {
    for (int i = 0; i < data->height; i++) {
        printf("%s", data->map[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <ruta_del_mapa>\n", argv[0]);
        return 1;  // Si no se pasa la ruta del mapa, se muestra un mensaje de uso
    }

    const char *ruta = argv[1];  // Usamos el primer argumento como la ruta del mapa

    t_mapa data;

    // Asignamos memoria para el mapa
    data.map = (char **)malloc(sizeof(char *) * 100);  // Asumiendo que no habrá más de 100 filas

    // Llamamos a la función para leer el mapa
    leer_mapa(ruta, &data);

    // Imprimimos el mapa para ver si todo se leyó correctamente
    imprimir_mapa(&data);

    // Imprimimos los resultados de la lectura
    printf("Total de coleccionables: %d\n", data.colectables);
    printf("Posición inicial de 'P': (%d, %d)\n", data.y, data.x);

    // Liberamos la memoria del mapa
    for (int i = 0; i < data.height; i++) {
        free(data.map[i]);
    }
    free(data.map);

    return 0;
}
