#include <stdbool.h>     // use booleans in C
#include <stdlib.h>      // use common functions
#include <stdio.h>       // use input/output functions
#include <string.h>      // use string functions
#include <unistd.h>      // use POSIX functions

#include <sys/socket.h>  // use socket function
#include <netinet/in.h>  // use internet address datatypes
#include <arpa/inet.h>   // use inet_ntoa function
#include <netdb.h>       // use network database functions

/** Basic client application using UDP/IP connection.
    Hostname and port number of server are passed as arguments.
    By default, the server is assumed at localhost, port 5001.
*/
int main(int argc, char* argv[])
{
	// Read parameters
	if (argc != 3) {
		printf("Usage: UDPClient [<hostname>] [<port>]\n\n");
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

	/** -- Main program -- */

	bool running = true;
	char buffer[1024];
	int len = 0;
	while (running)
	{
		// Read message from user
		memset(buffer, 0, 1024);
		printf("Enter request:\n> ");
		fgets(buffer, 1024, stdin);
		len = strlen(buffer);
		if (len > 0 && buffer[len-1] == '\n') {
			buffer[len-1] = '\0';  // remove trailing newline
			len--;
		}

		// Exit program when input is empty
		if (len == 0) {
			running = false;
			continue;
		}

		// Send message to server
		if (sendto(sock, buffer, len, 0, (struct sockaddr*)&serverAddr, addrLen) < 0) {
			printf("Failed to send message to server!\n");
			running = false;
			continue;
		} else {
			printf("Sent message to server: \"%s\"\n", buffer);
		}

		// Receive response from server
		printf("Waiting for response...\n");
		memset(buffer, 0, 1024);
		if (recvfrom(sock, buffer, 1024, 0, (struct sockaddr*)&serverAddr, &addrLen) < 0) {
			printf("Failed to receive response from server!\n");
			running = false;
			continue;
		}

		// Print received response
		printf("Received response from server: \"%s\"\n", buffer);
	}

	// Close socket
	close(sock);

	return 0;
}
