/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongwole <dongwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:47:08 by dongwole          #+#    #+#             */
/*   Updated: 2023/11/10 18:04:35 by dongwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	t_op_cnt	op_cnt;

	if (is_sorted(a))
		return ;
	if (a->cnt <= 3)
	{
		simple_sort(a, b);
		return ;
	}
	while (a->cnt > 3)
	{
		choose_best_elem(a, b, &op_cnt);
		pb_best_elem(a, b, &op_cnt);
	}
	set_b_max_on_top(a, b);
	sort_3(a, b);
	while (b->top)
		do_op(a, b, "pa");
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		i;

	init_stack(&a);
	init_stack(&b);
	i = 1;
	while (i < argc)
	{
		if (!*argv[i])
			error();
		while (*argv[i])
			argv[i] = get_values(&a, argv[i]);
		i++;
	}
	push_swap(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}

int	ft_max(int n, int m)
{
	if (n > m)
		return (n);
	else
		return (m);
}

int	ft_min(int n, int m)
{
	if (n < m)
		return (n);
	else
		return (m);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
