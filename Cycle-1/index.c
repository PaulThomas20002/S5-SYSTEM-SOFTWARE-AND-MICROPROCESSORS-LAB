#include<stdio.h>
#include<stdlib.h>
#define SIZE 50
struct node{
    int data;
    int nextBlock;
};

struct node memBlock[50];

int flag,prevBlock=-1;

void indexed(){

    int size, i, st, flag=0, j=0, allocated=0;
    printf("\nEnter the length of file : ");
    scanf("%d",&size);
    for ( j=0; j<SIZE; j++ ){
        if (memBlock[j].data == 0){
            if(flag == 0 ){
            st = j;
            flag = 1;
            }
            
            allocated++;
            memBlock[j].data = 1;
            memBlock[prevBlock].nextBlock = j;
            prevBlock = j;
        }
        if (allocated == size){
            break;
        }
    }
    
    int var = st;
    printf("\n%d ---- Allocated", st);
    
    for (i=0; i<size-1; i++){
    
        var = memBlock[var].nextBlock;
        printf("\n%d ----- Allocated", var);
    }
}

int main(){

    int i,d;
    
    do{
    
    printf("\n1.Index\n2. Exit\n");
    scanf("%d", &d);    
    switch(d){    
        case 1 : indexed(); break;
        
        default : printf("Try again");
    }       
 }while (d != 2);

return 0;
}
