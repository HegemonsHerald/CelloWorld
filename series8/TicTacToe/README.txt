Build client and server application as usual with:

	> gcc -o TicTacToeServer TicTacToeServer.c TicTacToeFunctions.c -g
	> gcc -o TicTacToeClient TicTacToeClient.c -g

---

Start the server at some custom port (e. g.: 5001) with:

	> ./TicTacToeServer 5001

Now you can start clients in other terminals and connect to the server
to start one or multiple games:

	> ./TicTacToeClient localhost 5001

Here localhost is used, since both server and client are running on the
same host. You can also use the hostname shown by the server at startup.
