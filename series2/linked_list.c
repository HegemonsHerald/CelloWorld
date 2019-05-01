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

	return el;

}



/* The global list */

struct list_item* front = (struct list_item*) NULL;
struct list_item* back  = (struct list_item*) NULL;



/* operations on linked lists */

// append NEW item, return its id
int appendItem(char* label) {

	struct list_item* el = mk_list_item(label);

	// append el to the global list
	if (back != NULL) back->cdr = el;	// if there are already items, then append
	else              front     = el;	// otherwise you actually kinda create the list

	// set the new last item
	back = el;
	
	return el->id;

}

// print the global list
void printList() {

	struct list_item* ptr = front;

	while (ptr != NULL) {
		printf("ID: %d\tLABEL: %s\n", ptr->id, ptr->label);
		ptr = ptr->cdr;
	}
}

// finds an item
struct list_item* findItem(int id) {

	struct list_item* ptr = front;

	while (ptr != NULL) {
		if (ptr->id == id) return ptr;
		ptr = ptr->cdr;
	}

	return NULL;

}

// delete an item from the global list
void deleteItem(int id) {

	// define a sliding window on the last two items of the list
	struct list_item* ptr_before = front;
	struct list_item* ptr_item   = front;

	while (ptr_item != NULL) {

		// if you found the correct thingy bajingy
		if (ptr_item->id == id) {

			// unlink the item from the list
			ptr_before->cdr = ptr_item->cdr;

			// deallocate the item
			free(ptr_item);

			// no need to continue
			return;

		}

		// slide the pointer window ahead
		ptr_before = ptr_item;
		ptr_item   = ptr_item->cdr;

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

	// for good measure
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

	// I HAVE NO IDEA WHY, BUT THIS LIST IMPLEMENTATION CAN'T DELETE THE LAST LIST ITEM.
	// FOR SOME REASON

	return 0;
}
