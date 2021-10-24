import java.util.*;

public class Example8 {
    public static void main(String[] args) {
        // list declaration
        List<String> strList = new ArrayList<String>();
        strList.add("Now");
        strList.add("move");
        strList.add("towards");
        strList.add("list");
        System.out.println("List is: " + strList);
        // Update List Values
        strList.set(3, "Java");
        System.out.println("Updated List is: " + strList);
        // Remove By Index
        strList.remove(3);
        System.out.println("Updated List after removal of Specified index: " + strList);
        // Add new Object
        strList.add("OOP");
        System.out.println("List is: " + strList);
        // Remove By Object
        strList.remove("towards");
        System.out.println("Updated List after removal of Specified String: " + strList);
    }
}