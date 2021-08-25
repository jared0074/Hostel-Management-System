#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "total_function.h"

/*                              ************************
                                |         MENU         |
                                ************************

        ------------------------------------------------------------------------------
        | BLOCK |  GENDER  |  AVAILABILITY  |   TYPE   |  RENTALS  | LAUNDRY  | GYM  |
        ------------------------------------------------------------------------------
        |  A 1  |   MALE   |        98      |  SINGLE  |   RM400   |   RM20   | RM10 |
        |  A 2  |   MALE   |       100      |  2-BEDS  |   RM200   |   RM20   | RM10 |
        |  A 3  |   MALE   |   UNAVAILABLE  |  3-BEDS  |   RM150   |   RM20   | RM10 |
        |  A 4  |   MALE   |   UNAVAILABLE  |  4-BEDS  |   RM100   |   RM20   | RM10 |
        ------------------------------------------------------------------------------

        1) BLOCK A1 , SINGLE BEDDED ROOM , RM400 WEEKLY
        2) BLOCK A2 , DOUBLE BEDDED ROOM , RM200 WEEKLY
        3) BLOCK A3 ,  THREE BEDDED ROOM , RM150 WEEKLY
        4) BLOCK A4 ,   FOUR BEDDED ROOM , RM100 WEEKLY

        PLEASE CHOOSE THE BLOCK YOU WANT TO CHANGE (1 - 4):
*/

/* FUNCTION IS CALLED IN ORDER TO MAKE CHANGES TO THE ROOM, IT ACTS LIKE THE BOOKING MENU FUNCTION IN booking_menu.c*/

