/**
 * Daily_Prog#277E
 * Created on 5/17/2017
 *
 * TODO Add a short description of the class here
 *
 * @author Tanner Kvarfordt
 * @version 1.0
 */
public class Main {
    public static void main(String[] args) {
        Fraction fraction = new Fraction(4, 8);
        System.out.print(fraction.getNumerator() + " / " + fraction.getDenominator());
        fraction.simplify();
        System.out.println(" = " + fraction.getNumerator() + " / " + fraction.getDenominator());

        fraction.setNumerator(8);
        fraction.setDenominator(4);
        System.out.print(fraction.getNumerator() + " / " + fraction.getDenominator());
        fraction.simplify();
        System.out.println(" = " + fraction.getNumerator() + " / " + fraction.getDenominator());

        fraction.setNumerator(0);
        fraction.setDenominator(4);
        System.out.print(fraction.getNumerator() + " / " + fraction.getDenominator());
        fraction.simplify();
        System.out.println(" = " + fraction.getNumerator() + " / " + fraction.getDenominator());

        fraction.setNumerator(8);
        fraction.setDenominator(0);
        System.out.print(fraction.getNumerator() + " / " + fraction.getDenominator());
        fraction.simplify();
        System.out.println(" = " + fraction.getNumerator() + " / " + fraction.getDenominator());

        fraction.setNumerator(15);
        fraction.setDenominator(3);
        System.out.print(fraction.getNumerator() + " / " + fraction.getDenominator());
        fraction.simplify();
        System.out.println(" = " + fraction.getNumerator() + " / " + fraction.getDenominator());

        fraction.setNumerator(3);
        fraction.setDenominator(15);
        System.out.print(fraction.getNumerator() + " / " + fraction.getDenominator());
        fraction.simplify();
        System.out.println(" = " + fraction.getNumerator() + " / " + fraction.getDenominator());

        fraction.setNumerator(17);
        fraction.setDenominator(3);
        System.out.print(fraction.getNumerator() + " / " + fraction.getDenominator());
        fraction.simplify();
        System.out.println(" = " + fraction.getNumerator() + " / " + fraction.getDenominator());

        fraction.setNumerator(3);
        fraction.setDenominator(17);
        System.out.print(fraction.getNumerator() + " / " + fraction.getDenominator());
        fraction.simplify();
        System.out.println(" = " + fraction.getNumerator() + " / " + fraction.getDenominator());

        fraction.setNumerator(-3);
        fraction.setDenominator(17);
        System.out.print(fraction.getNumerator() + " / " + fraction.getDenominator());
        fraction.simplify();
        System.out.println(" = " + fraction.getNumerator() + " / " + fraction.getDenominator());

        fraction.setNumerator(-3);
        fraction.setDenominator(15);
        System.out.print(fraction.getNumerator() + " / " + fraction.getDenominator());
        fraction.simplify();
        System.out.println(" = " + fraction.getNumerator() + " / " + fraction.getDenominator());

        fraction.setNumerator(3);
        fraction.setDenominator(-15);
        System.out.print(fraction.getNumerator() + " / " + fraction.getDenominator());
        fraction.simplify();
        System.out.println(" = " + fraction.getNumerator() + " / " + fraction.getDenominator());

        fraction.setNumerator(-3);
        fraction.setDenominator(-15);
        System.out.print(fraction.getNumerator() + " / " + fraction.getDenominator());
        fraction.simplify();
        System.out.println(" = " + fraction.getNumerator() + " / " + fraction.getDenominator());
    }
}
