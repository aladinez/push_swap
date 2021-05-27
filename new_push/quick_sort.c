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

void    push_chunk(t_chunk *head, int start, int end)
{
    
}

void    initialise_chunks(t_data data, t_chunk *a, t_chunk *b)
{
    b = NULL;
    a = (t_chunk *)malloc(sizeof(t_chunk));
    a->index[0] = 0;
    a->index[1] = data.size;
    a->is_sorted = UNSORTED;
    a->next = NULL;
}

void quick_sort(t_data *data)
{
    t_chunk A_chunks;
    t_chunk B_chunks;
    intialise_chunks(*data, &A_chunks, &B_chunks);
    while (1)
    {
        if (is_chunk_sorted(*data, A_chunks.index[0], A_chunks.index[1]) && !B_chunks)
            break ;
        else if (is_chunk_sorted(*data, A_chunks.index[0], A_chunks.index[1]))
        {
            // B to A
        }
        else
        {
            // A to B

        }
    }


}