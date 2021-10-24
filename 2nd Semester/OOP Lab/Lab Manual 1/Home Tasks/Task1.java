import java.util.Scanner;

public class Task1 {// Grade Calculator.//
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int avg = 0;
    char grade;
    int[] arr = new int[8];
    System.out.print("Enter Obtained Marks: ");
    for (int i = 0; i < 8; i++) {
      arr[i] = scanner.nextInt();
    }
    scanner.close();
    for (int i = 0; i < 8; i++) {
      avg = avg + arr[i];
    }
    avg = avg / 8;
    if (avg >= 80) {
      grade = 'A';
    } else if (avg >= 70) {
      grade = 'B';
    } else if (avg >= 60) {
      grade = 'C';
    } else if (avg >= 50) {
      grade = 'D';
    } else {
      grade = 'F';
    }
    System.out.println("Average Marks: " + avg);
    System.out.println("Grade: " + grade);
  }
}
