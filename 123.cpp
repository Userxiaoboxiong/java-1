/*************************************************************
    date: June 2017
    copyright: Zhu En��ף����
    DO NOT distribute this code.
**************************************************************/
// ���Ӵ洢��ջʵ���ļ�
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
typedef int T; // ջԪ�ص���������
struct LNode {
    T data;
    LNode* next;
};
struct LinkStack {
        LNode* top; // ջ��ָ��
        int len; // ջ�ĳ���
};

/*����ջ*/
LinkStack* LS_Create()
{
    LinkStack* ls=(LinkStack*)malloc(sizeof(LinkStack));
    ls->top = NULL;
    ls->len = 0;
    return ls;
}

/*�ͷ�ջ*/
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

/*��ջ��Ϊ��ջ*/
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

/*�ж�ջ�Ƿ�Ϊ��*/
bool LS_IsEmpty(LinkStack* ls)
{
    // �������ﲹ����룬��ɱ�������
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

/*��ȡջ�ĳ���*/
int LS_Length(LinkStack* ls)
{
    // �������ﲹ����룬��ɱ�������
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

/*��x��ջ*/
void LS_Push(LinkStack* ls, T x)
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    LNode* curr=new LNode;
    curr->data=x;
    curr->next=ls->top;
    ls->top=curr;
    ls->len++;
    /********** End **********/
}

/*��ջ����ջԪ�ط���item�������ջ��������false*/
bool LS_Pop(LinkStack* ls, T& item)
{
    // �������ﲹ����룬��ɱ�������
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

/*��ջ��Ԫ�ط���item�������ջ��������false*/
bool LS_Top(LinkStack* ls, T& item)
{
    // �������ﲹ����룬��ɱ�������
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

/*��ջ����ջ�״�ӡ���������*/
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
