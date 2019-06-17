#include <stdbool.h>     // use booleans in C
#include <stdlib.h>      // use common functions
#include <stdio.h>       // use input/output functions
#include <string.h>      // use string functions
#include <unistd.h>      // use POSIX functions

#include <sys/socket.h>  // use socket function
#include <netinet/in.h>  // use internet address datatypes
#include <arpa/inet.h>   // use inet_ntoa function
#include <netdb.h>       // use network database functions

/** Print field represented by given character array.
  The array must contains 9 chars ('O', 'X' or ' ')
  ordered row-wise from top left to bottom right. */
void printField(char* field)
{
	printf("+---+---+---+\n");
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			printf("| %c ", field[row*3+col]);
		}
		printf("|\n+---+---+---+\n");
	}
}

/** Simple client application for Tic-Tac-Toe game using UDP.
  Hostname and port number of server are passed as arguments.
  By default, the server is assumed at localhost, port 5001.
  */
int main(int argc, char* argv[])
{
	// Read parameters
	if (argc != 3) {
		printf("Usage: TicTacToeClient [<hostname>] [<port>]\n\n");
	}
	char* hostname = argc > 1 ? argv[1] : "localhost";
	int port = argc > 2 ? atoi(argv[2]) : 5001;

	/** -- Setup connection -- */

	// Get server host information
	struct hostent* serverInfo = gethostbyname(hostname);
	if (serverInfo == NULL) {
		printf("Failed to get info for host '%s'!\n", hostname);
		return -1;
	}

	// Create UDP/IP socket
	int sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (sock < 0) {
		printf("Failed to create socket!\n");
		return -1;
	}

	// Set address and port of server
	struct sockaddr_in serverAddr;
	serverAddr.sin_family = serverInfo->h_addrtype;
	serverAddr.sin_port = htons(port);
	memcpy(&serverAddr.sin_addr.s_addr, serverInfo->h_addr, serverInfo->h_length);
	unsigned int addrLen = sizeof(serverAddr);

	printf("Expecting server at %s:%d\n\n",
			inet_ntoa(serverAddr.sin_addr), ntohs(serverAddr.sin_port));


	/** -- Main game -- */

	bool running = true;

	// init message with the parts, that don't change
	char message[16] = "FIELD:";
	message[15] = '\0';

	// init command with the parts, that don't change
	char command[6];
	command[5] = '\0';

	char field[9];
	memset(field, ' ', 9);
	printField(field);

	while (running)
	{
		// Read row and column from user
		int row = 0, col = 0;
		printf("Select row and column (1-3): ");
		scanf("%d %d", &row, &col);
		while (getchar() != '\n') {}  // discard remaining input
		if (row < 1 || row > 3 || col < 1 || col > 3) {
			printf("Invalid row or column!\n");
			continue;
		}

		// Update field
		int idx = (row-1)*3 + col-1;
		if (field[idx] != ' ') {
			printf("This field is already occupied!\n");
			continue;
		}
		field[idx] = 'X';
		printField(field);


		/* Compose and send message to server */

		// Add the current field state to the message
		for(int i=0; i<9; i++)
			message[6+i] = field[i];

		// Send message to server
		if (sendto(sock, message, 16, 0, (struct sockaddr*)&serverAddr, addrLen) < 0) {
			printf("Failed to send message to server!\n");
			running = false;
			continue;
		}


		/* Receive answer from server and react accordingly */

		char response[16];

		// Receive response from server
		if (recvfrom(sock, response, 16, 0, (struct sockaddr*)&serverAddr, &addrLen) < 0) {
			printf("Failed to receive response from server!\n");
			running = false;
			continue;
		}

		// get the current command
		for(int i=0; i<5; i++)
			command[i] = response[i];

		// handle the error command
		if (command[0] == 'E') {
			printf("ERROR\n");
			running=false;

		// handle all the other commands
		} else {

			// Unless something went wrong, all commands should output the new
			// field state.

			// Update the field and print it
			for(int i=0; i<9; i++) { field[i] = response[6+i]; }
			printField(field);

			// We wanted to use the 'if(strcmp(string, "string"))' method, but for
			// some reason that just didn't want to work. Instead we identify the
			// command by unique characters.

			// fDraw
			if (command[1] == 'D') {
				printf("The game is a draw.\n");
				running=false;

			// fwinX or fwinO
			} else if (command[4] != 'D') {
				printf("%c wins the game.\n", command[4]);
				running=false;
			}

			// FIELD doesn't have to be handled explicitely, because the field is
			// updated and printed anyways.

		}

	}

	// Close socket
	close(sock);

	return 0;
}
