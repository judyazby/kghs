t = int(input())
if t*3 < 299:
	print(t*3)
elif t <= 300:
	print(299)
elif 299 + (t-300)*3 <= 699:
	print(299 + (t-300)*3)
elif t <= 750:
	print(699)
else:
	print(699+(t-750)*3)