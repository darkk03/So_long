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

void ft_get_map(char *file)
{
    int fd;
    char *line;
    int ret;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        ft_error("Map error", data);
    while (1)
    {
        ret = get_next_line(fd, &line);
        if (ret < 0)
            ft_error("Map error", data);
        if (ret == 0)
            break;
        printf("%s\n", line);
        free(line);
    }
    close(fd);
}