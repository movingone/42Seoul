/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongwole <dongwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:44:39 by dongwole          #+#    #+#             */
/*   Updated: 2023/11/10 16:42:51 by dongwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{	
	write(2, "Error\n", 6);
	exit(1);
}

void	add_last(t_stack *stack, int elem)
{
	t_node	*ptr;

	if (!stack->top)
		stack->top = getnode(NULL, elem);
	else
	{
		ptr = stack->top;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = getnode(NULL, elem);
		if (!ptr->next)
			error();
	}
	if (elem > stack->max[0])
		stack->max[0] = elem;
	if (elem < stack->min)
		stack->min = elem;
	stack->cnt++;
}

char	*get_values_sub(t_stack *a, const char *str, int sign)
{
	long long	num;
	t_node		*ptr;

	if (*str < '0' || *str > '9')
		error();
	num = 0;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str++ - '0');
		if (sign * num < -2147483648 || sign * num > 2147483647)
			error();
	}
	ptr = a->top;
	while (ptr)
	{
		if (ptr->elem == sign * num)
			error();
		ptr = ptr->next;
	}
	add_last(a, sign * num);
	return ((char *)str);
}

char	*get_values(t_stack *a, const char *str)
{
	int	sign;

	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
	{
		str++;
		sign = -sign;
	}
	if (!*str)
		return ((char *)str);
	return (get_values_sub(a, str, sign));
}
