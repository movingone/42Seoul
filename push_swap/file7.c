/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file7.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongwole <dongwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:47:21 by dongwole          #+#    #+#             */
/*   Updated: 2023/11/10 18:04:36 by dongwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *a, t_stack *b)
{
	int	first;
	int	second;
	int	third;

	first = a->top->elem;
	second = a->top->next->elem;
	third = a->top->next->next->elem;
	if (first > second && second > third && first > third)
	{
		do_op(a, b, "sa");
		do_op(a, b, "rra");
	}
	else if (first < second && second > third && first < third)
	{
		do_op(a, b, "rra");
		do_op(a, b, "sa");
	}
	else if (first > second && second < third && first < third)
		do_op(a, b, "sa");
	else if (first < second && second > third && first > third)
		do_op(a, b, "rra");
	else if (first > second && second < third && first > third)
		do_op(a, b, "ra");
}

void	sort_2(t_stack *a, t_stack *b)
{
	if (a->top->elem > a->top->next->elem)
		do_op(a, b, "sa");
}

void	simple_sort(t_stack *a, t_stack *b)
{
	if (a->cnt == 3)
		sort_3(a, b);
	else if (a->cnt == 2)
		sort_2(a, b);
	else
		return ;
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
