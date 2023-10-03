/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:59:42 by dgutak            #+#    #+#             */
/*   Updated: 2023/10/03 12:47:21 by dgutak           ###   ########.fr       */
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
		if ((x > 2147483647 && sign == 1) || (x > 2147483648 && sign == -1))
			return (9876543210);
		str++;
	}
	return (sign * x);
}

int	*new_strmapi(char **s, long int (*f)(char *), t_data *data, int i)
{
	unsigned int	count;
	int				*ret;
	long int		temp;

	count = 0;
	while (s[count])
		count++;
	data->stack_a_count = count;
	if (data->stack_a_count < 1)
		(free_double_p(s), error(data, 0));
	ret = malloc(sizeof(int) * (count + 1));
	if (!ret)
		return (0);
	data->indexes = malloc(sizeof(int) * (count + 1));
	data->stack_b = malloc(sizeof(int) * (count + 1));
	if (!data->indexes || !data->stack_b)
		(free(ret), free_double_p(s), error(data, 1));
	while (s[++i])
	{
		temp = f(s[i]);
		if (temp == 9876543210)
			(free(ret), free_double_p(s), error(data, 1));
		ret[i] = (int)temp;
	}
	return (ret);
}

void	check_duplicate(t_data *data)
{
	int	i;
	int	count;

	i = data->stack_a_count;
	while (--i > 0)
	{
		count = i;
		while (--count >= 0)
		{
			if (data->stack_a[count] == data->stack_a[i])
				error(data, 1);
		}
	}
}

void	is_sorted(t_data *data)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while ((i + 1) < data->stack_a_count)
	{
		if (!(data->stack_a[i] < data->stack_a[i + 1]))
			flag = 1;
		i++;
	}
	if (flag == 0)
		error(data, 0);
}
