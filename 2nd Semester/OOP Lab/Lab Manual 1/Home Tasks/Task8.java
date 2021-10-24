import java.util.Scanner;

public class Task8 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter String: ");
        String input = scanner.next();
        scanner.close();
        // boolean flag = isNumeric(input);
        if (input.matches("-?\\d+(\\.\\d+)?")) {
            System.out.println("String is a number");
        } else {
            System.out.println("String is not a number");
        }
    }
}