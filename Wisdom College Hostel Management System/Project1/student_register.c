#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "total_function.h"

/*****************************************************
'|            STUDENT REGISTRATION SYSTEM            |
 *****************************************************

 PLEASE ENTER YOUR STUDENT ID (TP049952) : TP000000
 PLEASE ENTER YOUR FIRST NAME : ROSIE
 PLEASE ENTER YOUR LAST NAME : TAN
 PLEASE ENTER YOUR GENDER MALE (M) OR FEMALE (F) : F
 PLEASE ENTER YOUR IC OR PASSPORT (990515729931) or (AK518233) :
 000530280384
 PLEASE ENTER YOUR AGE : 19
 PLEASE ENTER YOUR PHONE NUMBER : 0123456789
 PLEASE ENTER YOUR EMAIL ADDRESS : rosie_tan00@gmail.com


 *****        PLEASE WAIT FOR 4 SECONDS          *****
 
 *******************    SUCCESS    *******************
			 REDIRECTING TO BOOKING MENU
 */

/* STUDENT REGISTRATION FUNCTION IS TO RECEIVE STUDENT DETAILS READY TO BE STORED INSIDE THE TEXT FILE */
/* IDENTIFYING STUDENT"S GENDER AND THEN REASSIGN BLOCK BASE ON THEIR GENDER */
/* LASTLY RETURNING CHECK_REGISTER VALUE IN ORDER TO CHECK IF STUDENTS HAVE SUCCEFFULY REGISTERED OR IS ALREADY REGISTERED*/

/* THIS FUNCTION IS USED INSIDE THE MAIN SOURCE FILE WHICH IS hostel_management_menu.c*/

int student_registration() {
	system("CLS");
	int check_register = 1;
	char gender;
	FILE *block;
	printf("\t*****************************************************\n");
	printf("\t|            STUDENT REGISTRATION SYSTEM            |\n");
	printf("\t*****************************************************\n\n");
	printf("\tPLEASE ENTER YOUR STUDENT ID (TP000000) : ");
	scanf("%s", strupr(apply.studentID));
	block = fopen("Student.txt", "r");
	while (fscanf(block, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, &check.age, check.phone_num, check.email, check.block_area, &check.room_num, &check.laundry_service, &check.gym_service, &check.week_stay, &check.amount_due, &check.paid_amount, &check.bed_num) != EOF) {
		if (strcmp(strupr(apply.studentID), check.studentID) == 0) {
			printf("\tWE HAVE FOUND A RECORD THAT YOU HAVE REGISTERED, PLEASE LOGIN !\n\n");
			_sleep(4000);
			printf("\t****         RETURNING BACK TO MAIN MENU         ****");
			_sleep(4000);
			system("CLS");
			check_register = 0;
			return check_register;
		}
	}
	fclose(block);
	printf("\tPLEASE ENTER YOUR FIRST NAME : ");
	scanf("%s", apply.firstName);
	getchar();
	printf("\tPLEASE ENTER YOUR LAST NAME : ");
	scanf("%s", apply.lastName);
choose_gender:
	printf("\tPLEASE ENTER YOUR GENDER MALE (M) OR FEMALE (F) : ");
	getchar();
	scanf("%c", &gender);
	switch (gender) {
	case 'M':
	case 'm':
		strcpy(apply.gender, "M");
		break;
	case 'F':
	case 'f':
		strcpy(apply.gender, "F");
		break;
	default:
		printf("PLEASE ENTER A VALID OPTION");
		_sleep(4000);
		goto choose_gender;
	}
	printf("\tPLEASE ENTER YOUR IC OR PASSPORT (990515729931) or (AK518233) :\n\t");
	scanf("%s", apply.identification);
	printf("\tPLEASE ENTER YOUR AGE : ");
	scanf("%d", &apply.age);
	printf("\tPLEASE ENTER YOUR PHONE NUMBER : ");
	scanf("%s", apply.phone_num);
	printf("\tPLEASE ENTER YOUR EMAIL ADDRESS : ");
	scanf("%s", apply.email);
	printf("\n\n");
	printf("\t*****        PLEASE WAIT FOR 4 SECONDS          *****\n\n");
	_sleep(4000);
	printf("\t*******************    SUCCESS    *******************\n");
	printf("\t            REDIRECTING TO BOOKING MENU              ");
	_sleep(4000);
	return check_register;
}
