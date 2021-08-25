#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "total_function.h"

/* 

        WHICH BLOCK WOULD YOU LIKE TO SEARCH ? (A1 , A2 , B1 , B3)
        PLEASE ENTER YOUR CHOICE : a1
        STUDENT ID: TP049952 FIRST NAME: JARED GENDER: M BLOCK: A1 ROOM: 1 IDETIFICATION: 990423076521 PHONE: 0134020303 EMAIL: jaredchan0074@gmail.com
        STUDENT ID: TP204357 FIRST NAME: ROBERT GENDER: M BLOCK: A1 ROOM: 96 IDETIFICATION: AK729302 PHONE: 0174338694 EMAIL: iron_man99@gmail.com


        PRESS ANYTHING TO EXIT :

*/

/* THIS FUNCTION IS CALLED FOR LISTING ALL THE DEATILS OF STUDENTS BASED ON BLOCK */
/* VISUALS SHOWN ABOVE IS FOR BLOCK A1*/

/* FUNCTION IS CALLED IN check_room_available.c*/

void check_block_student() {
	FILE *block;
	char check_block[3],check_choice;
	block = fopen("Student.txt", "r");
	printf("\tWHICH BLOCK WOULD YOU LIKE TO SEARCH ? (A1 , A2 , B1 , B3)\n");
	printf("\tPLEASE ENTER YOUR CHOICE : ");
	scanf("%s",check_block);
	if ((check_block[0] == 'A' || check_block[0] == 'a') && check_block[1] == '1') {
		while (fscanf(block, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, &check.age, check.phone_num, check.email, check.block_area, &check.room_num, &check.laundry_service, &check.gym_service, &check.week_stay, &check.amount_due, &check.paid_amount, &check.bed_num) != EOF) {
			if (check.block_area[0] == 'A' && check.block_area[1] == '1')
				printf("\tSTUDENT ID: %s FIRST NAME: %s GENDER: %s BLOCK: %s ROOM: %d IDETIFICATION: %s PHONE: %s EMAIL: %s AMOUNT RECEIVABLE: %d\n", check.studentID, strupr(check.firstName), check.gender, check.block_area, check.room_num, check.identification, check.phone_num, check.email, check.amount_due);
		}
	}
	else if ((check_block[0] == 'A' || check_block[0] == 'a') && check_block[1] == '2') {
		while (fscanf(block, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, &check.age, check.phone_num, check.email, check.block_area, &check.room_num, &check.laundry_service, &check.gym_service, &check.week_stay, &check.amount_due, &check.paid_amount, &check.bed_num) != EOF) {
			if (check.block_area[0] == 'A' && check.block_area[1] == '2')
				printf("\tSTUDENT ID: %s FIRST NAME: %s GENDER: %s BLOCK: %s ROOM: %d IDETIFICATION: %s PHONE: %s EMAIL: %s AMOUNT RECEIVABLE: %d\n", check.studentID, strupr(check.firstName), check.gender, check.block_area, check.room_num, check.identification, check.phone_num, check.email, check.amount_due);
		}
	}
	else if ((check_block[0] == 'B' || check_block[0] == 'b') && check_block[1] == '1') {
		while (fscanf(block, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, &check.age, check.phone_num, check.email, check.block_area, &check.room_num, &check.laundry_service, &check.gym_service, &check.week_stay, &check.amount_due, &check.paid_amount, &check.bed_num) != EOF) {
			if (check.block_area[0] == 'B' && check.block_area[1] == '1')
				printf("\tSTUDENT ID: %s FIRST NAME: %s GENDER: %s BLOCK: %s ROOM: %d IDETIFICATION: %s PHONE: %s EMAIL: %s AMOUNT RECEIVABLE: %d\n", check.studentID, strupr(check.firstName), check.gender, check.block_area, check.room_num, check.identification, check.phone_num, check.email, check.amount_due);
		}
	}
	else if ((check_block[0] == 'B' || check_block[0] == 'b') && check_block[1] == '3') {
		while (fscanf(block, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, &check.age, check.phone_num, check.email, check.block_area, &check.room_num, &check.laundry_service, &check.gym_service, &check.week_stay, &check.amount_due, &check.paid_amount, &check.bed_num) != EOF) {
			if (check.block_area[0] == 'B' && check.block_area[1] == '3')
				printf("\tSTUDENT ID: %s FIRST NAME: %s GENDER: %s BLOCK: %s ROOM: %d IDETIFICATION: %s PHONE: %s EMAIL: %s AMOUNT RECEIVABLE: %d\n", check.studentID, strupr(check.firstName), check.gender, check.block_area, check.room_num, check.identification, check.phone_num, check.email, check.amount_due);
		}
	}
	printf("\n\n\tPRESS ANYTHING TO EXIT : ");
	scanf("%c", &check_choice);
	fclose(block);
}