import java.util.Scanner;
import java.io.FileInputStream;

public class Solution {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int T;
        T = sc.nextInt();

        for (int test_case = 1; test_case <= T; test_case++) {
            int N = sc.nextInt();
            int[] arr = new int[N];
            for (int i = 0; i < N; i++) {
                arr[i] = sc.nextInt();
            }

            for (int i = 0; i < N-1; i++){
                for (int j = N-1; j > i; j--) {
                    if (arr[j-1] > arr[j]) {
                        int temp = arr[j];
                        arr[j] = arr[j-1];
                        arr[j-1] = temp;
                    }
                }
            }

            System.out.print("#"+test_case+" ");
            for (int i : arr) {
                System.out.print(i+" ");
            }
            System.out.println();
        }
    }
}
