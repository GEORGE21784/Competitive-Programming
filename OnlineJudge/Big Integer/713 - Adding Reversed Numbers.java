import java.util.*;
import java.math.BigInteger;

public class Main {
    private static String reverse(String S) {
        return new StringBuilder(S).reverse().toString();
    }
    private static String removeLeadingZeros(String s) {
        int i = 0;
        while (i < s.length() - 1 && s.charAt(i) == '0') {i++;}
        return s.substring(i);
    }
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        in.nextLine();
        for (int i = 0; i < t; i++) {
            String line = in.nextLine();
            String[] inp = line.split(" ");
            BigInteger A = new BigInteger(reverse(inp[0]));
            BigInteger B = new BigInteger(reverse(inp[1]));
            BigInteger sum = A.add(B);
            String result = removeLeadingZeros(reverse(sum.toString()));
            System.out.println(result);
        }
    }
}