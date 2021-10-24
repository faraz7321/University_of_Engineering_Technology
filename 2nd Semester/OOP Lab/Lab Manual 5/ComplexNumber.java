package app;

import java.lang.Math;

public class ComplexNumber {
    private double real;
    private double imaginary;

    public ComplexNumber(double r, double i) {
        real = r;
        imaginary = i;
    }

    /**
     * @return double
     */
    public double getImaginary() {
        return imaginary;
    }

    /**
     * @return double
     */
    public double getReal() {
        return real;
    }

    /**
     * this meathod is used to calculate sum of two complex number.
     * 
     * @param c2
     * @return ComplexNumber
     */
    public ComplexNumber sum(ComplexNumber c2) {
        // creating a temporary complex number to hold the sum of two numbers
        ComplexNumber temp = new ComplexNumber(0, 0);

        temp.real = this.real + c2.real;
        temp.imaginary = this.imaginary + c2.imaginary;

        // returning the output complex number
        return temp;
    }

    /**
     * this meathod is used to subtract two complex number.
     * 
     * @param c2
     * @return ComplexNumber
     */
    public ComplexNumber subtract(ComplexNumber c2) {
        ComplexNumber temp = new ComplexNumber(0, 0);

        temp.real = this.real - c2.real;
        temp.imaginary = this.imaginary - c2.imaginary;

        // returning the output complex number
        return temp;

    }

    /**
     * this meathod is used to calculate product of two complex number.
     * 
     * @param c2
     * @return ComplexNumber
     */
    public ComplexNumber product(ComplexNumber c2) {
        ComplexNumber temp = new ComplexNumber(0, 0);

        temp.real = (this.real * c2.real) - (this.imaginary * c2.imaginary);
        temp.imaginary = (this.real * c2.imaginary) + (this.imaginary * c2.real);

        // returning the output complex number
        return temp;
    }

    /**
     * this meathod is used to divide two complex number.
     * 
     * @param c1
     * @return ComplexNumber
     */
    public ComplexNumber division(ComplexNumber c2) {
        ComplexNumber temp = new ComplexNumber(0, 0);
        temp.real = (this.real * c2.real) - (this.imaginary * c2.imaginary);
        temp.imaginary = (this.real * c2.imaginary) + (this.imaginary * c2.real);

        // returning the output complex number
        return temp;
    }

    /**
     * @param c1
     * @return ComplexNumber
     */
    public ComplexNumber sin() {

        ComplexNumber temp = new ComplexNumber(0, 0);
        double x = Math.sin(this.real) * Math.cos(this.imaginary);
        double y = Math.sin(this.imaginary) * Math.cos(this.real);
        temp.real = x;
        temp.imaginary = y;

        // returning the output complex number
        return temp;
    }

    /**
     * @param c1
     * @return ComplexNumber
     */
    public ComplexNumber cos() {

        ComplexNumber temp = new ComplexNumber(0, 0);
        double x = Math.cos(this.real) * Math.cos(this.imaginary);
        double y = Math.sin(this.imaginary) * Math.sin(this.real);
        temp.real = x;
        temp.imaginary = y;

        // returning the output complex number
        return temp;
    }

    /**
     * @param c1
     * @return ComplexNumber
     */
    public ComplexNumber tan(ComplexNumber c1) {

        ComplexNumber temp = new ComplexNumber(0, 0);

        // returning the output complex number
        return temp;
    }

    /**
     * @param c1
     * @return ComplexNumber
     */
    public ComplexNumber abs(ComplexNumber c1) {

        ComplexNumber temp = new ComplexNumber(0, 0);

        // returning the output complex number
        return temp;
    }

    /**
     * @param c1
     * @return ComplexNumber
     */
    public ComplexNumber norm(ComplexNumber c1) {

        ComplexNumber temp = new ComplexNumber(0, 0);

        // returning the output complex number
        return temp;
    }

    /**
     * @param c1
     * @return ComplexNumber
     */
    public ComplexNumber conjugate(ComplexNumber c1) {

        ComplexNumber temp = new ComplexNumber(0, 0);

        // returning the output complex number
        return temp;
    }
}
