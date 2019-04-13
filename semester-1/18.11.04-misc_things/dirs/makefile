# Variables

# directories
PWD = .
SRC = $(PWD)/sources
OBJ = $(PWD)/objects
LIB = $(PWD)/libs

# object files
objects = $(OBJ)/add.o $(OBJ)/print.o $(OBJ)/subtract.o


# Rules

# compile executable from main.c and the library; this rule calls the mkdir targets
main : $(OBJ) $(LIB) $(OBJ)/main.o $(LIB)/libstuff.a
	gcc -o $@ $(OBJ)/main.o -L$(LIB) -lstuff

# compile library from object files; this rule uses fancy variable substitution
$(LIB)/libstuff.a : $(objects)
	ar rcs $@ $(objects)

# compile object files from source files; this is a pattern rule
$(OBJ)/%.o : $(SRC)/%.c
	gcc -c -fpic -o $@ $<

# make directories, if they don't already exist
$(OBJ):
	mkdir $(OBJ)

$(LIB):
	mkdir $(LIB)

clean :
	rm -rd $(OBJ) $(LIB)


# OK
# You need to be careful, when referencing the current working directory, cause
# make likes to turn that from ./ into /, which obviously won't work!!!
#
#
# Also, if you want make to create directories for you, you can do that by
# making them targets. But in order for make to actually call those targets, the
# targets need to be prerequisits of other things, that are being called somewhere.
#
# So the first target ('main') has the directories as its prerequisit, cause from
# there all other targets are being called, which in turn need the directories.
# Create the dirs at the beginning and you are good to go!
#
# Basically: learn from this, that for a target to be executed, it has to have
# some relationship with another target, except for the very first target. And unless
# you are planning on calling the target specifically, like make install or sth.
#
# Also: prerequisits are being checked left-to-right and the associated targets
# are run, when encountered, so putting the mkdir targets at the beginning of main, makes
# sure that they exist, when they are needed for the main.o and libstuff.a prerequisits.
#
# Also: when you use variables those are expanded in place, which is why you can't
# just write $(OBJ)/$(objects), but you have to put the $(OBJ) in front of each of the
# elements of objects... sadly.
