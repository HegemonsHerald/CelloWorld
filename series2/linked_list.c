#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* the type definition */

struct list_item {
	int                id;
	char        label[16];
	struct list_item* cdr;
};

// global id counter
int ID = 0;

// create a new list_item
struct list_item* mk_list_item(char* label) {

	// MMMMMallocate!
	struct list_item* el = (struct list_item*) malloc(sizeof(struct list_item));

	// set the initial values, ommitting the cdr of course
	el->id = ++ID;

	// copy the label into the label field, but cut it off, if it's too long
	strncpy(el->label, label, 16);

	// don't forget that there's to be nothing following this item
	el->cdr = (struct list_item*) NULL;

	return el;

}



/* The global list */

struct list_item* front = (struct list_item*) NULL;
struct list_item* back  = (struct list_item*) NULL;



/* Operations on linked lists */

// append a new item, return its id
int appendItem(char* label) {

	struct list_item* item = mk_list_item(label);

	// append item to the global list
	if (back != NULL) back->cdr = item;	// if there are already items, then append
	else              front     = item;	// otherwise you actually kinda create the list

	// set the new last item
	back = item;
	
	return item->id;

}

// print the global list
void printList() {

	struct list_item* ptr = front;

	// edge case
	if (front == NULL) { printf("empty\n"); return; }

	// otherwise you may just print them all!
	while (ptr != NULL) {
		printf("ID: %d\tLABEL: %s\n", ptr->id, ptr->label);
		ptr = ptr->cdr;
	}

}

// finds an item
struct list_item* findItem(int id) {

	struct list_item* ptr = front;

	// go looking for the item
	while (ptr != NULL) {
		if (ptr->id == id) return ptr;
		ptr = ptr->cdr;
	}

	// didn't find it, :(
	return NULL;

}

// delete an item from the global list
void deleteItem(int id) {

	struct list_item* prev = NULL;
	struct list_item* curr = front;

	// case 1: there's just one item in the list, and that's the one to delete
	if (front == back && curr->id == id) {

		front = NULL;
		back  = NULL;

		free(curr);
		return;
	}

	// case 2: the list has more than one item
	//         this excludes the last item, see below
	while (curr != back) {

		if (curr->id == id) {

			if (prev == NULL) { front     = curr->cdr; }	// if the item is the first item
			else              { prev->cdr = curr->cdr; }	// if the item is any other item

			free(curr);
			return;
		}

		prev = curr;
		curr = prev->cdr;
	}

	// case 3: the list has multiple items, and the item is the last of them
	//         special case, because here prev->cdr needs to be set to NULL, which'd cause a segfault in case 2
	if (curr->id == id) {

		prev->cdr = (struct list_item*) NULL;
		back = prev;

		free(curr);
	}

}

// delete the global list
void deleteList() {

	// delete from the front to the back

	struct list_item* ptr_curr = front;
	struct list_item* ptr_next = front;

	while (ptr_curr != NULL) {

		// temp the next item
		ptr_next = ptr_curr->cdr;

		// free the current item
		free(ptr_curr);

		// continue with the next
		ptr_curr = ptr_next;
	}

	// nullify to get back to the initial state
	front = (struct list_item*) NULL;
	back  = (struct list_item*) NULL;

	// We're not resetting the ID counter, there's no reason to assume, that there
	// may not be items outside the global list.

}




int main () {

	// let's make some items, shall we
	appendItem("According to al");		// <- labels the length of 15 chars work!
	appendItem("l known laws of");
	appendItem("aviation, there");
	appendItem("is no way a bee");
	appendItem("should be able ");
	appendItem("to fly.  Its wi");
	appendItem("ngs are too sma");
	appendItem("ll to get its f");
	appendItem("at little body ");
	appendItem("off the ground.");
	appendItem("The bee, of cou");
	appendItem("rse, flies anyw");
	appendItem("ay because bees");
	appendItem("don't care what");
	appendItem("humans think is");
	appendItem("impossible.");		// <- labels shorter than 15 chars work!
	appendItem("yabba-dabbah-dooooooh");	// <- labels longer than 15 work as well!

	// output.
	printList();

	// it won't find this one:
	printf("%s\n", findItem(329048));	// ==> (null)

	// it will find this one:
	printf("%s\n", findItem(12)->label);	// ==> rse, flies anyw

	// you may delete:
	deleteItem(12);
	printf("%s\n", findItem(12));		// ==> (null)

	// you may even try twice, though that doesn't do anything
	deleteItem(12);
	printf("%s\n", findItem(12));		// ==> (null)

	// you may even delete the whole list
	deleteList();
	printf("%s\n", findItem(7));		// ==> (null)
	printf("%s\n", front);			// ==> (null)
	printf("%s\n", back);			// ==> (null)


	/* provided tests */

	int id1, id2, id3, id4, id5;

	id1 = appendItem("item_1");
	id2 = appendItem("item_2");
	id3 = appendItem("item_3");
	printList();
	deleteItem(id1);
	printf("\n");
	printList();
	printf("\n");
	deleteItem(id3);
	printf("\n");
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
