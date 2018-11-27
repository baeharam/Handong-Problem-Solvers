def compare(a, b):
  if a>b:
    return a
  else:
    return b

num = int(input())
for sticker_n in range(num):
  sticker = []
  size = int(input())
  for i in range(2):
    st = list(map(int, input().split(" ")))

    if len(st) > size:
      for k in range(size,len(st)):
        st.pop(k)
  
    sticker.append(st)
  sample = [[0]*2 for i in range(2)]
  sample[0][0] = sticker[0][0]
  sample[1][0] = sticker[1][0]
  sample[0][1] = sticker[0][1] + sample[1][0]
  sample[1][1] = sticker[1][1] + sample[0][0]

  for i in range(2,size,1):
    sample[0].append(sticker[0][i] + compare(sample[1][i-1], sample[1][i-2]))
    sample[1].append(sticker[1][i] + compare(sample[0][i-1], sample[0][i-2]))

  print(compare(sample[0][size-1],sample[1][size-1]))