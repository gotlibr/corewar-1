#pragma once

typedef struct s_environment	t_environment;
typedef struct s_player			t_player;

struct s_environment
{
	void						*processes_queue;
	void						*players;
	int 						cyclesToDie;
	unsigned char				*map;
	int							counterAlive;
};

struct  s_player
{
	char						*name;
	char						*description;
	int							id;
	unsigned long int			last_live_cycle;
};
