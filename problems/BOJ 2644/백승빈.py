people = [[0]*101 for i in range(101)]
v = [0]*101

n = int(input(""))
p1, p2 = input("").split(" ")
m = int(input(""))

for i in range(m):
  x, y = input("").split(" ")
  x = int(x)
  y = int(y)
  people[x][y] = people[y][x] = 1
  
q = []
q.append(int(p1))

while q!=[] :
  present = q.pop(0)
  for i in range(1,n+1):
    if people[present][i] != 0 and v[i] == 0:
      v[i] = v[present]+1
      q.append(i)

if(v[int(p2)]!=0):
  print(v[int(p2)])
else:
  print(-1)