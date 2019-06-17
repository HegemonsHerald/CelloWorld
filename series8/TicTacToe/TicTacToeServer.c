#include <stdlib.h>      // use common functions
#include <stdio.h>       // use input/output functions
#include <string.h>      // use string functions
#include <unistd.h>      // use POSIX functions

#include <sys/socket.h>  // use socket function
#include <netinet/in.h>  // use internet address datatypes
#include <arpa/inet.h>   // use inet_ntoa function

#include "TicTacToeFunctions.h"  // declares game functions

/** Simple server application for Tic-Tac-Toe game using UDP.
    The port number is passed as an argument to the program.
    By default, the server runs at port 5001.
*/
int main(int argc, char* argv[])
{
	// Read parameters
	if (argc != 2) {
		printf("Usage: TicTacToeServer [<port>]\n\n");
	}
	int port = argc > 1 ? atoi(argv[1]) : 5001;

	/** -- Setup connection -- */

	// Create UDP/IP socket
	int sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (sock < 0) {
		printf("Failed to create socket!\n");
		return -1;
	}

	// Set server port
	struct sockaddr_in serverAddr;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(port);
	serverAddr.sin_addr.s_addr = INADDR_ANY;

	// Bind socket to port
	int res = bind(sock, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	if (res < 0) {
		printf("Failed to bind socket to port %d!\n", port);
		return -1;
	}
	char hostname[256];
	gethostname(hostname, 256);
	printf("Server running at host %s, port %d\n\n", hostname, port);

	// This variable will receive the client address and port
	struct sockaddr_in clientAddr;
	unsigned int addrLen = sizeof(clientAddr);

	/** -- Main game -- */

	bool running = true;
	char message[16];
	char command[6];
	char field[9];
	memset(field, ' ', 9);
	while (running)
	{
		// Receive message from client
		printf("Waiting for messages...\n");
		memset(message, 0, 16);
		if (recvfrom(sock, message, 16, 0, (struct sockaddr*)&clientAddr, &addrLen) < 0) {
			printf("Failed to receive message from client!\n");
			continue;
		}

		// Print received message (as hex codes and string)
		printf("Client at %s:%d sent: \"",
		       inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
		for (int i = 0; i < 16; i++)
			printf("%c", message[i]);
		printf("\"\n(hex:");
		for (int i = 0; i < 16; i++)
			printf(" %02x", message[i]);
		printf(")\n");

		// Read command and field from message
		memcpy(command, message, 5);
		command[5] = '\0';
		memcpy(field, message + 6, 9);
		printField(field);

		// Check message and field and respond
		if (strcmp(command, "FIELD") != 0) {
			printf("Wrong message format: FIELD missing at begin!\n");
			strcpy(command, "ERROR");
		} else if (message[5] != ':') {
			printf("Wrong message format: colon missing after FIELD!\n");
			strcpy(command, "ERROR");
		} else if (message[15] != '\0') {
			printf("Wrong message format: zero byte missing at end!\n");
			strcpy(command, "ERROR");
		} else if (!checkField(field)) {
			printf("Received invalid field!\n");
			strcpy(command, "ERROR");
		} else if (checkWin(field, 'X')) {
			printf("Player X has won!\n");
			strcpy(command, "FWINX");
		} else if (checkDraw(field)) {
			printf("Draw game!\n");
			strcpy(command, "FDRAW");
		} else {
			printf("Computing next move...\n");
			nextMove(field, 'O');
			printField(field);
			if (checkWin(field, 'O')) {
				printf("Player O has won!\n");
				strcpy(command, "FWINO");
			} else if (checkDraw(field)) {
				printf("Draw game!\n");
				strcpy(command, "FDRAW");
			} else {
				strcpy(command, "FIELD");
			}
		}

		// Build response message
		memcpy(message, command, 5);    // update command in message
		message[5] = ':';               // insert colon after command
		memcpy(message + 6, field, 9);  // update field in message
		message[15] = '\0';             // insert zero byte at end

		// Send response to client
		if (sendto(sock, message, 16, 0, (struct sockaddr*)&clientAddr, addrLen) < 0) {
			printf("Failed to send response to client at %s:%d!\n",
			       inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
		} else {
			printf("Sent response to client at %s:%d: \"%s\"\n",
			       inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port), message);
		}
	}

	// Close socket
	close(sock);

	return 0;
}
