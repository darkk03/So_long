/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizenbe <aaizenbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:46:47 by aaizenbe          #+#    #+#             */
/*   Updated: 2024/01/03 17:46:47 by aaizenbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_free(char *a) 
{
    free(a);
    a = NULL;
    return (NULL);
}

static char ft_readfunc(int fd, char *buf, char *save) 
{
    int ret; // n butes leidos
    char *str; 

    ret = 1;
    while (ret != '\0')
    {
        ret = read(fd, buf, BUFFER_SIZE); // lee el archivo y guarda en ret
        if (ret == -1)
            return (NULL);
        else if (ret == 0)
            break ;
        buf[ret] = '\0'; // null al final de la linea leida
        if (save == NULL) 
            save = ft_strdup(buf);  // duplica la cadena de  buf para guardarla en save
        str = save;
        save = ft_strjoin(save, buf); // concatena  buf para guardar en save
        ft_free(str);
        if (ft_strchr(save, '\n')) // si hay un salto de linea para 
            break ;
    }
    return (save);
}

static char *ft_linebreak(char *str) 
{
    char *save;
    size_t i;

    i = 0;
    while (str[i] != '\n' && str[i] != '\0') // cuenta los caracteres de la linea leida
        i++;
    if (str[i] == '\0') // si hay un salto de linea
        return (NULL);
    save = ft_substr(str, 0, i); // guarda la linea leida en save
    if (save == NULL)
        ft_free(save);
    str[i] = '\0'; 
    return (save);
}

char *get_next_line(int fd) // lee el archivo linea , guarda la linea leida y la devuelve 
{
    char *str; // linea leida
    char *buf; // buffer
    static char *save; // guarda la linea leida

    buf = malloc(sizeof(char) * (BUFFER_SIZE + 1)); // asigna memoria para el buffer BUFFER_SIZE + 1

    if (fd < 0 || BUFFER_SIZE <= 0 || !buf ) 
        return (NULL);
    
    str = readfunc(fd, buf, save); 
    ft_free(buf);
    if (str == NULL)
        return (NULL);
    save = ft_linebreak(str);
    return (str);
}