#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>


void advent(char *input);
void advent2(char *input);
long ALG(char *in, size_t len);

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
	advent2(in);
	free(in);
	exit(0);
}

void advent(char *input)
{
	char *decompf;
	int i_x, pos, d_x, num, times, mark_x;
	bool marker, done;
	marker = false;
	done = false;
	mark_x = 0;
	i_x = 0;
	pos = 0;
	d_x = 0;
	num = 0;
	times = 0;
	
	decompf = malloc(100000 * sizeof(char));
	printf("%zd\n", strlen(input));
	while(!done){

		 if(marker){
			if (input[i_x] != ')'){
				i_x++;
			} else {
				marker = false;
				i_x++;
				sscanf(input + mark_x, "(%dx%d)", &num, &times);
				printf("copying %d bytes %d times\n", num, times);
				for(times; times > 0; times--){
					strncpy(decompf + d_x, input + i_x, num);
					d_x += num;
				}
				i_x += num;
			}
		
		} else if (input[i_x] == '('){
			marker = true;
			mark_x = i_x;
			i_x++;
		
		} else {
			if(input[i_x] == 0) done = true;
			decompf[d_x] = input[i_x];
			d_x++;
			i_x++;
		}
	}
	
	printf("%zd\n", strlen(decompf));
}

void advent2(char * input){
	long len;
	len = ALG(input, strlen(input));
	printf("Wow! %ld bytes long.\n", len);
}

long ALG(char *in, size_t len){
	long dl;
	int i, m_x, n, t;
	dl = 0;
	n = 0;
	t = 0;
	for(i=0; i < len; i++){
		if(in[i] != '('){
			dl++;
		} else {
			m_x = i;
			for(i; in[i] != ')'; i++);
			i++;
			sscanf(in + m_x, "(%dx%d)", &n, &t);
			dl += ALG(in + i, n) * t;
			i += n - 1;
		}
	}
	return dl;
}
