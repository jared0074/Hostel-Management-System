#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "total_function.h"

/* THIS FUNCTION IS TO ADD 0s INSIDE ARRAY AS ROOMS AND BEDS IN BLOCK A1, A2, B1, B3 AND WILL THEN BE USED TO PROVIDE VISUALS*/
/* PURPOSE OF 0 IS TO REPRESENT ROOM IS AVAILABLE AND LATER ON IF A STUDENT CHOSE THE ROOM THE 0 WILL TURN INTO 1 WHICH REPRESENT THEY BOOKED THE ROOM*/
/* THIS FUNCTION IS INCLUDED IN THE MAIN SOURCE FILE WHICH IS hostel_management_menu.c*/

void initialize_block() {
	int i;
	for (i = 0; i < 100; i++) {
		block_a1[i] = 0;
		block_a2[i][0] = 0;
		block_a2[i][1] = 0;
		block_b1[i] = 0;
		block_b3[i][0] = 0;
		block_b3[i][1] = 0;
		block_b3[i][2] = 0;

	}
}