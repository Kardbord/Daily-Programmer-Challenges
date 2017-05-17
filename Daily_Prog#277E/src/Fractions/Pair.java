package Fractions;

/**
 * Daily_Prog#277E
 * Created on 5/17/2017
 *
 * Holds a pair of things
 *
 * @author Tanner Kvarfordt
 * @version 1.0
 */
public class Pair<T1, T2> {

    public Pair(T1 first, T2 second) {
        this.first = first;

        this.second = second;
    }

    public T1 getFirst() {
        return first;
    }

    public T2 getSecond() {
        return second;
    }

    public void setFirst(T1 first) {
        this.first = first;
    }

    public void setSecond(T2 second) {
        this.second = second;
    }

    private T1 first;

    private T2 second;
}
