

objects=hausaufgabe2 sizes pow_vs_shift

all: $(objects)

% : %.c
	clang -o $@ $<

clean: $(objects)
	rm $^
