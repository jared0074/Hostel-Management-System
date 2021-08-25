#include <stdio.h>


int main() {
	FILE *f;
	f = fopen("Student.txt", "a+");
	fputs("\n", f);
	fputs(("%s", s.studentID), f);
	fputs(("%s", s.firstName), f);
	fputs(("%s", s.lastName), f);
	fputs(("%s", s.gender), f);
	fclose(f);
}