#include <stdio.h>
#include <string.h>


//This code was written by Jeremy Akey for Lab 8.




int i, j, time, flag, size;
int count = 0;
char schedule[5][20];
int input;
char holder[20];
char cholder;
int people[5];
char phone[5][11];




void request(void);
void cancel(void);
void list(void);
void letterlist(void);
void numberlist(void);





int main() {



    for (i = 0; i < 5; i++) {
        schedule[i][0] = '\0';
        phone[i][0] = '\0';
    }

    printf("What would you like to do?\n");


    while (1) {
        scanf("%d", &input);

        switch (input) {
        case 1:

            request();

            break;

        case 2:
            cancel();
            break;

        case 3:
            list();
            break;

        case 4:

            letterlist();

            break;

        case 5:

            numberlist();

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

    void request(void) {
	int flag2 = 0;
        if (count == 5) {
            printf("No available time slots!\n");
        }
        else {
            flag = 0;
            printf("Please enter the name you want to have the appointment under\n");
            scanf("%s", holder);
            for (i = 0; i < 5; i++) {
                if (strcmp(holder, schedule[i]) == 0) {
                    printf("There is already an appointment under that name\n");
                    flag = 1;
                }
            }
            if (flag == 0) {
	    strcpy(schedule[count], holder);
            printf("Please enter the number of people attending (Up to 4)\n");
            scanf("%d", &people[count]);
	    if(people[count] > 4){
		printf("There are too many people!\n");
		flag2 = 1;			
	    }
	    if(flag2 == 0){
            printf("Please enter a phone number so we can contact you\n");
            scanf("%s", phone[count]);
            count++;
            printf("Thank you for scheduling an appointment\n");
	    } else{
	    schedule[count][0] = '\0';
	    }
        }
        }

        return;
    }
    void cancel(void) {
        if (count == 0) {
            printf("No lessons to cancel\n");
        }
        else {
            flag = 0;
            printf("Enter the name you'd like to remove!\n");
            scanf("%s", holder);
            for (i = 0; i < 5; i++) {
                int cmp = strcmp(schedule[i], holder);
                if (cmp == 0) {
                    flag = 1;
                    break;
                }
            }
        }
	
        if (flag == 1) {
	printf("%s was removed\n",schedule[i]);
            for (j = i; j < 4; j++) {
		if(schedule[j+1][0] != '\0'){
		printf("%s with phone number %s was moved up a timeslot!\n",schedule[j+1], phone[j+1]);
		}
                strcpy(schedule[j], schedule[j + 1]);
                strcpy(phone[j], phone[j + 1]);
                people[i] = people[i + 1];
            }
            schedule[4][0] = '\0';
            phone[4][0] = '\0';
            count--;
        }

        return;
    }
    void list(void) {

        for (i = 0; i < 5; i++) {
            if (count == 0) {
                printf("The schedule is empty\n");
            }
	  if (schedule[i][0] == '\0') {
                printf("Free\n");
            }
            else {
                printf("%s has this timeslot for %d people, phone number %s\n", schedule[i], people[i], phone[i]);
            }
        }
        return;
    }
    void letterlist(void) {
       
        printf("Enter the first letter of the name on the timeslot\n");
        scanf("%c", &cholder);

        for (i = 0; i < 5; i++) {
            if (schedule[i][0] == cholder) {
                time = i + 1;
                printf("The appointment is under %s at %d\n", schedule[i], time);
            }
        }
        return;
    }
    void numberlist(void) {
        if (count == 0) {
            printf("The schedule is empty\n");
        }
        else {
            printf("What group size would you like to search for?\n");
            scanf("%d", &size);
            for (i = 0; i < 5; i++) {
                time = i + 1;
                if (people[i] == size) {
                    printf("Group named %s at %d is %d people\n", schedule[i], time, size);
                }
            }
        }

    }





