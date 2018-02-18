#include "environment.h"
#include "../libft/ft_printf/libftprintf/libft.h"
#include "../libft/classes_lib/linked_list.h"


const char *hex_convert_pair_to_alph(char const *tmp)
{
	int 	temp;
	int		i;
	char	*ret;
	int 	base;

	base = 1;
	i = 1;
	ret = ft_memalloc(sizeof(char) * 2);
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
	ret[0] =(char) temp;
	return (ret);
}

char *decode_hex_to_str(char *old, char *new)
{
	char *tmp;
	int		i;

	i = 0;
	while(i < 4)
	{
		tmp = ft_strsub(new, 0, 2);
		realloc(old, ft_strlen(hex_convert_pair_to_alph(tmp)) + ft_strlen(old));
		old = ft_strcat(old, hex_convert_pair_to_alph(tmp));
		i += 2;
		new += 2;
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
		if (ft_strstr(str,"0000"))
			break;
		player->name = decode_hex_to_str(player->name,str);
	}
	while (ft_strstr(str,"0000"))
		read(fd, str, 5);
	while (1)
	{
		read(fd, str, 5);
		player->description = decode_hex_to_str(player->description,str);
		if (ft_strstr(str,"0000"))
			break;
	}
	return (1);
}

void put_player_ints(t_player *player, int i) {
	player->id = i;
	player->last_live_cycle = 0;
	player->current_lives = 0;
}

void add_to_map(int fd, t_environment *env)
{
	int ret;
	char str[6];
	int i;
	int k;

	i = 0;
	while ((ret = (int)read(fd, str, 5)))
		if (!strstr(str, "0000"))
			break;
	while (ret)
	{
		k = 0;
		while (k < 4 && str[k])
			env->map[i++] =(unsigned char) str[k++];
		ret = (int)read(fd, str, 5);
	}
}


int get_player(int fd, t_environment *env, int i) {
	t_player *player;

	player = (t_player *)ft_memalloc(sizeof(t_player));
	get_name_and_desc(fd, player);
	put_player_ints(player, i);
	llst_add(env->players, player);
	add_to_map(fd, env); /*Think about where to past those values*/
	return (1);
}


