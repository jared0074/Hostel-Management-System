#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "total_function.h"

/*        *******     HERE IS YOUR BOOKING DETAILS    *******

         STUDENT ID         : TP049952
         YOUR FIRST NAME    : JARED
         YOUR LAST NAME     : CHAN
         YOUR GENDER        : M
         YOUR IDENTIFICATION: 990423076521
         YOUR AGE           : 20
         YOUR PHONE         : 0134020303
         YOUR EMAIL         : jaredchan0074@gmail.com
         YOUR BLOCK         : A1
         YOUR ROOM          : 1
		 YOUR WEEK OF STAY  : 4
         YOUR PAYMENT DUE   : 680
         YOUR PAYMENT MADE  : 920
		 LAUNDRY            : YES
		 GYM                : YES
*/

/*      WOULD YOU LIKE TO MAKE ANY CHANGES TO YOUR DETAILS ? YES(Y) OR NO(N) :y
        WHAT DETAILS WOULD YOU LIKE TO CHANGE? (1-7) :
        1) STUDENT ID
        2) FIRST NAME
        3) LAST NAME
        4) AGE
        5) IDENTIFICATION
        6) PHONE NUMBER
        7) EMAIL
*/

/* THIS FUNCTION IS CALLED FOR CHECKING STUDENTS DETAILS AS WELL AS CHANGING THE STUDENT DETAILS*/

/* FUNCTION IS CALLED IN student_login.c*/

