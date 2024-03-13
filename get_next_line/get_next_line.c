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

char *ft_free(char *a) 
{
    free(a);
    a = NULL;
    return (NULL);
}

char *ft_readfunc(int fd, char *buf, char *save) 
{
    ssize_t ret; // n butes leidos
    char *temp; 

    ret = 1;

    while (ret != 0)
    {
        ret = read(fd, buf, BUFFER_SIZE); // lee el archivo y guarda en ret
        /*
        {
            //ft_free(buf); 
            break;
        }
        */
        if (ret == 0)
            break ;
        
        buf[ret] = '\0'; // null al final de la linea leida
        if (save == NULL)
            save = ft_strdup(""); 
        temp = save;
        save = ft_strjoin(temp, buf); // concatena  buf para guardar en save
        ft_free(temp);
        if (ft_strchr(buf, '\n') || ret < BUFFER_SIZE) // si hay un salto de linea para 
            break ;
    }
    if(save == NULL)
        return (NULL);
    return (save);
}

char *ft_linebreak(char *str) 
{
    char *save;
    size_t i;

    i = 0;
    while (str[i] != '\n' && str[i] != '\0') // cuenta los caracteres de la linea leida
        i++;
    if (str[i] == '\0' || str[i + 1] == '\0') // si hay un salto de linea
        return (NULL);
    save = ft_substr(str, i + 1, ft_strlen(str) - i ); // guarda la linea leida en save
    if (*save == '\0'){
        return ft_free(save);
    }
        
    str[i + 1] = '\0';
    return (save);
}

char *get_next_line(int fd) // lee el archivo linea , guarda la linea leida y la devuelve 
{
    char *str; // linea leida
    char *buf; // buffer
    static char *save; // guarda la linea leida

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    if(read(fd, 0, 0) == -1)
    {
        free(save);
        save = NULL;
        return (NULL);
    }
    
    buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)); // asigna memoria para el buffer + 1
    if (!buf)
        return (NULL);
    str = ft_readfunc(fd, buf, save);
    ft_free(buf);
    if (!str) 
        return (NULL);
    save = ft_linebreak(str);
    return (str);
}