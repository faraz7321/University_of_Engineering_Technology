package app;

import javax.swing.JOptionPane;

public class App {
    static String printMenu() {
        String menu = JOptionPane.showInputDialog("Choose from the following options: \n\n" + "Press 1 For Addition\n"
                + "Press 2 For Subtraction\n" + "Press 3 For Mutiplication\n" + "Press 4 For Division");
        return menu;
    }

    public static void main(String[] args) throws Exception {
        do {
            switch (printMenu()) {
            // Addition.//
            case "1": {

                break;
            }
            // Subtraction.//
            case "2": {

                break;
            }
            // Multiplication.//
            case "3": {

                break;
            }
            // Division.//
            case "4": {

                break;
            }
            // End Program.//
            case "0": {

                break;
            }
            default:

                JOptionPane.showMessageDialog(null, "INVALID INPUT!\nPlease choose a correct option");

                break;
            }

        } while (!printMenu().equals("0"));
    }
}
