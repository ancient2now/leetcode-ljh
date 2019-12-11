/*实现循环队列*/
#include <stdio.h>
#include <stdbool.h>

#define size 5
int items[size];
int front = size-1;
int rear = size-1;
bool full_flag = false;
void push_back(int * q, int item){
    if((rear%size == front) && (full_flag == true)){
        printf("queue is full item=%d\n", item);
        return;
    }
    rear = (rear+1) % size;
    items[rear] = item;
    full_flag = true;
}
bool is_empty(int * q){
    return (front == rear) && (full_flag == false);
}
int pop_front(int * q){
    if(is_empty(q)){
        printf("queue is empty\n");
        return -1;
    }
    front = (front+1) % size;
    full_flag = false;
    return q[front];
}
void queue_print(int * q){
    for(int i = 0; i < size; i++){
        printf("%d ", q[i]);
    }
    puts("");
}

int main(int argc, char const *argv[])
{
    push_back(items, 1);
    queue_print(items);
    push_back(items, 2);
    queue_print(items);
    push_back(items, 3);
    queue_print(items);
    push_back(items, 4);
    queue_print(items);
    push_back(items, 5);
    queue_print(items);
    int ret = pop_front(items);
    queue_print(items);
    printf("front=%d rear=%d ret=%d\n", front, rear, ret);
    push_back(items, 6);
    queue_print(items);


    return 0;
}
