#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "total_function.h"

/* BELOW 4 FUNCTIONS IS USED FOR CALCULATING AVAILABLE ROOM FOR DIFFERENT BLOCKS (A1, A2, B1, B3) */

/* FUCTION IS CALLED IN booking_menu.c, change_room.c, check_room_available.c*/

int a1_room_available() {
	int i, occupied_room = 0, available_room;
	for (i = 0; i < 100; i++) {
		if (block_a1[i] == 1)
			occupied_room++;
	}
	available_room = 100 - occupied_room;
	return available_room;
}


int a2_room_available() {
	int i, occupied_room = 0, available_room;
	for (i = 0; i < 100; i++) {
		if (block_a2[i][0] && block_a2[i][1] == 1)
			occupied_room++;
	}
	available_room = 100 - occupied_room;
	return available_room;
}

int b1_room_available() {
	int i, occupied_room = 0, available_room;
	for (i = 0; i < 100; i++) {
		if (block_b1[i] == 1)
			occupied_room++;
	}
	available_room = 100 - occupied_room;
	return available_room;
}

int b3_room_available() {
	int i, occupied_room = 0, available_room;
	for (i = 0; i < 100; i++) {
		if (block_b3[i][0] && block_b3[i][1] && block_b3[i][2] == 1)
			occupied_room++;
	}
	available_room = 100 - occupied_room;
	return available_room;
}
