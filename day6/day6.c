#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

void advent1(char *input);

int main()
{
	char *in;
	int fd, i;
	in = malloc(100000 * sizeof(char));
	fd = open("input", O_RDONLY);
	if(in==NULL || fd < 0){
		perror("try again");
		exit(1);
	}
	for(i=0; read(fd, in + (i * 256), 256); i++);
	close(fd);
	advent1(in);
	free(in);
	exit(0);
}

void advent1(char *input)
{
	char *instruction, c[9]; 
	int i, j, min, counts[8][26];
	for(i=0; i<8; i++){
		for(j=0; j<26; j++){
			counts[i][j] = 0;
		}
	}
	c[8] = 0;
	//name = malloc(100 * sizeof(char));
	//hash = malloc(100 * sizeof(char));
	instruction = strtok(input, "\n");
	while(NULL != instruction){
		sscanf(instruction, "%c%c%c%c%c%c%c%c", c, c+1, c+2, c+3, c+4, c+5, c+6, c+7); // gross
		for(i=0; i<8; i++){
			counts[i][c[i] - 97] ++;
		}
		//memset(name, 0, 100);
		//memset(hash, 0, 100);
		instruction = strtok(NULL, "\n");
	}
	for(i=0; i<8; i++){
		min = 1000000;
		for(j=0; j<26; j++){
			if(counts[i][j] < min && counts[i][j] != 0){ 
				min = counts[i][j];
				c[i] = j + 97;
			}
		}
	}
	printf("%s\n", c); 
}

