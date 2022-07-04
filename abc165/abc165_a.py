k = int(input())
a,b = map(int, input().split())

flag =(b//k)-((a-1)//k)
if flag>0:
  print("OK")
else:
  print("NG")