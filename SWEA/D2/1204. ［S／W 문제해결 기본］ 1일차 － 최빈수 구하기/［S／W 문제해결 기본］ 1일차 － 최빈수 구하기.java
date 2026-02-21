import java.util.HashMap;
import java.util.Iterator;
import java.util.Scanner;
import java.io.FileInputStream;

public class Solution {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int T;
        T = sc.nextInt();
        // 테스트 케이스 개수만큼 반복
        for (int t = 0; t < T; t++) {
            int tcNum = sc.nextInt();
            // 점수들 저장할 배열 만들고 입력받기
            int[] arr = new int[1000];
            for (int i = 0; i < 1000; i++) {
                arr[i] = sc.nextInt();
            }

            // HashMap 자료구조로 점수, 개수를 쌍으로 저장하기
            HashMap<Integer, Integer> scores = new HashMap<>();
            // 배열을 순회하면서 점수가 해시맵에 있으면 값만 증가시키고 없다면 해시맵에 새로 추가
            for (int i : arr) {
                if (scores.containsKey(i)) {
                    scores.put(i, scores.get(i) + 1);
                } else {
                    scores.put(i, 1);
                }
            }
            
            
            int mode_key = 0;
            int mode_value = 0;

            // 이터레이터로 해시맵 순회하면서 최빈수 찾기
            // 기존 최빈보다 더 많이 등장한 수는 바로 업데이트한다
            // 기존 최빈수보다 등장 횟수가 많으면서 key(점수)도 큰 경우에도 업데이트한다
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

