#include<stdio.h>
#include<stdlib.h>
struct node
{
        int data;
        struct node *link;
};
struct node *getnode()
{
       
        return((struct node *)malloc(sizeof(struct node)));
        
}

int main()
{
        struct node *first,*temp,*temp1,*temp2;
        int val,i,size;
        printf("Enter size\n");
        scanf("%d",&size);
        printf("Enter element\n");
        scanf("%d",&val);
        temp=getnode();
        temp->data=val;
	temp->link=NULL;
        first=temp;
        for(i=1;i<size;i++)
        {
                temp1=getnode();
                printf("Enter element\n");
                scanf("%d",&val);
                temp1->data=val;
                temp->link=temp1;
		temp1->link=NULL;
                temp=temp1;
        }
       // temp1->link=NULL;
        int ch,pos;
        while(1)
        {
                printf("\n MENU\n");
                printf("1.Insert at front\n");
                printf("2.Insert at any position\n");
                printf("3.deleting based on specified value\n");
                printf("4.searching a node based on specified value\n");
                printf("5.Display all nodes\n");
                printf("\n Enter Choice\n");
                scanf("%d",&ch);
        

 switch(ch)
        {
                case 1:
                        
                        
                                temp1=getnode();
                                printf("Enter Element\n");
                                scanf("%d",&val);
                                temp1->data=val;
                                temp1->link=first;
                                first=temp1;
                                size=size+1;
                                break;
                        

                case 2:
                        printf("Enter the position you want to insert(not greater than %d)",size);
                        temp2=first;
			scanf("%d",&pos);
                        if(pos==0)
			{
				temp1=getnode();
				printf("enter the element\n");
				scanf("%d",&val);
				temp1->data=val;
                                temp1->link=first;
				first=temp1;
                                size=size+1;
      }                          
               else
			{
                        for(i=0;i<=(pos-2);i++)
                        {
                                temp2=temp2->link;
                        }
                        temp1=getnode();
                        printf("Enter element\n");
                        scanf("%d",&val);
                        temp1->data=val;
                        temp1->link=temp2->link;
                        temp2->link=temp1;
                        size=size+1;
                        }
break;

                case 5:
                        temp=first;
                        while(temp!=NULL)
                        {
                                printf("\n%d",temp->data);
                                temp=temp->link;
                        }
                        break;

		 case 3:
                        temp1=first;
                        temp=first;
                        printf("Enter value\n");
                        scanf("%d",&val);
                        if(temp->data==val)
                        {
                                first=temp->link;
                                free(temp);
				break;
                        }
                        for(i=1;i<size;i++)
                        {       temp=temp->link;
                                if(temp->data==val)
                                {
                                        temp1->link=temp->link;
					free(temp);
					temp=temp1;
                                }
                                else
                                {
                                        temp1=temp1->link;
                                }
                        }
                        size=size-1;
                        break;

                case 4:
                        temp=first;
                        printf("Enter value\n");
                        scanf("%d",&val);
                        for(i=0;i<size;i++)
                        {
                                if(temp->data==val)
                                {
                                        printf("node found at pos %d",i);
                                }
                                temp=temp->link;
                        }
                        break;
                default:exit(0);
        }
}
}




