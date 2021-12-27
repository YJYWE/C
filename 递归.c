//递归

#include <stdio.h>

void print(int n)
{
    if (n>9) {
        print(n/10);
    }
    printf("%d ",n%10);
}
int main()
{
    unsigned int num=0;
    scanf("%d",&num);
    print(num);
    return 0;
}

-----------------------------------------------

//递归

#include <stdio.h>

int my_strlen(char* str)
{
    if (*str !='/0') {
        return 1+my_strlen(str+1);
    }
    else
    {
        return 0;
    }
}
int main()
{
    char arr[]="bit";
    int len=my_strlen(arr);
    printf("The length of arr is %d",len);
    return 0;
}


-------------------------------------------------

//斐波那契数列
//1 1 2 3 5 8 13 21 34 55

#include <stdio.h>

//递归

int Fib(int n)
{
    if (n<=2) {
        return 1;
    }
    else
    {
        return Fib(n-1)+Fib(n-2);
    }
}

//    50
//  49   48
//48 47 47 46
//计算速度太慢，效率太低


/*
//循环
int Fib(int n)
{
    int a=1;
    int b=1;
    int c=1;
    
    while (n>2) {
        c=a+b;
        a=b;
        b=c;
        n--;
    }
    return c;
}
 */


int main()
{
    int n=0;
    int ret=0;
    scanf("%d",&n);
    ret=Fib(n);
    printf("ret=%d\n",ret);
    return 0;
}

------------------------------------------------

//颠倒数组中字符顺序

#include <stdio.h>

int my_strlen(char* arr)
{
    int count=0;
    for (int i=0; arr[i]!='\0'; i++) {
        count++;
    }
    return count;
}

void reverse_string(char* arr)
{
    char tmp=0;
    int len=my_strlen(arr);
    tmp=arr[0];
    arr[0]=arr[len-1];
    arr[len-1]='\0';
    if (my_strlen(arr+1)>=2) {
        reverse_string(arr+1);
    }
    arr[len-1]=tmp;
}
int main()
{
    char arr[]="abcdef";
    reverse_string(arr);
    printf("%s\n", arr);

    return 0;
}

-------------------------------------------------
    
//递归 输入一个非负整数，返回组成它的数字之和
//eg: 1729 1+7+2+9=19
#include <stdio.h>

int DigitSum(int n)
{
    if (n>9) {
        return DigitSum(n/10)+n%10;
    }
    else
    {
        return n;
    }
}

int main()
{
    int n=0;
    scanf("%d", &n);
    int sum=DigitSum(n);
    printf("sum=%d\n",sum);
    return 0;
}
