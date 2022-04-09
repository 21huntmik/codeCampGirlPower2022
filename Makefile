spirograph: spirograph.o arrowButtons.o spirograph.h glut.h arrowButtons.h
	g++ -g -w -Wall -o spirograph spirograph.o arrowButtons.o -lGL -lGLU -lglut

spirograph.o: spirograph.cpp spirograph.h glut.h arrowButtons.h
	g++ -g -c spirograph.cpp

arrowButtons.o: arrowButtons.cpp spirograph.h arrowButtons.h glut.h
	g++ -g -c arrowButtons.cpp
