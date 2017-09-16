all:
	g++ main.cpp -std=c++11 -Wall -lGLEW -L/usr/local/lib -lglfw3 -lGL -lm -ldl -lXinerama -lXrandr -lXi -lXcursor -lX11 -lXxf86vm -lpthread
