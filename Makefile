spirograph: spirograph.o slider.o spirograph.h glut.h slider.h
	g++ -g -w -Wall -o spirograph spirograph.o slider.o -lGL -lGLU -lglut

spirograph.o: spirograph.cpp spirograph.h glut.h slider.h
	g++ -g -c spirograph.cpp

slider.o: slider.cpp spirograph.h slider.h glut.h
	g++ -g -c slider.cpp
