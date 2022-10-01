# Pokemon Game by Sarthak Roy
arr=[]
i=0
while i==0:
    x=input("Pokemon Name:")
    if x=="":
        break
    else:
        arr.append(x)
arr.sort()
for i in range(0,len(arr)-1):
    j=i+1
    while j<len(arr):
        print(arr[i]," beats ", arr[j])
        j=j+1
