/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizenbe <aaizenbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:12:19 by aaizenbe          #+#    #+#             */
/*   Updated: 2024/03/10 16:12:19 by aaizenbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_draw_map(t_game *game, t_data *data)
{
    int x;
    int y;
    int tile_size = 32;

    y = 0;
    while (data->map[y])
    {
        x = 0;
        while (data->map[y][x])
        {
            if (data->map[y][x] == '1') 
            {
                mlx_put_image_to_window(game->mlx, game->win, game->textures.wall, x * tile_size, y * tile_size);
            }
            else if (data->map[y][x] == '0') 
            {
                mlx_put_image_to_window(game->mlx, game->win, game->textures.floor, x * tile_size, y * tile_size);
            }
            else if (data->map[y][x] == 'P') 
            {
                mlx_put_image_to_window(game->mlx, game->win, game->textures.player, x * tile_size, y * tile_size);
            }
            else if (data->map[y][x] == 'E') 
            {
                mlx_put_image_to_window(game->mlx, game->win, game->textures.floor, x * tile_size, y * tile_size);
            }
            else if (data->map[y][x] == 'C') 
            {
                mlx_put_image_to_window(game->mlx, game->win, game->textures.floor, x * tile_size, y * tile_size);
            }

            x++;
        }
        y++;
    }
}
