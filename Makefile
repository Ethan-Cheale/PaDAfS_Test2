CC = g++
SRS = main.cpp system.cpp disk.cpp
OUT = main

all:
	$(CC) $(SRS) -o $(OUT)