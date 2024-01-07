//
//  stack.c
//  1
//
//  Created by 刘阳阳 on 2024/1/7.
//

#include "stack.h"
#include <assert.h>

// define the Data Structure
typedef struct {
    int item[MAXITEMS];
    int top;
} stackRep;

// define the Data Object
static stackRep stackObject;

// set up empty stack
void StackInit(void) {
    stackObject.top = -1;
}

// check whether the stack is empty
int StackIsEmpty(void) {
    return (stackObject.top < 0);
}

// insert int on top of stack
void StackPush(int v) {
    assert(stackObject.top < MAXITEMS - 1);
    stackObject.top++;
    int i = stackObject.top;
    stackObject.item[i] = v;
}

// remove int from top of stack
int StackPop(void) {
    assert(stackObject.top > -1);
    int i = stackObject.top;
    int v = stackObject.item[i];
    stackObject.top--;
    return v;
}
