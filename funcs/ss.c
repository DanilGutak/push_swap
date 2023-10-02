/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:54:35 by dgutak            #+#    #+#             */
/*   Updated: 2023/10/02 18:42:06 by dgutak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data)
{
	int	temp;

	temp = data->stack_a[1];
	data->stack_a[1] = data->stack_a[0];
	data->stack_a[0] = temp;
	action(data, "sa");
}

void	sb(t_data *data)
{
	int	temp;

	temp = data->stack_b[1];
	data->stack_b[1] = data->stack_b[0];
	data->stack_b[0] = temp;
	action(data, "sb");
}

void	ss(t_data *data)
{
	sa(data);
	sb(data);
}
