#include <stdio.h>
//The main menu of the system

void mmainMenu() {
	int BlockA1 = 99, BlockA2 = 70;
	FILE *block;

	printf("\t\t\t==============\n\t\t\t|         Menu         |\n\t\t\t===============\n");
	printf("----------------------------------------------------------------------------\n");
	printf("| Block |  Gender  |  Availability  |   Type   |  Rentals  | Laundry  | Gym  | \n");
	printf("----------------------------------------------------------------------------\n");
	printf("|  A 1  |   Male   |    Available   |  Single  |   RM400   |   RM20   | RM10 |\n");
	printf("|  A 2  |   Male   |    Available   |  2-beds  |   RM200   |   RM20   | RM10 |\n");
	printf("|  A 3  |   Male   |   Unavailable  |  Single  |   RM150   |   RM20   | RM10 |\n");
	printf("|  A 4  |   Male   |   Unavailable  |  3-beds  |   RM100   |   RM20   | RM10 |\n");
	printf("----------------------------------------------------------------------------\n");
	printf("What would you like to do?\n\n1. Booking a room\n2. Make a room cancellation\n3. Changing rooms\n4. Checking Room Details\n5. Make a payment");
	printf("\nPlease enter a choice!\n");

}

