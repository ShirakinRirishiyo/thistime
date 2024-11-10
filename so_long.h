/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 11:55:45 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/11/07 12:32:46 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef _COLORS
# define _COLORS

# define BLACK   "\033[1;30m"
# define RED     "\033[1;31m"
# define GREEN   "\033[1;32m"
# define YELLOW  "\033[1;33m"
# define BLUE    "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN    "\033[1;36m"
# define WHITE   "\033[1;37m"
# define NC      "\033[0m"

#endif // !_COLORS

# ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./printf/libft/libft.h"
# include "./printf/ft_printf.h"
# include "./minilibx-linux/mlx.h"


# define ESC	65307
# define W		119
# define A		97
# define S		115
# define D		100
# define SPRITE_SIZE 64
# define BACKGROUif (cargar_imagen(data, &(data->imagenes->collect2), COLLECT2_IMAGE)) return 1;ND_COLOR 0x00FF00 

// # define RED "\033[0;31m"
// # define BLUE "\033[0;34m"
// # define YELLOW "\033[0;33m"
// # define GREEN "\033[0;32m"
// # define CYAN "\033[0;36m"
// # define WHITE "\033[0;97m"
// # define RESET "\033[0m"

# define WALL_IMAGE "./sprites/walls.xpm"
# define SPACE_IMAGE "./sprites/pared.xpm"
# define PLAYER_F1 "./sprites/player1.xpm"
# define COLLECT1_IMAGE "./sprites/oritoabajo.xpm"
# define EXIT_IMAGE "./sprites/castle.xpm"


# define VALIDOS "10CPE"

typedef struct s_check 
{
    int **maps;         // Mapa de celdas visitadas
    int coins_left;     // Número de monedas restantes
    int exitparse;      // Indica si la salida fue encontrada
    int exit_x;         // Coordenada X de la salida
    int exit_y;         // Coordenada Y de la salida
} t_check;


typedef struct s_imagenes
{
    void *wall;
    void *space;
    void *player_frame1;
    void *player_frame2;
    void *collect;
    void *exit;
    void *torre;
    void *fuego1;
    void *fuego2;
} t_imagenes;


typedef struct s_mapa 
{
    char *text;             // Nombre del archivo .ber o información adicional
    char **map;             // Matriz del mapa
    int height;             // Altura del mapa (en número de filas)
    int width;              // Anchura del mapa (en número de columnas)
    int i; 
    int element;        // Tipo de elemento en la posición actual
    int start_i;        // Posición i inicial del jugador
    int start_j;             // Posición i del jugador
    int j;              // Posición j del jugador
    int x;                  // Posición x genérica (p. ej., posición del jugador)
    int y; 
    int size_x;          // Ancho de la ventana en píxeles
    int size_y;
    int exit;                // Posición y genérica (p. ej., posición del jugador)
    int player_x;           // Coordenada X inicial del jugador
    int player_y;           // Coordenada Y inicial del jugador
    int exit_x;             // Coordenada X de la salida
    int exit_y;             // Coordenada Y de la salida
    int player;             // Contador de jugadores en el mapa (para validación)
    int colectables;        // Número de coleccionables en el mapa
    int finish;   
    unsigned int pasos;     // Contador de pasos del jugador
    void *background_img;   // Imagen de fondo
    void *mlx;              // Puntero a la instancia de MLX
    void *win;              // Puntero a la ventana de MLX
    t_imagenes *imagenes;   // Estructura de imágenes del juego
} t_mapa;   

typedef struct s_indices 
{
    int i;   
    int j;   
    int end; 
} t_indices;

typedef struct s_contxt
{
    void    *mlx;        
    void    *win;        
    t_imagenes *imagenes; 
} t_contxt;

typedef struct s_mapa_info 
{
    int fd;                    // Descriptor de archivo para el archivo del mapa
    char *line;                // Línea de texto actual leída del archivo
    int line_length;           // Longitud de la línea
    int current_line_length;   // Longitud de la línea actual
    int first_line_length;     // Longitud de la primera línea
    int is_rectangular;        // Bandera para verificar si el mapa es rectangular
    int i;                     // Contador de líneas
} t_mapa_info;


int write_itoa(int n);
void ft_input_error(int argc);
void load_map(t_mapa *data);
int cargar_imagen(t_mapa *data, void **img,  char *ruta);
void ft_free(t_check *c, int height);
void manejar_error_fd(const char *mensaje, int fd, char *line);
void dibujar_mapa(t_mapa *data); 
void procesa_line(t_mapa *data, t_mapa_info *info);
void es_posible(t_mapa *data);
void move_w(t_mapa *data);
void move_s(t_mapa *data);
void move_d(t_mapa *data);
void move_a(t_mapa *data);
int	ft_strlen_trimmed(const char *str);
void encontrar_posiciones(t_check *check, t_mapa *data);
int es_valido(int x, int y, t_check *check, t_mapa *data);
void flood_fill(int x, int y, t_check *check, t_mapa *data);
void find_exit(t_mapa *data, t_check *c);
void init_map(t_mapa *data, t_mapa_info *info);
void    reset_data(t_mapa *data, char *name);
int	frame_s(t_mapa *data);
// int key_hook(int keycode, t_mapa *data);
int key_hook(int keycode, void *param);
void ft_printear(unsigned int n);
int exit_game(t_mapa *data);
void find_px_py(t_mapa *data);
void ft_parse_input(t_mapa *data, char **argv, int argc);
 void	ft_check_borders(t_mapa *data);
void	ft_game_result(t_mapa *data);
void	manejar_error(const char *mensaje);
void actualizar_pantalla(t_mapa *data);
void actualizar_animacion_fuego(t_mapa *data);
void dibujo_mapa(t_mapa *data);
void malloc_fail(void);
void read_map(t_mapa *data);
void mapa_size(t_mapa *data);
void objetos_de_mapa(t_mapa *data);
void caracter_valido(t_mapa *data);
int	cargar_imagenes(t_mapa *data);
t_check *inicializar_check(int height, int width);
void liberar_check(t_check *check, int height);
int analizar_accesibilidad(t_mapa *data);
void comprobacion_open_ber(t_mapa *data);
void ft_window_size(t_mapa *data);
int check_rectangular(t_mapa *mapa);
int es_valido(int x, int y, t_check *check, t_mapa *data);
void flood_fill(int x, int y, t_check *check, t_mapa *data);
int camino_hacia_coleccionables(t_check *check);
int camino_hacia_salida(t_check *check);
int llamada_funciones(t_mapa *data, char **argv);
void check_general(t_mapa *data);
void draw_grid(t_mapa *data); 
void reset_data(t_mapa *data, char *name);
void check_general(t_mapa *data);
void free_game(t_mapa *data);
void free_array(char **array);
void look_player(t_mapa *data);

#endif
