import java.util.Scanner;

class Solution {
    public static int isPalindrome(String str) {
        StringBuilder sb = new StringBuilder(str);
        String reverse = sb.reverse().toString();
        return str.equals(reverse) ? 1 : 0;
    }

    public static void main(String args[]) throws Exception {
        Scanner sc = new Scanner(System.in);
        int T;
        T = sc.nextInt();

        for (int t = 1; t <= T; t++) {
            String str = sc.next();
            System.out.println("#" + t + " " + isPalindrome(str));
        }
    }
}