function solution(num_list) {
    let ele = 1, ele_sum =0;
    for (let i = 0; i < num_list.length; i++) {
        ele *= num_list[i];
        ele_sum += num_list[i];
    }
    ele_sum = ele_sum * ele_sum;
    var answer = ele < ele_sum ? 1 : 0;
    return answer;
}