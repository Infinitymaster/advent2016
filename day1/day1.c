#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int advent1(char *input);
int advent2(char *input);

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
	printf("Answer: %d blocks away\n", advent2(in));
	free(in);
	exit(0);
}

int advent1(char *input)
{
	char heading, turn_dir;
	char *instruction;
	int dist, h, v;
	heading = 'N';
	instruction = strtok(input, ",");
	h = 0;
	v = 0;
	while(NULL != instruction){
		sscanf(instruction, " %c%i ", &turn_dir, &dist);
		if('R' == turn_dir){
			heading = ('N' == heading ? 'E' : ('E' == heading ? 'S' : ('S' == heading ? 'W' : 'N')));
		} else {
			heading = ('N' == heading ? 'W' : ('E' == heading ? 'N' : ('S' == heading ? 'E' : 'S')));
		}
		printf("Moving %d in %c direction\n", dist, heading);
		switch(heading){
			case 'N':
				v += dist;
				break;
			case 'S':
				v -= dist;
				break;
			case 'E':
				h += dist;
				break;
			case 'W':
				h -= dist;
				break;
		}
		instruction = strtok(NULL, ",");
	}
	h = abs(h);
	v = abs(v);
	h += v;
	return h;
}

int advent2(char *input)
{
	char heading, turn_dir;
	char *instruction;
	bool crossed_yet;
	int dist, h, v, i_num, rip_i, step;
	int pos[2];
	int rip[5000][2];
	heading = 'N';
	pos[0] = 0;
	pos[1] = 0;
	i_num = 0;
	crossed_yet = false;

	instruction = strtok(input, ",");
	while(NULL != instruction && !crossed_yet){
		sscanf(instruction, " %c%i ", &turn_dir, &dist);
		if('R' == turn_dir){
			heading = ('N' == heading ? 'E' : ('E' == heading ? 'S' : ('S' == heading ? 'W' : 'N')));
		} else {
			heading = ('N' == heading ? 'W' : ('E' == heading ? 'N' : ('S' == heading ? 'E' : 'S')));
		}
		
		printf("Moving %d in %c direction\n", dist, heading);
		switch(heading){
			case 'N':
				for(step = 0; step < dist && !crossed_yet; step++, i_num++){
					pos[1] ++;
					for(rip_i = 0; rip_i < i_num; rip_i++){
						if(pos[0] == rip[rip_i][0] && pos[1] == rip[rip_i][1])
							crossed_yet = true;
					}
					rip[i_num][0] = pos[0];
					rip[i_num][1] = pos[1];
				}
				break;
			case 'S':
				for(step = 0; step < dist && !crossed_yet; step++, i_num++){
					pos[1] --;
					for(rip_i = 0; rip_i < i_num; rip_i++){
						if(pos[0] == rip[rip_i][0] && pos[1] == rip[rip_i][1])
							crossed_yet = true;
					}
					rip[i_num][0] = pos[0];
					rip[i_num][1] = pos[1];
				}
				break;
			case 'E':
				for(step = 0; step < dist && !crossed_yet; step++, i_num++){
					pos[0] ++;
					for(rip_i = 0; rip_i < i_num; rip_i++){
						if(pos[0] == rip[rip_i][0] && pos[1] == rip[rip_i][1])
							crossed_yet = true;
					}
					rip[i_num][0] = pos[0];
					rip[i_num][1] = pos[1];
				}
				break;
			case 'W':
				for(step = 0; step < dist && !crossed_yet; step++, i_num++){
					pos[0] --;
					for(rip_i = 0; rip_i < i_num; rip_i++){
						if(pos[0] == rip[rip_i][0] && pos[1] == rip[rip_i][1])
							crossed_yet = true;
					}
					rip[i_num][0] = pos[0];
					rip[i_num][1] = pos[1];
				}
				break;
		}
		instruction = strtok(NULL, ",");
		i_num++;
	}

	return abs(pos[0]) + abs(pos[1]);
}
