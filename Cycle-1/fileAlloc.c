#include<stdio.h>
#include<stdlib.h>
#define SIZE 50
struct node
{
int data;
int nextBlock;
struct node *link;
}*first=NULL,*last,*temp,*new;
struct node memBlock[50];
int flag,prevBlock=-1;
int check(int start, int size);
void sequential();
void linked();
void indexed();
void main()
{
int choice;
printf("\n1.Sequential Allocation\n2.Linked Allocation\n3.IndexedAllocation\n4.Exit\n");
printf("Enter a choice : ");
scanf("%d", &choice);
switch (choice)
{
case 1:{
sequential();
main();
break;
}
case 2:{
linked();
main();
break;
}
case 3:{
indexed();
main();
break;
}
case 4:{
break;
}
default:{
printf("\nInvalid choice");
main();
}
}
}
int check(int start, int size)
{
int i;
for (i = start; i < start+size; i++)
{
if (memBlock[i].data == 1)
{
return 1;
break;
}
}
return 0;
}
void sequential()
{
int i,start,size;
printf("\nEnter the start block : ");
scanf("%d",&start);
printf("\nEnter the length of the file : ");
scanf("%d",&size);
flag = 0;
flag = check(start, size);
if (flag==0)
{
for (i = start; i < start+size; i++)
{
memBlock[i].data = 1;
printf("%d ---> %d\n",i,memBlock[i].data);
}
printf("\nFile is allocated...\n");
}
else
{
printf("\nFile cannot be allocated");
}
}
void linked()
{
int i,start,size;
printf("\nEnter the start block : ");
scanf("%d",&start);
printf("\nEnter the length of the file : ");
scanf("%d",&size);
flag=0;
flag = check(start, size);
if (flag == 0)
{
for(i=start;i<start+size;i++)
{
memBlock[i].data = 1;
new = (struct node *)malloc(sizeof(struct node));
new -> data = 1;
new -> link = NULL;
if(first == NULL)
{
first = new;
last = new;
}
else
{
last -> link = new;
last = new;
}
}
}
if(first == NULL)
{
printf("\nFile cannot be allocated\n");
}
else
{
    temp = first;
    while(temp != NULL){
    
        for(i=start;i<start+size;i++){

            printf("%d ---> %d\n",i,temp->data);
            temp = temp->link;
            }
    }
    printf("\nFile is allocated...\n");
}

}

void indexed()
{
int size,i,st,flag=0,j=0,allocated=0;
printf("\nEnter the length of file : ");
scanf("%d",&size);
for (j = 0; j < SIZE; j++)
{
if (memBlock[j].data == 0)
{
if (flag==0)
{
st = j;
flag=1;
}
allocated++;
memBlock[j].data = 1;
memBlock[prevBlock].nextBlock = j;
prevBlock = j;
}
if (allocated==size)
{
break;
}
}
int c = st;
printf("\n%d---->%d",st,1);
for (i = 0; i < size-1; i++)
{
c = memBlock[c].nextBlock;
printf("\n%d---->%d",c,1);
}
}
