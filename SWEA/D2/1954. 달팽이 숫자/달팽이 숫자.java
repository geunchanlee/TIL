import java.util.Scanner;
 
class Solution
{
    public static void main(String args[]) throws Exception
    {
        Scanner sc = new Scanner(System.in);
        int T;
        T=sc.nextInt();
 
for (int t = 1; t <= T; t++) {
            int N = sc.nextInt();
            int[][] snail = new int[N][N];
 
            int x = 0; int y = 0; int d =0;
            int[] dx = {1, 0, -1, 0};
            int[] dy = {0, 1, 0, -1};
 
            for (int num = 1; num < N * N + 1; num++) {
                snail[y][x] = num;
                int nx = x + dx[d];
                int ny = y + dy[d];
 
                if ((0 <= nx && nx < N && 0 <= ny && ny < N) && snail[ny][nx] == 0) {
                    x = nx;
                    y = ny;
                } else {
                    d = (d + 1) % 4;
                    x += dx[d];
                    y += dy[d];
                }
            }
 
            System.out.println("#" + t );
            for (int[] i : snail) {
                for (int j : i) {
                    System.out.print(j + " ");
                }
                System.out.println();
            }
        }
    }
}