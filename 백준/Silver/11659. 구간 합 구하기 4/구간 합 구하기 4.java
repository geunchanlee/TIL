import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int M = sc.nextInt();

        int[] nums = new int[N];
        for (int i = 0; i < N; i++) {
            nums[i] = sc.nextInt();
        }

        int[] prefix = new int[N+1];
        for (int i = 1; i < N + 1; i++) {
            prefix[i] = prefix[i-1] + nums[i-1];
        }

        for (int n = 0; n < M; n++) {
            int i = sc.nextInt();
            int j = sc.nextInt();
            int sectionSum = prefix[j] - prefix[i-1];
            System.out.println(sectionSum);
        }
    }
}
