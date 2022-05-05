#include <cstdio>

#define MAX_LEN 26

// pre, in: 트리의 전위 및 중위 순회
char pre[MAX_LEN], in[MAX_LEN];
// pre_idx[i], in_idx[i]: 트리의 전위 및 중위 순회에서 i + 'A'의 인덱스
int pre_idx[MAX_LEN], in_idx[MAX_LEN];

// 전위 순회의 [ps, pe), 중위 순회의 [is, ie) 구간을 후위 순회로 복구
void dfs(int ps, int pe, int is, int ie) {
    // im: 중위 순회에서 루트 노드(pre[ps])의 인덱스
    // prs: 전위 순회에서 오른쪽 서브 트리의 루트 노드의 인덱스
    //      즉, 전위 순회의 시작 지점(ps에서 왼쪽 서브 트리의 길이im - is)와
    //      루트 노드의 길이(1)를 더한 값
    int im = in_idx[pre[ps] - 'A'], prs = ps + (im - is) + 1;

    // pe - ps가 1보다 클 경우, 즉 트리가 자식 노드를 가진 트리일 경우
    if (pe - ps > 1) {
        // 왼쪽 서브 트리와 오른쪽 서브 트리를 차례로 후위 순회로 바꾼 뒤
        dfs(ps + 1, prs, is, im);
        dfs(prs, pe, im + 1, ie);
    }

    // pe - ps가 true일 경우, 즉 트리의 루트 노드가 존재할 경우 이를 출력
    if (pe - ps) printf("%c", pre[ps]);
}

int main() {
    // 각 트리의 길이
    int len;
    // 각 테스트 케이스를 입력받은 뒤
    while (scanf("%s %s", pre, in) != EOF) {
        // 두 순회에서 각 노드의 인덱스를 배열에 저장하고
        for (len = 0; len < MAX_LEN && in[len]; len++){
            pre_idx[pre[len] - 'A'] = len;
            in_idx[in[len] - 'A'] = len;
        }
        // dfs를 이용해 후위 순회를 출력
        dfs(0, len, 0, len);
        // 개행 문자를 출력해 테스트 케이스의 출력을 종료
        printf("\n");
    }

    return 0;
}
