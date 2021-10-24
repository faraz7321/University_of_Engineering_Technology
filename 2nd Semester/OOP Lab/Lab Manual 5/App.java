package app;

/**
 * 
 * @author Faraz Ahmad
 */

import javax.swing.JOptionPane;

public class App {

    /**
     * this method is used to print the menu options//
     * 
     * @return String
     */
    static String printMenu() {
        String menu = JOptionPane.showInputDialog(null, "1> ADD\n" + "2> SUBTRACT\n" + "3> MULTIPLY\n" + "4> DIVIDE\n"
                + "5> sin\n" + "6> cos\n" + "7> tan\n" + "8> ABSOLUTE\n" + "9> CONJUGATE\n" + "10> NORMAL\n");
        return menu;
    }

    /**
     * @param args the command line arguments
     * @throws Exception
     */
    public static void main(String[] args) throws Exception {
        double r1, r2, i1, i2;

        do {

            String input1 = JOptionPane.showInputDialog(null, "Enter First Complex Number:\neg (3,4.5)");
            String[] splStrings1 = input1.split(",");
            r1 = Integer.parseInt(splStrings1[0]);
            i1 = Integer.parseInt(splStrings1[1]);
            String input2 = JOptionPane.showInputDialog(null, "Enter Second Complex Number:\neg (3,4.5)");
            String[] splStrings2 = input2.split(",");
            r2 = Integer.parseInt(splStrings2[0]);
            i2 = Integer.parseInt(splStrings2[1]);
            switch (printMenu()) {

            case "1": {

                ComplexNumber c1 = new ComplexNumber(r1, i1);
                ComplexNumber c2 = new ComplexNumber(r2, i2);
                ComplexNumber temp = c1.sum(c2);
                JOptionPane.showMessageDialog(null,
                        input1 + " + " + input2 + " = " + temp.getReal() + " + " + temp.getImaginary() + "i");
                break;
            }
            // SUBTRACTION.//
            case "2": {

                ComplexNumber c1 = new ComplexNumber(r1, i1);
                ComplexNumber c2 = new ComplexNumber(r2, i2);
                ComplexNumber temp = c1.subtract(c2);
                JOptionPane.showMessageDialog(null,
                        input1 + " - " + input2 + " = " + temp.getReal() + " + " + temp.getImaginary() + "i");
                break;
            }
            // MULTIPLICATION.//
            case "3": {

                ComplexNumber c1 = new ComplexNumber(r1, i1);
                ComplexNumber c2 = new ComplexNumber(r2, i2);
                ComplexNumber temp = c1.product(c2);
                JOptionPane.showMessageDialog(null,
                        input1 + " x " + input2 + " = " + temp.getReal() + " + " + temp.getImaginary() + "i");
                break;
            }
            // DIVISION.//
            case "4": {

                break;
            }
            // sin.//
            case "5": {
                ComplexNumber c1 = new ComplexNumber(r1, i1);
                ComplexNumber c2 = new ComplexNumber(r2, i2);
                ComplexNumber temp1 = c1.sin();
                ComplexNumber temp2 = c2.sin();
                JOptionPane.showMessageDialog(null,
                        "sin(" + r1 + " + " + i1 + "i) = " + temp1.getReal() + " + " + temp1.getImaginary() + "i)\n"
                                + "sin(" + r2 + " + " + i2 + "i) = " + temp2.getReal() + " + " + temp2.getImaginary()
                                + "i)");

                break;
            }
            // cos.//
            case "6": {
                ComplexNumber c1 = new ComplexNumber(r1, i1);
                ComplexNumber c2 = new ComplexNumber(r2, i2);
                ComplexNumber temp1 = c1.cos();
                ComplexNumber temp2 = c2.cos();
                JOptionPane.showMessageDialog(null,
                        "cos(" + r1 + " + " + i1 + "i) = " + temp1.getReal() + " + " + temp1.getImaginary() + "i)\n"
                                + "cos(" + r2 + " + " + i2 + "i) = " + temp2.getReal() + " + " + -1*(temp2.getImaginary())
                                + "i)");
                break;
            }
            // tan.//
            case "7": {

                break;
            }
            // conjugate.//
            case "8": {

                break;
            }
            // abs.//
            case "9": {

                break;
            }
            // norm.//
            case "10": {

                break;
            }

            default:
                JOptionPane.showMessageDialog(null, "INVALID INPUT! Please try again.");
                break;
            }
        } while (!printMenu().equals("0"));
    }

}
