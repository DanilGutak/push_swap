/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 12:03:27 by dgutak            #+#    #+#             */
/*   Updated: 2023/10/02 18:42:30 by dgutak           ###   ########.fr       */
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
		(free_double_p(str), error(data, 1));
	data->stack_a = new_strmapi(str, atoi_new, data);
	free_double_p(str);
	if (!data->stack_a)
		error(data, 1);
	check_input(data);
}
void	run_n(t_data *data, int n, void (*f)(t_data *))
{
	while (n--)
		f(data);
}

void	check_chunk(t_data *data, int start, int end, int j)
{
	int	middle;
	int	i;

	middle = (end - start) / 2;
	while (++j < data->stack_a_count)
	{
		i = start - 1;
		while (++i < end)
		{
			if (data->stack_a[j] == data->indexes[i])
			{
				if (data->stack_a_count - j > j)
					run_n(data, j, ra);
				else
					run_n(data, data->stack_a_count - j, rra);
				pb(data);
				if (i > middle + start)
					rb(data);
				j = -1;
				break ;
			}
		}
	}
}
void	push_b(t_data *data, int start, int end, int i)
{
	int	j;

	while (++i < data->chunk_size)
	{
		check_chunk(data, start, end, -1);
		j = start - 1;
		while (++j < end - 1 - (end - start) / 2)
			rrb(data);
		start += data->chunk_size;
		end += data->chunk_size;
		if (i + 2 == data->chunk_size)
			end += data->chunk_last_size;
	}
}
int check_for_insert(t_data *data)
{
	int	k;

	k = data->stack_b_count + data->stack_a_count;
	while (--k)
	{
		if (data->stack_b[0] == data->indexes[k])
			return (1);
		if (data->stack_a[data->stack_a_count - 1] == data->indexes[k])
			return (0);
	}
	return (0);
}


void	run_b_a(t_data *data, int n, int flag, int *j)
{
	while (n--)
	{
		if (data->end == 0 || check_for_insert(data))
		{
			pa(data);
			ra(data);
			data->end++;
			*j = -1;
			return ;
		}
		else
		{
			if (flag == 2)
				rrb(data);
			else
				rb(data);
		}
	}
	pa(data);
	*j = -1;
}

void	check_b_stack(t_data *data, int i)
{
	int	j;

	j = -1;
	while (++j < data->stack_b_count)
	{
		if (data->stack_b[j] == data->indexes[i])
		{
			if (data->stack_b_count - j >= j)
				run_b_a(data, j, 1, &j);
			else
				run_b_a(data, data->stack_b_count - j, 2, &j);
		}
	}
}
void	push_a(t_data *data, int i)
{
	data->end = 0;
	while (--i > -1)
	{
		if (data->stack_b[0] == data->indexes[i])
		{
			pa(data);
		}
		else
		{
			check_b_stack(data, i);
			if (data->stack_a[data->stack_a_count - 1] == data->indexes[i])
			{
				rra(data);
			}
		}
	}
}
int	main(int argc, char **argv)
{
	t_data	data;

	if (argc > 1)
		parse_input(&data, argc, argv);
	data.cmd[0] = 0;
	sort_for_index(&data);
	push_b(&data, 0, data.chunk_size, -1);
	push_a(&data, data.stack_b_count);
	error(&data, 0);
}
