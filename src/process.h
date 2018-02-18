#pragma once

#include "op.h"

typedef struct			s_command_cache
{
	int					cycles_left;
	unsigned char		op_code;
	unsigned char		args[10];
}						t_command_cache;

typedef struct			s_process
{
	char				player_id;
	unsigned char		memory[REG_NUMBER];
	unsigned char		*program_counter;
	int					carry;
	unsigned int		live_executions;
	t_command_cache		command_cache;
}						t_process;
