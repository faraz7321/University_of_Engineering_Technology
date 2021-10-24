import java.util.Scanner;
public class Example7 {
public static int findMax(int a , int b){
if (a > b ){
return a;
}
else {
return b;
}
}
public static void main(String[] args) {
Scanner scanner = new Scanner(System.in);
System.out.println("Enter the number 1");
int number1 = scanner.nextInt();
System.out.println("Enter the number 2");
int number2 = scanner.nextInt();
int max = findMax(number1, number2);
System.out.print(" Maximum Number is " + max);
}
}