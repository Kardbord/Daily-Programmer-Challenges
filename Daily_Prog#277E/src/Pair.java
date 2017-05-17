/**
 * Daily_Prog#277E
 * Created on 5/17/2017
 *
 * Holds a pair of things
 *
 * @author Tanner Kvarfordt
 * @version 1.0
 */
public class Pair<T> {

    public Pair(T first, T second) {
        this.first = first;

        this.second = second;
    }

    public T getFirst() {
        return first;
    }

    public T getSecond() {
        return second;
    }

    public void setFirst(T first) {
        this.first = first;
    }

    public void setSecond(T second) {
        this.second = second;
    }

    private T first;

    private T second;
}
