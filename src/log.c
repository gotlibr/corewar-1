//
// Created by Maksym KONIEV on 2/18/18.
//

#include <ft_printf.h>
#include "environment.h"
#include "../libft/classes_lib/linked_list.h"
#include "../libft/classes_lib/queue.h"
#include "process.h"

/*
<events>
[<player_id> <index_on_map> <what_changed>]
…
<players>
[<player_id> <current_lives> <last_live_cycle>]
…
<processes>
[<player_id> <proc_ind>]
 */

unsigned long		return_ind(unsigned char *adr, t_environment *environment)
{
	return (environment->map - adr);
}

void	log_state(t_environment *environment)
{
	int fd;
	t_llist *temp = (t_llist *)(environment->players);
	t_llist *processes;

	processes = (t_llist *)(((t_queue *)(environment->processes_queue))->front);
	fd = open("log.txt", O_RDONLY);
	ft_printf("<players>");
	while (temp)
	{
		ft_printf_fd("[%d %d %d]\n", fd, ((t_player *)(temp->content))->id,
					 ((t_player *)(temp->content))->current_lives,
					 ((t_player *)(temp->content))->last_live_cycle);
		temp = temp->next;
	}
	ft_printf("<processes>");
	while (processes)
	{
		ft_printf_fd("[%d %d]", fd, ((t_process *)(processes->content))->player_id,
					 return_ind(((t_process *)(processes->content))->program_counter, environment));
		processes = processes->next;
	}
	close(fd);
}

void	log_event(t_process *process, unsigned char *destination_adr, t_environment *environment)
{
	int fd;
	int param_num;
	int i;

	i = 0;
	fd = open("log.txt", O_RDONLY);
	if ((int)(destination_adr) <= 16 && (int)(destination_adr) > 0)
		param_num = op_tab[(int)(destination_adr)].args_num;
	else
		param_num = 0;
	ft_printf("[%d %d ", process->player_id, return_ind(destination_adr, environment));
	while (i <= param_num)
	{
		ft_printf("%x", destination_adr + i);
		i++;
	}
	ft_printf("]\n");
	close(fd);
}