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


# define WALL_IMAGE "./sprites/walls.xpm"
# define SPACE_IMAGE "./sprites/pared.xpm"
# define PLAYER_F1 "./sprites/player1.xpm"
# define COLLECT1_IMAGE "./sprites/oritoabajo.xpm"
# define EXIT_IMAGE "./sprites/castle.xpm"


# define VALIDOS "10CPE"

typedef struct s_check 
{
    int **maps;         
    int coins_left;    
    int exitparse;      
    int exit_x;      
    int exit_y;         
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
    t_imagenes *imagenes;   
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
    int fd;                    
    char *line;               
    int line_length;           
    int current_line_length;   
    int first_line_length;     
    int is_rectangular;        
    int i;                     
} t_mapa_info;


void	handle_error(const char *mensaje);
void	find_position(t_check *check, t_mapa *data);
void	free_check(t_check *check, int height);
void	free_imagenes(t_mapa *data);
int		ft_accesibility(t_mapa *data);
void	flood_fill(int x, int y, t_check *check, t_mapa *data);
int		load_imagen(t_mapa *data, void **img, char *ruta);
int		load_imagenes(t_mapa *data);
int 	call_function(t_mapa *data, char **argv);
void	handle_error_fd(const char *mensaje, int fd, char *line);
void	maps_objects(t_mapa *data);
void	exit_error(const char *message);
void	exit_error(const char *message);
void	comprobacion_open_ber(t_mapa *data);
void	load_map(t_mapa *data);
void	draw_map(t_mapa *data);
void	draw_map_element(t_contxt *ctx, t_mapa *data, int i, int j);
void	draw_element(t_contxt *ctx, void *img, int x, int y);
void	ft_printing(unsigned int n);
void	refresh_window(t_mapa *data);
void	mapa_dimention_window(t_mapa *data);
int		way_to_collect(t_check *check);
void	memory_map(t_mapa *data);
void	upload_mapa(t_mapa *data);
int		is_valid(int x, int y, t_check *check, t_mapa *data);
void	free_double_p(t_mapa *data);

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
void free_game(t_mapa *data);
void free_array(char **array);
void look_player(t_mapa *data);

#endif
