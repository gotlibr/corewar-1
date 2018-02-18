#pragma once

#include "environment.h"
#include "process.h"

void	vm_loop(t_environment *environment);
int		processes_are_dead(t_environment *env);
void 	update_live_executions(t_environment *env);
int		wasnt_decreased_since_last(t_environment *env);
int 	is_bigger_delta_cycle(t_environment *env);
void	make_turn(t_environment *environment);
void	process_operation(t_process *current_proc, t_environment *env, void *queue);
