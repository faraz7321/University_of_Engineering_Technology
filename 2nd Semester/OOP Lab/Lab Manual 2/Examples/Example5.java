public class Example5 {
    public static void main(String[] args) {
        // create double type variable
        double number = 20.65;
        System.out.println("User Input Double Value: " + number);
        try {
            // convert into int type
            int data = (int) number;
            System.out.println("The integer value after conversion: " + data);
        } catch (Exception ex) {
            System.out.println("Invalid conversion");
        }
    }
}