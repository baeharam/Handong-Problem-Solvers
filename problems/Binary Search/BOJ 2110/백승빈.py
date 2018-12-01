areas = []

nums = list(map(int, input().split(" ")))

for i in range(nums[0]):
  area = int(input())
  areas.append(area)

copy = sorted(areas)

left = 1
right = copy[len(copy)-1]-copy[0]

while left<=right:
  dif = int((left+right)/2)
  count=1
  standard = copy[0]

  for i in range(nums[0]):
    if(copy[i]-standard>=dif):
      count+=1
      standard = copy[i]
      
  if count >= nums[1]:
    answer = dif
    left = dif+1
  else:
    right = dif-1

print(answer)
