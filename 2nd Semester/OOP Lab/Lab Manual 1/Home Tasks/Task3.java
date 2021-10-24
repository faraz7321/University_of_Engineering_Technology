public class Task3 {
    public static void main(String[] args) {// Two Numbers Swapping
        int x = 70;
        int y = 33;
        System.out.println("First Number: " + x);
        System.out.println("Second Number: " + y);
        x = x + y;
        y = x - y;
        x = x - y;

        System.out.println("\nAfter Swaping");
        System.out.println("First Number: " + x);
        System.out.println("Second Number: " + y);

    }
}