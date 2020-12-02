/*
    Advent of Code 2020, Day 2
    Author: Ethan Gingrich
    This was my first java program in almost 3 years, still got it :)
 */

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.StringTokenizer;

public class day2 {
    public static void main(String[] args) 
    {
        try {
            File input = new File ("/home/ethan/git/Advent-Of-Code-2020/day 2/input");
            Scanner reader = new Scanner (input);
            int countp1 = 0;
            int countp2 = 0;
            while (reader.hasNextLine()) {
                String line = reader.nextLine();
                boolean validp1 = is_valid_password_part1 (line);
                boolean validp2 = is_valid_password_part2 (line);
                if (validp1 == true) {
                    countp1++;
                }
                if (validp2 == true) {
                    countp2++;
                }
            }
            System.out.println("The total # of passwords that are valid is: " + countp1);
            System.out.println("The total # of passwords that are valid is: " + countp2);
            reader.close();
        } catch (FileNotFoundException e) {
            System.out.println("error.");
            e.printStackTrace();
        }
    }

    // For part one, find the # of passwords that have the required letter a number of times, between the bounds of lower and upper
    public static boolean is_valid_password_part1 (String line) {
        StringTokenizer tokens = new StringTokenizer(line, "-: ");
        while (tokens.hasMoreTokens()) {
            long lower = Long.parseLong(tokens.nextToken());        // lower bound of letters required
            long upper = Long.parseLong(tokens.nextToken());        // upper bound of letters required
            String letter = tokens.nextToken();                     // the letter required 
            String pw = tokens.nextToken();                         // the password

            long count = pw.chars().filter(ch -> ch == letter.charAt(0)).count();
            if (count <= upper && count >= lower) {
                return true;
            }
        }
        return false;
    }

    // For part two, the letter can be at one position, BUT not at both positions.
    public static boolean is_valid_password_part2 (String line) {
        StringTokenizer tokens = new StringTokenizer(line, "-: ");
        while (tokens.hasMoreTokens()) {
            int pos1 = Integer.parseInt(tokens.nextToken());         // position 1 of the letter required
            int pos2 = Integer.parseInt(tokens.nextToken());         // position 2 of the letter required
            String letter = tokens.nextToken();                      // the letter required 
            String pw = tokens.nextToken();                          // the password

            // pos1 and pos2 are 0 1 indexed, but need it to be 0 indexed for charAt, so -1
            if ((pw.charAt(pos1-1) == letter.charAt(0)) && pw.charAt(pos2-1) != letter.charAt(0))
                return true;
            else if ((pw.charAt(pos1-1) != letter.charAt(0)) && pw.charAt(pos2-1) == letter.charAt(0))
                return true;
        }
        return false;
    }
}