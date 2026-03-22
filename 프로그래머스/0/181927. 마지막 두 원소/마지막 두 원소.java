import java.util.Arrays;

class Solution {
    public int[] solution(int[] num_list) {
        int l = num_list.length-1;
        int[] answer = Arrays.copyOf(num_list, l+2);
        if (num_list[l] <= num_list[l-1]) {
            answer[l+1] = num_list[l] * 2;
        } else {
            answer[l+1] = num_list[l] - num_list[l-1];
        }
        return answer;
    }
}