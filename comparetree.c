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

void inorder(struct node *root)
{
    struct node *temp=root;
    if(temp!=NULL)
    {
        inorder(temp->left);
        printf("%d\t",temp->data);
        inorder(temp->right);
    }
}

int compare(struct node *root1,struct node *root2)
{
    struct node *temp1=root1, *temp2=root2;
    if(temp1==NULL&&temp2==NULL)
        return 1;
    else 
       if(temp1!=NULL&&temp2!=NULL)
          if(temp1->data==temp2->data)
             if(compare(temp1->left,temp2->left))
                 return compare(temp1->right,temp2->right);
            return 0;
}


int main()
{
    struct node *root1=NULL,*root2=NULL;
    root1=create(root1);
    printf("\nfirst tree");
    inorder(root1);
    root2=create(root2);
    printf("\nsecond tree");
    inorder(root2);
    if(compare(root1,root2))
       printf("\ntree are same");
    else
       printf("\nnot same tree");
       
}