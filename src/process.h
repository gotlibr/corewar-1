#pragma once

#include "op.h"


typedef struct			s_process
{
	char				player_id;
	unsigned char		*memory;
	unsigned char		*program_counter;
	int					carry;
	unsigned int		live_executions;
	struct s_process	*next;
}						t_process;
