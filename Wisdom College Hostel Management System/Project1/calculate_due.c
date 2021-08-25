#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "total_function.h"

/*FUCTION IS USED TO CALCULATE THE PERSONAL AMOUNT DUE*/

/* THIS FUNCTION IS CALLED IN THE SOURCE FILE add_menu.c, booking_menu.c, change_room.c*/

int personal_due(int rental, int gym, int laundry, int week_stay, int paid_amount) {
	int total_personal_amount;
	total_personal_amount = rental + gym + laundry;
	total_personal_amount = (total_personal_amount * week_stay) - paid_amount;
	return total_personal_amount;
}
