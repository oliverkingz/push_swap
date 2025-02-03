/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:54:59 by ozamora-          #+#    #+#             */
/*   Updated: 2025/02/03 02:51:15 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(char **args)
{
	t_stack	*stack;
	int		*args_int;
	int		i;

	args_int = ft_strarray_to_intarray(args);
	if (!args_int)
		return (ft_err("Failed to convert args to int array"), NULL);
	stack = init_stack();
	if (!stack)
		return (free(args_int), ft_err("Failed to init stack"), NULL);
	i = ft_strarray_len(args) - 1;
	while (i >= 0)
	{
		push(stack, args_int[i]);
		i--;
	}
	free(args_int);
	return (stack);
}

t_stack	*init_stack(void)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->head = NULL;
	new_stack->tail = NULL;
	new_stack->size = 0;
	return (new_stack);
}

t_dnode	*init_dnode(int value)
{
	t_dnode	*new_dnode;

	new_dnode = (t_dnode *)malloc(sizeof(t_dnode));
	if (!new_dnode)
		return (NULL);
	new_dnode->value = value;
	new_dnode->prev = NULL;
	new_dnode->next = NULL;
	return (new_dnode);
}

void	print_stack(t_stack *stack)
{
	t_dnode	*current;

	current = stack->head;
	if (stack->size == 0)
	{
		ft_printf("Stack is empty\n");
		return ;
	}
	while (current != NULL)
	{
		ft_printf("%d\n", current->value);
		current = current->next;
	}
}

void	free_stack(t_stack *stack)
{
	t_dnode	*current;
	t_dnode	*next;

	current = stack->head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}
