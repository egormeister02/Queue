#include <stdio.h>
#include <stdlib.h>

typedef int Elem_t;

struct queue
{
    size_t  head =    0;
    size_t  tale =    0;
    size_t  size =    0;
    Elem_t* buf  = NULL;
};

const Elem_t QUEUE_POISON = 0xACFEEDCA;

int QueueCtor(queue* que, size_t size);     // return 0  if OK
                                            // return 1  if queue* que == NULL
                                            // return -1 if could not allocate memory

int push(queue* que, Elem_t value);         // return 0  if OK
                                            // return -1 if the queue is full

Elem_t pop(queue* que);                     // return "first element" if OK
                                            // return    QUEUE_POISON if the queue is empty

Elem_t front(queue* que);                   // return "first element" if OK
                                            // return    QUEUE_POISON if the queue is empty

Elem_t back(queue* que);                    // return "first element" if OK
                                            // return    QUEUE_POISON if the queue is empty

int QueueDtor(queue* que);                  // return 0 if OK
                                            // return 1 if queue* que == NULL

int QueuePrint(queue* que);                 // return 0  if OK
                                            // return 1  if queue* que == NULL
                                            // return -1 if que->buf   == NULL