/* FUCTION IS CALLED IN student_login.c */
void change_room() {
	FILE *block, *newBlock;
	block = fopen("Student.txt", "r");
	while (fscanf(block, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, &check.age, check.phone_num, check.email, check.block_area, &check.room_num, &check.laundry_service, &check.gym_service, &check.week_stay, &check.amount_due, &check.paid_amount, &check.bed_num) != EOF)
		if (strcmp(strupr(apply.studentID), check.studentID) == 0 && check.gender[0] == 'M') {
			fclose(block);
			int new_block_type, new_room_num, new_rental, new_laundry, new_gym, new_total_due, i, new_week_stay, a1_room_count, a2_room_count;
			char block_area[3];
			a1_room_count = a1_room_available();
			a2_room_count = a2_room_available();
		choose_block:
			system("CLS");
			printf("\t\t\t\t************************\n\t\t\t\t|         MENU         |\n");
			printf("\t\t\t\t************************\n\n");
			printf("\t------------------------------------------------------------------------------\n");
			printf("\t| BLOCK |  GENDER  |  AVAILABILITY  |   TYPE   |  RENTALS  | LAUNDRY  | GYM  |\n");
			printf("\t------------------------------------------------------------------------------\n");
			printf("\t|  A 1  |   MALE   |       %3d      |  SINGLE  |   RM400   |   RM20   | RM10 |\n", a1_room_count);
			printf("\t|  A 2  |   MALE   |       %3d      |  2-BEDS  |   RM200   |   RM20   | RM10 |\n", a2_room_count);
			printf("\t|  A 3  |   MALE   |   UNAVAILABLE  |  3-BEDS  |   RM150   |   RM20   | RM10 |\n");
			printf("\t|  A 4  |   MALE   |   UNAVAILABLE  |  4-BEDS  |   RM100   |   RM20   | RM10 |\n");
			printf("\t------------------------------------------------------------------------------\n\n");
			printf("\t1) BLOCK A1 , SINGLE BEDDED ROOM , RM400 WEEKLY\n");
			printf("\t2) BLOCK A2 , DOUBLE BEDDED ROOM , RM200 WEEKLY\n");
			printf("\t3) BLOCK A3 ,  THREE BEDDED ROOM , RM150 WEEKLY\n");
			printf("\t4) BLOCK A4 ,   FOUR BEDDED ROOM , RM100 WEEKLY\n\n");
			printf("\tPLEASE CHOOSE THE BLOCK YOU WANT TO CHANGE (1 - 4): ");
			scanf("%d", &new_block_type);
			switch (new_block_type) {
			case 1:
				new_rental = 400;
				strcpy(apply.block_area, "A1");
				new_room_num = a1room_visuals();
				system("CLS");
				new_laundry = laundry_calculation();
				new_gym = gym_calculation();
				printf("\tHOW MANY WEEKS WOULD YOU LIKE TO STAY?");
				scanf("%d", &new_week_stay);
				apply.paid_amount = 0;
				new_total_due = personal_due(new_rental, new_gym, new_laundry, new_week_stay, apply.paid_amount);
				apply.room_num = new_room_num, apply.laundry_service = new_laundry, apply.gym_service = new_gym, apply.week_stay = new_week_stay, apply.amount_due = new_total_due, apply.bed_num = 0;
				block = fopen("Student.txt", "r");
				newBlock = fopen("NewStudent.txt", "w+");
				while (fscanf(block, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, &check.age, check.phone_num, check.email, check.block_area, &check.room_num, &check.laundry_service, &check.gym_service, &check.week_stay, &check.amount_due, &check.paid_amount, &check.bed_num) != EOF) {
					if (strcmp(strupr(apply.studentID), check.studentID) == 0)
						fprintf(newBlock, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, check.age, check.phone_num, check.email, apply.block_area, apply.room_num, apply.laundry_service, apply.gym_service, apply.week_stay, apply.amount_due, apply.paid_amount, apply.bed_num);
					else
						fprintf(newBlock, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, check.age, check.phone_num, check.email, check.block_area, check.room_num, check.laundry_service, check.gym_service, check.week_stay, check.amount_due, check.paid_amount, check.bed_num);
				}
				fclose(block); fclose(newBlock);
				printf("\n\n\n\t*******    CONGRATULATIONS YOU HAVE SUCCESSFULLY CHANGED    *******\n\n");
				printf("\t*******                  PLEASE LOGIN AGAIN                   *******\n");
				_sleep(2000);
				printf("\tPLEASE NOTE THAT A FINE OF RM 200 WILL BE CHARGED, PLEASE PAY THE ADMIN !");
				_sleep(3000);
				system("CLS");
				break;
			case 2:
				new_rental = 200;
				strcpy(apply.block_area, "A2");
				new_room_num = a2room_visuals();
				system("CLS");
				new_laundry = laundry_calculation();
				new_gym = gym_calculation();
				printf("\tHOW MANY WEEKS WOULD YOU LIKE TO STAY?");
				scanf("%d", &new_week_stay);
				apply.paid_amount = 0;
				new_total_due = personal_due(new_rental, new_gym, new_laundry, new_week_stay, apply.paid_amount);
				apply.room_num = new_room_num, apply.laundry_service = new_laundry, apply.gym_service = new_gym, apply.week_stay = new_week_stay, apply.amount_due = new_total_due;
				block = fopen("Student.txt", "r");
				newBlock = fopen("NewStudent.txt", "w+");
				while (fscanf(block, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, &check.age, check.phone_num, check.email, check.block_area, &check.room_num, &check.laundry_service, &check.gym_service, &check.week_stay, &check.amount_due, &check.paid_amount, &check.bed_num) != EOF) {
					if (strcmp(strupr(apply.studentID), check.studentID) == 0)
						fprintf(newBlock, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, check.age, check.phone_num, check.email, apply.block_area, apply.room_num, apply.laundry_service, apply.gym_service, apply.week_stay, apply.amount_due, apply.paid_amount, apply.bed_num);
					else
						fprintf(newBlock, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, check.age, check.phone_num, check.email, check.block_area, check.room_num, check.laundry_service, check.gym_service, check.week_stay, check.amount_due, check.paid_amount, check.bed_num);
				}
				fclose(newBlock);
				fclose(block);
				printf("\n\n\n\t*******    CONGRATULATIONS YOU HAVE SUCCESSFULLY CHANGED    *******\n\n");
				printf("\t*******                  PLEASE LOGIN AGAIN                   *******\n");
				_sleep(2000);
				printf("\tPLEASE NOTE THAT A FINE OF RM 200 WILL BE CHARGED, PLEASE PAY THE ADMIN !");
				_sleep(3000);
				system("CLS");
				break;
			case 3:
			case 4:
				printf("\tSORRY TO INFORM YOU THAT, BLOCK A3 AND A4 IS TEMPORARILY UNAVAILABLE, ");
				printf("PLEASE CHOOSE ANOTHER BLOCK");
				_sleep(4000);
				goto choose_block;
				break;
			default:
				printf("\tPLEASE ENTER A VALID OPTION");
				_sleep(4000);
				goto choose_block;
			}
		}
		else if (strcmp(strupr(apply.studentID), check.studentID) == 0 && check.gender[0] == 'F') {
			fclose(block);
			int new_block_type, new_room_num, new_rental, new_laundry, new_gym, new_total_due, i, new_week_stay, b1_room_count, b3_room_count;
			char block_area[3];
			FILE *block;
			b1_room_count = b1_room_available();
			b3_room_count = b3_room_available();
		female_choose_block:
			system("CLS");
			printf("\t\t\t\t************************\n\t\t\t\t|         MENU         |\n");
			printf("\t\t\t\t************************\n\n");
			printf("\t------------------------------------------------------------------------------\n");
			printf("\t| BLOCK |  GENDER  |  AVAILABILITY  |   TYPE   |  RENTALS  | LAUNDRY  | GYM  |\n");
			printf("\t------------------------------------------------------------------------------\n");
			printf("\t|  B 1  |  FEMALE  |       %3d      |  SINGLE  |   RM400   |   RM20   | RM10 |\n", b1_room_count);
			printf("\t|  B 2  |  FEMALE  |   UNAVAILABLE  |  2-BEDS  |   RM200   |   RM20   | RM10 |\n");
			printf("\t|  B 3  |  FEMALE  |       %3d      |  3-BEDS  |   RM150   |   RM20   | RM10 |\n", b3_room_count);
			printf("\t|  B 4  |  FEMALE  |   UNAVAILABLE  |  4-BEDS  |   RM100   |   RM20   | RM10 |\n");
			printf("\t------------------------------------------------------------------------------\n\n");
			printf("\t1) BLOCK B1 , SINGLE BEDDED ROOM , RM400 WEEKLY\n");
			printf("\t2) BLOCK B2 , DOUBLE BEDDED ROOM , RM200 WEEKLY\n");
			printf("\t3) BLOCK B3 ,  THREE BEDDED ROOM , RM150 WEEKLY\n");
			printf("\t4) BLOCK B4 ,   FOUR BEDDED ROOM , RM100 WEEKLY\n\n");
			printf("\tPLEASE CHOOSE THE BLOCK YOU DESIRE (1 - 4): ");
			scanf("%d", &new_block_type);
			switch (new_block_type) {
			case 1:
				new_rental = 400;
				strcpy(apply.block_area, "B1");
				new_room_num = b1room_visuals();
				system("CLS");
				new_laundry = laundry_calculation();
				new_gym = gym_calculation();
				printf("\tHOW MANY WEEKS WOULD YOU LIKE TO STAY?");
				scanf("%d", &new_week_stay);
				apply.paid_amount = 0;
				new_total_due = personal_due(new_rental, new_gym, new_laundry, new_week_stay, apply.paid_amount);
				apply.room_num = new_room_num, apply.laundry_service = new_laundry, apply.gym_service = new_gym, apply.week_stay = new_week_stay, apply.amount_due = new_total_due, apply.bed_num = 0;
				block = fopen("Student.txt", "r");
				newBlock = fopen("NewStudent.txt", "w+");
				while (fscanf(block, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, &check.age, check.phone_num, check.email, check.block_area, &check.room_num, &check.laundry_service, &check.gym_service, &check.week_stay, &check.amount_due, &check.paid_amount, &check.bed_num) != EOF) {
					if (strcmp(strupr(apply.studentID), check.studentID) == 0)
						fprintf(newBlock, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, check.age, check.phone_num, check.email, apply.block_area, apply.room_num, apply.laundry_service, apply.gym_service, apply.week_stay, apply.amount_due, apply.paid_amount, apply.bed_num);
					else
						fprintf(newBlock, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, check.age, check.phone_num, check.email, check.block_area, check.room_num, check.laundry_service, check.gym_service, check.week_stay, check.amount_due, check.paid_amount, check.bed_num);
				}
				fclose(newBlock);
				fclose(block);
				printf("\n\n\n\t*******    CONGRATULATIONS YOU HAVE SUCCESSFULLY CHANGED    *******\n\n");
				printf("\t*******                  PLEASE LOGIN AGAIN                   *******\n");
				_sleep(2000);
				printf("\tPLEASE NOTE THAT A FINE OF RM 200 WILL BE CHARGED, PLEASE PAY THE ADMIN !");
				_sleep(3000);
				system("CLS");
				break;
			case 3:
				new_rental = 150;
				strcpy(apply.block_area, "B3");
				new_room_num = b3room_visuals();
				system("CLS");
				new_laundry = laundry_calculation();
				new_gym = gym_calculation();
				printf("\tHOW MANY WEEKS WOULD YOU LIKE TO STAY?");
				scanf("%d", &new_week_stay);
				apply.paid_amount = 0;
				new_total_due = personal_due(new_rental, new_gym, new_laundry, new_week_stay, apply.paid_amount);
				apply.room_num = new_room_num, apply.laundry_service = new_laundry, apply.gym_service = new_gym, apply.week_stay = new_week_stay, apply.amount_due = new_total_due;
				block = fopen("Student.txt", "r");
				newBlock = fopen("NewStudent.txt", "w+");
				while (fscanf(block, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, &check.age, check.phone_num, check.email, check.block_area, &check.room_num, &check.laundry_service, &check.gym_service, &check.week_stay, &check.amount_due, &check.paid_amount, &check.bed_num) != EOF) {
					if (strcmp(strupr(apply.studentID), check.studentID) == 0)
						fprintf(newBlock, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, check.age, check.phone_num, check.email, apply.block_area, apply.room_num, apply.laundry_service, apply.gym_service, apply.week_stay, apply.amount_due, apply.paid_amount, apply.bed_num);
					else
						fprintf(newBlock, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, check.age, check.phone_num, check.email, check.block_area, check.room_num, check.laundry_service, check.gym_service, check.week_stay, check.amount_due, check.paid_amount, check.bed_num);
				}
				fclose(newBlock);
				fclose(block);
				printf("\n\n\n\t*******    CONGRATULATIONS YOU HAVE SUCCESSFULLY CHANGED    *******\n\n");
				printf("\t*******                  PLEASE LOGIN AGAIN                   *******\n");
				_sleep(2000);
				printf("\tPLEASE NOTE THAT A FINE OF RM 200 WILL BE CHARGED, PLEASE PAY THE ADMIN !");
				_sleep(3000);
				system("CLS");
				break;
			case 2:
			case 4:
				printf("\tSORRY TO INFORM YOU THAT, BLOCK B2 AND B4 IS TEMPORARILY UNAVAILABLE, ");
				printf("PLEASE CHOOSE ANOTHER BLOCK");
				_sleep(4000);
				goto female_choose_block;
				break;
			default:
				printf("\tPLEASE ENTER A VALID OPTION");
				_sleep(4000);
				goto female_choose_block;
			}
		}
}

