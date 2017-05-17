/**
 * Daily_Prog#277E
 * Created on 5/17/2017
 *
 * This class simplifies a Fraction
 *
 * @author Tanner Kvarfordt
 * @version 1.0
 */
public class Simplifier {

    public static void main(String[] args) {

    }

    private Simplifier() {
    }


    public static void simplify(Integer numerator, Integer denominator) {

    }

    /**
     * Calculates the greatest common factor of a and the b using the Euclidean algorithm
     * See https://www.khanacademy.org/computing/computer-science/cryptography/modarithmetic/a/the-euclidean-algorithm
     *
     * @param a is the first Integer
     * @param b is the second Integer
     * @return the greatest common factor of the a and b
     */
    public static Integer computeGCF(Integer a, Integer b) {
        Integer c = Math.abs(a);
        Integer d = Math.abs(b);

        if (c == 0) return d;
        if (d == 0) return c;
        if (c.equals(d)) return c;
        if (c < d) return computeGCF(d, c);
        return computeGCF(d, c % d);
    }
}
