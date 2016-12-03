#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

void advent1(char *input);
void advent2(char *input);

int main()
{
	char *in;
	int fd, i;
	in = malloc(10000 * sizeof(char));
	fd = open("input.txt", O_RDONLY);
	if(in==NULL || fd < 0){
		perror("try again");
		exit(1);
	}
	for(i=0; read(fd, in + (i * 256), 256); i++);
	close(fd);
	advent2(in);
	free(in);
	exit(0);
}

void advent1(char *input)
{
	char *instruction;
	int count, sides[3];
	count = 0;
	sides[0] = 0;
	sides[1] = 0;
	sides[2] = 0;
	instruction = strtok(input, "\n");
	while(NULL != instruction){
		sscanf(instruction, "%d %d %d", &sides[0], &sides[1], &sides[2]);
		if(sides[0] + sides[1] > sides[2] && sides[1] + sides[2] > sides[0] && sides[2] + sides[0] > sides[1]){
			count++;
		}
		instruction = strtok(NULL, "\n");
	}
	printf("%d\n", count);
}

void advent2(char *input)
{
	char *instruction;
	int count, sides[9], tri;
	count = 0;
	tri = 0;
	for(int i = 0; i < 9; i++){
		sides[i] = 0;
	}
	instruction = strtok(input, "\n");
	while(NULL != instruction){
		sscanf(instruction, "%d %d %d", &sides[tri], &sides[3 + tri], &sides[6 + tri]);
		++tri;
		if(tri == 3){
			tri = 0;
			if(sides[0] + sides[1] > sides[2] && sides[1] + sides[2] > sides[0] && sides[2] + sides[0] > sides[1]){
				count++;
			}
			if(sides[3] + sides[4] > sides[5] && sides[4] + sides[5] > sides[3] && sides[5] + sides[3] > sides[4]){
				count++;
			}
			if(sides[6] + sides[7] > sides[8] && sides[7] + sides[8] > sides[6] && sides[8] + sides[6] > sides[7]){
				count++;
			}
		}
		instruction = strtok(NULL, "\n");
	}
	printf("%d\n", count);
}


