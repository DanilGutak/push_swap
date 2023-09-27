/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:59:42 by dgutak            #+#    #+#             */
/*   Updated: 2023/06/19 18:18:13 by dgutak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	atoi_new(char *str)
{
	long int	x;
	long int	sign;

	x = 0;
	sign = 1;
	while (*str == ' ' || *str == '\v' || *str == '\t' || *str == '\n'
		|| *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			x = x * 10 + *str - '0';
		else
			break ;
		str++;
	}
	return (sign * x);
}

int	*new_strmapi(char **s, long int (*f)(char *))
{
	unsigned int	count;
	int			*ret;
	int				i;

	i = 0;
	count = 0;
	while (s[count])
		count++;
	ret = malloc(sizeof(char) * (count + 1));
	if (!ret)
		return (0);
	while (s[i])
	{
		ret[i] = f( s[i]);
		i++;
	}
	ret[i] = 0;
	return (ret);
}

/*
#include <stdio.h>

int	main(void)
{
	char str1[] = "   12345";
	char str2[] = "   -6789";
	char str3[] = "   +42";
	char str4[] = "   ------++123";
	char str5[] = "   +--123";
	char str6[] = "15";
	char str7[] = "";
	char str8[] = "1234asd5";

	printf("%d\n", ft_atoi(str1)); // should output 12345
	printf("%d\n", ft_atoi(str2)); // should output -6789
	printf("%d\n", ft_atoi(str3)); // should output 42
	printf("%d\n", ft_atoi(str4)); // should output 0
	printf("%d\n", ft_atoi(str5)); // should output -123
	printf("%d\n", ft_atoi(str6)); // should output 0
	printf("%d\n", ft_atoi(str7)); // should output 0
	printf("%d\n", ft_atoi(str8)); // should output 0

	return (0);
} */