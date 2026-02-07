import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int maxNum = -1;
        int[] maxIdx = {0, 0};

        for (int i = 0; i < 9; i++) {
            ArrayList<Integer> arr = new ArrayList<Integer>();
            // 한 줄 입력받기
            for (int j = 0; j < 9; j++) {
                arr.add(sc.nextInt());
            }
            // 최댓값 검사
            for (int k : arr) {
                if (k > maxNum) {
                    maxNum = k;
                    maxIdx[0] = i + 1;
                    maxIdx[1] = arr.indexOf(k) + 1;
                }
            }
        }

        System.out.println(maxNum);
        for (int i : maxIdx) {
            System.out.println(i);
        }
    }
}
