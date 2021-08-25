#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "total_function.h"

/* THIS FUNCTION OPENS Student.txt FOR READING, TO CHECK PREVIOUS BOOKINGS RECORDED IN TEXT FILE AND THEN REASSIGN IT INTO THE ARRAY*/
/* THIS FUNCTION IS INCLUDED IN THE MAIN SOURCE FILE hostel_management_system.c */

void reassign_previous_booking() {
	FILE *block;
	char blocktype_a1[3], blocktype_a2[3], blocktype_b1[3], blocktype_b3[3];
	strcpy(blocktype_a1, "A1");
	strcpy(blocktype_a2, "A2");
	strcpy(blocktype_b1, "B1");
	strcpy(blocktype_b3, "B3");
	block = fopen("Student.txt", "r");
	while (fscanf(block, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", check.studentID, check.firstName, check.lastName, check.gender, check.identification, &check.age, check.phone_num, check.email, check.block_area, &check.room_num, &check.laundry_service, &check.gym_service, &check.week_stay, &check.amount_due, &check.paid_amount, &check.bed_num) != EOF) {
		if (strcmp(check.block_area, blocktype_a1) == 0)
			block_a1[check.room_num] = 1;
		else if (strcmp(check.block_area, blocktype_a2) == 0)
			block_a2[check.room_num][check.bed_num] = 1;
		else if (strcmp(check.block_area, blocktype_b1) == 0)
			block_b1[check.room_num] = 1;
		else if (strcmp(check.block_area, blocktype_b3) == 0)
			block_b3[check.room_num][check.bed_num] = 1;
	}
	fclose(block);
}