/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharik <acharik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 06:49:49 by acharik           #+#    #+#             */
/*   Updated: 2024/08/06 09:54:19 by acharik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
    int	count;
    int	i;

    count = 0;
    i = 0;
    while (s[i])
    {
        while (s[i] && s[i] == c)
            i++;
        if (s[i])
            count++;
        while (s[i] && s[i] != c)
            i++;
    }
    return (count);
}

static char	**free_split_array(char **array)
{
    int	i;

    i = 0;
    while (array[i])
        free(array[i++]);
    free(array);
    return (NULL);
}

char    **ft_split(char const *s, char c)
{
    char    **result;
    size_t  i;
    size_t  j;
    size_t  word_len;

    if (!s)
        return (NULL);
    result = malloc(sizeof(char *) * (count_words(s, c) + 1));
    if (!result)
        return (NULL);
    i = 0;
    j = 0;
    while (s[i])
    {
        while (s[i] && s[i] == c)
            i++;
        if (!s[i])
            break;
        word_len = 0;
        while (s[i + word_len] && s[i + word_len] != c)
            word_len++;
        result[j] = ft_substr(s, i, word_len);
        if (!result[j])
            return (free_split_array(result));
        i += word_len;
        j++;
    }
    result[j] = NULL;
    return (result);
}