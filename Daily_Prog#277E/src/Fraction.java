/**
 * Daily_Prog#277E
 * Created on 5/17/2017
 *
 * A class for representing a fraction, with Integers for numerator and denominator. Provides capability to simplify.
 *
 * @author Tanner Kvarfordt
 * @version 1.0
 */
public class Fraction extends Pair<Integer, Integer> {

    public Fraction(Integer numerator, Integer denominator) {
        super(numerator, denominator);
    }

    public Integer getNumerator() {
        return this.getFirst();
    }

    public Integer getDenominator() {
        return this.getSecond();
    }

    public void setNumerator(Integer numerator) {
        this.setFirst(numerator);
    }

    public void setDenominator(Integer denominator) {
        this.setSecond(denominator);
    }

    // TODO: add simplify method which changes the value of numerator and denominator

    // TODO: add getSimplified method which returns the simplified fraction but does not change the actual values
}
