/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizenbe <aaizenbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 22:12:43 by aaizenbe          #+#    #+#             */
/*   Updated: 2024/03/09 22:12:43 by aaizenbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "MLX42/include/MLX42/MLX42.h"
#include <fcntl.h>
#include "libft/get_next_line.h"
#include "libft/ft_printf.h"

#define MAP_HEIGHT 10

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define GAME_NAME "Wizard's Quest"

typedef struct t_data
{
    char **map;
    int     fd;
    int     widthmap;
    int     heightmap;


}	t_data;

typedef struct t_game
{

    void   *mlx;
    void   *win;
    int     width;
    int     height;
    t_data  *data;

    struct s_textures
    {
        void *wall;
        void *floor;
        void *player;
        void *collectible;
        void *exit;
    }           textures;

}           t_game;

void	*mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);
void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
int	mlx_destroy_window(void *mlx_ptr, void *win_ptr);
int	mlx_destroy_image(void *mlx_ptr, void *img_ptr);
int    mlx_destroy_display(void *mlx_ptr);

int ft_get_map(char **argv, t_data *data);
int add_line(t_data *data, char *line);
int width_of_map(char *map);
void ft_error(char *str, t_data *data);
void ft_init_mlx(t_game *game);
void ft_end_game(t_game *game);
void ft_draw_map(t_game *game, t_data *data);
void ft_init_game(t_game *game, t_data *data);
int main(int argc, char **argv);

#endif
