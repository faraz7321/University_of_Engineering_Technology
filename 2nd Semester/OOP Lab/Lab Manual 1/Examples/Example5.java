import java.util.Scanner;
public class Example5 {
public static void main(String[] args) {
Scanner scanner = new Scanner(System.in);
System.out.println("Enter Currency Value(In Dollar) ");
int user_input = scanner.nextInt();
if (user_input > 0)
{
System.out.println("Converted Value is " + user_input * 160 + ".");
}
else
{
System.out.println("You have entered invalid value.");
}
}
}