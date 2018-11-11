/*************************************************************
    date: June 2017
    copyright: Zhu En（祝恩）
    DO NOT distribute this code.
**************************************************************/
// 链接存储的栈实现文件
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
typedef int T; // 栈元素的数据类型
struct LNode {
    T data;
    LNode* next;
};
struct LinkStack {
        LNode* top; // 栈顶指针
        int len; // 栈的长度
};

/*创建栈*/
LinkStack* LS_Create()
{
    LinkStack* ls=(LinkStack*)malloc(sizeof(LinkStack));
    ls->top = NULL;
    ls->len = 0;
    return ls;
}

/*释放栈*/
void LS_Free(LinkStack* ls)
{
    LNode* curr = ls->top;
    while(curr) {
        LNode* next = curr->next;
        free(curr);
        curr=next;
    }
    free(ls);
}

/*将栈变为空栈*/
void LS_MakeEmpty(LinkStack* ls)
{
    LNode* curr = ls->top;
    while(curr) {
        LNode* next = curr->next;
        free(curr);
        curr=next;
    }
    ls->top = NULL;
    ls->len = 0;
}

/*判断栈是否为空*/
bool LS_IsEmpty(LinkStack* ls)
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
	if(ls->len==0)
    {
        return true;
    }
    else
    {
        return false;
    }
    /********** End **********/
}

/*获取栈的长度*/
int LS_Length(LinkStack* ls)
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    return ls->len;
    /*LNode* curr = ls->top;
    int i=0;
    while(curr) {
        LNode* next = curr->next;
        curr=next;
        i++;
    }
    return i; */
    /********** End **********/
}

/*将x进栈*/
void LS_Push(LinkStack* ls, T x)
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    LNode* curr=new LNode;
    curr->data=x;
    curr->next=ls->top;
    ls->top=curr;
    ls->len++;
    /********** End **********/
}

/*出栈。出栈元素放入item；如果空栈，将返回false*/
bool LS_Pop(LinkStack* ls, T& item)
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
	if(LS_IsEmpty(ls))
    {
        return false;
    }
    LNode* curr=ls->top;
    item=curr->data;
    ls->top=curr->next;
    ls->len--;
	return true;
    /********** End **********/
}

/*读栈顶元素放入item。如果空栈，将返回false*/
bool LS_Top(LinkStack* ls, T& item)
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
	if(LS_IsEmpty(ls))
    {
        return false;
    }
    LNode* curr=ls->top;
    item=curr->data;
	return true;

    /********** End **********/
}

/*从栈顶到栈底打印各结点数据*/
void LS_Print(LinkStack* ls)
{
    if (ls->len==0){
        printf("The stack: Empty!");
        return;
    }
    printf("The stack (from top to bottom):");
    LNode* curr=ls->top;
    int i=ls->len;
    while(i>0) {
        printf("*** %d", curr->data);
        curr=curr->next;
        i--;
    }
   // printf("\n");
}

int main()
{
    LinkStack* ls=LS_Create();
    char dowhat[100];
    while(true) {
        scanf("%s", dowhat);
        if (!strcmp(dowhat,"push")) {
            T x;
            scanf("%d", &x);
            LS_Push(ls,x);
        }else if (!strcmp(dowhat,"pop")) {
            T item;
            LS_Pop(ls, item);
        }
        else {
            break;
        }
    }
    int length=LS_Length(ls);
    printf("Stack length: %d\n", length);
    LS_Print(ls);
    LS_Free(ls);
    system("PAUSE");
}
