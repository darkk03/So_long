/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizenbe <aaizenbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:43:17 by aaizenbe          #+#    #+#             */
/*   Updated: 2024/03/10 16:43:17 by aaizenbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_end_game(t_game *game)
{
    mlx_destroy_image(game->mlx, game->textures.wall);
    mlx_destroy_image(game->mlx, game->textures.floor);
    mlx_destroy_image(game->mlx, game->textures.player);

    mlx_destroy_window(game->mlx, game->win);

    mlx_destroy_display(game->mlx);
    free(game->mlx);

    exit(0);
}
