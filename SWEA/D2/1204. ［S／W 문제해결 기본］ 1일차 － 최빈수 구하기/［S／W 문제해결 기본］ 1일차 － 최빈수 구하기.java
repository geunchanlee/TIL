import java.util.HashMap;
import java.util.Iterator;
import java.util.Scanner;
import java.io.FileInputStream;

public class Solution {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int T;
        T = sc.nextInt();
        for (int t = 0; t < T; t++) {
            int tcNum = sc.nextInt();
            int[] arr = new int[1000];
            for (int i = 0; i < 1000; i++) {
                arr[i] = sc.nextInt();
            }

            HashMap<Integer, Integer> scores = new HashMap<>();

            for (int i : arr) {
                if (scores.containsKey(i)) {
                    scores.put(i, scores.get(i) + 1);
                } else {
                    scores.put(i, 1);
                }
            }

            int mode_key = 0;
            int mode_value = 0;

            Iterator<Integer> keys = scores.keySet().iterator();
            while (keys.hasNext()) {
                int key = keys.next();
                if (scores.get(key) > mode_value) {
                    mode_key = key;
                    mode_value = scores.get(key);
                } else if (scores.get(key) == mode_value && key > mode_key) {
                    mode_key = key;
                    mode_value = scores.get(key);
                }
            }

            System.out.print("#" + tcNum + " ");
            System.out.println(mode_key);
        }
    }
}

