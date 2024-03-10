/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizenbe <aaizenbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 22:12:34 by aaizenbe          #+#    #+#             */
/*   Updated: 2024/03/09 22:12:34 by aaizenbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    t_game *game;
    t_data *data;

    if (argc != 2)
        return (0);
    data = malloc(sizeof(t_data));
    if (!data)
        ft_error("Malloc failed", data);
    ft_get_map(&argv[1], data);
    game = malloc(sizeof(t_game));
    if (!game)
        ft_error("Malloc failed", data);
    ft_init_game(game, data);
    ft_init_mlx(game->mlx);
    ft_end_game(game);
    return (0);
}


void ft_error(char *str, t_data *data)
{
    free(data);
    ft_printf("%s\n", str);
    exit(1);
}
