
# Find out what OS you're on
OS := $(shell uname -s)

# Define source and build directories
SRC_DIR=src
BUILD_DIR=build

# If you're on Linux use build_linux as build target
ifeq ($(OS),Linux)
	BUILD_DIR=build_linux
endif

# If you're on Mac use build_mac as build target
ifeq ($(OS),Darwin)
	BUILD_DIR=build_mac
endif


# Which Objects should be made using this makefile?
objects=$(BUILD_DIR)/union $(BUILD_DIR)/S4-H-2-1137429-1123920 $(BUILD_DIR)/to_binary $(BUILD_DIR)/using_bitmask $(BUILD_DIR)/preproc_test


# make everything
# If make doesn't find a BUILD_DIR, it makes one using the BUILD_DIR rule
# If make doesn't find an object from the objects list, it makes it using the 'make anything in BUILD_DIR from anything.c in SRC_DIR' rule
all : $(BUILD_DIR) $(objects)

# How to make the BUILD_DIR
$(BUILD_DIR) :
	mkdir $(BUILD_DIR)

# How to compile the c files
$(BUILD_DIR)/% : $(SRC_DIR)/%.c
	clang -o $@ $<

# Reset by deleting all the build files
clean :
	rm $(BUILD_DIR)/*
