#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "total_function.h"

/* THIS FUNCTION CHECKS IF Student.txt EXISTS, IF IT DOESN'T EXIST, FUNCTION WILL THEN OPEN A Student.txt FILE*/
/* THIS FUNCTION IS INCLUDED IN THE MAIN SOURCE FILE hostel_management_system.c */

void check_file_created() {
	FILE *block;
	block = fopen("Student.txt", "r+");
	if (block == NULL) {
		block = fopen("Student.txt", "w+");
	}
	fclose(block);
}