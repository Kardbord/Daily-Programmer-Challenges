package Fractions;

/**
 * Daily_Prog#277E
 * Created on 5/17/2017
 *
 * Contains the main method
 *
 * @author Tanner Kvarfordt
 * @version 1.0
 */
public class Main {
    public static void main(String[] args) {
        Fraction fraction = new Fraction(4, 8);
        System.out.print(fraction.getAsString());
        fraction.simplify();
        System.out.println(" = " + fraction.getAsString());

        fraction.setNumerator(8);
        fraction.setDenominator(4);
        System.out.print(fraction.getAsString());
        fraction.simplify();
        System.out.println(" = " + fraction.getAsString());

        fraction.setNumerator(0);
        fraction.setDenominator(4);
        System.out.print(fraction.getAsString());
        fraction.simplify();
        System.out.println(" = " + fraction.getAsString());

       try {
            fraction.setNumerator(8);
            fraction.setDenominator(0);
            System.out.print(fraction.getAsString());
            fraction.simplify();
            System.out.println(" = " + fraction.getAsString());
        } catch (Exception e) {
            // This is expected behavior
            fraction.setDenominator(1); // set denom to not be 0
        }

        fraction.setNumerator(15);
        fraction.setDenominator(3);
        System.out.print(fraction.getAsString());
        fraction.simplify();
        System.out.println(" = " + fraction.getAsString());

        fraction.setNumerator(3);
        fraction.setDenominator(15);
        System.out.print(fraction.getAsString());
        fraction.simplify();
        System.out.println(" = " + fraction.getAsString());

        fraction.setNumerator(17);
        fraction.setDenominator(3);
        System.out.print(fraction.getAsString());
        fraction.simplify();
        System.out.println(" = " + fraction.getAsString());

        fraction.setNumerator(3);
        fraction.setDenominator(17);
        System.out.print(fraction.getAsString());
        fraction.simplify();
        System.out.println(" = " + fraction.getAsString());

        fraction.setNumerator(-3);
        fraction.setDenominator(17);
        System.out.print(fraction.getAsString());
        fraction.simplify();
        System.out.println(" = " + fraction.getAsString());

        fraction.setNumerator(-3);
        fraction.setDenominator(15);
        System.out.print(fraction.getAsString());
        fraction.simplify();
        System.out.println(" = " + fraction.getAsString());

        fraction.setNumerator(3);
        fraction.setDenominator(-15);
        System.out.print(fraction.getAsString());
        fraction.simplify();
        System.out.println(" = " + fraction.getAsString());

        fraction.setNumerator(-3);
        fraction.setDenominator(-15);
        System.out.print(fraction.getAsString());
        fraction.simplify();
        System.out.println(" = " + fraction.getAsString());
    }
}
