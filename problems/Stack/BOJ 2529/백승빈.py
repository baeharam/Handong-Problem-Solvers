max_num = []
min_num = []

def swap(numlist,i):
  temp = numlist[i]
  numlist[i] = numlist[i+1]
  numlist[i+1] = temp

def check(numlist):
  count = 0
  for i in range(len(sign_list)):
    if sign_list[i]==">" and numlist[i]<numlist[i+1]:
      swap(numlist,i)
      count=1
    elif sign_list[i]=="<" and numlist[i]>numlist[i+1]:
      swap(numlist,i)
      count=1
  return count,numlist

num = int(input())
sign = input()
sign_list = sign.split(" ")

if(len(sign_list) > num): #sign이 num보다 크면 다 잘라 냄
  for i in range(num,len(sign_list)):
    sign_list.pop(i)

for i in range(9,8-len(sign_list),-1): #max list 추가
  max_num.append(str(i))

for i in range(len(sign_list)+1): #min list 추가 
  min_num.append(str(i))

count = 1
while(count==1):
  count = check(max_num)[0]
print("".join(check(max_num)[1]))

count = 1
while(count==1):
  count = check(min_num)[0]
print("".join(check(min_num)[1]))