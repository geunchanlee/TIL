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
                int max_v = boxes[0];
                int min_v = boxes[0];
                for (int i : boxes) {
                    if (i > max_v) max_v = i;
                    if (i < min_v) min_v = i;
                }

                int gap = max_v - min_v;
                if (gap <= 1) {
                    break;
                } else {
                    int max_idx = 0;
                    int min_idx = 0;
                    for (int i = 0; i < boxes.length; i++) {
                        if (boxes[i] == max_v) {
                            max_idx = i;
                        } else if (boxes[i] == min_v) {
                            min_idx = i;
                        }
                    }
                    boxes[max_idx] -= 1;
                    boxes[min_idx] += 1;
                }
            }
            int max_v = boxes[0];
            int min_v = boxes[0];
            for (int i : boxes) {
                if (i > max_v) max_v = i;
                if (i < min_v) min_v = i;
            }

            int gap = max_v - min_v;
            System.out.println("#" + test_case + " " + gap);
        }
    }
}