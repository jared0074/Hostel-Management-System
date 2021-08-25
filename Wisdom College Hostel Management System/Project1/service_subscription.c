#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "total_function.h"

/*****************************
 |      LAUNDRY    RM20      |
 *****************************

 WOULD YOU LIKE TO SUBSCRIBE TO LAUNDRY EXPENESES ?
 1) YES, I WOULD LIKE TO
 2) NO , I WOULD NOT
 PLEASE ENTER YOUR CHOICE (1 - 2):

 */

/*CHOICE 1: ADD LAUNDRY RM20 INTO THE DETAILS OF THE STUDENT AND IT WILL BE RECORDED IN Student.txt*/
/*CHOICE 2: ADD LAUNDRY RM0 INTO THE DETAILS OF THE STUDENT AND IT WILL BE RECORDED IN Student.txt*/

/* THIS FUNCTION IS CALLED IN THE SOURCE FILE add_menu.c, change_room.c*/

int laundry_calculation() {
	int laundry_choice, laundry;
laundry_subscription:
	printf("\t*****************************\n");
	printf("\t|      LAUNDRY    RM20      |\n");
	printf("\t*****************************\n\n");
	printf("\tWOULD YOU LIKE TO SUBSCRIBE TO LAUNDRY EXPENESES ? \n");
	printf("\t1) YES, I WOULD LIKE TO\n");
	printf("\t2) NO , I WOULD NOT \n");
	printf("\tPLEASE ENTER YOUR CHOICE (1 - 2): ");
	scanf("%d", &laundry_choice);
	switch (laundry_choice) {
	case 1:
		laundry = 20;
		return laundry;
		break;
	case 2:
		laundry = 0;
		return laundry;
		break;
	default:
		printf("\tPLEASE ENTER A VALID OPTION");
		_sleep(4000);
		goto laundry_subscription;
	}
}

/*****************************
 |        GYM    RM10        |
 *****************************
 
 WOULD YOU LIKE TO SUBSCRIBE TO LAUNDRY EXPENESES ?
 1) YES, I WOULD LIKE TO
 2) NO , I WOULD NOT
 PLEASE ENTER YOUR CHOICE (1 - 2):

 */

 /*CHOICE 1: ADD GYM RM20 INTO THE DETAILS OF THE STUDENT AND IT WILL BE RECORDED IN Student.txt*/
 /*CHOICE 2: ADD GYM RM0 INTO THE DETAILS OF THE STUDENT AND IT WILL BE RECORDED IN Student.txt*/

/* THIS FUNCTION IS CALLED IN THE SOURCE FILE add_menu.c, change_room.c*/

int gym_calculation() {
	int gym_choice, gym;
gym_subscription:
	printf("\t*****************************\n");
	printf("\t|        GYM    RM10        |\n");
	printf("\t*****************************\n\n");
	printf("\tWOULD YOU LIKE TO SUBSCRIBE TO GYM SERVICE ?\n ");
	printf("\t1) YES, I WOULD LIKE TO\n\t2) NO , I WOULD NOT\n");
	printf("\tPLEASE ENTER YOUR CHOICE (1 - 2): ");
	scanf("%d", &gym_choice);
	switch (gym_choice) {
	case 1:
		gym = 10;
		return gym;
		break;
	case 2:
		gym = 0;
		return gym;
		break;
	default:
		printf("\tPLEASE ENTER A VALID OPTION");
		_sleep(4000);
		goto gym_subscription;
	}
}

