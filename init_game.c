/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizenbe <aaizenbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:23:24 by aaizenbe          #+#    #+#             */
/*   Updated: 2024/03/10 16:23:24 by aaizenbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void ft_init_game(t_game *game, t_data *data)
{
    game->width = WINDOW_WIDTH;
    game->height = WINDOW_HEIGHT;
    game->data = data;
    game->mlx = NULL;
    game->win = NULL;
    game->textures.wall = NULL;
    game->textures.floor = NULL;
    game->textures.player = NULL;
    game->textures.collectible = NULL;
    game->textures.exit = NULL;
}

void ft_init_mlx(t_game *game)
{
    int tex_width;
    int tex_height;
    game->mlx = mlx_init(game->width, game->height, GAME_NAME, false);
    if (!game->mlx)
        ft_error("Failed to initialize mlx", NULL);

    game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "So Long");

    game->textures.wall = mlx_xpm_file_to_image(game->mlx, "images/wall.xpm", &tex_width, &tex_height);
    game->textures.floor = mlx_xpm_file_to_image(game->mlx, "images/ground.xpm", &tex_width, &tex_height);
    game->textures.player = mlx_xpm_file_to_image(game->mlx, "images/wizard.xpm", &tex_width, &tex_height);
    game->textures.collectible = mlx_xpm_file_to_image(game->mlx, "images/book.xpm", &tex_width, &tex_height);
    game->textures.exit = mlx_xpm_file_to_image(game->mlx, "images/doorclosed.xpm", &tex_width, &tex_height);

    if (!game->textures.wall || !game->textures.floor || !game->textures.player || !game->textures.collectible || !game->textures.exit)
        ft_error("Failed to load textures", NULL);
}
