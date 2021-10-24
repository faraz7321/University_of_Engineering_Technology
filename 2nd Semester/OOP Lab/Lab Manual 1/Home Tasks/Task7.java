import java.util.Scanner;

public class Task7 {// Integer Array Sorting.//
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] intArr = new int[10];
        int temp = 0;
        System.out.print("Enter Elements: ");
        for (int i = 0; i < 10; i++) {
            intArr[i] = scanner.nextInt();
        }
        scanner.close();
        for (int i = 0; i < 10; i++) {
            for (int j = i + 1; j < 10; j++) {
                if (intArr[i] > intArr[j]) {
                    temp = intArr[i];
                    intArr[i] = intArr[j];
                    intArr[j] = temp;
                }
            }
        }
        System.out.print("\nElements of array sorted in ascending order: ");
        for (int i = 0; i < 10; i++) {
            System.out.print(intArr[i] + " ");
        }
        System.out.print("\nElements of array sorted in decending order: ");
        for (int i = 9; i >= 0; i--) {
            System.out.print(intArr[i] + " ");
        }
    }
}