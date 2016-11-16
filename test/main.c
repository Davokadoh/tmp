/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 15:59:21 by pbondoer          #+#    #+#             */
/*   Updated: 2016/11/01 02:20:02 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "threadpool.h"
#include <stdio.h>
#include <unistd.h>

void thread(void *i)
{
	int ri;

	ri = *(int *)i;
	if (ri % 2)
		usleep(100000 * (i % 8));
	else
		usleep(1000000);
	ft_memdel(&i);
	printf("- %d done\n", ri);
}

int main(int argc, char **argv)
{
	(void)argv;
	(void)argc;

	int i;
	t_threadpool *tp;

	tp = threadpool_init(8);
	printf("Threadpool address: %p\n", tp);
	i = 0;
	while (i < 100)
	{
		int *x = (int *)ft_memalloc(sizeof(int));
		*x = i;
		threadpool_add(tp, thread, x);
		i++;
	}
	while (tp->queue_count > 0)
	{
		printf(" --- Queue left: %d\n", tp->queue_count);
		usleep(1000000);
	}
	usleep(1000000);
	return (1);
}
