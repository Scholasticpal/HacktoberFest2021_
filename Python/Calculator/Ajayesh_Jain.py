q=int(input("Enter the Number_1: "))
s=int(input("Enter the Number_2: "))
while(1):

 a=int(input("1: Addition\n2: Substraction\n3: Division\n4: Multiplication\n5: Enter 0 to
Exit\n\nEnter the Input: "))

 if(a==0):
 break
 elif(a==1):
 print("\nThe Addition is:",q+s)
 elif(a==2):
 print("\nThe Substraction is:",q-s)
 elif(a==3):
 print("\nThe Division is:",q/s)
 elif(a==4):
 print("\nThe Multiplication is:",q*s)
 else:
 print("\nWrong Try again")
