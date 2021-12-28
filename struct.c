//  结构体链表
//
//  Created by 刘阳阳 on 2021/11/26.
//

#include <stdio.h>
#include <stdlib.h>

#define LEN sizeof(struct student)

struct student *creatt();
struct student *del(struct student *head, int num);

struct student *insert(struct student *head, struct student *stu_2);

void print(struct student *head);

struct student
{
    int num;
    float score;
    struct student *next;
};

int n;

void main()
{
    struct student *stu, *p, stu_2;
    int n;
    
    stu=creatt();
    p=stu;
    print(p);
    
    printf("\nPlease enter the num to delete: ");
    scanf("%d", &n);
    print(del(p, n));
    print(stu);
    
    printf("\nPlease enter the num to insert: ");
    scanf("%d", &stu_2.num);
    printf("Please in put the score: ");
    scanf("%f", &stu_2.score);
    
    p=insert(stu, &stu_2);
    print(p);
    
    printf("\n\n");
    system("pause");
}

struct student *creatt()
{
    struct student *head;
    struct student *p1, *p2;
    
    p1=p2=(struct student *)malloc(LEN);
    
    printf("Please enter the num: ");
    scanf("%d", &p1->num);
    printf("Please enter the score: ");
    scanf("%f",&p1->score);
    
    //head=NULL;
    n=0;
    
    while (p1->num)
    {
        n++;
        if(1==n)
        {
            head=p1;
        }
        else
        {
            p2->next=p1;
        }
        
        p2=p1;
        p1=(struct student *)malloc(LEN);
        
        printf("\nPlease enter the num: ");
        scanf("%d",&p1->num);
        printf("please enter the score: ");
        scanf("%f",&p1->score);
    }
    p2->next=NULL;
    
    return head;
}

void print(struct student *head)
{
    struct student *p;
    printf("\nThere are %d records!\n\n",n);
    
    p=head;
    if (head) {
        do
        {
            printf("学号为%d的成绩是：%f\n", p->num, p->score);
            p=p->next;
        }while(p);
    }
}

struct student *del(struct student *head, int num)
{
    struct student *p1, *p2;
    
    if (NULL==head) {
        printf("\nThis list is null!\n");
        goto END;
    }
    
    p1=head;
    while (p1->num!=num && p1->next!=NULL)
    {
        p2=p1;
        p1=p1->next;
    }
    if (num==p1->num) {
        if (p1==head) {
            head=p1->next;
        }
        else
        {
            p2->next=p1->next;
        }
        
        printf("\nDelete No: %d succeed!\n", num);
        n=n-1;
    }
    else
    {
        printf("%d noot been found!\n", num);
    }
END:
    return head;
}

struct student *insert(struct student *head, struct student *stu_2)
{
    struct student *p0, *p1, *p2;
    
    p1=head;
    p0=stu_2;
    if (NULL==head)
    {
        head=p0;
        p0->next=NULL;
    }
    else
    {
        while ((p0->num>p1->num)&&(p1->next!=NULL))
        {
            p2=p1;
            p1=p1->next;
        }
        
        if (p0->num<=p1->num)
        {
            if (head==p1)
            {
                head=p0;
            }
            else
            {
                p2->next=p0;
            }
            p0->next=p1;
        }
        else
        {
            p1->next=p0;
            p0->next=NULL;
        }
    }
    
    n=n+1;
    
    return head;
}

------------------------------------------------------------
  
  //结构体传参

#include <stdio.h>

typedef struct Stu
{
    char name[20];
    short age;
    char tele[12];
    char sex[5];
}Stu;

void Print1(Stu tmp)
{
    printf("name: %s\n",tmp.name);
    printf("age: %d\n",tmp.age);
    printf("tele: %s\n",tmp.tele);
    printf("sex: %s\n",tmp.sex);
}

void Print2(Stu* ps)
{
    printf("name: %s\n",ps->name);
    printf("age: %d\n",ps->age);
    printf("tele: %s\n",ps->tele);
    printf("sex: %s\n",ps->sex);
}

int main()
{
    Stu s={"李四", 40, "15598886688", "男"};
    Print1(s);
    Print2(&s);
    return 0;
}
