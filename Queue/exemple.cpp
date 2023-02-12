#include "queue.h"

int main()
{
    queue que;
    QueueCtor(&que, 10);

    for (int i = 0; i < 10; i++)
    {
        push(&que, i+1);
        QueuePrint(&que);
    }
    for (int i = 0; i < 11; i++)
        {
            pop(&que);
            QueuePrint(&que);
        }
}