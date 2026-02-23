import java.util.Arrays;


class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
	for (int n = 0; n < commands.length; n++) {  
	    int i = commands[n][0];  
	    int j = commands[n][1];  
	    int k = commands[n][2];  
	    
	    int[] ansArr = Arrays.copyOfRange(array, i - 1, j);  
	    Arrays.sort(ansArr);  
	    answer[n] = ansArr[k - 1];  
	}
        return answer;
    }
}