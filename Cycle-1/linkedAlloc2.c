#include <stdio.h>
#include <stdlib.h>
struct node{
int data;
struct node *link;
}*new, *temp, *last, *first;

struct node memBlock[50];

int flag;
int check(int start, int size){
    int i;
    for (i = start; i < start+size; i++){
        if (memBlock[i].data == 1){
            return 1;
            break;
        }
    }
    return 0;
}
void linked(){

int i, start, size;
    printf("\nStart block : ");
    scanf("%d",&start);
    printf("\nLength of the file : ");
    scanf("%d",&size);
    
    flag = 0;
    flag = check(start, size);
    
    if (flag == 0){
        for (int i=start; i<start+size; i++ ){
            memBlock[i].data = 1;
            new = (struct node *)malloc(sizeof(struct node));
            new->data = 1;
            new->link = NULL;
            
            if (first == NULL){
            first = new;
            last = new;
            }
            else{
            last->link = new;
            last = new;
            }
        }
    }
    
    if (first == NULL){
    printf("File NOT allocated.");
   
    }
    else{
        temp = first;
        while(temp!=NULL){
            for(i=start; i<start+size; i++)
            {
                printf("%d ------ Allocated.\n", i);
                temp = temp->link;
            }
        printf("\nFile allocated.");
        }
    }

}

int main(){

    int i,d;
    
    do{
    
    printf("\n1.linked \n2. Exit\n");
    scanf("%d", &d);    
    switch(d){    
        case 1 : linked(); main(); break;
        
        default : printf("Try again");
    }       
 }while (d != 2);

return 0;
}
