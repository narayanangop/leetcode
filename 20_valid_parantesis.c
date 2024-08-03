#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>

typedef struct my_stack
{
    char *data;
    int capacity;
    int top;
} stack_t;

stack_t* mystack_init(int capacity) {
    stack_t *ret = (stack_t *)malloc(sizeof(stack_t));
    if (!ret) {
        return NULL;
    }

    ret->data = (char *)malloc(sizeof(char) * capacity);
    if (!ret->data) {
        free(ret);
        return NULL;
    }

    ret->capacity = capacity;
    ret->top = capacity;
    return ret;
}

int mystack_push(stack_t *stack, char c) {
    if(stack->top == 0) {
        return -1;
    }
    stack->top--;
    stack->data[stack->top] = c;

    return 0;
}

int mystack_pop(stack_t *stack, char *c) {
    if(stack->top == stack->capacity) {
        return -1;
    }
    *c = stack->data[stack->top];
    stack->top++;
    return 0;
}

void mystack_free(stack_t *stack) {
    free(stack->data);
    free(stack);
}

bool isValid(char* s) {

    stack_t *stack = mystack_init(10000);
    char expected;
    int ret;
    while (s && *s != '\0')
    {
        switch (*s)
        {
        case '{':
        case '[':
        case '(':
            mystack_push(stack, *s);
            break;
        
        case '}':
            ret = mystack_pop(stack, &expected);
            if(ret || expected != '{') {
                mystack_free(stack);
                return false;
            }
            break;
        
        case ']':
            ret = mystack_pop(stack, &expected);
            if(ret || expected != '[') {
                mystack_free(stack);
                return false;
            }
            break;

        case ')':
            ret = mystack_pop(stack, &expected);
            if(ret || expected != '(') {
                mystack_free(stack);
                return false;
            }
            break;
        default:
            break;
        }
        s++;
    }

    if(stack->top != stack->capacity) {
        mystack_free(stack);
        return false;
    }

    mystack_free(stack);
    return(true);
    
}


int main() {
    printf("%d\n", isValid("{()[]{}}"));
    return 0;
}