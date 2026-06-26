program: main.cc
	g++ main.cc -o program.exe

clean:
	rm out/* program.exe

.PHONY: clean