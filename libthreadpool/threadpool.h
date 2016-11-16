/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threadpool.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 11:41:48 by pbondoer          #+#    #+#             */
/*   Updated: 2016/10/31 15:10:32 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREADPOOL_H
# include "libft.h"
# include <pthread.h>
# define THREADPOOL_DEFAULT_SIZE 8

typedef struct		s_threadpool_task
{
	void			(*function)(void *);
	void			*arg;
}					t_threadpool_task;
typedef struct		s_threadpool
{
	pthread_mutex_t	lock;
	pthread_cond_t	cond;
	t_list			*queue;
	pthread_t		*threads;
	unsigned int	thread_count;
	unsigned int	queue_count;
	int				shutdown;
}					t_threadpool;
t_threadpool		*threadpool_init(int count);
t_threadpool		*threadpool_destroy(t_threadpool *tp);
void				threadpool_add(t_threadpool *tp, void (*fn)(void *),
					void *arg);
#endif
