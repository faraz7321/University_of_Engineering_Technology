import java.util.Scanner;

public class Task6 {// Factorial Calculator.//

    public static int calculateFactorial(int x) {
        int fact = 1;
        for (int i = 1; i <= x; i++) {
            fact = fact * i;
        }
        return fact;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter Number to calculate its factorial: ");
        int x = scanner.nextInt();
        int fact = calculateFactorial(x);
        System.out.println("Factorial: " + fact);
        scanner.close();
    }
}