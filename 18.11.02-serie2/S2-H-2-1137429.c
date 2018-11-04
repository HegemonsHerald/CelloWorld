#import <stdio.h>

/* Declare Global Variables */

// Meta info
char serie       = 2;
char group       = 2;
char semester[]  = "WS 2018/2019";

// Info Student 1
char name_stu1[] = "Gerrit Heinen";
char sems_stu1   = 1;
int matr_stu1    = 1137429;

// Info Student 2
char name_stu2[] = "0";
char sems_stu2   = 0;
int matr_stu2    = 0;


/* Main! */

int main() {

	// Headline, like twice for some reason
	printf("Serie %d Computer Systeme:\tAbgabe Zettel\n", serie);
	printf("Abgabe Serie %d\t\t\tVorlesung Computer Systeme\n", serie);

	// Group and semester
	printf("Gruppe %d", group);
	printf("\t\t\t%s\n", semester);

	// Student 1
	printf("Teilnehmer 1:\t\t\t%s, %d. Semester\n", name_stu1, sems_stu1);
	printf("Matrikelnummer 1:\t\t%7d\n", matr_stu1);

	// Student 2
	printf("Teilnehmer 2:\t\t\t%s, %d. Semester\n", name_stu2, sems_stu2);
	printf("Matrikelnummer 2:\t\t%7d\n", matr_stu2);

	return 0;
}
