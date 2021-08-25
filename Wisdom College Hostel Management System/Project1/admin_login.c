#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "total_function.h"

/* ADMIN PASSWORD IS AbcD1234 */

/****************************************************
 |                ADMIN LOGIN SYSTEM                |
 ****************************************************
 
 WOULD YOU LIKE TO: 1) PROCEED LOGIN 2) EXIT TO MAIN MENU
 WHAT WOULD YOU LIKE TO DO (1-2) : 1
 PLEASE KEY IN THE PASSWORD : AbcD1234


 ***     SUCCESSFULLY LOGIN INTO ADMIN SYSTEM     ***

 ***         REDIRECTING TO ADMIN SYSTEM!         ***
 */

/* ADMIN LOGIN FUNCTION IS CALLED TO ALLOW ADMIN TO HAVE AN OVERALL REVIEW AND SPECIAL STAFF FEATURES*/
/* AFTER ADMIN SUCCESSFULLY LOGIN, THEY WILL BE REDIRECTED TO ADMIN SYSTEM*/

/* THIS FUNCTION IS USED INSIDE THE MAIN SOURCE FILE WHICH IS hostel_management_menu.c*/

void admin_login() {
	int admin_choice;
	char password[10] = "AbcD1234", check_password[10];
admin_login_menu:
	system("CLS");
	printf("\t****************************************************\n");
	printf("\t|                ADMIN LOGIN SYSTEM                |\n");
	printf("\t****************************************************\n\n");
	printf("\tWOULD YOU LIKE TO: 1) PROCEED LOGIN 2) EXIT TO MAIN MENU\n");
	printf("\tWHAT WOULD YOU LIKE TO DO (1-2) : ");
	scanf("%d", &admin_choice);
	switch (admin_choice) {
	case 1:
		printf("\tPLEASE KEY IN THE PASSWORD : ");
		scanf("%s", check_password);
		if (strcmp(password, check_password) == 0) {
			printf("\n\n\t***     SUCCESSFULLY LOGIN INTO ADMIN SYSTEM     ***");
			_sleep(2000);
			printf("\n\t***         REDIRECTING TO ADMIN SYSTEM!         ***");
			_sleep(2000);
			system("CLS");
			admin_system();
		}
		else {
			printf("\t* SORRY WRONG PASSWORD, PLEASE ENTER CORRECT PASSWORD! *\n");
			_sleep(3000);
			printf("\n\t***       REDIRECTING TO ADMIN LOGIN SYSTEM  !       ***");
			_sleep(2000);
			system("CLS");
			goto admin_login_menu;
		}
		break;
	case 2:
		printf("\t****          RETURNING BACK TO MAIN MENU          ****\n");
		_sleep(3000);
		system("CLS");
		break;
	default:
		printf("PLEASE ENTER A VALID OPTION !");
		_sleep(2000);
		system("CLS");
		goto admin_login_menu;
	}
}