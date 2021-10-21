def partition(start, end, array):
      
    pivot_index = start 
    pivot = array[pivot_index]
      
    while start < end:
          
        while start < len(array) and array[start] <= pivot:
            start += 1
              
        while array[end] > pivot:
            end -= 1
          
        if(start < end):
            array[start], array[end] = array[end], array[start]
      
    array[end], array[pivot_index] = array[pivot_index], array[end]
     
    return end
      
def quick_sort(start, end, array):
      
    if (start < end):
        p = partition(start, end, array)
        quick_sort(start, p - 1, array)
        quick_sort(p + 1, end, array)

arr = []
n = int(input("Number of elements in the array: "))
print("Enter each elemnt on one line: ");
for i in range(n):
    temp = input("> ")
    if temp.isnumeric():
        temp = int(temp)
    arr.append(temp)
quick_sort(0,n-1,arr);
print(f'Sorted array: {arr}')