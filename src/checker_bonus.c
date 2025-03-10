/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:07:37 by ozamora-          #+#    #+#             */
/*   Updated: 2025/02/10 17:14:48 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	read_and_exe_operations(t_stack *a, t_stack *b)
{
	char	*operation;

	while (1)
	{
		operation = get_next_line(0);
		if (operation == NULL || operation[0] == '\n')
			break ;
		exe_op(a, b, operation);
		free(operation);
	}
	free(operation);
}

int	main(int argc, char **argv)
{
	char	**args;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc <= 2)
		return (0);
	args = my_arg_to_strarray(argc, argv);
	if (!args || !check_args_int(args) || !check_args_dup(args))
		return (free_strarray(args), my_err("Invalid arg: dup or not int"), 1);
	stack_a = create_stack(args);
	stack_b = init_stack();
	read_and_exe_operations(stack_a, stack_b);
	if (check_stack_sorted(stack_a) == 1 && stack_b->size == 0)
		return (free_stacks(stack_a, stack_b), ft_printf("OK\n"), 0);
	else
		return (free_stacks(stack_a, stack_b), ft_putstr_fd("KO\n", 2), 1);
	return (free_stacks(stack_a, stack_b), 0);
}
