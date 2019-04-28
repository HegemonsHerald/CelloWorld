#include <stdio.h>



struct Cons {
	void* car;
	struct Cons* cdr;
};

void*        car(struct Cons *c) { return c->car; }
struct Cons* cdr(struct Cons *c) { return c->cdr; }

struct Cons* set_car(struct Cons *c, void *v) {
	c->car = v;
	return c;
}

struct Cons* set_cdr(struct Cons *c, struct Cons *v) {
	c->cdr = v;
	return c;
}




int main () {


	int whee      = 42;

	struct Cons c = { &whee, NULL };

	// ptr to whee
	int *w = c.car;

	// val of whee
	int v  = *w;

	// printf("%d\n", *((int*)car(&c)));
	
	struct Cons nother_value = { &whee, NULL };
	set_car(&c, &nother_value);
	set_cdr(&c, &nother_value);

	printf("%d\n", *((int*) car( (struct Cons*) car(&c) )));


	return 0;

}
