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
#include "MLX42/include/MLX42/MLX42.h"
#include <fcntl.h>

typedef struct s_data
{
    char **map;

}	t_data;

typedef struct t_game
{
    void   *mlx;
}           t_game;



void ft_error(char *str, t_data *data);

#endif
