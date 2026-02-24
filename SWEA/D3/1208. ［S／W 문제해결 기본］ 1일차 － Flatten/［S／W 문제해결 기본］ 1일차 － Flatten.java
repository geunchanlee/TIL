import java.util.Scanner;
import java.io.FileInputStream;

class Solution {
    public static void main(String args[]) throws Exception {
        Scanner sc = new Scanner(System.in);

        for (int test_case = 1; test_case <= 10; test_case++) {

            int dump = sc.nextInt();
            int[] boxes = new int[100];
            for (int i = 0; i < 100; i++) {
                boxes[i] = sc.nextInt();
            }

            for (int d = 0; d < dump; d++) {
                int max_idx = 0;
                int min_idx = 0;
                for (int i = 1; i < 100; i++) {
                    if(boxes[i] > boxes[max_idx]) max_idx = i;
                    if(boxes[i] < boxes[min_idx]) min_idx = i;
                }
                if (boxes[max_idx] - boxes[min_idx] <= 1) {
                    break;
                }

                boxes[max_idx]--;
                boxes[min_idx]++;
            }

            int max_idx = 0;
            int min_idx = 0;
            for (int i = 1; i < 100; i++) {
                if(boxes[i] > boxes[max_idx]) max_idx = i;
                if(boxes[i] < boxes[min_idx]) min_idx = i;
            }

            System.out.println("#" + test_case + " " + (boxes[max_idx] - boxes[min_idx]));
            
        }
    }
}