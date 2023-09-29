/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:59:42 by dgutak            #+#    #+#             */
/*   Updated: 2023/09/29 17:01:38 by dgutak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	atoi_new(char *str, t_data *data)
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
		if ((x > 2147483647 && sign == 1) || (x > 2147483648 && sign == -1))
			error(data, 1);
		str++;
	}
	return (sign * x);
}

int	*new_strmapi(char **s, long int (*f)(char *, t_data *), t_data *data)
{
	unsigned int	count;
	int				*ret;
	int				i;

	i = 0;
	count = 0;
	while (s[count])
		count++;
	data->stack_a_count = count;
	data->stack_b_count = 0;
	if (data->stack_a_count < 1)
		error(data, 0);
	ret = malloc(sizeof(int) * (count));
	data->indexes = malloc(sizeof(int) * (count));
	data->stack_b = malloc(sizeof(int) * (count));
	if (!ret || !data->indexes || !data->stack_b)
		return (0);
	while (s[i])
	{
		ret[i] = f(s[i], data);
		i++;
	}
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