public class Example4 {
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
/*
 * public static void main(String[] args) { // create string type variable
 * String data = "10"; System.out.println("The string value is: " + data); //
 * convert string variable to int int num = Integer.parseInt(data);
 * System.out.println("The integer value is: " + num); }
 */