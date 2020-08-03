//package com.company;
//codechef code invicta - BringPositivity task upsolve

import java.io.*;
import java.util.StringTokenizer;

public class Main {
   static long TIME_START, TIME_END;
   static long m = (long) 1e9 + 7;
   static int size = 260001;
   static long[] fact = new long[size];

   public static void main(String[] args) throws IOException {
       Scanner sc = new Scanner(System.in);
       PrintWriter pw = new PrintWriter(new BufferedOutputStream(System.out));
       TIME_START = System.currentTimeMillis();
       fact();
       solve(sc, pw);
       TIME_END = System.currentTimeMillis();
       pw.close();
       System.err.println("Time used: " + (TIME_END - TIME_START) + ".");

   }

   static void solve(Scanner sc, PrintWriter pw) throws IOException {
       int t = sc.nextInt();
       StringBuilder sb = new StringBuilder();
       while (t-- > 0) {
           int n = sc.nextInt();
           int k = sc.nextInt();
           long fact_k = fact[k];
           long ans = 0;
           int nk = n * k;
           for (int i = 1; i <= n; i++) {
               long tmp = ((C(n, i) * fact[nk - i * k + i] % m) % m * inverse(pow(fact_k, n - i))) % m;
               if ((i & 1) != 0)
                   ans = (ans + tmp) % m;
               else
                   ans = (ans - tmp + m) % m;
           }
           sb.append(ans + "\n");
       }
       pw.print(sb);
   }

   static void fact() {
       fact[0] = 1L;
       fact[1] = 1L;

       for (int i = 2; i < size; i++)
           fact[i] = (i * fact[i - 1]) % m;
   }

   static long C(int n, int k) {
       return (fact[n] * inverse((fact[k] * fact[n - k]) % m)) % m;
   }

   static long inverse(long n) {
       return pow(n, m - 2) % m;
   }

   static long pow(long base, long exp) {

        long res = 1;

        while (exp > 0) {
          if (exp & 1 == 1)
            res = (res * base) % m;

          exp >>= 1;
          base = (base * base) % m;
        }

        return res;

       // if (exp == 0)
       //     return 1;
       // if (exp == 1)
       //     return base % m;

       // long pow = pow(base, exp / 2) % m;
       // if ((exp & 1) == 0)
       //     return (pow % m * pow % m) % m;

       // return ((pow % m * pow % m) % m * (base % m)) % m;

   }
   

    static class Scanner {
       StringTokenizer st;
       BufferedReader br;

       public Scanner(InputStream s) {
           br = new BufferedReader(new InputStreamReader(s));
       }

       public Scanner(FileReader s) throws FileNotFoundException {
           br = new BufferedReader(s);
       }

       public String next() throws IOException {
           while (st == null || !st.hasMoreTokens())
               st = new StringTokenizer(br.readLine());
           return st.nextToken();
       }

       public int nextInt() throws IOException {
           return Integer.parseInt(next());
       }

       public long nextLong() throws IOException {
           return Long.parseLong(next());
       }

       public String nextLine() throws IOException {
           return br.readLine();
       }

       public double nextDouble() throws IOException {
           return Double.parseDouble(next());
       }

       public boolean ready() throws IOException {
           return br.ready();
       }
   }
}

