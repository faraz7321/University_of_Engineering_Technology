import java.util.Scanner;

public class Task2 {
    public static void main(String[] args) {// Instruct players about weather.//
        Scanner scanner = new Scanner(System.in);
        System.out.print("Is it raining outside? (Y/N): ");
        String str = scanner.next();
        char h = str.charAt(0);
        if (h == 'Y' || h == 'y') {
            System.out.println("\nTake Rest\n");
        } else if (h == 'n' || h == 'N') {
            System.out.print("\nWhat is the temperature outside?: ");
            int temperature = scanner.nextInt();
            if (temperature >= 80) {
                System.out.println("\ngo and play\n");
            } else {
                System.out.println("its too cold outside\n");
            }
        }
        scanner.close();
    }
}