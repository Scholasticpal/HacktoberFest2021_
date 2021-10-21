//Sorts a given Input Array using Insertion sort Algorithm

import java.util.Arrays;

class Insertionsort {

	public static void sortArray(int[] inputValues) {

		for (int k = 1; k < inputValues.length - 1; k++) {
			int temp = inputValues[k];
			int j = k - 1;
			while (j >= 0 && temp <= inputValues[j]) {
				inputValues[j + 1] = inputValues[j];
				j = j - 1;
			}
			inputValues[j + 1] = temp;
		}

		System.out.println("Sorted Array is:" + Arrays.toString(inputValues));

	}

	public static void main(String[] args) {
		int[] inputValues = { 9, 14, 3, 2, 43, 11, 58, 22 };
		sortArray(inputValues);
	}

}
