#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "total_function.h"
/*
        ******************************************************************************
        |                                  BLOCK A1                                  |
        ******************************************************************************
        A00  0  A01  1  A02  0  A03  0  A04  0  A05  0  A06  0  A07  0  A08  0  A09  0

        A10  0  A11  0  A12  0  A13  0  A14  0  A15  0  A16  0  A17  0  A18  0  A19  0

        A20  0  A21  0  A22  0  A23  0  A24  0  A25  0  A26  0  A27  0  A28  0  A29  0

        A30  0  A31  0  A32  0  A33  0  A34  0  A35  0  A36  0  A37  0  A38  0  A39  0

        A40  0  A41  0  A42  0  A43  0  A44  0  A45  0  A46  0  A47  0  A48  0  A49  0

        A50  0  A51  0  A52  0  A53  0  A54  0  A55  0  A56  0  A57  0  A58  0  A59  0

        A60  0  A61  0  A62  0  A63  0  A64  0  A65  0  A66  0  A67  0  A68  0  A69  0

        A70  0  A71  0  A72  0  A73  0  A74  0  A75  0  A76  0  A77  0  A78  0  A79  0

        A80  0  A81  0  A82  0  A83  0  A84  0  A85  0  A86  0  A87  0  A88  0  A89  0

        A90  0  A91  0  A92  0  A93  0  A94  0  A95  0  A96  1  A97  0  A98  0  A99  0

        ******************************************************************************
        |       0 MEANS AVAILABLE                           1 MEANS OCCUPIED         |
        ******************************************************************************

        YOU CAN NOW CHOOSE AVAILABLE ROOMS (0-99):
*/

/* ALL THE FUNCTION BELOW IS FOR VISUALISING EMPTY ROOM AND LETTING STUDENTS TO CHOOSE ROOM*/
/* VISUALS ABOVE IS FOR A1*/

/* FUNCTION IS CALLED IN booking_menu.c*/

int a1room_visuals() {
room_selection:
	int i, j, z = 0, x = 0, room_num;
	system("CLS");
	printf("\t******************************************************************************\n");
	printf("\t|                                  BLOCK A1                                  |\n");
	printf("\t******************************************************************************\n");
	for (i = 0; i < 10; i++) {
		printf("\t");
		for (j = 1; j < 11; j++) {
			printf("A%.2d ", z++);
			printf(" %d  ", block_a1[x++]);
		}
		printf("\n\n");
	}
	printf("\t******************************************************************************\n");
	printf("\t|       0 MEANS AVAILABLE                           1 MEANS OCCUPIED         |\n");
	printf("\t******************************************************************************\n\n");
	printf("\tYOU CAN NOW CHOOSE AVAILABLE ROOMS (0-99): ");
	scanf("%d", &room_num);
	if (block_a1[room_num] == 1) {
		printf("\tSORRY, THIS ROOM HAS BEEN OCUPIED, PLEASE CHOOSE ANOTHER ROOM");
		_sleep(2000);
		goto room_selection;
	}
	else if (block_a1[room_num] == 0)
		block_a1[room_num] = 1;
	else {
		printf("PLEASE ENTER A VALID OPTION !");
		goto room_selection;
	}
	return room_num;
}

int a2room_visuals() {
	char bed_choice;
room_selection:
	int i, j, z = 0, x = 0, room_num, bed_num;
	system("CLS");
	printf("\t******************************************************************************\n");
	printf("\t|                                  BLOCK A2                                  |\n");
	printf("\t******************************************************************************\n");
	for (i = 0; i < 20; i++) {
		printf("\t");
		for (j = 1; j < 6; j++) {
			printf(" A%.2d ", z++);
			printf("   (%d,%d)   ", block_a2[x][0], block_a2[x][1]);
			x++;
		}
		printf("\n\n");
	}
	printf("\t******************************************************************************\n");
	printf("\t|       0 MEANS AVAILABLE                           1 MEANS OCCUPIED         |\n");
	printf("\t******************************************************************************\n\n");
	printf("\tYOU CAN NOW CHOOSE AVAILABLE ROOMS (0-99): ");
	scanf("%d", &room_num);
	if (block_a2[room_num][0] && block_a2[room_num][1] == 1) {
		printf("\tSORRY ROOM IS FULL, PLEASE CHOOSE ANOTHER ROOM");
		_sleep(2000);
		system("CLS");
		goto room_selection;
	}
choose_bed:
	printf("\n\tPLEASE CHOOSE A BED LEFT(L) OR RIGHT(R) ?: ");
	getchar();
	scanf("%c", &bed_choice);
	switch (bed_choice) {
	case 'L':
	case 'l':
		apply.bed_num = 0;
		break;
	case 'R':
	case 'r':
		apply.bed_num = 1;
		break;
	default:
		printf("PLEASE INSERT A VALID OPTION !\n");
		_sleep(2000);
		system("CLS");
		goto choose_bed;
	}
	if (block_a2[room_num][apply.bed_num] == 1) {
		printf("\tSORRY, THIS BED HAS BEEN OCUPIED, PLEASE CHOOSE ANOTHER BED");
		_sleep(2000);
		goto choose_bed;
	}
	else if (block_a2[room_num][0] || block_a2[room_num][1] == 0)
		block_a2[room_num][apply.bed_num] = 1;
	else {
		printf("PLEASE ENTER A VALID OPTION !");
		_sleep(2000);
		goto room_selection;
	}
	return room_num;
}

