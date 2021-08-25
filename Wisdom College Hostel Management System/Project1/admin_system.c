#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "total_function.h"

/****************************************************
 |             WELCOME TO ADMIN SYSTEM              |
 ****************************************************

 1) CHECK OVERALL DETAILS
 2) SEARCH FOR STUDENT DETAILS
 3) CHECK BLOCK ROOM AVAILABILITY
 4) EXIT TO MAIN MENU

 WHAT WOULD YOU LIKE TO DO ? (1-4):
 */

/* THIS FUNCTION IS USED FOR ADMIN TO CHOOSE CHOICES*/
/* CHOICE 1 : IS TO CHECK OVERALL DETAILS LIKE TOTAL ROOM AVAILABLE, TOTAL AMOUNT RECEIVABLE, TOTAL PAYMENT MADE, TOTAL HOSTELER*/
/* CHOICE 2 : SEARCH FOR HOSTELER DETAILS WITH THEIR STUDENT ID*/
/* CHOICE 3 : CHECK AVAILABLE ROOM BASED ON BLOCK AND PROVIDE VISUAL TO KNOW WHICH ROOM IS OCCUPIED */
/* CHOICE 4 : EXIT TO THE MAIN HOSTEL MANAGEMENT SYSTEM*/

/* THIS FUNCTION IS USED INSIDE THE SOURCE FILE WHICH IS admin_login.c*/

void admin_system() {
	int admin_choice;
	system("CLS");
admin_system_menu:
	printf("\t****************************************************\n");
	printf("\t|             WELCOME TO ADMIN SYSTEM              |\n");
	printf("\t****************************************************\n\n");
	printf("\t1) CHECK OVERALL DETAILS\n\t");
	printf("2) SEARCH FOR STUDENT DETAILS\n\t3) CHECK BLOCK ROOM AVAILABILITY\n\t4) EXIT TO MAIN MENU\n\tWHAT WOULD YOU LIKE TO DO ? (1-4): ");
	scanf("%d", &admin_choice);
	switch (admin_choice) {
	case 1:
		check_r_available_and_m_receivables();
		goto admin_system_menu;
		break;
	case 2:
		search_student();
		goto admin_system_menu;
		break;
	case 3:
		check_room_availability();
		goto admin_system_menu;
		break;
	case 4:
		printf("\n\n\tREDIRECTING TO THE HOSTEL MANAGEMENT SYSTEM, PLEASE HOLD !");
		_sleep(2000);
		system("CLS");
		break;
	default:
		printf("PLEASE ENTER A VALID OPTION !");
		_sleep(2000);
		system("CLS");
		goto admin_system_menu;
	}

}