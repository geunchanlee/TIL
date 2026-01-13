#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000  // 역의 개수 최대치입니다.
#define NAME_MAX 200  // 역 이름의 최대길이입니다.
#define ID_MAX 20  // 역 번호의 최대길이입니다.
#define NO_ROUTE 9999  // 역 사이에 경로가 없는 구간을 나타내는 무한대 값입니다.

typedef struct {
    char num[ID_MAX]; // 역 번호를 저장할 변수입니다.
    char name[NAME_MAX]; // 역 이름을 저장할 변수입니다.
} Station;

typedef struct {
    int distance; // 역 사이의 거리를 저장할 변수입니다.
    char line[NAME_MAX]; // 호선을 저장할 변수입니다.
} Route;


// 역 이름, 번호를 역이름 파일에서 읽어 구조체에 저장하는 함수입니다.
int station_name(const char *filename, Station *station, char station_info[MAX][ID_MAX]) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("파일오픈에러");
        exit(1);
    }

    char line[256];
    fgets(line, sizeof(line), fp); // 첫 번째 줄을 건너뜁니다 (역 개수가 있는 줄)

    int station_cnt = 0;
    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%[^,],%s", station[station_cnt].num, station[station_cnt].name);
        strcpy(station_info[station_cnt], station[station_cnt].num);
        station_cnt++;
    }

    fclose(fp);
    return station_cnt;
}

// 역 번호정보로 역의 인덱스를 역이름 배열에서 찾는 함수입니다.
int find_index(const char *num, Station *station, int station_cnt) {
    for (int i = 0; i < station_cnt; i++) {
        if (strcmp(station[i].num, num) == 0) {
            return i;
        }
    }
    return -1;
}

// 인접행렬을 동적으로 할당하는 함수입니다.
Route **create_adj_matrix(int n) {
    Route **matrix = (Route **)malloc(n * sizeof(Route *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (Route *)malloc(n * sizeof(Route));
        for (int j = 0; j < n; j++) {
            matrix[i][j].distance = (i == j) ? 0 : NO_ROUTE;
            strcpy(matrix[i][j].line, "");
        }
    }
    return matrix;
}

// 각 호선별 파일을 읽어서 인접행렬에 내용을 채우는 함수입니다.
void line_info(const char *filename, Route **adj_matrix, Station *station, int station_cnt) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("파일오픈에러");
        exit(1);
    }

    char line[1024];
    char *token;
    int row = 0, col = 0;
    char line_name[NAME_MAX]; // 호선 이름을르 저장할 변수입니다.
    int temp_matrix[MAX][MAX] = {0};  // 파일을 읽을때 사용할 임시 2차원 배열입니다.

    // 파일의 첫번째 줄을 읽어줍니다. (호선 이름 포함해서 역 이름들이 있는 줄)
    fgets(line, sizeof(line), fp);
    token = strtok(line, ",");
    strcpy(line_name, token); // 0,0 위치에는 1호선, 2호선 처럼 호선 이름이 들어가 있어서 저장해줍니다.
    token = strtok(NULL, ",");

    // 첫 번째 행의 역 번호 추출합니다.
    char station_nums[MAX][ID_MAX];
    while (token != NULL) {
        if (col > 0) {  // 첫 번째 열은 호선명으로 무시합니다.
            strcpy(station_nums[col - 1], token);
        }
        token = strtok(NULL, ",");
        col++;
    }
     col--;

    // 나머지 행의 역 정보를 읽어 인접행렬에 저장합니다
    while (fgets(line, sizeof(line), fp)) {
        token = strtok(line, ",");
        strcpy(station_nums[row], token);  // 첫 번째 열은 출발역 번호입니다.

        int j = 0;
        while ((token = strtok(NULL, ",")) != NULL) {
            temp_matrix[row][j] = atoi(token);
            j++;
        }
        row++;
    }

    // 인접행렬 업데이트
    for (int i = 0; i < row; i++) {
        int from_index = find_index(station_nums[i], station, station_cnt);
        if (from_index == -1) {
            continue;
        }
        for (int j = 0; j < col; j++) {
            int to_index = find_index(station_nums[j], station, station_cnt);
            if (to_index == -1) {
                continue;
            }
            if (temp_matrix[i][j] != NO_ROUTE) {
                adj_matrix[from_index][to_index].distance = temp_matrix[i][j];
                strcpy(adj_matrix[from_index][to_index].line, line_name); // 호선 이름 저장
                adj_matrix[to_index][from_index].distance = temp_matrix[i][j];
                strcpy(adj_matrix[to_index][from_index].line, line_name); // 호선 이름 저장
            }
        }
    }

    fclose(fp);
}

// 동적할당된 인접행렬을 메모리에서 해제하는 함수
void free_adj_matrix(Route **matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]); // 각 행의 메모리 해제
    }
    free(matrix); // 행 포인터 배열의 메모리 해제
}

