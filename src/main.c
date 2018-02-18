#include <fcntl.h>
#include <zconf.h>
#include "environment.h"
#include "../libft/ft_printf/libftprintf/libft.h"
#include "../libft/classes_lib/classes_lib.h"
#include "loop_manager.h"
#include "../libft/ft_printf/ft_printf/ft_printf.h"

void 	ft_printf_last_error(char *err)
{
	ft_printf("%s\n", err);
	exit(0);
}

int 	init_game(char **param, t_environment *env, int pl_count)
{
	int fd;

	fd = open(param[1], O_RDONLY);
	env->cyclesToDie = 0;
	env->counterAlive = 0;
	env->last_check = 0;
	if (!get_player(fd, env, 0))
		ft_printf_last_error("Player pzdc");
	if (!process_init(env, 0, pl_count))
		ft_printf_last_error("Process pzdc");

}
int 	main(int argc, char **param)
{
	static t_environment env;


	make_classes();
	int pl_count = 1;
	if (!init_game(param, &env, pl_count))
		ft_printf_last_error("val pzdc");

	//print_winner(&env);
}
