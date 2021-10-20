package lecture_8_ARRAYS.Java;

import java.util.*;

public class QuickSort {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter array size: ");
        int arraySize = scanner.nextInt();

        System.out.println("Enter array elements: ");
        int[] nums = new int[arraySize];
        for (int i = 0; i < arraySize; i++) {
            nums[i] = scanner.nextInt();
        }

        quickSort(nums, 0, arraySize - 1);

        System.out.println("After Implementing Quick sort, the array is: ");
        for (int i = 0; i < arraySize; i++) {
            System.out.print(nums[i] + " ");
        }
        System.out.println();

    }


    static void quickSort(int[] nums, int low, int high) {
        if (low >= high) {
            return;
        }

        int startIndex = low;
        int endIndex = high;
        int midIndex = startIndex + (endIndex - startIndex) / 2;

        while (startIndex <= endIndex) {
            while (nums[startIndex] < nums[midIndex]) {
                startIndex++;
            }
            while (nums[endIndex] > nums[midIndex]) {
                endIndex--;
            }

            if (startIndex <= endIndex) {
                int temp = nums[startIndex];
                nums[startIndex] = nums[endIndex];
                nums[endIndex] = temp;
                startIndex++;
                endIndex--;
            }
        }

        quickSort(nums, low, endIndex);
        quickSort(nums, startIndex, high);

    }
}
