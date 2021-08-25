#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "total_function.h"

/*FUNCTION FOR ADDING ADDITIONAL SERVICE SUBSCRIPTION OR UNSUBSCRIBE ADDITIONAL SERVICE*/

void add_service() {
	FILE *block, *newBlock;
	int new_laundry, new_personal_due, rental, new_gym;
	char add_choice;
	getchar();
add_menu:
	printf("\tWHICH SERVICE WOULD YOU LIKE TO ADD ON OR CANCEL ? LAUNDRY(L) OR GYM(G) : ");
	scanf("%c", &add_choice);
	switch (add_choice) {
	case 'L':
	case 'l':
		system("CLS");
		block = fopen("Student.txt", "r");
		newBlock = fopen("NewStudent.txt", "w");
		while (fscanf(block, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, &check.age, check.phone_num, check.email, check.block_area, &check.room_num, &check.laundry_service, &check.gym_service, &check.week_stay, &check.amount_due, &check.paid_amount, &check.bed_num) != EOF) {
			if (strcmp(strupr(apply.studentID), check.studentID) == 0 && check.laundry_service == 0) {
				printf("\tSUBSCRIPTION MENU :\n\n");
				new_laundry = laundry_calculation();
				if (check.block_area[0] == 'A' && check.block_area[1] == '1')
					rental = 400;
				else if (check.block_area[0] == 'A' && check.block_area[1] == '2')
					rental = 200;
				else if (check.block_area[0] == 'B' && check.block_area[1] == '1')
					rental = 400;
				else
					rental = 150;
				new_personal_due = personal_due(rental, check.gym_service, new_laundry, check.week_stay, check.paid_amount);
				if (new_laundry == 20) {
					fprintf(newBlock, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, check.age, check.phone_num, check.email, check.block_area, check.room_num, new_laundry, check.gym_service, check.week_stay, new_personal_due, check.paid_amount, check.bed_num);
					printf("\n\n\t***      SUCCESSFULLY SUBSCRIBE TO THE LAUNDRY SERVICE       ***\n");
					_sleep(2000);
					printf("\t***        REDIRECTING TO THE MAIN MENU, PLEASE HOLD !       ***\n");
					_sleep(2000);
					system("CLS");
				}
				else {
					printf("\n\n\t***     YOU DIDN'T SUBSCRIBE TO THE LAUNDRY SERVICE !    ***\n");
					_sleep(2000);
					printf("\t***      REDIRECTING TO THE MAIN MENU, PLEASE HOLD !     ***\n");
					_sleep(2000);
					system("CLS");
					fprintf(newBlock, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, check.age, check.phone_num, check.email, check.block_area, check.room_num, check.laundry_service, check.gym_service, check.week_stay, check.amount_due, check.paid_amount, check.bed_num);
				}
			}
			else if (strcmp(apply.studentID, check.studentID) == 0 && check.laundry_service == 20) {
				printf("\tUNSUBSCRIPTION MENU :\n\n");
				new_laundry = laundry_calculation();
				if (check.block_area[0] == 'A' && check.block_area[1] == '1')
					rental = 400;
				else if (check.block_area[0] == 'A' && check.block_area[1] == '2')
					rental = 200;
				else if (check.block_area[0] == 'B' && check.block_area[1] == '1')
					rental = 400;
				else
					rental = 150;
				new_personal_due = personal_due(rental, check.gym_service, new_laundry, check.week_stay, check.paid_amount);
				if (new_laundry == 0) {
					fprintf(newBlock, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, check.age, check.phone_num, check.email, check.block_area, check.room_num, new_laundry, check.gym_service, check.week_stay, new_personal_due, check.paid_amount, check.bed_num);
					printf("\n\n\t***     SUCCESSFULLY UNSUBSCRIBE TO THE LAUNDRY SERVICE      ***\n");
					_sleep(2000);
					printf("\t***        REDIRECTING TO THE MAIN MENU, PLEASE HOLD !       ***\n");
					_sleep(2000);
					system("CLS");
				}
				else {
					printf("\n\n\t***    YOU DIDN'T UNSUBSCRIBE TO THE LAUNDRY SERVICE !   ***\n");
					_sleep(2000);
					printf("\t***      REDIRECTING TO THE MAIN MENU, PLEASE HOLD !     ***\n");
					_sleep(2000);
					system("CLS");
					fprintf(newBlock, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, check.age, check.phone_num, check.email, check.block_area, check.room_num, check.laundry_service, check.gym_service, check.week_stay, check.amount_due, check.paid_amount, check.bed_num);
				}
			}
			else
				fprintf(newBlock, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, check.age, check.phone_num, check.email, check.block_area, check.room_num, check.laundry_service, check.gym_service, check.week_stay, check.amount_due, check.paid_amount, check.bed_num);
		}
		fclose(block); fclose(newBlock);
		remove("Student.txt"); rename("NewStudent.txt", "Student.txt");
		break;
	case 'G':
	case 'g':
		system("CLS");
		block = fopen("Student.txt", "r");
		newBlock = fopen("NewStudent.txt", "w");
		while (fscanf(block, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, &check.age, check.phone_num, check.email, check.block_area, &check.room_num, &check.laundry_service, &check.gym_service, &check.week_stay, &check.amount_due, &check.paid_amount, &check.bed_num) != EOF) {
			if (strcmp(strupr(apply.studentID), check.studentID) == 0 && check.gym_service == 0) {
				printf("\tSUBSCRIPTION MENU :\n\n");
				new_gym = gym_calculation();
				if (check.block_area[0] == 'A' && check.block_area[1] == '1')
					rental = 400;
				else if (check.block_area[0] == 'A' && check.block_area[1] == '2')
					rental = 200;
				else if (check.block_area[0] == 'B' && check.block_area[1] == '1')
					rental = 400;
				else
					rental = 150;
				new_personal_due = personal_due(rental, new_gym, check.laundry_service, check.week_stay, check.paid_amount);
				if (new_gym == 10) {
					fprintf(newBlock, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, check.age, check.phone_num, check.email, check.block_area, check.room_num, check.laundry_service, new_gym, check.week_stay, new_personal_due, check.paid_amount, check.bed_num);
					printf("\n\n\t***        SUCCESSFULLY SUBSCRIBE TO THE GYM SERVICE         ***\n");
					_sleep(2000);
					printf("\t***        REDIRECTING TO THE MAIN MENU, PLEASE HOLD !       ***\n");
					_sleep(2000);
					system("CLS");
				}
				else {
					printf("\n\n\t***       YOU DIDN'T SUBSCRIBE TO THE GYM SERVICE !      ***\n");
					_sleep(2000);
					printf("\t***      REDIRECTING TO THE MAIN MENU, PLEASE HOLD !     ***\n");
					_sleep(2000);
					system("CLS");
					fprintf(newBlock, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, check.age, check.phone_num, check.email, check.block_area, check.room_num, check.laundry_service, check.gym_service, check.week_stay, check.amount_due, check.paid_amount, check.bed_num);
				}
			}
			else if (strcmp(apply.studentID, check.studentID) == 0 && check.gym_service == 10) {
				printf("\tUNSUBSCRIPTION MENU :\n\n");
				new_gym = gym_calculation();
				if (check.block_area[0] == 'A' && check.block_area[1] == '1')
					rental = 400;
				else if (check.block_area[0] == 'A' && check.block_area[1] == '2')
					rental = 200;
				else if (check.block_area[0] == 'B' && check.block_area[1] == '1')
					rental = 400;
				else
					rental = 150;
				new_personal_due = personal_due(rental, new_gym, check.laundry_service, check.week_stay, check.paid_amount);
				if (new_gym == 0) {
					fprintf(newBlock, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, check.age, check.phone_num, check.email, check.block_area, check.room_num, check.laundry_service, new_gym, check.week_stay, new_personal_due, check.paid_amount, check.bed_num);
					printf("\n\n\t***       SUCCESSFULLY UNSUBSCRIBE TO THE GYM SERVICE        ***\n");
					_sleep(2000);
					printf("\t***        REDIRECTING TO THE MAIN MENU, PLEASE HOLD !       ***\n");
					_sleep(2000);
					system("CLS");
				}
				else {
					printf("\n\n\t***      YOU DIDN'T UNSUBSCRIBE TO THE GYM SERVICE !     ***\n");
					_sleep(2000);
					printf("\t***      REDIRECTING TO THE MAIN MENU, PLEASE HOLD !     ***\n");
					_sleep(2000);
					system("CLS");
					fprintf(newBlock, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, check.age, check.phone_num, check.email, check.block_area, check.room_num, check.laundry_service, check.gym_service, check.week_stay, check.amount_due, check.paid_amount, check.bed_num);
				}
			}
			else
				fprintf(newBlock, "%s \t %s \t %s \t %s \t %s \t %d \t %s \t %s \t %s \t %d \t %d \t %d \t %d \t %d \t %d \t %d \n", strupr(check.studentID), check.firstName, check.lastName, check.gender, check.identification, check.age, check.phone_num, check.email, check.block_area, check.room_num, check.laundry_service, check.gym_service, check.week_stay, check.amount_due, check.paid_amount, check.bed_num);
		}
		fclose(block); fclose(newBlock);
		remove("Student.txt"); rename("NewStudent.txt", "Student.txt");
		break;
	default:
		printf("PLEASE ENTER A VALID OPTION !");
		_sleep(2000);
		system("CLS");
		goto add_menu;
	}
}
