list_quadtree = []

def check_same(x,y,size):
  global list_quadtree
  for i in range(y,y+size,1):
    for j in range(x,x+size,1):
      if list_quadtree[y][x] != list_quadtree[i][j]:
        return False
  return True

def quadtree(x,y,size):
  if check_same(x,y,size) == False:
    print("(",end='')
    if(size > 1):
      quadtree(x,y,int(size/2))
      quadtree(x+int(size/2),y,int(size/2))
      quadtree(x,y+int(size/2),int(size/2))
      quadtree(x+int(size/2),y+int(size/2),int(size/2))
      print(")",end='')        
  else:
    print(list_quadtree[y][x],end='')
      
  #순서대로 확인
  #확인하다가 다른게 나오면
  #더 작게 들어가서 확인

size = int(input()) #size 입력받기
for i in range(size):
  list_quadtree.append(input())

quadtree(0,0,size)
