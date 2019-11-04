lr,ly,lg=input().split()
lr,ly,lg=int(lr),int(ly),int(lg)
n=int(input())
time=0
for i in range(n):
    k,t=input().split()
    k,t=int(k),int(t)
    if k==0: time+=t
    if k==1: time+=t
    if k==2: time+=(t+lr)
    if k==3: pass
print(time)