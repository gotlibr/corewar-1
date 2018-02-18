#include <tclDecls.h>
#include <ft_printf.h>
#include "environment.h"
#include "process.h"
#include "../libft/classes_lib/new.h"
#include "../libft/classes_lib/queue.h"
#include "../libft/classes_lib/linked_list.h"
#include "../libft/ft_printf/libftprintf/libft.h"
#include "loop_manager.h"

unsigned char get_op_code(unsigned char *pc)
{
	unsigned char op_code;

	if (ft_isdigit(*pc))
		op_code = *pc - 48;
	else if (*pc >= 'A' && *pc <= 'F')
		op_code = *pc - 55;
	else if (*pc >= 'a' && *pc <= 'f')
		op_code = *pc - 87;
	else
		op_code = -1;
	return (op_code);
}

void get_args(unsigned char *map, t_command_cache *pCache, unsigned char *counter)
{
	if (map - counter < MEM_SIZE - 10)
		ft_memcpy(pCache->args, counter, 10);
	else
		ft_printf("Memory is on the edge.Cant copy. Write me finally\n");
}

int cycles_to_perform(unsigned char code)
{
	int res;
	res = (code == 1) ? 10 : 0;
	res = (code == 2) ? 5 : 0;
	res = (code == 3) ? 5 : 0;
	res = (code == 4) ? 10 : 0;
	res = (code == 5) ? 10 : 0;
	res = (code == 6) ? 6 : 0;
	res = (code == 7) ? 6 : 0;
	res = (code == 8) ? 6 : 0;
	res = (code == 9) ? 20 : 0;
	res = (code == 10) ? 25 : 0;
	res = (code == 11) ? 25 : 0;
	res = (code == 12) ? 800 : 0;
	res = (code == 13) ? 10 : 0;
	res = (code == 14) ? 50 : 0;
	res = (code == 15) ? 1000 : 0;
	res = (code == 16) ? 2 : 0;
	return (res);
}

void make_move(t_process *curr_process, t_environment *env, void *new_queue)
{
	t_command_cache *cache;

	cache = &curr_process->command_cache;
	if (cache->cycles_left > 0)
	{
		cache->cycles_left--;
		return ;
	}
	else if (cache->cycles_left == 0)
	{
		process_operation(curr_process, env, new_queue);
		return ;
	}
	cache->op_code = get_op_code(curr_process->program_counter);
	if (cache->op_code == 0)
	{
		curr_process->program_counter++;
		return ;
	}
	else
		get_args(env->map, cache, curr_process->program_counter);
	// TODO if check if args are valid for the current op_code

	cache->cycles_left = cycles_to_perform(cache->op_code);
}

void	make_turn(t_environment *environment)
{
	void *current_queue;
	void *temp_queue;
	t_process *current_process;

	current_queue = environment->processes_queue;
	temp_queue = new(g_queue);

	while(!queue_is_empty(current_queue))
	{
		current_process = dequeue(current_queue);
		make_move(current_process, environment, temp_queue);
		enqueue(temp_queue, current_process);
	}
	delete(current_queue);
	environment->processes_queue = temp_queue;
}
