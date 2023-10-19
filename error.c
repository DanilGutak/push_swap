/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:12:47 by dgutak            #+#    #+#             */
/*   Updated: 2023/10/19 11:56:35 by dgutak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(t_data *data, int status)
{
	if (data->stack_a)
		free(data->stack_a);
	if (data->gnl_buffer)
		free(data->gnl_buffer);
	if (data->stack_b)
		free(data->stack_b);
	if (data->input)
		free(data->input);
	if (data->indexes != 0)
		free(data->indexes);
	if (status == 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	else if (status == 0)
		exit(0);
}

void	free_double_p(char **p)
{
	int	i;

	i = -1;
	if (p)
	{
		while (p[++i])
			free(p[i]);
		free(p);
	}
}
