#include<iostream>
#include<string.h>
using namespace std;
struct Node
{
    int data;
    Node *next;

};
Node *LinkList(int Data[],int n)
{
    Node *first=new Node;
    Node *r=first;
    for(int i=0;i<n;i++)
    {
        Node *s=new Node;
        s->data=Data[i];
        r->next=s;
        r=s;
    }
    r->next=NULL;
    return first;
}

void DeleteList(Node *first)
{
    while(first!=NULL)
    {
        Node *q=first;
        first=first->next;
        delete q;
    }
}
int main(void)
{
    int DataLA[3]={4,5,6};
    int DataLB[4]={3,7,8,10};
    Node *LA=LinkList(DataLA,3);
    Node *firstA=LA;
    LA=LA->next;
    Node *LB=LinkList(DataLB,4);
    Node *firstB=LB;
    LB=LB->next;
    Node *first=new Node;
    Node *r=first;
    //cout<<<<endl;
    while(1)
    {
        if(LA==NULL)
        {
            r->next=LB;
            break;
        }else if(LB==NULL)
        {
            r->next=LA;
            break;
        }else
        {
            Node *s=new Node;
            if(LA->data < LB->data)
            {
                s->data=LA->data;
                LA=LA->next;
            }
            else
            {
                s->data=LB->data;
                LB=LB->next;
            }

            r->next=s;
            r=s;
        }
    }
    Node *p1,*p2,*p3;
    p1=first->next;
    p2=firstA->next;
    p3=firstB->next;
    cout<<"LA=";
    while(p2!=NULL)
    {
        cout<<p2->data<<" ";
        p2=p2->next;
    }
    cout<<endl<<"LB=";
    while(p3!=NULL)
    {
        cout<<p3->data<<" ";
        p3=p3->next;
    }
    cout<<endl<<"LC=";
    while(p1!=NULL)
    {
        cout<<p1->data<<" ";
        p1=p1->next;
    }
    DeleteList(firstA);
    DeleteList(firstB);
    DeleteList(first);
}
