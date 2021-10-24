import java.util.Scanner;
public class Example4 {
public static void main(String[] args) {
Scanner scanner = new Scanner(System.in);
System.out.println("Enter Your First Name");
String firstName = scanner.next();
System.out.println("Enter Your Last Name:");
String lastName = scanner.next();
//Area = (width*height)/2
System.out.println("My Name is: " + firstName +" " + lastName + ".");
}
}