#include "queue.h"

int QueueCtor(queue* que, size_t size)
{
    if (que == NULL) return 1;

    que->head = 1;
    que->tale = 1;
    que->size = size + 1;
    que->buf = (Elem_t*)calloc(que->size, que->size * sizeof(Elem_t));

    return -(que->buf == NULL);
}

int push(queue* que, Elem_t value)
{
    if (que->tale == (que->head - 1)) return -1;

    que->buf[que->tale] = value;
    que->tale = (que->tale + 1) % que->size;

    return 0;
}

Elem_t pop(queue* que)
{
    if (que->tale == que->head) return QUEUE_POISON;

    Elem_t value = que->buf[que->head];
    que->head = (que->head + 1) % que->size;

    return value;
}

Elem_t front(queue* que)
{
    if (que->tale == que->head) return QUEUE_POISON;

    return que->buf[que->head];
}

Elem_t back(queue* que)
{
    if (que->tale == que->head) return QUEUE_POISON;

    return que->buf[(que->tale == 0) * que->size + que->tale - 1];
}

int QueueDtor(queue* que)
{
    if (que == NULL) return 1;

    que->head = QUEUE_POISON;
    que->tale = QUEUE_POISON;
    que->size = QUEUE_POISON;

    free(que->buf);
    que->buf = NULL;

    return 0;
}

int QueuePrint(queue* que)
{
    if (que == NULL) 
    {
        puts("\n!!!__&que == NULL__!!!");
        return 1;
    }
    puts("\n---------queue--------\n");

    puts("---------");
    printf("head = %lu\n", que->head);
    printf("tale = %lu\n", que->tale);
    printf("size = %lu\n", que->size);
    puts("---------\n");

    if (que->buf == NULL)
    {
        puts("\n!!!__que->buf == NULL__!!!");
        return -1;
    }

    for (int i = 0; i < que->size; i++)
    {
        printf("[%d] = %d", i, que->buf[i]);
        
        if( i == que->head)
            puts("\t<---head");

        else if (i == que->head - 1)
            puts("\t<---allways empty");

        else if (i == que->tale)
            puts("\t<---tale");

        else putchar('\n');

    }
    puts("\n----------end---------\n");

    return 0;
}