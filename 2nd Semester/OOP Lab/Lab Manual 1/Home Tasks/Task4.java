public class Task4 {
    public static void main(String[] args) {// Reverse String input.//
        String input[] = "he is a programmer".split(" ");
        String reverse = "";
        for (int i = input.length - 1; i >= 0; i--) {
            reverse = reverse + input[i] + " ";
        }
        System.out.println("Reversed String: " + reverse);
    }
}