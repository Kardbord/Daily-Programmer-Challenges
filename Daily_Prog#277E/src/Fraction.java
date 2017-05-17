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
        sanitize();
    }

    public Integer getNumerator() {
        return this.getFirst();
    }

    public Integer getDenominator() {
        return this.getSecond();
    }

    public void setNumerator(Integer numerator) {
        this.setFirst(numerator);
        sanitize();
    }

    public void setDenominator(Integer denominator) {
        this.setSecond(denominator);
        sanitize();
    }

    public void simplify() {
        Fraction simplified = Simplifier.simplify(this.getNumerator(), this.getDenominator());
        this.setNumerator(simplified.getNumerator());
        this.setDenominator(simplified.getDenominator());
    }

    // TODO: add getSimplified method which returns the simplified fraction but does not change the actual values

    private void sanitize() {
        if (this.getNumerator() < 0 && this.getDenominator() < 0) {
            this.setNumerator(Math.abs(this.getNumerator()));
            this.setDenominator(Math.abs(this.getDenominator()));
        } else if (this.getDenominator() < 0 && this.getNumerator() > 0) {
            this.setDenominator(Math.abs(this.getDenominator()));
            this.setNumerator(-1 * this.getNumerator());
        } else if (this.getDenominator() == 0) {
            throw new IllegalArgumentException("Argument 'denominator' is 0");
        }
    }
}
