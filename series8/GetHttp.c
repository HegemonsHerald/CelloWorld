#include <stdbool.h>     // use booleans in C
#include <stdlib.h>      // use common functions
#include <stdio.h>       // use input/output functions
#include <string.h>      // use string functions
#include <unistd.h>      // use POSIX functions

#include <sys/socket.h>  // use socket function
#include <netinet/in.h>  // use internet address datatypes
#include <arpa/inet.h>   // use inet_ntoa function
#include <netdb.h>       // use network database functions

/** Will send a GET request to www.stardrifter.org/cgi-bin/ref.cgi
  * with the referer field set to the first CLI argument.
  */
int main(int argc, char* argv[])
{

	/** -- What to send as referer -- */

	char* ref_text;

	if (argc < 2) {

		// Incorrect user input
		printf("Usage: %s <phrase to send as referer>\n", argv[0]);
		exit(1);

	} else {
		ref_text = argv[1];
	}

	/** -- Setup connection -- */

	// We want to establish an http connection with stardrifter
	char* hostname = "www.stardrifter.org";
	int port = 80;

	// Get server host information
	struct hostent* serverInfo = gethostbyname(hostname);
	if (serverInfo == NULL) {
		printf("Failed to get info for host '%s'!\n", hostname);
		return -1;
	}

	// Create TCP/IP socket
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock < 0) {
		printf("Failed to create socket!\n");
		return -1;
	}

	// Set address and port of server
	struct sockaddr_in serverAddr;
	serverAddr.sin_family = serverInfo->h_addrtype;
	serverAddr.sin_port = htons(port);
	memcpy(&serverAddr.sin_addr.s_addr, serverInfo->h_addr, serverInfo->h_length);

	// Connect to server
	if (connect(sock, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
		printf("Failed to connect to server at %s:%d!\n",
				inet_ntoa(serverAddr.sin_addr), ntohs(serverAddr.sin_port));
		return -1;
	}


	/** -- Main program -- */

	/* Send the GET request with the referer field and whatnot */

	// Make the message
	char message[1024];
	sprintf(message, "GET /cgi-bin/ref.cgi HTTP/1.1\r\n\
Host: www.stardrifter.org\r\n\
User-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:46.0) Gecko/20100101 Firefox/46.0\r\n\
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\n\
Accept-Language: en-US,en;q=0.5\r\n\
Accept-Encoding: deflate\r\n\
Connection: keep-alive\r\n\
Cache-Control: max-age=0\r\n\
Referer: %s\r\n\
\r\n", ref_text);

	// We use the sprintf function to insert the referer text provided through
	// the command line arguments into the GET request.

	// Note, that we are using the 'deflate' encoding to get back plain text as
	// content, so one can actually read the html text.

	// Note also, that this program will be aborted if one enters a referer
	// text, that's very long, because of a buffer overflow on the message
	// buffer.

	// Send message to server
	if (send(sock, message, strlen(message), 0) < 0) {
		printf("Failed to send message to server!\n");
		return -1;
	}

	// Receive response from server
	char answer[1024];
	memset(answer, 0, 1024);
	if (recv(sock, answer, 1024, 0) < 0) {
		printf("Failed to receive response from server!\n");
		return -1;
	}

	// Print received response
	printf("%s", answer);

	// Close socket
	close(sock);

	return 0;
}
