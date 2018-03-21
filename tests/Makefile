CC = gcc
CFLAGS = -Wall
OBJ = vec2.o

all: vec2 vec3 vec4 mat4

vec2:
	$(CC) $(CFLAGS) -c vec2.c -o vec2.o
	$(CC) -lm vec2.o -o vec2

vec3:
	$(CC) $(CFLAGS) -c vec3.c -o vec3.o
	$(CC) -lm vec3.o -o vec3

vec4:
	$(CC) $(CFLAGS) -c vec4.c -o vec4.o
	$(CC) -lm vec4.o -o vec4

mat4:
	$(CC) $(CFLAGS) -c mat4.c -o mat4.o
	$(CC) -lm mat4.o -o mat4
