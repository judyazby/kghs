l, w, h, k = map(int, input().split())
if not(l%k or w%k or h%k):
	print((l*w*h)//(k*k*k))
else:
	print(0)