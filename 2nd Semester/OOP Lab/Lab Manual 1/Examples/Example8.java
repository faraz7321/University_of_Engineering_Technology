import java.util.Scanner;4
public class Example8 {
public static void main(String[] args) {
int n=-1;
Scanner scanner = new Scanner(System.in);
System.out.print("Enter no. of elements you want in array:");
n = scanner.nextInt();
int arr[] = new int[n];
int square[] = new int[n];
int cube[] = new int[n];
int sums[] = new int[n];
System.out.println("Enter all the elements:");
for(int i = 0; i < n; i++)
{
arr[i] = scanner.nextInt();
square[i] = arr[i]*arr[i];
cube[i] = arr[i]*arr[i]*arr[i];
sums[i] = arr[i]+ square[i]+cube[i];
}
System.out.print(" Input array is ");
for(int i = 0; i < n; i++)
{
System.out.print(">>"+arr[i]);
}
System.out.print(" Square array is ");
for(int i = 0; i < n; i++)
{
System.out.print(">>"+square[i]);
}
System.out.print(" Cubic array is ");
for(int i = 0; i < n; i++)
{
System.out.print(">>"+cube[i]);
}
System.out.print(" Sum array is ");
for(int i = 0; i < n; i++)
{
System.out.print(">>"+sums[i]);
}
}
}