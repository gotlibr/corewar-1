#include "environment.h"
#include "loop_manager.h"

void	vm_loop(t_environment *environment)
{
	int running;

	running = 1;
	while (running)
	{
		print_current_state(environment);
		make_turn(environment);
		check_live_executions(environment);
		if (wasnt_decreased_since_last(environment))
			decrease_cycles_to_die(environment);
		if (processes_are_dead(environment))
			running = 0;
	}
}