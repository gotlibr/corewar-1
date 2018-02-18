//
// Created by Hlib RIABTSEV on 2/18/18.
//

#include "environment.h"
#include "process.h"
#include "../libft/ft_printf/libftprintf/libft.h"

int get_counter(int pl_count, t_process *process, t_environment *env)
{
	int i;
	int k;

	i = 1;
	k = 0;
	while  (i < pl_count)
	{
		k = ft_strstr(env->map, "0000") - (char *)(env->map);
		while (k <= MEM_SIZE - 3 && env->map[k] == '0' && env->map[k + 1] == '0'
			   && env->map[k + 2] == '0' && env->map[k + 3] == '0')
			k += 4;
		i++;
	}
	process->program_counter = &(env->map[k]);
	return (1);
}

int process_init(t_environment *env, int i, int pl_count)
{
	t_process *process;

	process = (t_process *)ft_memalloc(sizeof(t_process));
	process->memory[0] = (unsigned char)i;
	process->player_id = (char)i;
	process->carry = 0;
	process->live_executions = 0;
	process->program_counter = get_counter(pl_count, process, env);
	/*add to quee env*/
}