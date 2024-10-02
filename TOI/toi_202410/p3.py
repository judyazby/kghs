def nprime(n):
	if n == 1:
		return 1
	p = 2
	# 不能從1開始數，n為2會數不到
	for i in range(2, int(n**0.5)+1):
		if n%i == 0:
			p += 2
	# 完全平方數會多+1，要扣掉
	if int(n**0.5)**2 == n:
		p -= 1;
	return p

x, y = map(int, input().split())
n, m = y, 2

for i in range(y-1, x-1, -1):
	temp = nprime(i);
	if temp >= m:
		n = i
		m = temp
print(n, m)