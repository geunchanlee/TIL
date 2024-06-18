#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000  // 최대 역 개수
#define NAME_MAX 100  // 역 이름 최대 길이
#define ID_MAX 10  // 역 번호 최대 길이
#define NO_PATH 9999  // 경로가 없는 구간을 나타내는 값

typedef struct {
    char num[ID_MAX];
    char name[NAME_MAX];
} Station;

// 역 이름과 번호를 파일에서 읽어 구조체에 저장하는 함수입니다.
int station_name(const char *filename, Station *stations) 
{
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("파일오픈에러");
        exit(1);
    }

    char line[256];
    // 첫 번째 줄을 건너뜁니다. => 총역수 써있는 줄
    fgets(line, sizeof(line), fp);

    int station_cnt = 0;
    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%[^,],%s", stations[station_cnt].num, stations[station_cnt].name);
        station_cnt++;
    }

    fclose(fp);
    return station_cnt;
}

// 역의 번호로 역 구조체 배열에서 인덱스를 찾는 함수입니다.
int index_find(char *num, Station *stations, int station_cnt) 
{
    for (int i = 0; i < station_cnt; i++) {
        if (strcmp(stations[i].num, num) == 0) {
            return i;
        }
    }
    return -1;
}

// 인접행렬을 동적으로 할당하는 함수입니다.
int **create_adj_matrix(int n) 
{
    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            matrix[i][j] = (i == j) ? 0 : NO_PATH; // 자기 자신으로의 거리는 0, 나머지는 무한대
        }
    }
    return matrix;
}

// 각 호선별 파일을 읽어서 인접행렬에 내용을 채우는 함수입니다.
void line_info(const char *filename, int **adj_matrix, Station *stations, int station_cnt) 
{
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("파일오픈에러");
        exit(1); 
    }

    char line[256]; 
    char from[ID_MAX], to[ID_MAX]; // 출발역과 도착역입니다.
    int time;

    // 첫 번째 줄 읽기 (역 번호)
    fgets(line, sizeof(line), fp);

    // 첫 번째 행의 역 번호 추출
    char station_nums[MAX][ID_MAX];
    int num_stations = 0;
    char *token = strtok(line, ",");
    while (token) {
        if (num_stations > 0) {  // 첫 번째 열은 호선명으로 무시
            strcpy(station_nums[num_stations - 1], token);
        }
        num_stations++;
        token = strtok(NULL, ",");
    }
    num_stations--;  // 첫 번째 열을 제외한 실제 역 개수

    // 나머지 행 읽기
    for (int i = 0; i < num_stations; i++) {
        if (!fgets(line, sizeof(line), fp)) {
            perror("Failed to read line");
            exit(1);
        }
        
        int j = 0;
        token = strtok(line, ",");
        while (token) {
            if (j == 0) {  // 첫 번째 열은 역 번호
                strcpy(from, token);
            } else {
                time = atoi(token);
                if (time != NO_PATH) {
                    int from_index = index_find(from, stations, station_cnt);
                    int to_index = index_find(station_nums[j - 1], stations, station_cnt);
                    if (from_index != -1 && to_index != -1) {
                        adj_matrix[from_index][to_index] = time;
                        adj_matrix[to_index][from_index] = time;
                    }
                }
            }
            token = strtok(NULL, ",");
            j++;
        }
    }

    fclose(fp);
}

// 환승정보 파일을 읽어서 인접행렬로 환승정보를 업데이트하는 함수입니다.
void transfer_info(const char *filename, int **adj_matrix, Station *stations, int station_cnt) 
{
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("파일오픈 에러");
        exit(1);
    }

    char line[256];
    char from[ID_MAX], to[ID_MAX];
    int time;

    // 첫 번째 줄 읽기 (역 번호)
    fgets(line, sizeof(line), fp);

    // 첫 번째 행의 역 번호 추출
    char station_nums[MAX][ID_MAX];
    int num_stations = 0;
    char *token = strtok(line, ",");
    while (token) {
        if (num_stations > 0) {  // 첫 번째 열은 호선명(1호선...)이기 때문에 무시합니다.
            strcpy(station_nums[num_stations - 1], token);
        }
        num_stations++;
        token = strtok(NULL, ",");
    }
    num_stations--;  // 첫 번째 열을 제외한 실제 역 개수

    // 나머지 행 읽기
    for (int i = 0; i < num_stations; i++) {
        fgets(line, sizeof(line), fp);
        int j = 0;
        token = strtok(line, ","); // ,를 기준으로 분리해줍니다.
        while (token) {
            if (j == 0) {  // 첫 번째 열은 역 번호를 나타냅니다.
                strcpy(from, token);
            } else {
                time = atoi(token);
                if (time != NO_PATH) {
                    int from_index = index_find(from, stations, station_cnt);
                    int to_index = index_find(station_nums[j - 1], stations, station_cnt);
                    if (from_index != -1 && to_index != -1) {
                        adj_matrix[from_index][to_index] = time;
                        adj_matrix[to_index][from_index] = time; // 양방향 그래프
                    }
                }
            }
            token = strtok(NULL, ",");
            j++;
        }
    }
    fclose(fp);
}

// 동적할당된 인접행렬을 메모리에서 해제하는 함수입니다.
void free_adj_matrix(int **matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]); // 각 행별로 할당된 메모리를 해제합니다.
    }
    free(matrix); // 행 포인터 배열을 해제해줍니다.
}

int main() {
    Station stations[MAX];

    int station_cnt = station_name("역이름.csv", stations); // 역이름.csv파일을 읽어줍니다.
    printf("Total stations: %d\n", station_cnt);

    int **adj_matrix = create_adj_matrix(station_cnt); // 동적으로 인접행렬을 할당해줍니다.

    // 각 호선별 파일들을 읽어 이동시간을 담은 행렬을 업데이트하는 부분입니다.
    const char *line[] = {"1호선.csv", "1지선.csv", "2호선.csv", "2지선.csv", "3호선.csv", 
        "4호선.csv", "5호선.csv", "5지선.csv", "6호선.csv", "7호선.csv", "8호선.csv", "9호선.csv", 
        "분당선.csv", "인천1선.csv", "중앙선.csv", "경춘선.csv",  "경의선.csv", "공항철도.csv"};
    int file_cnt = sizeof(line) / sizeof(line[0]); // 노선 파일의 개수를 구해줍니다.

    for (int i = 0; i < file_cnt; i++) { // 구한 노선 파일 수만큼 반복하면서 파일을 읽어들이고 인접 행렬을 업데이트합니다.
        line_info(line[i], adj_matrix, stations, station_cnt);
    }

    // 환승정보를 읽는 함수를 통해 노선 파일을 반영한 인접행렬에 환승 정보도 담아줍니다.
    transfer_info("환승정보.csv", adj_matrix, stations, station_cnt);

    // 인접 행렬 출력
    printf("역의 개수: %d\n", station_cnt);
    for (int i = 0; i < station_cnt; i++) {
        for (int j = 0; j < station_cnt; j++) {
            if (adj_matrix[i][j] == NO_PATH) {
                printf("N ");
            } else {
                printf("%3d ", adj_matrix[i][j]);
            }
        }
        printf("\n");
    }

    // 동적으로 만들어진 인접 행렬을 메모리에서 해제해줍니다.
    free_adj_matrix(adj_matrix, station_cnt);

    return 0;
}
