/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threadpool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 11:41:16 by pbondoer          #+#    #+#             */
/*   Updated: 2016/11/06 23:16:58 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "threadpool.h"
#include <pthread.h>

static void		*threadpool_work(void *threadpool)
{
	t_threadpool		*tp;
	t_threadpool_task	task;
	t_list				*elem;

	tp = (t_threadpool *)threadpool;
	while (42)
	{
		pthread_mutex_lock(&(tp->lock));
		while (tp->queue_count == 0 && tp->shutdown == 0)
			pthread_cond_wait(&(tp->cond), &(tp->lock));
		if (tp->shutdown)
			break;
		elem = tp->queue;
		task.function = ((t_threadpool_task *)elem->content)->function;
		task.arg = ((t_threadpool_task *)elem->content)->arg;
		tp->queue = tp->queue->next;
		ft_lstdelone(&elem, ft_lstdelfn);
		tp->queue_count--;
		pthread_mutex_unlock(&(tp->lock));
		(*(task.function))(task.arg);
	}
	pthread_mutex_unlock(&(tp->lock));
	pthread_exit(NULL);
	return (NULL);
}

t_threadpool	*threadpool_init(int count)
{
	t_threadpool	*tp;
	int				i;

	tp = (t_threadpool *)ft_memalloc(sizeof(t_threadpool));
	if (tp == NULL)
		return (NULL);
	tp->threads = (pthread_t *)ft_memalloc(sizeof(pthread_t) * count);
	if (tp->threads == NULL ||
			pthread_mutex_init(&(tp->lock), NULL) ||
			pthread_cond_init(&(tp->cond), NULL))
		return (threadpool_destroy(tp));
	i = 0;
	while (i < count)
	{
		if (pthread_create(tp->threads + i, NULL, threadpool_work, (void *)tp))
			return (threadpool_destroy(tp));
		i++;
		tp->thread_count++;
	}
	return (tp);
}

t_threadpool	*threadpool_destroy(t_threadpool *tp)
{
	unsigned int i;

	if (tp == NULL || tp->shutdown || pthread_mutex_lock(&(tp->lock)))
		return (NULL);
	tp->shutdown = 1;
	if (tp->threads != NULL)
	{
		pthread_cond_broadcast(&(tp->cond));
		pthread_mutex_unlock(&(tp->lock));
		i = 0;
		while (i < tp->thread_count)
			pthread_join(tp->threads[i++], NULL);
		ft_memdel((void **)&(tp->threads));
	}
	if (tp->queue != NULL)
		ft_lstdel(&tp->queue, ft_lstdelfn);
	ft_memdel((void **)&tp);
	return (NULL);
}

void			threadpool_add(t_threadpool *tp, void (*fn)(void *), void *arg)
{
	t_threadpool_task task;

	if (tp == NULL || fn == NULL || tp->shutdown ||
			pthread_mutex_lock(&(tp->lock)))
		return;
	task.function = fn;
	task.arg = arg;
	ft_lstadd(&(tp->queue), ft_lstnew(&task, sizeof(t_threadpool_task)));
	tp->queue_count++;
	pthread_cond_signal(&(tp->cond));
	pthread_mutex_unlock(&(tp->lock));
}
