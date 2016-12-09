#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

/* Here's a skeleton file that covers the file reading part, and has
 * a basic outline of a function */

void advent(char *input);

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
	advent(in);
	free(in);
	exit(0);
}

void advent(char *input)
{
	char *ins; 
	int i;
	i=0;
	//name = malloc(100 * sizeof(char));
	ins = strtok(input, "\n");
	while(NULL != ins){
		sscanf(ins, "");
		//memset(name, 0, 100);
		ins = strtok(NULL, "\n");
	}
}