// 다익스트라 알고리즘을 이용하여 최단 경로를 찾는 함수
void dijkstra(Route **adj_matrix, Station *station, int station_cnt, int start_index, int end_index) {
    int dist[MAX]; // 출발역으로부터의 최단 거리 변수
    int prev[MAX]; // 이전 역의 인덱스 변수
    char prev_line[MAX][NAME_MAX]; // 이전 역의 호선 이름 변수
    int visited[MAX] = {0}; // 방문한 역 표시하는 변수

    for (int i = 0; i < station_cnt; i++) { // 변수들을 초기화해줍니다
        dist[i] = NO_ROUTE;
        prev[i] = -1;
        strcpy(prev_line[i], "");
    }
    dist[start_index] = 0;

    // 다익스트라 알고리즘
    for (int i = 0; i < station_cnt; i++) {
        int min_dist = NO_ROUTE, u = -1; // 최소 거리 역을 찾기 위한 변수
        for (int j = 0; j < station_cnt; j++) { 
            if (!visited[j] && dist[j] < min_dist) { // 방문하지 않은 역 중 최소 거리 역을 찾음
                min_dist = dist[j]; // 최소 거리 업데이트
                u = j;
            }
        }

        if (u == -1) break; // 최소거리 역이 없으면 종료합니다
        visited[u] = 1;

        // 인접한 역의 거리 업데이트
        // min_dist, u 로 미방문 역 중 최소 거리 역을 찾아 반영합니다.
        // u가 NO_ROUTE이면 더 이상 갈 수 있는 역이 없다는 뜻입니다. 반복을 종료합니다.
        // v에 대해 alt가 더 작으면 거리와 이전 역을 업데이트합니다.
        for (int v = 0; v < station_cnt; v++) {
            if (!visited[v] && adj_matrix[u][v].distance != NO_ROUTE) {
                int alt = dist[u] + adj_matrix[u][v].distance;
                if (alt < dist[v]) {
                    dist[v] = alt;
                    prev[v] = u;
                    strcpy(prev_line[v], adj_matrix[u][v].line); // 해당 호선 이름 저장
                }
            }
        }
    }
    // 최단 경로를 출력합니다.
    if (dist[end_index] == NO_ROUTE) {
        printf("경로가 존재하지 않습니다.\n");
        return;
    }
    printf("최단 경로\n<출발>\n");

    int path[MAX];
    char lines[MAX][NAME_MAX];
    int len = 0;
    for (int i = end_index; i != -1; i = prev[i]) { // 역의 인덱스를 역 이름으로 바꿔 경로를 출력합니다.
        path[len] = i;
        strcpy(lines[len], prev_line[i]);
        len++;
    }

    // 첫 번째 역의 호선 정보를 저장합니다.
    if (len > 1) {
        strcpy(lines[len - 1], adj_matrix[start_index][path[len - 2]].line);
    }

    int station_count = len;

    // 경로를 출력해줍니다.
    for (int i = len - 1; i >= 0; i--) {
        printf("-><%s>%s", lines[i], station[path[i]].name); // 호선 이름과 역 이름 출력합니다.
        printf("\n");
    }
    printf("\n소요 시간: %d 분\n", dist[end_index]);
    printf("정거장 수: %d 개\n", station_count);
}

// 사용자 입력을 확인하는 함수입니다
int get_index(Station *station, int station_cnt, const char *user_input) {
    char station_name[NAME_MAX];
    int index;

    while (1) {
        printf("%s", user_input);
        scanf("%s", station_name);

        index = -1;
        for (int i = 0; i < station_cnt; i++) {
            if (strcmp(station[i].name, station_name) == 0) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            printf("입력한 역이 존재하지 않습니다. 다시 입력해주세요.\n");
        } else {
            break;
        }
    }
    return index;
}

int main() {
    Station stations[MAX]; // 역 정보를 저장하는 구조체 배열입니다.
    char station_nums[MAX][ID_MAX];  // 역 번호를 문자열로 저장하는 배열입니다.

    // 역 이름 파일을 읽고 역의 수를 저장
    int station_cnt = station_name("역이름.csv", stations, station_nums);
    // 동적으로 인접 행렬을 할당
    Route **adj_matrix = create_adj_matrix(station_cnt);

    // 호선별 파일들을 읽어서 인접행렬에 저장합니다.
    const char *line[] = {"1호선.csv", "1지선.csv", "2호선.csv", "2지선.csv", "3호선.csv", 
        "4호선.csv", "5호선.csv", "5지선.csv", "6호선.csv", "7호선.csv", "8호선.csv", "9호선.csv", 
        "분당선.csv", "인천1선.csv", "중앙선.csv", "경춘선.csv", "경의선.csv", "공항철도.csv"};
    int file_cnt = sizeof(line) / sizeof(line[0]);  // 호선 파일의 수를 구해 반복문을 돌려줍니다.

    for (int i = 0; i < file_cnt; i++) {
        line_info(line[i], adj_matrix, stations, station_cnt);
    }

    // 출발역과 도착역을 입력받습니다. 이상하게 입력시에는 다시 입력받습니다.
    int start_index, end_index;

    while (1) {
        start_index = get_index(stations, station_cnt, "출발역을 입력해주세요: ");
        end_index = get_index(stations, station_cnt, "도착역을 입력해주세요: ");

        if (start_index == end_index) {
            printf("출발역과 도착역이 같습니다. 다른 역을 입력해주세요.\n");
        } else {
            break;
        }
    }

    // 다익스트라 알고리즘을 이용하여 경로를 찾아 출력합니다.
    dijkstra(adj_matrix, stations, station_cnt, start_index, end_index);

    // 동적으로 만들어진 인접 행렬을 메모리에서 해제합니다
    free_adj_matrix(adj_matrix, station_cnt);

    return 0;
}

