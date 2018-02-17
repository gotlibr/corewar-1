#include "environment.h"

int 	main(int argc, char **param)
{
	static t_environment env;

	void	make_classes(void);

	if (!init_game(param, &env))
		ft_printf_last_error();
	vm_loop(&env);
	print_winner(&env);
}

t_player *new_player(char *file)
{
	t_player *player;
	int fd;

	fd = open(file, O_RDONLY);
	return (player);
}

int read_to_tmp(char **tmp, char *param)
{

}

int 	init_game(char **param, t_environment *env)
{
	char *tmp;
	if (!read_to_tmp(&tmp, param[1]))
		ft_printf_last_error();
}
