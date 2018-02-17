#include "environment.h"
#include "process.h"
#include "../libft/classes_lib/new.h"
#include "../libft/classes_lib/queue.h"
#include "../libft/classes_lib/linked_list.h"

void	make_turn(t_environment *environment)
{
	void *current_queue;
	void *temp_queue;
	t_process *current_process;

	current_queue = environment->current_queue;
	temp_queue = new(g_queue);
	void *list = new(g_list, queue);

	while(!queue_is_empty(current_queue))
	{
		current_process = dequeue(current_queue);
		make_move(current_process, environment);
		enqueue(temp_queue, current_process);
	}
	delete(current_queue);
	environment->current_queue = temp_queue;*/
}
