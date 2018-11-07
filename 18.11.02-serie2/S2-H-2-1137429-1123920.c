#import <stdio.h>
#define s(a) sizeof(a)

/* Declare Global Variables */

// Meta info
char series      = 2;
char group       = 2;
char semester[]  = "WS 2018 / 2019"; // contains 14 ascii symbols and a \0

// Info Student 1
char name_stu1[] = "Gerrit Heinen";
char sems_stu1   = 1;
int matr_stu1    = 1137429;

// Info Student 2
char name_stu2[] = "Natascha Wedel";
char sems_stu2   = 3;
int matr_stu2    = 1123920;


/* Main! */

int main() {

	// Headline, like twice for some reason
	printf("Serie %d Computer Systeme:\tAbgabe Zettel\n", series);
	printf("Abgabe Serie %d\t\t\tVorlesung Computer Systeme\n", series);

	// Group and semester
	printf("Gruppe %d", group);
	printf("\t\t\t%s\n", semester);

	// Student 1
	printf("Teilnehmer 1:\t\t\t%s, %d. Semester\n", name_stu1, sems_stu1);
	printf("Matrikelnummer 1:\t\t%7d\n", matr_stu1);

	// Student 2
	printf("Teilnehmer 2:\t\t\t%s, %d. Semester\n", name_stu2, sems_stu2);
	printf("Matrikelnummer 2:\t\t%7d\n", matr_stu2);

	/**
	 * The size of all the things, except the student's names
	 *
	 * The following lines produce the size using the sizeof() function:
	 *  int size = s(series) + s(group) + s(semester) + s(sems_stu1) + s(sems_stu2) + s(matr_stu1) + s(matr_stu2);
	 *  printf("%d\n", size);
	 *
	 * One can also add up from the known sizes of the data types used:
	 *  - 4 characters (series, group, sems_stu1, sems_stu2)
	 *  - 2 integers (matr_stu1, matr_stu2)
	 *  - 1 15 character-Array (semester)
	 *
	 *  --> 4 * 1 + 15 * 1 + 2 * 4 = 27
	 *
	 * So the variables excluding the names take up 27 Bytes of memory.
	 *
	 */

	return 0;
}
