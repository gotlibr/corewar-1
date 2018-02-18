#include "environment.h"
#include "process.h"

void process_operation(t_process *current_proc, t_environment *env, void *queue)
{
	t_command_cache *command;

	command = &current_proc->command_cache;
	if (command->op_code == 1)
		current_proc->live_executions++;
}