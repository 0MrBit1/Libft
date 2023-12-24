/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharik <acharik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 08:25:01 by acharik           #+#    #+#             */
/*   Updated: 2023/12/24 015:50:51 by acharik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*copy_data(int number_len, long number, int div_by, short flag)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)malloc(number_len + 1);
	if (flag)
	{
		ptr[i] = '-';
		i++;
	}
	while (div_by)
	{
		ptr[i] = number / div_by + '0';
		number = number % div_by;
		div_by = div_by / 10;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_itoa(int n)
{
	int		div_by;
	long	number;
	short	flag;
	short	number_len;

	number = n;
	div_by = 1;
	number_len = 1;
	flag = 0;
	if (number < 0)
	{
		number *= -1;
		flag = 1;
		number_len++;
	}
	while (number / div_by > 9)
	{
		div_by *= 10;
		number_len++;
	}
	return (copy_data(number_len, number, div_by, flag));
}
