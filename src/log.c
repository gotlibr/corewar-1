//
// Created by Maksym KONIEV on 2/18/18.
//

#include <stddef.h>
#include "environment.h"
#include "../libft/classes_lib/linked_list.h"

void log_state(t_environment *environment)
{
	int fd;
	t_llist *temp = (t_llist *)(environment->players);
	t_player *tmp_pl;
	t_llist *processes;

	tmp_pl = NULL;
	processes = (t_llist *)(((t_queue *)(environment->processes_queue))->front);
	fd = open("log.txt", O_RDONLY);
	while (temp)
	{
		tmp_pl = (t_player *)(temp->content);
		ft_printf_fd("[<player> %d %d %d]\n", fd, tmp_pl->id, tmp_pl->current_lives, tmp_pl->last_live_cycle);
		temp = temp->next;
	}
}
