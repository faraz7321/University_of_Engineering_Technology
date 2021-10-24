import java.util.Scanner;

public class Task9 {// Palindrome.//
    public static boolean isPalindrome(String input) {
        boolean flag = false;
        int length = input.length();
        char array[] = input.toCharArray();
        for (int i = 0; i < length; i++) {
            if (array[i] != array[length - i - 1]) {
                flag = true;
                break;
            }
        }
        return flag;
    }

    public static void main(String[] arg) {
        System.out.print("Enter String : ");
        Scanner scanner = new Scanner(System.in);
        String input = scanner.next();
        scanner.close();
        boolean flag = isPalindrome(input);
        if (flag == false) {
            System.out.print("String is a Palindrome");
        } else {
            System.out.print("String is not a Palindrome");
        }
    }
}