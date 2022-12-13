#include <stdio.h>
#include <string.h>


int main(){ 

int i, j, time, flag;
int count = 0;
char schedule[5][20];
int input;
char holder[20];
char cholder;

for(i=0;i<5;i++){
schedule[i][0] = '\0';
}

printf("What would you like to do?\n");


while(1){
scanf("%d",&input);
switch(input){
    case 1:
    
    if(count == 5){
	printf("No available time slots!\n");
	}else{
	 printf("Please enter the name you want to have the appointment under\n");
	 scanf("%s",schedule[count]);
	 count++;
	 printf("Thank you for scheduling an appointment\n");
	}	

    break;

    case 2:
    if(count == 0){
     printf("No lessons to cancel\n");
	 } else{
	printf("Enter the name you'd like to remove!\n");
	scanf("%s",holder);
	     for(i=0;i<5;i++){
	     int cmp = strcmp(schedule[i],holder);
		if(cmp == 0){
	    	flag = 1;
		break;
		}
        }
    }
    if(flag == 1){
	for(j=i;j<4;j++){
    strcpy(schedule[j],schedule[j+1]);
	    }
    schedule[4][0] = '\0';
    count--;
    }	

    break;

    case 3:
    for(i=0;i<5;i++){
    if(schedule[i][0] == '\0'){
	printf("Free\n");
    }else{
	printf("%s has this timeslot\n",schedule[i]);
    }
    }
    break;

    case 4:


    printf("Enter the first letter of the name on the timeslot\n");
    scanf("%c",&cholder);

    for(i=0;i<5;i++){
    if(schedule[i][0] == cholder){
	time = i+1;
    printf("The appointment is under %s at %d\n",schedule[i],time);
    }
    }

    break;

    case 9:

    return 0;


    break;

    default:

    printf("Enter a valid number please!\n");

    break;

    }
}
}

