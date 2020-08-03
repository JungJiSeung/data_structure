#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STACK_SIZE 10

typedef struct _Stack {
    char* dataList[STACK_SIZE];
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
char* peek(Stack* stack) {
    if(stack == NULL)
        return NULL;

    if(stack->top < 0)
        return NULL;

    return stack->dataList[stack->top];
}

/*
 * Description : pop data from stack
 * input : stack
 * output : if underflow then return -1 else return top data
 */
char* pop(Stack* stack) {
    char* res;
    
    if(stack == NULL)
        return NULL;

    if(stack->top < 0)
        return NULL;

    res = stack->dataList[stack->top];
    stack->top--;

    return res;
}

/*
 * Description : push data to stack
 * input : stack, int data to Add
 * output : if overflow then return -1 else return 0
 */
char* push(Stack* stack, char* data) {
    if(stack == NULL)
        return NULL;

    if(stack->top + 1 >= STACK_SIZE)
        return NULL;

    stack->top++;
    stack->dataList[stack->top] = data;

    return data;
}

/*
 * Description : test Stack
 */
void test(Stack* stack) {
    char *testString[STACK_SIZE+2] = {"AA", "AB", "AC", "AD", "AE", "AF", "AG", "AH", "AI", "AJ", "AK", "AL"};

    if(stack == NULL)
        return;

    // overflow test
    printf("overflow test\n");
    for(int i = 0; i < STACK_SIZE+1; i++) {
        if(push(stack, testString[i])==NULL){
            printf("overflow\n");
        } else {
            printf("%s\n", peek(stack));
        }
    }

    // underflow test
    printf("underflow test\n");
    for(int i = 0; i < STACK_SIZE+1; i++) {
        printf("%s\n", pop(stack));
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