int b1room_visuals() {
room_selection:
	int i, j, z = 0, x = 0, room_num;
	system("CLS");
	printf("\t******************************************************************************\n");
	printf("\t|                                  BLOCK B1                                  |\n");
	printf("\t******************************************************************************\n");
	for (i = 0; i < 10; i++) {
		printf("\t");
		for (j = 1; j < 11; j++) {
			printf("B%.2d ", z++);
			printf(" %d  ", block_b1[x++]);
		}
		printf("\n\n");
	}
	printf("\t******************************************************************************\n");
	printf("\t|       0 MEANS AVAILABLE                           1 MEANS OCCUPIED         |\n");
	printf("\t******************************************************************************\n\n");
	printf("\tYOU CAN NOW CHOOSE AVAILABLE ROOMS (0-99): ");
	scanf("%d", &room_num);
	if (block_b1[room_num] == 1) {
		printf("\tSORRY, THIS ROOM HAS BEEN OCUPIED, PLEASE CHOOSE ANOTHER ROOM");
		_sleep(2000);
		goto room_selection;
	}
	else if (block_b1[room_num] == 0)
		block_b1[room_num] = 1;
	else {
		printf("PLEASE ENTER A VALID OPTION !");
		_sleep(2000);
		goto room_selection;
	}
	return room_num;
}

int b3room_visuals() {
room_selection:
	int i, j, z = 0, x = 0, room_num, bed_num;
	char bed_choice;
	system("CLS");
	printf("\t******************************************************************************\n");
	printf("\t|                                  BLOCK B3                                  |\n");
	printf("\t******************************************************************************\n");
	for (i = 0; i < 20; i++) {
		printf("\t");
		for (j = 1; j < 6; j++) {
			printf(" B%.2d ", z++);
			printf("  (%d,%d,%d)  ", block_b3[x][0], block_b3[x][1], block_b3[x][2]);
			x++;
		}
		printf("\n\n");
	}
	printf("\t******************************************************************************\n");
	printf("\t|       0 MEANS AVAILABLE                           1 MEANS OCCUPIED         |\n");
	printf("\t******************************************************************************\n\n");
	printf("\tYOU CAN NOW CHOOSE AVAILABLE ROOMS (0-99): ");
	scanf("%d", &room_num);
	if (block_b3[room_num][0] && block_b3[room_num][1] && block_b3[room_num][2] == 1) {
		printf("\tSORRY ROOM IS FULL, PLEASE CHOOSE ANOTHER ROOM");
		_sleep(2000);
		system("CLS");
		goto room_selection;
	}
choose_bed:
	printf("\n\tPLEASE CHOOSE A BED LEFT(L) OR MIDDLE(M) OR RIGHT(R) ?: ");
	getchar();
	scanf("%c", &bed_choice);
	switch (bed_choice) {
	case 'L':
	case 'l':
		apply.bed_num = 0;
		break;
	case 'M':
	case 'm':
		apply.bed_num = 1;
		break;
	case 'R':
	case 'r':
		apply.bed_num = 2;
		break;
	default:
		printf("\tPLEASE INSERT A VALID OPTION !\n");
		_sleep(2000);
		system("CLS");
		goto choose_bed;
	}
	if (block_b3[room_num][apply.bed_num] == 1) {
		printf("\tSORRY, THIS BED HAS BEEN OCUPIED, PLEASE CHOOSE ANOTHER BED");
		_sleep(2000);
		goto choose_bed;
	}
	else if (block_b3[room_num][0] || block_b3[room_num][1] || block_b3[room_num][2] == 0)
		block_b3[room_num][apply.bed_num] = 1;
	else {
		printf("\tPLEASE ENTER A VALID OPTION !");
		_sleep(2000);
		goto room_selection;
	}
	return room_num;
}

