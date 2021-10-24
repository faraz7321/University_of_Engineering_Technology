import java.util.*;

public class Task2 {

    static Set<String> stringSet = new HashSet<String>();

    public static Set<String> saveData(String s) {
        stringSet.add(s);
        return stringSet;
    }

    public static String displayData() {
        System.out.println("\nDisplaying data in Set");
        String display = "";
        Iterator<String> itr = stringSet.iterator();
        while (itr.hasNext()) {
            display += itr.next() + "\n";
        }
        return display;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String name = "";
        String in = "";
        do {
            System.out.print("\033[H\033[2J");
            System.out.flush();
            System.out.println("Press 1 to add new data\nPress 2 to view data\n\nEnter input: ");
            in = scanner.nextLine();
            if (in.equals("1")) {
                System.out.println("Enter name: ");
                name = scanner.nextLine();
                saveData(name);
                System.out.println("Saved!");
                scanner.nextLine();
            } else if (in.equals("2")) {
                System.out.println(displayData());
                scanner.nextLine();
            }
        } while (!in.equals("0"));

    }

}