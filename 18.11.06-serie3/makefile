# The first rule will always be run
# that first rule must depend on all
# else, or nothing is going to happen!
all : main

% : %.c
	clang -o $@ $<
