import java.util.Scanner;

public class Task5 {
    public static void main(String[] args) {// ATM .//
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter amount to withdraw: ");
        int input = scanner.nextInt();
        if (input % 500 == 0) {
            System.out.println("Collect your money");

        } else {
            System.out.println("you have entered invalid amount, kindly entered in multiple of 500");
        }
        scanner.close();
    }
}