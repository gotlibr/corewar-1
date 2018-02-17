#include "environment.h"
#include "op.h"
#include "../libft/classes_lib/queue.h"

void 	update_live_executions(t_environment *env)
{
	if (env->cyclesToDie > CYCLE_DELTA)
		env->cyclesToDie -= CYCLE_DELTA
	else
		env->cyclesToDie = 0;
}

int		wasnt_decreased_since_last(t_environment *env)
{
	if (env->last_check > MAX_CHECKS)
		return (1);
	return (0);
}

int 	is_bigger_delta_cycle(t_environment *env)
{
	if (env->counterAlive > CYCLE_DELTA)
	{
		env->last_check = 0;
		return (1);
	}
	return (0);
}

int processes_are_dead(t_environment *env)
{
	if (queue_is_empty(env->processes_queue))
		return (1);
	return (0);
}
