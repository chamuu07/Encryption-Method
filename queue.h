
#ifndef CIPHER_QUEUE_H
#define CIPHER_QUEUE_H

#define queue_size 26

typedef struct{
char items[queue_size];
int front;
int rear;}circularQueue;

//create queue A-Z
void createqueue(circularQueue *q){
    q->front=0;
    q->rear=-1;
    for(char ch='A'; ch<='Z';ch++){
        q->rear=(q->rear+1);
        q->items[q->rear]=ch;}
}

//Get index for according latter
int getindex(circularQueue *q,char ch){
for(int i=0;i<queue_size;i++){
    if(q->items[i]==ch){
         return i;}
    }
}

//Get char for according index
char getinchar(circularQueue *q,int index){
    return q->items[index%queue_size];
    }


#endif // CIPHER_QUEUE_H
