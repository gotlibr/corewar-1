#include "environment.h"

int 	main(int argc, char **param)
{
	static t_environment env;

	void	make_classes(void);

	if (init_game(param, &env))
		ft_printf_last_error();
	vm_loop(&env);
	print_winner(&env);
}