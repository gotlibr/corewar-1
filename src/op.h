
#ifndef COREWAR_OP_H
#define COREWAR_OP_H

#define IND_SIZE				2
#define REG_SIZE				4
#define DIR_SIZE				REG_SIZE
# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3


#define MAX_ARGS_NUMBER			4
#define MAX_PLAYERS				4
#define MEM_SIZE				(4*1024)
#define IDX_MOD					(MEM_SIZE / 8)
#define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

#define COMMENT_CHAR			'#'
#define LABEL_CHAR				':'
#define DIRECT_CHAR				'%'
#define SEPARATOR_CHAR			','

#define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"

#define NAME_CMD_STRING			".name"
#define COMMENT_CMD_STRING		".comment"

#define REG_NUMBER				16

#define CYCLE_TO_DIE			1536
#define CYCLE_DELTA				50
#define NBR_LIVE				21
#define MAX_CHECKS				10

/*
**
*/

typedef char	t_arg_type;

#define T_REG					1
#define T_DIR					2
#define T_IND					4
#define T_LAB					8

/*
**
*/

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

typedef struct		header_s
{
	unsigned int		magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
}						header_t;

typedef struct			s_op
{
	char				*name;
	char				args_num;
	char				arg[3];
	char				opcode;
	int					cycles;
	int					codage;
	int					carry;
	int					lable_size;
}						t_op;

t_op    op_tab[17] =
{
		{"live", 1, {T_DIR}, 1, 10, 0, 0, 4},
		{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, 1, 0, 4},
		{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, 1, 0, -1},
		{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, 1, 0, -1},
		{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, 1, 0, -1},
		{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6, 1, 0, 4},
		{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6, 1, 0, 4},
		{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6, 1, 0, 4},
		{"zjmp", 1, {T_DIR}, 9, 20, 0, 1, 2},
		{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25, 1, 1, 2},
		{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25, 1, 1, 2},
		{"fork", 1, {T_DIR}, 12, 800, 0, 1, 2},
		{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, 1, 0, 4},
		{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50, 1, 1, 2},
		{"lfork", 1, {T_DIR}, 15, 1000, 0, 1, 2},
		{"aff", 1, {T_REG}, 16, 2, 1, 0, -1},
		{0, 0, {0}, 0, 0, 0, 0, 0, -1}
};

#endif //COREWAR_OP_H
