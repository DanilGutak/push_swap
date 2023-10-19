/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 09:56:52 by codespace         #+#    #+#             */
/*   Updated: 2023/10/19 12:06:59 by dgutak           ###   ########.fr       */
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
	if (data->flag == 0)
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
int	ft_strcmp(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (-1);
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
int decide_func(t_data *data, char *temp)
{
    if (ft_strcmp(temp, "pa\n") == 0)
        pa(data);
    else if (ft_strcmp(temp, "pb\n") == 0)
        pb(data);
    else if (ft_strcmp(temp, "sa\n") == 0)
        sa(data);
    else if (ft_strcmp(temp, "sb\n") == 0)
        sb(data);
    else if (ft_strcmp(temp, "ss\n") == 0)
        ss(data);
    else if (ft_strcmp(temp, "ra\n") == 0)
        ra(data);
    else if (ft_strcmp(temp, "rb\n") == 0)
        rb(data);
    else if (ft_strcmp(temp, "rr\n") == 0)
        rr(data);
    else if (ft_strcmp(temp, "rra\n") == 0)
       rra(data);
    else if (ft_strcmp(temp, "rrb\n") == 0)
        rrb(data);
    else if (ft_strcmp(temp, "rrr\n") == 0)
        rrr(data);
    else
        return 1;
    return 0;
}
void gnl_cycle(t_data *data)
{
   char *temp1;
    while (1)
	{
		temp1 = get_next_line(0, data);
        if (!temp1)
            break ;
        if (decide_func(data,temp1) == 1)
        {
            free(temp1);
            error(data, 1);
        }
        free(temp1);
	}
    free(temp1);
}
int	check_sorted(t_data *data)
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
	if (flag == 0 && data->stack_b_count == 0)
		return 1;
    return 0;
}
int main(int argc, char **argv)
{
    t_data	data;
	
    if (argc > 1)
	{
		data.input = 0;
		data.stack_a = 0;
		data.stack_b = 0;
		data.indexes = 0;
        data.gnl_buffer = 0;
        data.flag = 1;
		data.cmd[0] = 0;
		data.stack_b_count = 0;
		if (check_argv(argv) == 1)
			error(&data, 1);
		parse_input(&data, argc, argv);
		gnl_cycle(&data);
		if (check_sorted(&data) == 1)
            ft_printf("OK\n");
        else
            ft_printf("KO\n");
		error(&data, 0);
	}
	return (0);
 }