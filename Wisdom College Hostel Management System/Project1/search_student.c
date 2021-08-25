#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "total_function.h"

/*      *****************************************************
        |               STUDENT SEARCH SYSTEM               |
        *****************************************************

        PLEASE INSERT THE STUDENT ID TO SEARCH THE STUDENT DETAILS : TP049952

*/

/*       *******     HERE IS THE BOOKING DETAILS OF THE STUDENT   *******

         STUDENT ID    : TP049952
         FIRST NAME    : JARED
         LAST NAME     : CHAN
         GENDER        : M
         IDENTIFICATION: 990423076521
         AGE           : 20
         PHONE         : 0134020303
         EMAIL         : jaredchan0074@gmail.com
         BLOCK         : A1
         ROOM          : 1
         PAYMENT DUE   : 680
         PAYMENT MADE  : 920

        ENTER ANYTHING TO EXIT :
*/

/* FUNCTION IS CALLED FOR ADMIN TO SEARCH STUDENT DETAILS USING STUDENT ID*/

/* FUNCTION IS CALLED IN admin_system.c*/

void search_student() {
	FILE *block;
	int check_login = 0;
	char search_studentID[10],search_choice;
	system("CLS");
	printf("\t*****************************************************\n");
	printf("\t|               STUDENT SEARCH SYSTEM               |\n");
	printf("\t*****************************************************\n\n");
	printf("\tPLEASE INSERT THE STUDENT ID TO SEARCH THE STUDENT DETAILS : ");
	scanf("%s", search_studentID);
	block = fopen("Student.txt","r");
	while (fscanf(block, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, &check.age, check.phone_num, check.email, check.block_area, &check.room_num, &check.laundry_service, &check.gym_service, &check.week_stay, &check.amount_due, &check.paid_amount, &check.bed_num) != EOF) {
		if (strcmp(strupr(search_studentID), check.studentID) == 0) {
			check_login = 1;
			break;
		}
		else
			check_login = 0;
	}
	if (check_login == 0) {
		printf("\tSORRY BUT WE DON'T HAVE THE RECORD OF THIS STUDENT !\n\n");
		_sleep(2000);
		printf("\tREDIRECTING TO ADMIN SYSTEM ");
		_sleep(2000);
		return;
	}
	else {
		system("CLS");
		printf("\t*******     HERE IS THE BOOKING DETAILS OF THE STUDENT   *******\n");
		printf("\n\t STUDENT ID    : %s", strupr(check.studentID));
		printf("\n\t FIRST NAME    : %s", strupr(check.firstName));
		printf("\n\t LAST NAME     : %s", strupr(check.lastName));
		printf("\n\t GENDER        : %s", strupr(check.gender));
		printf("\n\t IDENTIFICATION: %s", check.identification);
		printf("\n\t AGE           : %d", check.age);
		printf("\n\t PHONE         : %s", check.phone_num);
		printf("\n\t EMAIL         : %s", check.email);
		printf("\n\t BLOCK         : %s", check.block_area);
		printf("\n\t ROOM          : %d", check.room_num);
		printf("\n\t PAYMENT DUE   : %d", check.amount_due);
		printf("\n\t PAYMENT MADE  : %d\n\n", check.paid_amount);
		printf("\tENTER ANYTHING TO EXIT : ");
		getchar();
		scanf("%c", &search_choice);
	}
	system("CLS");
	fclose(block);
}