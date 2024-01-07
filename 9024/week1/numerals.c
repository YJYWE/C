//
//  numerals.c
//  1
//
//  Created by 刘阳阳 on 2024/1/7.
//

#include "stack.h"
#include <stdio.h>

void numerals(int a, int b) {
    StackInit();
    while (a > 0) {
        StackPush(a % b);
        a = a / b;
    }
    while (!StackIsEmpty()) {
        printf("%d", StackPop());
    }
    putchar('\n');
}

int main(void) {
    numerals(13, 2);
    return 0;
}
