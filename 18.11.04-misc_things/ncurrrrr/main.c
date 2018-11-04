#include <locale.h>
#include <ncurses.h>

int main() {

	// wide char support
	setlocale(0, "");

	// start ncurses
	initscr();

	// basic setup
	keypad(stdscr, 1); // recognize f-keys and arrows
	cbreak(); // no need for carriage return with getch()
	noecho(); // don't print input

	// use colors
	start_color();

	// use the default colors, so -1 becomes available for emulator default!
	use_default_colors();

	// define the color palette
	init_pair(1, COLOR_BLUE, -1);
	init_pair(2, COLOR_YELLOW, -1);

	attron(COLOR_PAIR(1)); // set the colors to blue!
	printw("ㄩHonk!ƣ … and even with unicode!\n\n");

	attron(COLOR_PAIR(2)); // set the colors to yellow!
	attron(A_BOLD); // bold!
	printw("Honkitonk!");

	// update the output
	refresh();

	// give me time to see the output
	getch();

	// die
	endwin();

	return 0;

}
