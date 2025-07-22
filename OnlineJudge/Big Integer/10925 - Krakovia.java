import java.util.*;
import java.math.BigInteger;

public class Main {
   public static Scanner in = new Scanner(System.in);
   public static int noCase = 1;

   public static void solve(int n, int m) {
      BigInteger sum = BigInteger.ZERO;
      for(int i = 0; i < n; i++) {
         String next = in.nextLine();
         sum = sum.add(new BigInteger(next));
      }
      System.out.println("Bill #" + noCase + " costs " + sum.toString() + ": each friend should pay " + (sum.divide(BigInteger.valueOf(m))) + '\n');
   }

   public static void main(String[] args) throws Exception {
      while(true) {
         int n = in.nextInt(), f = in.nextInt();
         if(n == 0 && f == 0) break;
         in.nextLine();
         solve(n, f);
         noCase += 1;
      }
   }
}