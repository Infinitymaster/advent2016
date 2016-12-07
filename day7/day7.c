#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

void advent1(char *input);
bool match(char inside, char outside, char tests[110][3], int index);

int main()
{
	char *in;
	int fd, i;
	in = malloc(1000000 * sizeof(char));
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
	char *ins, aba[110][3], bab[110][3];	
	bool outside, SSL;
	int i, c, L, P, count, abax, babx;
	count = 0;
	ins = strtok(input, "\n");
	while(NULL != ins){
		for(i=0; i<110; i++){
			memset(aba[i], 0, 3);
			memset(bab[i], 0, 3);
		}
		abax = 0;
		babx = 0;
		c = 2;
		L = 1;
		P = 0;
		outside = true;
		SSL = false;
		if(ins[c] == '[' || ins[L] == '[' || ins[P] == '[') outside = false;
		for(; c < strlen(ins) && !SSL; c++, L++, P++){
			if(outside){
				if(ins[c] == '['){
					outside = false;
				} else if(ins[c] == ins[P] && ins[L] != ']'){
					aba[abax][0] = ins[P];
					aba[abax][1] = ins[L];
					aba[abax][2] = ins[c];
					abax++;
					if(match(ins[c], ins[L], bab, babx)) SSL = true;
				}
			} else {
				if(ins[c] == ']'){
					outside = true;
				} else if(ins[c] == ins[P] && ins[L] != '[' ){
					bab[babx][0] = ins[P];
					bab[babx][1] = ins[L];
					bab[babx][2] = ins[c];
					babx++;
					if( match(ins[c], ins[L], aba, abax)) SSL = true;
				}
			}
		}
		if(SSL) count++;
		ins = strtok(NULL, "\n");
	}
	printf("%d\n", count);
	free(ins);
}

bool match(char inside, char outside, char tests[110][3], int index){
	int i;
	for(i=0; i<index; i++){
		if(outside == inside) return false;
		if(tests[i][0] == outside && tests[i][2] == outside && tests[i][1] == inside) return true;
	}
	return false;
}
