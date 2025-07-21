import java.util.*;
import java.math.BigInteger;

public class Main {
   public static Scanner in = new Scanner(System.in);
   
   public static void solve(int _n, int _a) {
      BigInteger n = BigInteger.valueOf(_n);
      BigInteger a = BigInteger.valueOf(_a);
      BigInteger ans = BigInteger.ZERO;
      for(int i = 1; i <= n.intValue(); i++) {
         BigInteger add = a.pow(i);
         add = add.multiply(BigInteger.valueOf(i));
         ans = ans.add(add);
      }
      System.out.println(ans);
   }

   public static void main(String[] args) throws Exception {
      while(in.hasNextInt() && in.hasNextInt()) {
         int n = in.nextInt();
         int a = in.nextInt();
         solve(n, a);
      }
   }
}