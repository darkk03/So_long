/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizenbe <aaizenbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 23:25:16 by aaizenbe          #+#    #+#             */
/*   Updated: 2024/03/09 23:25:16 by aaizenbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int width_of_map(char *map)
{
    int i;

    i = 0;
    while (map[i])
        i++;
    return (i);
}

int add_line(t_data *data, char *line)
{
    char **newmap;
    int i;

    i = 0;
    while (data->map[i])
        i++;
    newmap = malloc(sizeof(char *) * (i + 2));
    if (!newmap)
        return (0);
    i = 0;
    while (data->map[i])
    {
        newmap[i] = data->map[i];
        i++;
    }
    newmap[i] = line;
    newmap[i + 1] = 0;
    free(data->map);
    data->map = newmap;
    return (1);
}

int ft_get_map(char **argv, t_data *data)
{
	char	*readmap;

	data->fd = open(argv[1], O_RDONLY);
	if (data->fd < 0)
		return (0);
	while (1)
	{
		readmap = get_next_line(data->fd);
		if (!add_line(data, readmap))
			break ;
	}
	close (data->fd);
	data->widthmap = width_of_map(data->map[0]);
	return (1);
}