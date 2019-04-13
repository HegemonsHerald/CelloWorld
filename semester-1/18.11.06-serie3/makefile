# Find out on what OS we are
OS := $(shell uname -s)
# ... := $(shell ... ) is the shell function, runs a command, puts the output in the variable

# Adjust the build directory to the OS

# Default
BUILD_DIR=build

# If linux
ifeq ($(OS),Linux)
	BUILD_DIR=build_linux
endif

# If mac
ifeq ($(OS),Darwin)
	BUILD_DIR=build_mac
endif


# Define build objects in terms of build directory
objects=$(BUILD_DIR)/main.out $(BUILD_DIR)/S3-H-2-1137429-1123920.out


# 'All' target: create build directory and build all objects
all : $(BUILD_DIR) $(objects)

# How to compile code
$(BUILD_DIR)/%.out : %.c
	clang -o $@ $^

# How to make the build directory
$(BUILD_DIR) :
	mkdir $(BUILD_DIR)

# Cleanup
clean :
	rm $(BUILD_DIR)/*.out
