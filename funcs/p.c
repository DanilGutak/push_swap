/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:02:15 by dgutak            #+#    #+#             */
/*   Updated: 2023/10/02 18:55:58 by dgutak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_data *data)
{
	int	i;

	i = data->stack_a_count;
	if (data->stack_a_count == 1)
		data->stack_a[1] = data->stack_a[0];
	else
	{
		while (i > 0)
		{
			data->stack_a[i] = data->stack_a[i - 1];
			i--;
		}
	}
	data->stack_a[0] = data->stack_b[0];
	data->stack_a_count++;
	i = 0;
	while (i < data->stack_b_count - 1)
	{
		data->stack_b[i] = data->stack_b[i + 1];
		i++;
	}
	data->stack_b_count--;
	action(data, "pa");
}

void	pb(t_data *data)
{
	int	i;

	i = data->stack_b_count;
	if (data->stack_b_count == 1)
		data->stack_b[1] = data->stack_b[0];
	else
	{
		while (i > 0)
		{
			data->stack_b[i] = data->stack_b[i - 1];
			i--;
		}
	}
	data->stack_b[0] = data->stack_a[0];
	data->stack_b_count++;
	i = 0;
	while (i < data->stack_a_count - 1)
	{
		data->stack_a[i] = data->stack_a[i + 1];
		i++;
	}
	data->stack_a_count--;
	action(data, "pb");
}

void	action(t_data *data, char *cmd)
{
	if (ft_strncmp(cmd, "end", 4) == 0)
	{
		if (data->cmd[0] == 0)
			ft_printf("%s\n", cmd);
	}
	else if (data->cmd[0] == 0)
		ft_strlcpy(data->cmd, cmd, 4);
	else if ((ft_strncmp(cmd, "rra", 4) == 0 && ft_strncmp(data->cmd, "rrb",
				4) == 0) || (ft_strncmp(cmd, "rrb", 4) == 0
			&& ft_strncmp(data->cmd, "rra", 4) == 0))
	{
		ft_printf("rrr\n");
		data->cmd[0] = 0;
	}
	else if ((ft_strncmp(cmd, "ra", 4) == 0 && ft_strncmp(data->cmd, "rb",
				4) == 0) || (ft_strncmp(cmd, "rb", 4) == 0
			&& ft_strncmp(data->cmd, "ra", 4) == 0))
	{
		ft_printf("rr\n");
		data->cmd[0] = 0;
	}
	else
		(ft_printf("%s\n", data->cmd), ft_strlcpy(data->cmd, cmd, 4));
}
