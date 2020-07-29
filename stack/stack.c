#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STACK_SIZE 10

typedef struct _Stack {
    int dataList[STACK_SIZE];
    int top;
} Stack;

Stack *my_stack;

/*
 * Description : initialize stack
 * input : stack to init
 */
void initStack(Stack* stack) {
    if(stack == NULL)
        return;

    memset(stack->dataList, 0, STACK_SIZE);
    stack->top = -1;
}

/*
 * Description : return top data of stack
 * input : stack
 * output : if stack item count is 0 then return -1
 *          else return data
 */
int peek(Stack* stack) {
    if(stack == NULL)
        return -1;

    if(stack->top < 0)
        return -1;

    return stack->dataList[stack->top];
}

/*
 * Description : pop data from stack
 * input : stack
 * output : if underflow then return -1 else return top data
 */
int pop(Stack* stack) {
    int res;
    
    if(stack == NULL)
        return -1;

    if(stack->top < 0)
        return -1;

    res = stack->dataList[stack->top];
    stack->top--;

    return res;
}

/*
 * Description : push data to stack
 * input : stack, int data to Add
 * output : if overflow then return -1 else return 0
 */
int push(Stack* stack, int data) {
    if(stack == NULL)
        return -1;

    if(stack->top + 1 >= STACK_SIZE)
        return -1;

    stack->top++;
    stack->dataList[stack->top] = data;

    return 0;
}

/*
 * Description : test Stack
 */
void test(Stack* stack) {
    if(stack == NULL)
        return;
    
    // overflow test
    printf("overflow test\n");
    for(int i = 0; i < STACK_SIZE+1; i++) {
        if(push(stack, i+100)!=0){
            printf("overflow\n");
        } else {
            printf("%d\n", peek(stack));
        }
    }

    // underflow test
    printf("underflow test\n");
    for(int i = 0; i < STACK_SIZE+1; i++) {
        printf("%d\n", pop(stack));
    }
}

int main(void) {
    // create stack
    my_stack = malloc(sizeof(Stack));
    initStack(my_stack);
    
    test(my_stack);  
//    push(my_stack, 1);
//    push(my_stack, 2);
//    push(my_stack, 3);
//    printf("%d\n", pop(my_stack));
//    printf("%d\n", pop(my_stack));
//    printf("%d\n", pop(my_stack));
//    printf("%d\n", pop(my_stack));

    free(my_stack);
}
