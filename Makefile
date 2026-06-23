program: main.cc
	g++ main.cc -o program.exe

clean:
	rm *.txt program

.PHONY: clean