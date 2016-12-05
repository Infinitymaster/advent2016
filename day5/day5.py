import hashlib
def fuckinghash(code, var):
	tocode = (code + str(var)).encode()
	return tocode

count = 0
code = 'cxdnnyjw'
var = 0
password = [ '%', '%', '%', '%', '%', '%', '%', '%']
while count < 8:
	tohash = fuckinghash(code, var)
	hash = hashlib.md5(tohash).hexdigest()
	if(hash[:5] == '00000'):
		if(int(hash[5], 16) < 8 and password[int(hash[5])] == '%'):
			password[int(hash[5])] = hash[6]
			count += 1
	var += 1
print(password)
