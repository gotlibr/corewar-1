#pragma once

#include "op.h"

typedef struct		s_process
{
	const int		player_id;
	unsigned char	memory[REG_NUMBER];
	unsigned char	*program_counter;
	int 			carry;
	unsigned int	live_executions;
}					t_process;

§