#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "total_function.h"

/*      ******************************************************
        | WELCOME TO WISDOM COLLEGE HOSTEL MANAGEMENT SYSTEM |
        ******************************************************

        PLEASE PROCEED TO FOLLOWING CHOICES :
        1) STUDENT REGISTER
        2) STUDENT LOGIN
        3) ADMIN LOGIN
        4) EXIT

        PLEASE ENTER A CHOICE (1-4):
*/

/* THIS IS THE MAIN SOURCE FILE AND THE MAIN FUNCTION */

int main() {
main_menu:
	check_file_created();
	initialize_block();
	reassign_previous_booking();
	int choice, check_register,check_login;
	printf("\t******************************************************\n");
	printf("\t| WELCOME TO WISDOM COLLEGE HOSTEL MANAGEMENT SYSTEM |\n");
	printf("\t******************************************************\n\n");
	printf("\tPLEASE PROCEED TO FOLLOWING CHOICES :\n");
	printf("\t1) STUDENT REGISTER \n\t2) STUDENT LOGIN\n\t3) ADMIN LOGIN \n\t4) EXIT\n\n");
	printf("\tPLEASE ENTER A CHOICE (1-4): ");
	scanf("%d", &choice);
	switch (choice) {
	    case 1:
			check_register = student_registration();
			if (apply.gender[0] == 'M' && check_register == 1) {
				male_booking_menu();
				goto main_menu;
			}
			else if (apply.gender[0] == 'F' && check_register == 1) {
				female_booking_menu();
				goto main_menu;
				}
			else
				goto main_menu;
			break;
		case 2:
			student_login();
			goto main_menu;
			break;
		case 3:
			admin_login();
			goto main_menu;
			break;
		case 4:
			exitProgram();
			break;
		default:
			goto main_menu;
	}
	return 0;
}

