#include <stdio.h>

//This code was written by Jeremy Akey on 10/22/21 for COEN10 Lab Six 

int main(){

    
int save;
int count1 = 1;
int schedule[5];
int counter = 1;
int input;
int cancel=0;
int i,j;
int apps;


printf("Press 1 to schedule a lesson\n");
printf("Press 2 to cancel a lesson\n");
printf("Press 3 to list lesson times\n");
printf("Press 9 to quit\n");

while(1){

scanf("%d",&input);

if(input == 1){
    for(i=0;i<=5;i++){
        if(counter > 5){
	  counter = 1;
	}
	 if(apps>=5){
	printf("No appointmets available!\n");
	break;
	 }
	     if(cancel>0) {
	     i = cancel - 1;
	    counter = cancel;
	     }

		 if(schedule[i] == 0){
	    	schedule[i] = 1;
		printf("Thank You for scheduling an appointment at %d:00 pm!\n",counter);
		counter++;
		apps++;
		break;    
		 }
    	
    }

}else if(input == 2) {

    printf("What time would you like to cancel? (1,2,3,4,5)?\n");
    scanf("%d",&cancel);  
    cancel -= 1;
    apps--;

    schedule[cancel] = 0;
    cancel++;
    printf("Your lesson at %d:00 pm has been succesfully canceled!\n",cancel);
    counter = cancel-1;

}else if(input == 3){
    for(j = 0; j<=5;j++){
    
    if(schedule[j] == 0){
	printf("The time at %d:00 pm is open\n",count1);
	count1++;
	}else if(schedule[j] == 1){	   
	 printf("The time at %d:00 pm is not available\n",count1);
	count1++;
	}

    }


}else if(input == 9){
    printf("Thank you for using the scheduling system! Goodbye!\n");
    return 1;
    
}else{
printf("Invalid Input, please enter either 1,2,3 or 9\n");

}
count1 = 1;
}
}


