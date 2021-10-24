import java.util.Iterator;
import java.util.LinkedList;
import java.util.Scanner;

class Operations {
    LinkedList<Integer> L1 = new LinkedList<>();
    LinkedList<Integer> L2 = new LinkedList<>();

    public LinkedList<Integer> saveEven(int number) {
        for (int i = 0; i <= number; i++) {
            if (i % 2 == 0) {
                L1.add(i);
            }
        }

        return L1;
    }

    public LinkedList<Integer> displayEven() {
        Iterator<Integer> itr = L1.iterator();
        while (itr.hasNext()) {
            int e = 2 * itr.next();
            L2.add(e);
        }
        Iterator<Integer> itr2 = L2.iterator();
        while (itr2.hasNext()) {
            System.out.println(itr2.next());
        }
        return L2;
    }

    public int printEven(int number) {
        Iterator<Integer> itr = L1.iterator();
        int search = 0;
        while (itr.hasNext()) {
            if (number == itr.next()) {
                return number;
            }
        }
        return search;
    }
}

public class Task3 {
    public static void main(String[] args) {
        Operations op = new Operations();
        System.out.println("Enter a positive integer: ");
        Scanner scanner = new Scanner(System.in);
        int number = scanner.nextInt();
        op.saveEven(number);
        op.displayEven();
        System.out.println("Enter number to search: ");
        number = scanner.nextInt();
        System.out.println(op.printEven(number));
    }
}
