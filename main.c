/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 12:03:27 by dgutak            #+#    #+#             */
/*   Updated: 2023/09/26 20:55:08 by dgutak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(t_data *data,int status)
{
	if (data->stack_a)
		free(data->stack_a);
	if (data->stack_b)
		free(data->stack_b);
	if (status == 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	else if (status == 0)
		exit(0);
}
int checkfile(char **str)
{
	int i;

	i = 0;
	while (str[i] != NULL)
	{
		while (*str[i] == ' ' || *str[i] == '\v' || *str[i] == '\t' || *str[i] == '\n'
		|| *str[i] == '\f' || *str[i] == '\r')
			str[i]++;
		if (*str[i] == '-' || *str[i] == '+')
			str[i]++;
		while (*str[i])
		{
			if (!(*str[i] >= '0' && *str[i] <= '9'))
				return (1);
			str[i]++;
		}
		i++;
	}
	return (0);
}
void parse_input(t_data *data, int argc, char **argv)
{
	int 	i;
	char	**str;

	i = 1;
	data->input = 0;
	data->stack_a = 0;
	data->stack_b = 0;
	while (i < argc)
	{
		data->input = ft_strjoin(data->input, argv[i]);
		data->input = ft_strjoin(data->input, " ");
		i++;
	}
	if (!data->input)
		error(data, 1);
	str = ft_split(data->input, ' ');
	if (!str)
		error(data, 1);
	if (checkfile(str))
		error(data, 1);
	data->stack_a = new_strmapi(str, atoi_new);
	free(str);
	if(!data->stack_a)
		error(data, 1);
	i = -1;
	while (++i < 6)
		ft_printf("%d\n", data->stack_a[i]);
	
}
int	main(int argc, char **argv)
{
	t_data data;
	
	if (argc > 1)
		parse_input(&data, argc, argv);

}
