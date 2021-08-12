test: main.cpp globals.h
	g++ main.cpp -o jedit

clean:
	rm jedit
	rm *.txt