#import <stdio.h>

// Types
struct student {
	char name[20];
};

// Global Variables
int series		= 0;
char semester[13]	= "WS 2018/2019";


int main() {

	// Init Studs
	struct student stud1 =  { "Gerrit Heinen" };
	struct student stud2 =  { "Natascha" };

	// Print Output
	printf("Semester: %s\n", semester);
	printf("Serie:    %d\n", series);
	printf("Student 1\n");
	printf(" Name: %s\n", stud1.name);
	printf("Student 2\n");
	printf(" Name: %s\n", stud2.name);


}
