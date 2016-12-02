#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

void advent(char *input);
int code1(int start, char dir);
int code2(int start, char dir);

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
	advent(in);
	free(in);
	exit(0);
}

void advent(char *input)
{
	char *instruction;
	int state, i, length;
	state = 5;
	instruction = strtok(input, "\n");
	while(NULL != instruction){
		length = strlen(instruction);
		for(i=0; i < length; i++){
			state = code2(state, instruction[i]);
		}
		printf("Next button is: %x\n", state); 
		instruction = strtok(NULL, "\n");
	}
}

int code1(int start, char dir)
{
	int state;
	state = start;
	switch(dir){
		case 'U':
			if(state > 3) state -= 3;
			break;
		case 'D':
			if(state < 7) state += 3;
			break;
		case 'L':
			if(!((state + 2) % 3 == 0)) state -= 1;
			break;
		case 'R':
			if(!(state % 3 == 0)) state += 1;
	}
	return state;
}

int code2(int start, char dir)
{
	int state;
	state = start;
	switch(dir){
		case 'U':
			if(state != 1 &&
				state != 2 &&
				state != 4 &&
				state != 5 &&
				state != 9){
				
				state -= 2;
				if(state != 11 && state != 1) state -= 2;
			}
			break;
		case 'D':
			if(state != 5 &&
				state != 9 &&
				state != 10 &&
				state != 12 &&
				state != 13){
				
				state += 2;
				if(state != 3 && state != 13) state += 2;
			}
			break;
		case 'L':
			if(state != 1 &&
				state != 2 &&
				state != 5 &&
				state != 10 &&
				state != 13) state -= 1;
			break;
		case 'R':
			if(state != 1 &&
				state != 4 &&
				state != 9 &&
				state != 12 &&
				state != 13) state += 1;
	}
	return state;
}

