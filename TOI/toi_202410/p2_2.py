t = int(input())
a = t*3;
b = 299+max(0, (t-300)*3);
c = 699+max(0, (t-750)*3);
print(min(a, min(b, c)))