#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

void advent1(char *input);
void cipher(char *name, int ID);

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
	char test[5], *name, *hash, *instruction; 
	int i, j, sum, max[5], ID, chars[26];
	sum = 0;
	ID = 0;
	name = malloc(100 * sizeof(char));
	hash = malloc(100 * sizeof(char));
	instruction = strtok(input, "\n");
	while(NULL != instruction){
		memset(name, 0, 100);
		memset(hash, 0, 100);
		for(i=0; i < 5; i++){
			max[i] = 0;
			test[i] = 0;
			chars[i] = 0;
		}
		for(; i<26; i++){
			chars[i] = 0;
		}
		
		sscanf(instruction, "%[^0-9]%d[%[a-z]]", name, &ID, hash);
		for(i=0; i< strlen(name); i++){
			if(name[i] != '-') 
				chars[name[i] - 97] += 1;
		}
		
		for(i=0; i < 5; i++){
			for(j=0; j < 26; j++){
				if(chars[j] > max[i]){
					max[i] = chars[j];
					test[i] = j + 97;
				}
			}
			chars[test[i] - 97] = 0;
		}
		if(!strcmp(test, hash)){
			sum+= ID;
			cipher(name, ID);
			printf("%s with ID: %d\n\n", name, ID);
		}
		instruction = strtok(NULL, "\n");
	}
	free(name);
	free(hash);
}

void cipher(char *name, int ID){
	int len, i, j;
	len = strlen(name);
	for(i=0; i<ID; i++){
		for(j=0; j<len; j++){
			if(name[j] < 'z'){
				name[j]++;
			} else {
				name[j] = 'a';
			}
		}
	}
}
