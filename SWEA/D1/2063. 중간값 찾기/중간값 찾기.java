import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;
import java.io.FileInputStream;

public class Solution {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int T;
        T = sc.nextInt();

        ArrayList<Integer> arr = new ArrayList<Integer>();
        for (int i = 0; i < T; i++) {
            arr.add(sc.nextInt());
        }
        arr.sort(Comparator.naturalOrder());

        int middle = arr.size() / 2;
        System.out.println(arr.get(middle));
    }
}
