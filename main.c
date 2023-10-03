/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 12:03:27 by dgutak            #+#    #+#             */
/*   Updated: 2023/10/03 13:30:26 by dgutak           ###   ########.fr       */
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
		(free_double_p(str), error(data, 1));
	data->stack_a = new_strmapi(str, atoi_new, data, -1);
	free_double_p(str);
	if (!data->stack_a)
		error(data, 1);
	check_input(data);
}

int	check_argv(char **argv)
{
	int	i;
	int	flag;

	while (*argv)
	{
		i = 0;
		flag = 0;
		if ((*argv)[0] == 0)
			return (1);
		while ((*argv)[i])
		{
			if ((*argv)[i] != ' ')
				flag = 1;
			i++;
		}
		if (flag == 0)
			return (1);
		argv++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc > 1)
	{
		data.input = 0;
		data.stack_a = 0;
		data.stack_b = 0;
		data.indexes = 0;
		data.cmd[0] = 0;
		data.stack_b_count = 0;
		if (check_argv(argv) == 1)
			error(&data, 1);
		parse_input(&data, argc, argv);
		if (data.stack_a_count < 6)
			sort_small(&data);
		sort_for_index(&data);
		push_b(&data, 0, data.chunk_size, -1);
		push_a(&data, data.stack_b_count);
		action(&data, "end");
		error(&data, 0);
	}
	return (0);
}
