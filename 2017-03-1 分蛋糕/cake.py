
n,k = input().split();
n,k=int(n),int(k);
cake = input().split();
count=0;
sum=0;
for i in range(n):
    c=int(cake[i])
    sum+=c
    if sum>=k:
        count = count + 1
        sum=0
if sum>0:
    count = count + 1
print(count)