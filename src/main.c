#include <fcntl.h>
#include <zconf.h>
#include "environment.h"
#include "../libft/ft_printf/libftprintf/libft.h"
#include "../libft/get_next_line/get_next_line.h"
#include "../libft/ft_printf/ft_printf/ft_printf.h"


const char *hex_convert_pair_to_alph(char *tmp)
{
	int 	temp;
	int		i;
	char	*ret;
	int 	base;

	base = 1;
	i = 1;
	ret =ft_memalloc(sizeof(char) * 2);
	temp = 0;
	while (i >= 0)
	{
		if (tmp[i] >= '0' && tmp[i] <= '9')
			temp += (tmp[i] - '0') * base;
		else
			temp += (tmp[i] - 'a' + 10) * base;
		i--;
		base *= 16;
	}
	ret[0] = temp;
	return (ret);
}

char *decode_hex_to_str(char *old, char *new)
{
	char *tmp;
	int		i;

	i = 0;
	while(i < 5)
	{
		tmp = ft_strsub(new, 0, 2);
		old = ft_strcat(old, hex_convert_pair_to_alph(tmp));
		i += 2;
		free(tmp);
	}
	return old;
}

int get_name_and_desc(int fd, t_player *player)
{
	char str[6];

	read(fd, str, 5);
	while (1)
	{
		read(fd, str, 5);
		player->name = decode_hex_to_str(player->name,str);
		if (ft_strstr(str,"0000"))
			break;
	}
	while (ft_strstr(str,"0000"))
		read(fd, str, 5);

	while (1)
	{
		read(fd, str, 5);
		player->description = decode_hex_to_str(player->name,str);
		if (ft_strstr(str,"0000"))
			break;
	}
	return (1);
}

int		get_player(char *param, t_environment *env)
{
	int fd;
	t_player *player;

	fd = open(param, O_RDONLY);
	player = (t_player *)ft_memalloc(sizeof(t_player));
	get_name_and_desc(fd, player);
	put_player_id(fd);
	close(fd);
	return (1);
}

void put_player_id() {

}

int 	init_game(char **param, t_environment *env)
{
	if (!get_player(param[1], env))
		ft_printf_last_error();
}
int 	main(int argc, char **param)
{
	static t_environment env;

	void	make_classes(void);

	if (!init_game(param, &env))
		ft_printf_last_error();
	vm_loop(&env);
	print_winner(&env);
	return (1);
}