w, h = 50, 6
display = [[0 for x in range(w)] for y in range(h)]

def rect(A, B):
	for x in range(A):
		for y in range(B):
				display[y][x] = 1

def rot(dir, A, B):
	if dir == 'row':
		temp = [0 for x in range (w)]
		for x in range(w):
			if display[A][x] > 0:
				temp[(x + B)%w] += 1
		display[A] = temp
	else:
		temp = [0 for y in range (h)]
		for y in range(h):
			if display[y][A] > 0:
				temp[(y + B)%h] += 1
		for y in range(h):
			display[y][A] = temp[y]


f = open('input', 'r')
for line in f:
	cmd = line.split()
	if cmd[0] == 'rect':
		rect(int(cmd[1].split('x')[0]), int(cmd[1].split('x')[1]))
	elif cmd[0] == 'rotate':
		if cmd[1] == 'row':
			rot('row', int(cmd[2][2:]), int(cmd[4]))
		else:
			rot('column', int(cmd[2][2:]), int(cmd[4])) 

count = 0
print('\n')
for y in range(h):
	for x in range(w):
		count += display[y][x]
		if display[y][x]:
			print('@', end='')
		else:
			print(' ', end='')
	print('')
print('\n')


