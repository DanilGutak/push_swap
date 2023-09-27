/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 12:03:27 by dgutak            #+#    #+#             */
/*   Updated: 2023/09/27 20:43:07 by dgutak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checkfile(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != NULL)
	{
		j = 0;
		while (str[i][j] == ' ' || str[i][j] == '\v' || str[i][j] == '\t'
			|| str[i][j] == '\n' || str[i][j] == '\f' || str[i][j] == '\r')
			j++;
		if (str[i][j] == '-' || str[i][j] == '+')
			j++;
		if (!str[i][j])
			return (1);
		while (str[i][j])
		{
			if (!(str[i][j] >= '0' && str[i][j] <= '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
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

void	check_input(t_data *data)
{
	check_duplicate(data);
	is_sorted(data);
}

void	parse_input(t_data *data, int argc, char **argv)
{
	int		i;
	char	**str;

	i = 0;
	data->input = 0;
	data->stack_a = 0;
	data->stack_b = 0;
	data->indexes = 0;
	while (++i < argc)
	{
		data->input = ft_strjoin(data->input, argv[i]);
		data->input = ft_strjoin(data->input, " ");
	}
	if (!data->input)
		error(data, 1);
	str = ft_split(data->input, ' ');
	if (!str)
		error(data, 1);
	if (checkfile(str))
		error(data, 1);
	data->stack_a = new_strmapi(str, atoi_new, data);
	free_double_p(str);
	if (!data->stack_a)
		error(data, 1);
	check_input(data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc > 1)
		parse_input(&data, argc, argv);
	/* printf("%d %d %d %d\n",data.stack_a[0],data.stack_a[1],data.stack_a[2],data.stack_a[3]); */
	rra(&data);
	/* printf("%d %d %d %d\n",data.stack_a[0],data.stack_a[1],data.stack_a[2],data.stack_a[3]); */
	ra(&data);
	/* printf("%d %d %d %d\n",data.stack_a[0],data.stack_a[1],data.stack_a[2],data.stack_a[3]); */

}
