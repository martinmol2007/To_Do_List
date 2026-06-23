program: main.cc
	g++ main.cc -o program

clean:
	rm *.txt program

.PHONY: clean