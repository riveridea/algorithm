#include <stdio.h>
#include "queue.h"

typedef struct queueNodeTag{
    queueElementT element;
    struct queueElementTag *next;
}queueNodeT;

typedef struct queueCDT{
    queueNodeT *front, *rear;
}queueCDT;

queueADT queueCreat(void)
{
    queueADT queue; //queueADT is a poiter of type queueCDT

    //1.allocate memeory for queue structure
    queue = (queueADT)malloc(sizeof(queue(CDT)));
    
    //2.Iniitlaized
    if(queue == NULL)
    {
        fprintf(stderr, "insufficient memory");
        exit(1);
    }
    queue->front = queue->rear = NULL;

    return queue;
}

void queueDestroy(queueADT queue)
{
    if(queue == NULL) return;
    //1.Remove the nodes
    while(!queueIsEmpty(queue))
        queueDelete(queue);
    
    //2.Reset the front and rear
    queue->front = queue->rear = NULL;

    //3.Delete the queue structure
    free(queue);
}

void queueEnter(queueADT queue, queueElementT element)
{
    //1.allocate the node for the new element
    queueNodeT *newNodeP = (queueNodeT*)malloc(sizeof(queueNodeT));

    //2. initialize the new node 
    newNodeP->element = element;
    newNodeP->next = NULL;

    //3. Insert the queue
    if(queue->front == NULL)
    { 
        queue->front = queue->rear = newNodeP;
    }
    else
    {
        queue->rear->next = newNodeP;
        queue->rear = newNodeP;
    }
}

queueElementT queueDelete(queueADT queue)
{
    if(queue == NULL) 
    {
        fprintf(stderr, "NULL pointer to queue");
        exit(1);
    }
    queueElementT element;

    queueNodeT *rmNodeP = queue->front;
    queue->front = rmNodeP->next;

    element = rmNodeP->element;
    rmNodeP->next = NULL;

    if(queue->front == NULL) queue->rear = NULL;

    return element;

}

bool queueIsEmpty(queueADT queue)
{
    if(queue == NULL)
    { 
        fprintf(stderr, "NULL pointer to queue");
        exit(1);
    }
    
    if(queue->front == NULL && queue->rear == NULL)
    {
        return TRUE;
    }
    else if(queue->front != NULL && queue->real != NULL)
    {
        return FALSE;
    }
    else
    {
        fprintf(stderr, "Pointer Error");
        exit(1);
    }
}

