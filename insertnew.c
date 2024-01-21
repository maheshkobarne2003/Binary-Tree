#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *left,*right;
};

struct node *create(struct node *root)
{
    int i,n,num;
    struct node *parent,*newnode,*temp;
    printf("\nenter limit:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("enter value:");
        scanf("%d",&num);
        newnode->data=num;
        newnode->left=NULL;
        newnode->right=NULL;
        if(root==NULL)
        {
            root=newnode;
            continue;
        } 
        temp=root;
        while(temp!=NULL) 
        {
            parent=temp; 
            if(num<temp->data)
               temp=temp->left;
            else
               temp=temp->right;
        }
        if(num<parent->data)
           parent->left=newnode;
        else
           parent->right=newnode;
    }
    return root;
}

struct node *insert(struct node *root)
{
    int i,n,num;
    struct node *parent,*newnode,*temp;
    
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("enter value:");
        scanf("%d",&num);
        newnode->data=num;
        newnode->left=NULL;
        newnode->right=NULL;
        if(root==NULL)
        {
            root=newnode;

        } 
        temp=root;
        while(temp!=NULL) 
        {
            parent=temp; 
            if(num<temp->data)
               temp=temp->left;
            else
               temp=temp->right;
        }
        if(num<parent->data)
           parent->left=newnode;
        else
           parent->right=newnode;
    
    return root;
}


void display(struct node *root)
{
    struct node *temp=root;
    if(temp!=NULL)
    {
        display(temp->left);
        printf("%d\t",temp->data);
        display(temp->right);
    }
}

int main()
{
    struct node *root=NULL;
    int ch;
    do{
        printf("\n1-create \n2-display \n3-insert");
        printf("\n enter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:root=create(root);
                    break;
            case 2: display(root);
                    break;
            case 3: root=insert(root);
                    break;
            default: printf("invalid choice");
                    break;
        }
    }while(ch<4);
}