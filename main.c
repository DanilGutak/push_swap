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
void parse_input(t_data *data, int argc, char **argv)
{
	int 	i;

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
	ft_printf("%s", data->input);
}
int	main(int argc, char **argv)
{
	t_data data;
	
	if (argc > 1)
		parse_input(&data, argc, argv);
}
