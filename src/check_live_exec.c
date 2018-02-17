#include "environment.h"
#include "op.h"

void 	check_live_executions(t_environment *env)
{
	if (env->counterAlive > env->cyclesToDie)
	{
		if (CYCLE_DELTA > env->counterAlive)
			env->cyclesToDie = 0;
		else
			env->cyclesToDie -= CYCLE_DELTA;
		env->counterAlive = 0;
	}
}