int student_details() {
	system("CLS");
	FILE *block, *newBlock;
	int change_choice, new_age,change_ID = 0;
	char choice, new_studentID[10], new_first_name[30], new_last_name[30], new_identification[15], new_email[50], new_phone_num[20], laundry [4],gym [4];
details_menu:
	block = fopen("Student.txt", "r");
	while (fscanf(block, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, &check.age, check.phone_num, check.email, check.block_area, &check.room_num, &check.laundry_service, &check.gym_service, &check.week_stay, &check.amount_due, &check.paid_amount, &check.bed_num) != EOF) {
		if (strcmp(apply.studentID, check.studentID) == 0) {
			printf("\t*******     HERE IS YOUR BOOKING DETAILS    *******\n");
			printf("\n\t STUDENT ID         : %s", strupr(check.studentID));
			printf("\n\t YOUR FIRST NAME    : %s", strupr(check.firstName));
			printf("\n\t YOUR LAST NAME     : %s", strupr(check.lastName));
			printf("\n\t YOUR GENDER        : %s", strupr(check.gender));
			printf("\n\t YOUR IDENTIFICATION: %s", check.identification);
			printf("\n\t YOUR AGE           : %d", check.age);
			printf("\n\t YOUR PHONE         : %s", check.phone_num);
			printf("\n\t YOUR EMAIL         : %s", check.email);
			printf("\n\t YOUR BLOCK         : %s", check.block_area);
			printf("\n\t YOUR ROOM          : %d", check.room_num);
			printf("\n\t YOUR WEEK OF STAY  : %d", check.week_stay);
			printf("\n\t YOUR PAYMENT DUE   : %d", check.amount_due);
			printf("\n\t YOUR PAYMENT MADE  : %d", check.paid_amount);
			if (check.laundry_service == 0)
				strcpy(laundry, "NO");
			else
				strcpy(laundry, "YES");
			if (check.gym_service == 0)
				strcpy(gym, "NO");
			else
				strcpy(gym, "YES");
			printf("\n\t LAUNDRY            : %s", laundry);
			printf("\n\t GYM                : %s", gym);
			break;
		}
	}
	fclose(block);
	getchar();
	printf("\n\n\tWOULD YOU LIKE TO MAKE ANY CHANGES TO YOUR DETAILS ? YES(Y) OR NO(N) :");
	scanf("%c", &choice);
	switch (choice) {
	case 'Y':
	case 'y':
		printf("\tWHAT DETAILS WOULD YOU LIKE TO CHANGE? (1-7) : \n");
		printf("\t1) STUDENT ID\n\t2) FIRST NAME\n\t3) LAST NAME\n\t4) AGE\n\t5) IDENTIFICATION\n\t6) PHONE NUMBER\n\t7) EMAIL\n\t");
		scanf("%d", &change_choice);
		switch (change_choice) {
		case 1:
		change_student_ID:
			printf("\tPLEASE INSERT THE CORRECT STUDENT ID (TP000000):");
			scanf("%s", new_studentID);
			block = fopen("Student.txt", "r");
			newBlock = fopen("NewStudent.txt", "w+");
			while (fscanf(block, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, &check.age, check.phone_num, check.email, check.block_area, &check.room_num, &check.laundry_service, &check.gym_service, &check.week_stay, &check.amount_due, &check.paid_amount, &check.bed_num) != EOF) {
				if (strcmp(strupr(new_studentID), strupr(check.studentID)) == 0) {
					printf("\tSORRY, THIS STUDENT ID ALREADY EXISTED !\n");
					fclose(block); fclose(newBlock);
					goto change_student_ID;
				}
			}
			fclose(block); fclose(newBlock);
			block = fopen("Student.txt", "r");
			newBlock = fopen("NewStudent.txt", "w+");
			while (fscanf(block, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, &check.age, check.phone_num, check.email, check.block_area, &check.room_num, &check.laundry_service, &check.gym_service, &check.week_stay, &check.amount_due, &check.paid_amount, &check.bed_num) != EOF) {
				if (strcmp(strupr(apply.studentID), check.studentID) == 0)
					fprintf(newBlock, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(new_studentID), check.firstName, check.lastName, check.gender, check.identification, check.age, check.phone_num, check.email, check.block_area, check.room_num, check.laundry_service, check.gym_service, check.week_stay, check.amount_due, check.paid_amount, check.bed_num);
				else
					fprintf(newBlock, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, check.age, check.phone_num, check.email, check.block_area, check.room_num, check.laundry_service, check.gym_service, check.week_stay, check.amount_due, check.paid_amount, check.bed_num);
			}
			fclose(block); fclose(newBlock);
			remove("Student.txt");
			rename("NewStudent.txt", "Student.txt");
			change_ID = 1;
			return change_ID;
			break;
		case 2:
			printf("\tPLEASE INSERT THE CORRECT FIRST NAME : ");
			scanf("%s", new_first_name);
			block = fopen("Student.txt", "r");
			newBlock = fopen("NewStudent.txt", "w+");
			while (fscanf(block, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, &check.age, check.phone_num, check.email, check.block_area, &check.room_num, &check.laundry_service, &check.gym_service, &check.week_stay, &check.amount_due, &check.paid_amount, &check.bed_num) != EOF) {
				if (strcmp(strupr(apply.studentID), check.studentID) == 0)
					fprintf(newBlock, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), new_first_name, check.lastName, check.gender, check.identification, check.age, check.phone_num, check.email, check.block_area, check.room_num, check.laundry_service, check.gym_service, check.week_stay, check.amount_due, check.paid_amount, check.bed_num);
				else
					fprintf(newBlock, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, check.age, check.phone_num, check.email, check.block_area, check.room_num, check.laundry_service, check.gym_service, check.week_stay, check.amount_due, check.paid_amount, check.bed_num);
			}
			fclose(block); fclose(newBlock);
			remove("Student.txt");
			rename("NewStudent.txt", "Student.txt");
			return change_ID;
			break;
		case 3:
			printf("\tPLEASE INSERT THE CORRECT LAST NAME : ");
			scanf("%s", new_last_name);
			block = fopen("Student.txt", "r");
			newBlock = fopen("NewStudent.txt", "w+");
			while (fscanf(block, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, &check.age, check.phone_num, check.email, check.block_area, &check.room_num, &check.laundry_service, &check.gym_service, &check.week_stay, &check.amount_due, &check.paid_amount, &check.bed_num) != EOF) {
				if (strcmp(strupr(apply.studentID), check.studentID) == 0)
					fprintf(newBlock, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, new_last_name, check.gender, check.identification, check.age, check.phone_num, check.email, check.block_area, check.room_num, check.laundry_service, check.gym_service, check.week_stay, check.amount_due, check.paid_amount, check.bed_num);
				else
					fprintf(newBlock, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, check.age, check.phone_num, check.email, check.block_area, check.room_num, check.laundry_service, check.gym_service, check.week_stay, check.amount_due, check.paid_amount, check.bed_num);
			}
			fclose(block); fclose(newBlock);
			remove("Student.txt");
			rename("NewStudent.txt", "Student.txt");
			return change_ID;
			break;
		case 4:
			printf("\tPLEASE INSERT THE CORRECT AGE : ");
			scanf("%d", &new_age);
			block = fopen("Student.txt", "r");
			newBlock = fopen("NewStudent.txt", "w+");
			while (fscanf(block, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, &check.age, check.phone_num, check.email, check.block_area, &check.room_num, &check.laundry_service, &check.gym_service, &check.week_stay, &check.amount_due, &check.paid_amount, &check.bed_num) != EOF) {
				if (strcmp(strupr(apply.studentID), check.studentID) == 0)
					fprintf(newBlock, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, new_age, check.phone_num, check.email, check.block_area, check.room_num, check.laundry_service, check.gym_service, check.week_stay, check.amount_due, check.paid_amount, check.bed_num);
				else
					fprintf(newBlock, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, check.age, check.phone_num, check.email, check.block_area, check.room_num, check.laundry_service, check.gym_service, check.week_stay, check.amount_due, check.paid_amount, check.bed_num);
			}
			fclose(block); fclose(newBlock);
			remove("Student.txt");
			rename("NewStudent.txt", "Student.txt");
			return change_ID;
			break;
		case 5:
			printf("\tPLEASE INSERT THE CORRECT IC (990911029392) OR PASSPORT (AK0416): ");
			scanf("%s", new_identification);
			block = fopen("Student.txt", "r");
			newBlock = fopen("NewStudent.txt", "w+");
			while (fscanf(block, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, &check.age, check.phone_num, check.email, check.block_area, &check.room_num, &check.laundry_service, &check.gym_service, &check.week_stay, &check.amount_due, &check.paid_amount, &check.bed_num) != EOF) {
				if (strcmp(strupr(apply.studentID), check.studentID) == 0)
					fprintf(newBlock, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, new_identification, check.age, check.phone_num, check.email, check.block_area, check.room_num, check.laundry_service, check.gym_service, check.week_stay, check.amount_due, check.paid_amount, check.bed_num);
				else
					fprintf(newBlock, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, check.age, check.phone_num, check.email, check.block_area, check.room_num, check.laundry_service, check.gym_service, check.week_stay, check.amount_due, check.paid_amount, check.bed_num);
			}
			fclose(block); fclose(newBlock);
			remove("Student.txt");
			rename("NewStudent.txt", "Student.txt");
			return change_ID;
			break;
		case 6:
			printf("\tPLEASE INSERT THE CORRECT PHONE NUMBER (0123456789) : ");
			scanf("%s", new_phone_num);
			block = fopen("Student.txt", "r");
			newBlock = fopen("NewStudent.txt", "w+");
			while (fscanf(block, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, &check.age, check.phone_num, check.email, check.block_area, &check.room_num, &check.laundry_service, &check.gym_service, &check.week_stay, &check.amount_due, &check.paid_amount, &check.bed_num) != EOF) {
				if (strcmp(strupr(apply.studentID), check.studentID) == 0)
					fprintf(newBlock, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, check.age, new_phone_num, check.email, check.block_area, check.room_num, check.laundry_service, check.gym_service, check.week_stay, check.amount_due, check.paid_amount, check.bed_num);
				else
					fprintf(newBlock, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, check.age, check.phone_num, check.email, check.block_area, check.room_num, check.laundry_service, check.gym_service, check.week_stay, check.amount_due, check.paid_amount, check.bed_num);
			}
			fclose(block); fclose(newBlock);
			remove("Student.txt");
			rename("NewStudent.txt", "Student.txt");
			return change_ID;
			break;
		case 7:
			printf("\tPLEASE INSERT THE CORRECT EMAIL (xxxxxxxx@xmail.com) : ");
			scanf("%s", new_email);
			block = fopen("Student.txt", "r");
			newBlock = fopen("NewStudent.txt", "w+");
			while (fscanf(block, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, &check.age, check.phone_num, check.email, check.block_area, &check.room_num, &check.laundry_service, &check.gym_service, &check.week_stay, &check.amount_due, &check.paid_amount, &check.bed_num) != EOF) {
				if (strcmp(strupr(apply.studentID), check.studentID) == 0)
					fprintf(newBlock, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, check.age, check.phone_num, new_email, check.block_area, check.room_num, check.laundry_service, check.gym_service, check.week_stay, check.amount_due, check.paid_amount, check.bed_num);
				else
					fprintf(newBlock, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, check.age, check.phone_num, check.email, check.block_area, check.room_num, check.laundry_service, check.gym_service, check.week_stay, check.amount_due, check.paid_amount, check.bed_num);
			}
			fclose(block); fclose(newBlock);
			remove("Student.txt");
			rename("NewStudent.txt", "Student.txt");
			return change_ID;
			break;
		}
		break;
	case 'N':
	case 'n':
		printf("\tREDIRECTING TO THE LOGIN MENU, PLEASE HOLD !");
		_sleep(2000);
		system("CLS");
		break;
	default:
		printf("PLEASE ENTER A VALID OPTION !");
		_sleep(2000);
		system("CLS");
		goto details_menu;
	}
}