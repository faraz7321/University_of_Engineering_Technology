import java.util.Scanner;
public class Example2 {
public static void main(String[] args) {
// Creates a reader instance which takes
// input from standard input - keyboard
Scanner reader = new Scanner(System.in);
System.out.print("Enter a number in feet: ");
// nextInt() reads the next integer from the keyboard
int feet = reader.nextInt();
int inch = feet * 12;
System.out.println("Converted Value in inch's' is: "+ inch);
}
}