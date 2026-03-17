import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String[] board = new String[5];
        for (int i = 0; i < 5; i++) {
            String words = sc.nextLine();
            board[i] = words.strip();
        }

        for (int i = 0; i < 15; i++) {
            for (int j = 0; j < 5; j++) {
                if (board[j].length() > i) {
                    System.out.print(board[j].charAt(i));
                }
            }
        }
    }
}