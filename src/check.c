/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:22:44 by ozamora-          #+#    #+#             */
/*   Updated: 2025/02/07 22:13:35 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args_int(char **args)
{
	int	i;

	if (args == NULL || *args == NULL)
		return (0);
	i = 0;
	while (args[i] != NULL)
	{
		if (!ft_issigned_nbr(args[i]))
			return (0);
		if (my_str_num_len(args[i]) > 10)
			return (0);
		i++;
	}
	return (1);
}

int	check_args_dup(char **args)
{
	int	i;
	int	j;
	int	*args_int;
	int	arg_len;

	if (args == NULL || *args == NULL)
		return (0);
	args_int = my_strarray_to_intarray(args);
	if (args_int == NULL)
		return (0);
	arg_len = my_strarray_len(args);
	i = 0;
	while (i < arg_len)
	{
		j = i + 1;
		while (j < arg_len)
		{
			if (args_int[i] == args_int[j])
				return (free(args_int), 0);
			j++;
		}
		i++;
	}
	return (free(args_int), 1);
}

int	check_stack_sorted(t_stack *a)
{
	t_dnode	*current;
	int		sorted;

	if (a->size >= 2)
	{
		sorted = 1;
		current = a->head;
		while (current->next != NULL)
		{
			if (current->value > current->next->value)
			{
				sorted = sorted * 0;
				break ;
			}
			current = current->next;
		}
		return (sorted);
	}
	if (a->size == 1)
		return (1);
	return (0);
}
