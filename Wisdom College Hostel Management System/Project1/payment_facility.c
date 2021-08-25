#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "total_function.h"
/*      ************************************
        |         PAYMENT FACILITY         |
        ************************************

        HI , YOUR PAYMENT DUE IS 680, HOW MUCH WOULD YOU LIKE TO PAY? :

*/

/* FUNCTION IS CALLED FOR MAKING PAYMENTS FOR THE AMOUNT DUE BY STUDENTS*/
/* FUNCTION WILL READ TEXT FILE AND RETRIEVE THE AMOUNT DUE FROM THE TEXT FILE BASED ON THE STUDENT ID THAT THE STUDENT HAD ENTERED*/
/* AFTER PAYMENT HAS BEEN MADE, THE PAYMENT WILL THEN ADD ITS AMOUNT TO PREVIOUS PAYMENT MADE BY STUDENTS AND WRITE IT INSIDE THE Student.txt FILE*/

/* THIS FUNCTION IS USED INSIDE THE SOURCE FILE student_login.c*/

void payment_facility() {
	system("CLS");
	FILE *block, *newBlock;
	int payment_due, payment_made, new_payment_due, new_payment_made;
	block = fopen("Student.txt", "r"); newBlock = fopen("NewStudent.txt", "w");
payment_menu:
	printf("\t************************************\n");
	printf("\t|         PAYMENT FACILITY         |\n");
	printf("\t************************************\n\n");
	while (fscanf(block, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, &check.age, check.phone_num, check.email, check.block_area, &check.room_num, &check.laundry_service, &check.gym_service, &check.week_stay, &check.amount_due, &check.paid_amount, &check.bed_num) != EOF)
		if (strcmp(strupr(apply.studentID), check.studentID) == 0)
			payment_due = check.amount_due;
	fclose(block); fclose(newBlock);
	printf("\tHI %s, YOUR PAYMENT DUE IS %d, HOW MUCH WOULD YOU LIKE TO PAY? :\n\t", strupr(check.firstName), payment_due);
	scanf("%d", &payment_made);
	if (payment_due < payment_made) {
		printf("\tSORRY, PLEASE MAKE A PAYMENT LESSER THAN YOUR PAYMENT DUE !");
		_sleep(3000);
		system("CLS");
		goto payment_menu;
	}
	else {
		block = fopen("Student.txt", "r"); newBlock = fopen("NewStudent.txt", "w");
		while (fscanf(block, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, &check.age, check.phone_num, check.email, check.block_area, &check.room_num, &check.laundry_service, &check.gym_service, &check.week_stay, &check.amount_due, &check.paid_amount, &check.bed_num) != EOF) {
			if (strcmp(strupr(apply.studentID), check.studentID) == 0) {
				new_payment_due = payment_due - payment_made;
				new_payment_made = check.paid_amount + payment_made;
				fprintf(newBlock, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, check.age, check.phone_num, check.email, check.block_area, check.room_num, check.laundry_service, check.gym_service, check.week_stay, new_payment_due, new_payment_made, check.bed_num);
			}
			else
				fprintf(newBlock, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, check.age, check.phone_num, check.email, check.block_area, check.room_num, check.laundry_service, check.gym_service, check.week_stay, check.amount_due, check.paid_amount, check.bed_num);
		}
		printf("\n\n\t***       PAYMENT SUCCESSFULLY MADE !       ***\n");
		printf("\t***        REDIRECTING TO LOGIN MENU         ***");
		_sleep(2000);
		system("CLS");
	}
	fclose(block); fclose(newBlock);
	remove("Student.txt"); rename("NewStudent.txt", "Student.txt");
}

