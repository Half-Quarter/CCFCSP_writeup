op=map(int,input().split())
score = 0
comb = 1
op = list(op);
for index in range(len(op)) :
    if index==0:
        if op[index]==1: score=score+1
        elif op[index]==2:
            score=score+2
    else :
     if op[index]==2:
         if op[index-1]==2 :
            comb = comb + 1
            score=score+comb*2
         elif op[index-1]==1 :
            comb = 1
            score=score+2
     elif op[index]==1 :
         comb = 1
         score=score+1
print(score)
