#include <stdio.h>
#include <stdlib.h>

int flag =-1;

struct node{
    int data;
};
    

struct node memBlock[50];
    
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
void sequential()
{
int i,start,size;
    printf("\nStart block : ");
    scanf("%d",&start);
    printf("\nLength of the file : ");
    scanf("%d",&size);
    
    flag = 0;
    flag = check(start, size);
    
    if (flag==0){
    for(i = start; i < start+size; i++){
    
        memBlock[i].data = 1;
        printf("%d ------- Allocated\n",i);
    }
    //printf("\nFile is allocated...\n");
    }
    
    else{
    printf("\nFile cannot be allocated");
    }
}

int main(){
    int i,d;
    
    do{
    
    printf("\n1.Sequential \n2. Exit\n");
    scanf("%d", &d);    
    switch(d){    
        case 1 : sequential(); break;
        
        default : printf("Try again");
    }       
 }while (d != 2);
         
   return 0;
}
