import java.util.Scanner;
import java.io.FileInputStream;

public class Solution {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        int T;
        T = sc.nextInt();

        for (int test_case = 1; test_case <= T; test_case++) {
            int max = 0;
            for (int i=0; i<10; i++){
                int n = sc.nextInt();
                if (n > max) {
                    max = n;
                }
            }
            System.out.print("#"+test_case+" ");
            System.out.println(max);
        }
    }
}
