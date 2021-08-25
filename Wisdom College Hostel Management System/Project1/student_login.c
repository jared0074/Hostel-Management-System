#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "total_function.h"

/*      ****************************************************
        |               STUDENT LOGIN SYSTEM               |
        ****************************************************

        PLEASE INSERT YOUR STUDENT ID (TP000000) : TP049952
*/

/*      *******************************************************
        |           WELCOME TO STUDENT LOGIN SYSTEM           |
        *******************************************************

        WHAT WOULD YOU LIKE TO DO?

        1) CHANGE / CANCEL ROOM
        2) CHECK / CHANGE PERSONAL DETAILS
        3) MAKE PAYMENT
        4) EXIT TO HOSTEL MANAGEMENT SYSTEM

        PLEASE ENTER A CHOICE (1-4):
*/

/* FUNCTION IS CALLED FOR STUDENTS WHO SUCCESSFULLY REGISTERED AND LOGIN TO CHANGE OR CANCLE ROOM, CHECK OR CHANGE DETAILS, MAKE PAYMENT*/

/* THIS FUNCTION IS USED INSIDE THE MAIN SOURCE FILE WHICH IS hostel_management_menu.c*/

int student_login() {
	FILE *block;
	int choice, change_choice, check_login = 0,check_ID;
	system("CLS");
	printf("\t****************************************************\n");
	printf("\t|               STUDENT LOGIN SYSTEM               |\n");
	printf("\t****************************************************\n\n");
	printf("\tPLEASE INSERT YOUR STUDENT ID (TP000000) : ");
	scanf("%s", strupr(apply.studentID));
	block = fopen("Student.txt", "r");
	while (fscanf(block, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, &check.age, check.phone_num, check.email, check.block_area, &check.room_num, &check.laundry_service, &check.gym_service, &check.week_stay, &check.amount_due, &check.paid_amount, &check.bed_num) != EOF) {
		if (strcmp(strupr(apply.studentID), check.studentID) == 0) {
			printf("\n\tHI, %s WELCOME BACK! WE WILL REDIRECT YOU TO THE LOGIN SYSTEM !\n\n", strupr(check.firstName));
			printf("\t                 REDIRECTING TO LOGIN SYSTEM                   ");
			_sleep(2000);
			system("CLS");
			check_login = 1;
			break;
		}
		else
			check_login = 0;
	}
	fclose(block);
	if (check_login == 1) {
	main_menu:
		printf("\t*******************************************************\n");
		printf("\t|           WELCOME TO STUDENT LOGIN SYSTEM           |\n");
		printf("\t*******************************************************\n\n");
		printf("\tWHAT WOULD YOU LIKE TO DO?\n\n");
		printf("\t1) CHANGE / CANCEL ROOM\n\t2) CHECK / CHANGE PERSONAL DETAILS\n\t3) MAKE PAYMENT\n\t4) EXIT TO HOSTEL MANAGEMENT SYSTEM\n\n");
		printf("\tPLEASE ENTER A CHOICE (1-4): ");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
		change_menu:
			printf("\tWOULD YOU LIKE TO : \n\t1) CHANGE ROOM \n\t2) CANCEL ROOM \n\t3) CHANGE LAUNDRY OR GYM SERVICE : ");
			scanf("%d", &change_choice);
			switch (change_choice) {
			case 1:
				change_room();
				printf("\tSUCCESSFULLY CHANGED ROOM, PLEASE LOGIN AGAIN");
				remove("Student.txt"); rename("NewStudent.txt", "Student.txt");
				_sleep(2000);
				system("CLS");
				break;
			case 2:
				cancel_room();
				break;
			case 3:
				add_service();
				break;
			default:
				printf("\tPLEASE ENTER A VALID CHOICE !");
				_sleep(2000);
				system("CLS");
				goto change_menu;
			}
			break;
		case 2:
			check_ID = student_details();
			if (check_ID == 0) {
				system("CLS");
				goto main_menu;
			}
			else {
				printf("\n\n\tPLEASE LOGIN AGAIN TO CHECK YOUR DETAILS");
				_sleep(2000);
				system("CLS");
				break;
			}
		case 3:
			payment_facility();
			goto main_menu;
			break;
		case 4:
			printf("\n\n\tREDIRECTING TO THE HOSTEL MANAGEMENT SYSTEM, PLEASE HOLD !");
			_sleep(2000);
			system("CLS");
			return;
			break;
		default:
			printf("PLEASE ENTER A VALID OPTION !");
			_sleep(2000);
			system("CLS");
			goto main_menu;
		}
	}
	else {
		printf("\n\n\n\t*  SORRY WE DON'T HAVE YOUR RECORD, PLEASE REGISTER!  *\n");
		_sleep(3000);
		printf("\t****          RETURNING BACK TO MAIN MENU          ****\n");
		_sleep(3000);
		system("CLS");
		return;
	}
}