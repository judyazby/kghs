def nprime(n):
	p = 0
	for i in range(1, n+1):
		if n%i == 0:
			p += 1
	return p

x, y = map(int, input().split())
n, m = y, 2

for i in range(y-1, x-1, -1):
	temp = nprime(i);
	if temp >= m:
		n = i
		m = temp
print(n, m)