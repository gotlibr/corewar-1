#pragma once

#include "environment.h"

int		processes_are_dead(t_environment *env);
void 	update_live_executions(t_environment *env);
int		wasnt_decreased_since_last(t_environment *env);
int 	is_bigger_delta_cycle(t_environment *env);
void	make_turn(t_environment *environment);