/* FUNCTION IS CALLED FOR CANCELING ROOM BOOKINGS, AND DELETING DETAILS OF HOSTELER*/
/* FUNCTION READS FROM Student.txt AND CHECK FOR THE HOSTELER WHO WANTS TO CANCEL BOOKING*/
/* UPON CHECKING IF STUDENT DETAILS IS NOT THE HOSTELER WHO WANTS TO CANCEL, IT WILL BE WRITTEN IN A NewStudent.txt*/
/* AFTER ITS DONE, Student.txt WILL THEN BE DELETED AND NewStudent.txt WILL BE RENAMED TO Student.txt*/


/* THIS FUNCTION IS CALLED IN THE SOURCE FILE student_login.c*/

void cancel_room() {
	FILE *block, *newBlock;
	char cancel_choice;
cancel_menu:
	getchar();
	printf("\tARE YOU SURE YOU WANTED TO CANCEL THE ROOM? YES(Y) OR NO(N):");
	scanf("%c", &cancel_choice);
	switch (cancel_choice) {
	case 'Y':
	case 'y':
		block = fopen("Student.txt", "r");
		newBlock = fopen("NewStudent.txt", "w");
		while (fscanf(block, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, &check.age, check.phone_num, check.email, check.block_area, &check.room_num, &check.laundry_service, &check.gym_service, &check.week_stay, &check.amount_due, &check.paid_amount, &check.bed_num) != EOF) {
			if (strcmp(strupr(apply.studentID), check.studentID) == 0)
				continue;
			else
				fprintf(newBlock, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, check.age, check.phone_num, check.email, check.block_area, check.room_num, check.laundry_service, check.gym_service, check.week_stay, check.amount_due, check.paid_amount, check.bed_num);
		}
		fclose(block); fclose(newBlock);
		remove("Student.txt"); rename("NewStudent.txt", "Student.txt");
		printf("\n\n\t****    WE HAVE SUCCESSFULLY CANCELLED YOUR ROOM!    ****\n");
		_sleep(2000);
		printf("\t**      HOPE TO SEE YOU AGAIN SOON IN THE FUTURE       **\n");
		_sleep(2000);
		printf("\tPLEASE NOTE THAT A FINE OF RM 300 WILL BE CHARGED, PLEASE PAY THE ADMIN !");
		_sleep(3000);
		system("CLS");
	case 'N':
	case 'n':
		printf("\tREDIRECTING TO THE LOGIN MENU, PLEASE HOLD !");
		_sleep(2000);
		system("CLS");
		return;
		break;
	default:
		printf("PLEASE ENTER A VALID OPTION !");
		_sleep(2000);
		system("CLS");
		goto cancel_menu;
	}
}