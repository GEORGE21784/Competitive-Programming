import java.util.*;
import java.math.BigInteger;

public class Main {
    public static Scanner in = new Scanner(System.in);
    
    public static void solve(String _n) {
        BigInteger n = new BigInteger(_n);
        System.out.println(n.remainder(new BigInteger("17")).equals(BigInteger.ZERO) ? "1" : "0");
    }

    public static void main(String[] args) throws Exception {
        while(true) {
            String n = in.nextLine();
            if(n.equals("0")) break;
            solve(n);
        }
    }
}