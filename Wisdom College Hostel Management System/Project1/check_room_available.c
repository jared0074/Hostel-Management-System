#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "total_function.h"

/*      ************************
        |      CHECK MENU      |
        ************************

        -----------------------------------------------------------------------------------------------------------------
        | BLOCK |  GENDER  |  AVAILABILITY  |   TYPE   |  AMOUNT RECEIVABLE  | PAYMENT RECEIVED | STUDENT BOOKED AMOUNT |
        -----------------------------------------------------------------------------------------------------------------
        |  A 1  |   MALE   |        98      |  SINGLE  |         2830        |        920       |            2          |
        |  A 2  |   MALE   |       100      |  2-BEDS  |            0        |          0       |            0          |
        |  B 1  |  FEMALE  |        99      |  SINGLE  |         2150        |          0       |            1          |
        |  B 3  |  FEMALE  |       100      |  3-BEDS  |            0        |          0       |            0          |
        -----------------------------------------------------------------------------------------------------------------
        TOTAL ROOM AVAIBLE: 397   TOTAL AMOUNT RECEIVABLE: 4980    TOTAL PAYMENT RECEIVED: 920   TOTAL HOSTELER: 3

        1) CHECK ALL STUDENTS DETAILS BY BLOCK
        2) EXIT TO ADMIN SYSTEM MENU
        PLEASE ENTER A CHOICE (1-2) :
*/

/* FUNCTION IS CALLED FOR ADMIN TO HAVE AN OVERALL VIEW OF ALL THE DETAILS ABOUT BLOCKS, AMOUNT RECEIVABLE, PAYMENT RECEIVED AND HOSTELER*/

/* FUNCTION IS CALLED IN admin_system.c*/

void check_r_available_and_m_receivables() {
	system("CLS");
	FILE *block;
	int a1_room_count, a2_room_count, b1_room_count, b3_room_count, a1_amount_receivable = 0, a1_payment_received = 0, a2_amount_receivable = 0, a2_payment_received = 0, b1_amount_receivable = 0, b1_payment_received = 0, b3_amount_receivable = 0, b3_payment_received = 0,a1_student_amount = 0, a2_student_amount = 0, b1_student_amount = 0, b3_student_amount = 0;
	int total_room_available, total_hosteler, total_amount_receivable, total_amount_payment,  check_choice;
	float male_percentage, female_percentage, total_male_student, total_female_student;
	a1_room_count = a1_room_available(); a2_room_count = a2_room_available(); b1_room_count = b1_room_available(); b3_room_count = b3_room_available();
	block = fopen("Student.txt", "r");
	while (fscanf(block, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, &check.age, check.phone_num, check.email, check.block_area, &check.room_num, &check.laundry_service, &check.gym_service, &check.week_stay, &check.amount_due, &check.paid_amount, &check.bed_num) != EOF) {
		if (check.block_area[0] == 'A' && check.block_area[1] == '1') {
			a1_amount_receivable = a1_amount_receivable + check.amount_due;
			a1_payment_received = a1_payment_received + check.paid_amount;
			a1_student_amount++;
		}
		else if (check.block_area[0] == 'A' && check.block_area[1] == '2') {
			a2_amount_receivable = a2_amount_receivable + check.amount_due;
			a2_payment_received = a2_payment_received + check.paid_amount;
			a2_student_amount++;
		}
		else if (check.block_area[0] == 'B' && check.block_area[1] == '1') {
			b1_amount_receivable = b1_amount_receivable + check.amount_due;
			b1_payment_received = b1_payment_received + check.paid_amount;
			b1_student_amount++;
		}
		else {
			b3_amount_receivable = b3_amount_receivable + check.amount_due;
			b3_payment_received = b3_payment_received + check.paid_amount;
			b3_student_amount++;
		}
	}
	total_room_available = a1_room_count + a2_room_count + b1_room_count + b3_room_count;
	total_amount_receivable = a1_amount_receivable + a2_amount_receivable + b1_amount_receivable + b3_amount_receivable;
	total_amount_payment = a1_payment_received + a2_payment_received + b1_payment_received + b3_payment_received;
	total_hosteler = a1_student_amount + a2_student_amount + b1_student_amount + b3_student_amount;
	total_male_student = (a1_student_amount + a2_student_amount)/ (float)1;
	total_female_student = (b1_student_amount + b3_student_amount) / (float)1;
	male_percentage = 100 * (total_male_student / (float)total_hosteler);
	female_percentage = 100 * (total_female_student / (float)total_hosteler);
check_menu:
	printf("\t************************\n\t|      CHECK MENU      |\n");
	printf("\t************************\n\n");
	printf("\t-----------------------------------------------------------------------------------------------------------------\n");
	printf("\t| BLOCK |  GENDER  |  AVAILABILITY  |   TYPE   |  AMOUNT RECEIVABLE  | PAYMENT RECEIVED | STUDENT BOOKED AMOUNT |\n");
	printf("\t-----------------------------------------------------------------------------------------------------------------\n");
	printf("\t|  A 1  |   MALE   |       %3d      |  SINGLE  |        %5d        |      %5d       |          %3d          |\n", a1_room_count, a1_amount_receivable, a1_payment_received, a1_student_amount);
	printf("\t|  A 2  |   MALE   |       %3d      |  2-BEDS  |        %5d        |      %5d       |          %3d          |\n", a2_room_count, a2_amount_receivable, a2_payment_received, a2_student_amount);
	printf("\t|  B 1  |  FEMALE  |       %3d      |  SINGLE  |        %5d        |      %5d       |          %3d          |\n", b1_room_count, b1_amount_receivable, b1_payment_received, b1_student_amount);
	printf("\t|  B 3  |  FEMALE  |       %3d      |  3-BEDS  |        %5d        |      %5d       |          %3d          |\n", b3_room_count, b3_amount_receivable, b3_payment_received, b3_student_amount);
	printf("\t-----------------------------------------------------------------------------------------------------------------\n");
	printf("\tTOTAL ROOM AVAIBLE: %d   TOTAL AMOUNT RECEIVABLE: %d    TOTAL PAYMENT RECEIVED: %d   TOTAL HOSTELER: %d\n\n",total_room_available,total_amount_receivable,total_amount_payment,total_hosteler);
	printf("\tPERCENTAGE OF MALE STUDENT: %.2f%%        PERCENTAGE OF FEMALE STUDENTS: %.2f%% \n\n",male_percentage,female_percentage);
	printf("\t1) CHECK ALL STUDENTS DETAILS BY BLOCK\n\t2) EXIT TO ADMIN SYSTEM MENU\n\tPLEASE ENTER A CHOICE (1-2) : ");
	scanf("%d", &check_choice);
	switch (check_choice) {
	case 1:
		check_block_student();
		break;
	case 2:
		printf("\n\n\tREDIRECTING TO THE ADMIN SYSTEM, PLEASE HOLD !");
		_sleep(2000);
		system("CLS");
		break;
	default:
		printf("PLEASE ENTER A VALID OPTION !");
		_sleep(2000);
		system("CLS");
		goto check_menu;

	}
	fclose(block);
	getchar();
	system("CLS");
}