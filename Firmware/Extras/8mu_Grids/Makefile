.PHONY: build test run-test

build:
	g++ test.cpp grids.cpp pattern_generator.cpp resources.cpp avrlib/random.cc -o test

run-test:
	./test

test : build run-test