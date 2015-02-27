#! /bin/make

GPP      := g++
SRCS     := $(shell find -regex .*\.cpp)
OBJS     := $(addsuffix .o,$(basename $(SRCS)))
CPPFLAGS := -g --std=gnu++11 -Wall -pedantic
TARGET   := economy

default: build

build: $(TARGET)

clean:
	@rm -rf $(OBJS) $(TARGET)

all: clean build

run: build
	@echo [RUN ] Running $(TARGET)...
	@./$(TARGET)

$(TARGET): $(OBJS)
	@echo [LINK] Running $(TARGET)...
	@$(GPP) -o $@ $^

.cpp.o:
	@echo [COMPILE] Compiling $@ from $<...
	@$(GPP) $(CPPFLAGS) -o $@ -c $<
