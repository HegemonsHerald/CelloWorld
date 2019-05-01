#include <stdio.h>   // Include to use printf
#include <string.h>  // Include to use strcpy
#include <stdlib.h>  // Include to use malloc

// TODO : Define singly-linked list data structure and functions!

int main()
{
	int id1, id2, id3, id4, id5;

	id1 = appendItem("item_1");
	id2 = appendItem("item_2");
	id3 = appendItem("item_3");
	printList();

	deleteItem(id1);
	printList();
	deleteItem(id3);
	printList();
	deleteItem(id1);
	printList();

	id4 = appendItem("item_4");
	id5 = appendItem("item_5");
	printList();

	deleteItem(id5);
	printList();
	deleteItem(id4);
	printList();
	deleteItem(id2);
	printList();

	appendItem("gizmo");
	appendItem("bar");
	appendItem("bar");
	appendItem("foo");
	printList();
	deleteList();
	printList();

	return 0;
}
