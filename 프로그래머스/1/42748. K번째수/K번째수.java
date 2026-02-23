import java.util.Arrays;


class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        for (int n = 0; n < commands.length; n++) {
            int[] ansArr = Arrays.copyOfRange(array, commands[n][0]-1, commands[n][1]);
            Arrays.sort(ansArr);
            answer[n] = ansArr[commands[n][2]-1];
        }
        return answer;
    }
}