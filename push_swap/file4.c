/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongwole <dongwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:45:12 by dongwole          #+#    #+#             */
/*   Updated: 2023/11/10 18:08:55 by dongwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *a, t_stack *b)
{
	if (!b->cnt)
		return ;
	add_node(a, remove_node(b));
}

void	swap(t_stack *a)
{
	int		tmp;

	if (a->cnt <= 1)
		return ;
	tmp = a->top->elem;
	a->top->elem = a->top->next->elem;
	a->top->next->elem = tmp;
}

void	rotate(t_stack *a)
{
	t_node	*ptr;
	t_node	*tmp;

	if (a->cnt <= 1)
		return ;
	ptr = a->top;
	tmp = a->top->next;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = a->top;
	ptr->next->next = NULL;
	a->top = tmp;
}

void	reverse_rotate(t_stack *a)
{
	t_node	*ptr;
	t_node	*tmp;

	if (a->cnt <= 1)
		return ;
	ptr = a->top;
	while (ptr->next)
	{
		if (ptr->next->next == NULL)
			tmp = ptr;
		ptr = ptr->next;
	}
	tmp->next = NULL;
	ptr->next = a->top;
	a->top = ptr;
}
