package Fractions;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.regex.Pattern;

/**
 * Daily_Prog#277E
 * Created on 5/17/2017
 *
 * Contains the main method which takes an input file containing fractions where the numerator and denominator
 * are separated by a space. For example:
 *     4 8
 *     6 13
 *     5 4
 * These inputs would represent the fractions 4/8, 6/13, and 5/4
 *
 * @author Tanner Kvarfordt
 * @version 1.0
 */
public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        if (args.length == 0) {
            System.out.println("Error, no command line arguments present. Terminating program...");
            return;
        }

        Scanner scanner = new Scanner(new File(args[0]));

        ArrayList<Fraction> fractions = new ArrayList<>();
        for (int i = 0; scanner.hasNextLine(); ++i) {
            String line = scanner.nextLine();

            String[] split = line.split(" ");

            fractions.add(new Fraction(Integer.parseInt(split[0]), Integer.parseInt(split[1])));

            System.out.println(fractions.get(i).getAsString() + " = " + fractions.get(i).getSimplified().getAsString());
        }

    }
}
