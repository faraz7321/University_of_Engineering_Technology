import java.util.Scanner;
public class Example6 {
  
public static void main(String[] args) {
Scanner scanner = new Scanner(System.in);
System.out.println("Enter the number");
int number = scanner.nextInt();
System.out.print(" All positive even integers are ");
for (int i = 1; i <= number; i++)
{
//if number%2 == 0 it means its an even number
if (i % 2 == 0)
{
System.out.print(i + " ");
}
}
}
}