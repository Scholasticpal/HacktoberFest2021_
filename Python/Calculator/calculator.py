#simple calculator
# + addition
# - subtraction
# * multiplication
# / division
def add(x,y):
    return x + y   #Addition
def sub(x,y):
    return x - y   #subtrcation
def multiply(x,y):
    return x * y   #multiplication
def division(x,y):
    return x / y  #integer division
def power(x,y):
    return x ** y #power

#input from user
print("select operation:")
print("1.addition")
print("2.subtraction")
print("3.multiplication")
print("4.division")
print("5.power")

choice=input("Enter your choice:")
num1=int(input("Enter first number:"))
num2=int(input("Enter second number:"))
if choice=='1':
    print(num1,"+",num2,"=",add(num1,num2))
elif choice=='2':
    print(num1,"-",num2,"=",sub(num1,num2))
elif choice=='3':
    print(num1,"*",num2,"=",multiply(num1,num2))
elif choice=='4':
     if num2!=0:
        print(num1,"/",num2,"=",division(num1,num2))
     else:
         print("division with zero case")
elif choice=='5':
    print(num1,"**",num2,"=",power(num1,num2))
else:
    print("Invalid Entry")
