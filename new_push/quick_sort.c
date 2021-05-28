#include "push_swap1.h"

int		is_chunk_sorted(t_data data, int start, int end)
{
	int	i;

	i = start;
	while (i < end - 1)
	{
		// printf("root : %d | root->next : %d\n", root->data, root->next->data);
		if (data.stack[i] < data.stack[i + 1]) 
			return (0);
		i++;
	}
	return (1);
}

void    push_chunk(t_chunk **head, int start, int end)
{
    t_chunk *new_chunk;

	new_chunk = (t_chunk *)malloc(sizeof(t_chunk));
    new_chunk->index[0] = start;
    new_chunk->index[1] = end;
    new_chunk->status = UNSORTED;

	new_chunk->next = *head;
	*head = new_chunk;

}

void    initialise_chunks(t_data data, t_chunk *a, t_chunk *b)
{
    b = NULL;
	a = NULL;
    push_chunk(&a, 0, data.size);
}

void quick_sort(t_data *data)
{
    t_chunk *A_chunks;
    t_chunk *B_chunks;

    initialise_chunks(*data, A_chunks, B_chunks);
	// chunk a is invalid after initialising itttt
	while (A_chunks)
	{
		printf("index[0] = %d\nindex[1] = %d\nstatus = %d\n\n", A_chunks->index[0], A_chunks->index[1], A_chunks->status);
	}
	
    // while (1)
    // {
    //     if (is_chunk_sorted(*data, A_chunks->index[0], A_chunks->index[1]) && !B_chunks)
    //         break ;
    //     else if (is_chunk_sorted(*data, A_chunks->index[0], A_chunks->index[1]))
    //     {
    //         // B to A
    //     }
    //     else
    //     {
    //         // A to B

    //     }
    // }


}