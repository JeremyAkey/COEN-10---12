#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//Jeremy Akey's Code, Lab 5, Lab 35375.

int main(void){
int count = 0;
srand((int)time(NULL));
for(int i=0;i<10;i++){
int n1 = (rand()%13);
int n2 = (rand()%13);
int answer = n1*n2;
int input = 0;

printf("%d x %d\n",n1, n2);

scanf("%d",&input);

if(input == answer){
    printf("Congrats! Right Asnwer!\n");
    count++;
}else{
    printf("Wrong Answer!:(\n");

}

}

count *= 10;
printf("You got %d% Right!",count);

}
