import java.util.Scanner;
import java.io.FileInputStream;
import java.lang.Math;

public class Solution {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int T;
        T = sc.nextInt();
        for (int t = 0; t < T; t++) {
            int N = sc.nextInt();
            int M = sc.nextInt();

            int[] a = new int[N];
            for (int i = 0; i < N; i++) {
                a[i] = sc.nextInt();
            }

            int[] b = new int[M];
            for (int j = 0; j < M; j++) {
                b[j] = sc.nextInt();
            }

            int r = Math.abs(N - M) + 1;
            int[] result = new int[r];

            for (int i = 0; i < r; i++) {
                int sum = 0;
                if (a.length >= b.length) {
                    for (int j = 0; j < b.length; j++) {
                        sum += a[i + j] * b[j];
                    }
                } else {
                    for (int j = 0; j < a.length; j++) {
                        sum += a[j] * b[i + j];
                    }
                }
                result[i] = sum;
            }

            int max = result[0];
            for (int i = 1; i < result.length; i++) {
                if (result[i] > max) {
                    max = result[i];
                }
            }
            System.out.println("#" + (t + 1) + " " + max);
        }
    }
}
