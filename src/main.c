#include "environment.h"
#include "../libft/classes_lib/linked_list.h"
#include "../libft/classes_lib/new.h"
#include "../libft/classes_lib/classes_lib.h"
#include "loop_manager.h"

int 	main(int argc, char **param)
{
	static t_environment env;

	make_classes();
//	if (!init_game(param, &env))
//		ft_printf_last_error();
	vm_loop(&env);
	//print_winner(&env);
}
