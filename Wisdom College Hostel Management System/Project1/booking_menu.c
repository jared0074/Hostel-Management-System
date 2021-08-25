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

        PLEASE CHOOSE THE BLOCK YOU DESIRE (1 - 4):
*/

/* THIS FUNCTION IS CALLED FOR MALE STUDENTS TO PICK THE BLOCK THEY WANT TO STAY IN*/
/* ROOM AVAILABILITY PRICING AND TYPE WILL BE PROVIDED AS SHOWN ABOVE FOR THEM TO CHOOSE EASILY*/

/* THIS FUNCTION IS INCLUDED IN THE MAIN SOURCE FILE hostel_management_system.c */

void male_booking_menu() {
	int block_type, room_num, rental, laundry, gym, total_due, i, week_stay, a1_room_count, a2_room_count;
	char block_area[3];
	FILE *block;
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
	printf("\tPLEASE CHOOSE THE BLOCK YOU DESIRE (1 - 4): ");
	scanf("%d", &block_type);
	switch (block_type) {
	case 1:
		rental = 400;
		strcpy(apply.block_area, "A1");
		room_num = a1room_visuals();
		system("CLS");
		laundry = laundry_calculation();
		gym = gym_calculation();
		printf("\tHOW MANY WEEKS WOULD YOU LIKE TO STAY?");
		scanf("%d", &week_stay);
		apply.paid_amount = 0;
		total_due = personal_due(rental, gym, laundry, week_stay, apply.paid_amount);
		apply.room_num = room_num, apply.laundry_service = laundry, apply.gym_service = gym, apply.week_stay = week_stay, apply.amount_due = total_due, apply.bed_num = 0;
		block = fopen("Student.txt", "a+");
		fprintf(block, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(apply.studentID), apply.firstName, apply.lastName, apply.gender, apply.identification, apply.age, apply.phone_num, apply.email, apply.block_area, apply.room_num, apply.laundry_service, apply.gym_service, apply.week_stay, apply.amount_due, apply.paid_amount, apply.bed_num);
		fclose(block);
		printf("\n\n\n\t*******    CONGRATULATIONS YOU HAVE SUCCESSFULLY REGISTERED    *******\n\n");
		printf("\t*******               PLEASE PROCEED TO LOGIN                  *******\n");
		_sleep(2000);
		system("CLS");
		break;
	case 2:
		rental = 200;
		strcpy(apply.block_area, "A2");
		room_num = a2room_visuals();
		system("CLS");
		laundry = laundry_calculation();
		gym = gym_calculation();
		printf("\tHOW MANY WEEKS WOULD YOU LIKE TO STAY?");
		scanf("%d", &week_stay);
		apply.paid_amount = 0;
		total_due = personal_due(rental, gym, laundry, week_stay, apply.paid_amount);
		apply.room_num = room_num, apply.laundry_service = laundry, apply.gym_service = gym, apply.week_stay = week_stay, apply.amount_due = total_due;
		block = fopen("Student.txt", "a+");
		fprintf(block, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(apply.studentID), apply.firstName, apply.lastName, apply.gender, apply.identification, apply.age, apply.phone_num, apply.email, apply.block_area, apply.room_num, apply.laundry_service, apply.gym_service, apply.week_stay, apply.amount_due, apply.paid_amount, apply.bed_num);
		fclose(block);
		printf("\n\n\n\t*******    CONGRATULATIONS YOU HAVE SUCCESSFULLY REGISTERED    *******\n\n");
		printf("\t*******               PLEASE PROCEED TO LOGIN                  *******\n");
		_sleep(2000);
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

/*                              ************************
                                |         MENU         |
                                ************************

        ------------------------------------------------------------------------------
        | BLOCK |  GENDER  |  AVAILABILITY  |   TYPE   |  RENTALS  | LAUNDRY  | GYM  |
        ------------------------------------------------------------------------------
        |  B 1  |  FEMALE  |        99      |  SINGLE  |   RM400   |   RM20   | RM10 |
        |  B 2  |  FEMALE  |   UNAVAILABLE  |  2-BEDS  |   RM200   |   RM20   | RM10 |
        |  B 3  |  FEMALE  |       100      |  3-BEDS  |   RM150   |   RM20   | RM10 |
        |  B 4  |  FEMALE  |   UNAVAILABLE  |  4-BEDS  |   RM100   |   RM20   | RM10 |
        ------------------------------------------------------------------------------

        1) BLOCK B1 , SINGLE BEDDED ROOM , RM400 WEEKLY
        2) BLOCK B2 , DOUBLE BEDDED ROOM , RM200 WEEKLY
        3) BLOCK B3 ,  THREE BEDDED ROOM , RM150 WEEKLY
        4) BLOCK B4 ,   FOUR BEDDED ROOM , RM100 WEEKLY

        PLEASE CHOOSE THE BLOCK YOU DESIRE (1 - 4):

*/

/* THIS FUNCTION IS CALLED FOR FEMALE STUDENTS TO PICK THE BLOCK THEY WANT TO STAY IN*/
/* ROOM AVAILABILITY PRICING AND TYPE WILL BE PROVIDED AS SHOWN ABOVE FOR THEM TO CHOOSE EASILY*/

/* THIS FUNCTION IS INCLUDED IN THE MAIN SOURCE FILE hostel_management_system.c */

void female_booking_menu() {
	int block_type, room_num, rental, laundry, gym, total_due, i, week_stay, b1_room_count, b3_room_count;
	char block_area[3];
	FILE *block;
	b1_room_count = b1_room_available();
	b3_room_count = b3_room_available();
choose_block:
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
	scanf("%d", &block_type);
	switch (block_type) {
	case 1:
		rental = 400;
		strcpy(apply.block_area, "B1");
		room_num = b1room_visuals();
		system("CLS");
		laundry = laundry_calculation();
		gym = gym_calculation();
		printf("\tHOW MANY WEEKS WOULD YOU LIKE TO STAY? : ");
		scanf("%d", &week_stay);
		apply.paid_amount = 0;
		total_due = personal_due(rental, gym, laundry, week_stay, apply.paid_amount);
		apply.room_num = room_num, apply.laundry_service = laundry, apply.gym_service = gym, apply.week_stay = week_stay, apply.amount_due = total_due, apply.bed_num = 0;
		block = fopen("Student.txt", "a+");
		fprintf(block, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(apply.studentID), apply.firstName, apply.lastName, apply.gender, apply.identification, apply.age, apply.phone_num, apply.email, apply.block_area, apply.room_num, apply.laundry_service, apply.gym_service, apply.week_stay, apply.amount_due, apply.paid_amount, apply.bed_num);
		fclose(block);
		printf("\n\n\n\t*******    CONGRATULATIONS YOU HAVE SUCCESSFULLY REGISTERED    *******\n\n");
		printf("\t*******               PLEASE PROCEED TO LOGIN                  *******\n");
		_sleep(2000);
		system("CLS");
		break;
	case 3:
		rental = 150;
		strcpy(apply.block_area, "B3");
		room_num = b3room_visuals();
		system("CLS");
		laundry = laundry_calculation();
		gym = gym_calculation();
		printf("\tHOW MANY WEEKS WOULD YOU LIKE TO STAY?");
		scanf("%d", &week_stay);
		apply.paid_amount = 0;
		total_due = personal_due(rental, gym, laundry, week_stay, apply.paid_amount);
		apply.room_num = room_num, apply.laundry_service = laundry, apply.gym_service = gym, apply.week_stay = week_stay, apply.amount_due = total_due;
		block = fopen("Student.txt", "a+");
		fprintf(block, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(apply.studentID), apply.firstName, apply.lastName, apply.gender, apply.identification, apply.age, apply.phone_num, apply.email, apply.block_area, apply.room_num, apply.laundry_service, apply.gym_service, apply.week_stay, apply.amount_due, apply.paid_amount, apply.bed_num);
		fclose(block);
		printf("\n\n\n\t*******    CONGRATULATIONS YOU HAVE SUCCESSFULLY REGISTERED    *******\n\n");
		printf("\t*******               PLEASE PROCEED TO LOGIN                  *******\n");
		_sleep(2000);
		system("CLS");
		break;
	case 2:
	case 4:
		printf("\tSORRY TO INFORM YOU THAT, BLOCK B2 AND B4 IS TEMPORARILY UNAVAILABLE, ");
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