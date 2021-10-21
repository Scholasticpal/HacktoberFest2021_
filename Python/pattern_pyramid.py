n = int(input("Enter a number of n: "))
for i in range(n):
    print(" "*(n-i-1),end="")
    for j in range(i+1):
        print(i+1,"",end="")
    print()

