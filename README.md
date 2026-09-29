# push_swap · 42 Seoul

> 두 개의 스택과 제한된 명령어(`sa`, `pb`, `ra`, `rrr` 등)만으로 정수를 정렬하고, 그 명령어 목록을 출력하는 과제

## 개요
인자로 받은 정수를 스택 a에 넣고, 스택 b를 보조로 사용해 오름차순으로 정렬하는 명령어 순서를 표준 출력에 쓴다.
목표는 명령어 수를 줄이는 것이며, bonus로 명령어 목록을 검증하는 `checker`를 구현했다.

## 구현 포인트
- **자료구조**: 더미 헤드 노드를 둔 원형 이중 연결 리스트(`t_node`, `t_list`)로 스택을 표현한다. `head->next`가 top, top의 `prev`가 bottom이라 rotate/reverse rotate를 포인터 이동으로 처리한다.
- **입력 검증**: 각 인자를 공백으로 `ft_split`해 `"3 2 1"` 같은 문자열 인자도 받는다. 숫자 형식(`number_check`), int 범위와 중복(`same_range_check`)을 검사하고 실패 시 stderr에 `Error`를 출력한다.
- **좌표 압축**: `stack_a_sort`가 값을 배열로 복사해 `quick_sort`로 정렬한 뒤, 각 노드의 값을 순위(0 ~ n-1)로 바꾼다(`stack_a_indexing`). 이미 정렬된 입력이면 아무것도 출력하지 않는다.
- **소규모 입력**: 2~5개는 `stack_a_in_two_node`, `stack_a_in_three_node`, `stack_a_in_four_or_five`에서 경우별로 처리한다.
- **6개 이상 — 분할 후 그리디 삽입**:
  1. `stack_a_b_setting`이 인덱스 범위를 3구간으로 나눠 구간별로 b에 넘기고(`move_range_to_b`), a에는 인덱스 0, 1, 2와 최댓값만 남긴다. 최댓값도 b로 보낸 뒤 남은 3개를 정렬하고 최댓값을 다시 a로 가져온다.
  2. `one_round_count`가 b의 모든 원소에 대해, 그 원소를 b의 top으로 올리는 비용(`rb`/`rrb`)과 a의 알맞은 위치를 top으로 맞추는 비용(`ra`/`rra`)을 계산한다.
  3. `r_compare`가 같은 방향 회전을 `rr`/`rrr`로 합쳐 비용을 줄이고, `cnt_optimization`이 총 명령어 수가 가장 적은 원소를 고른다.
  4. `cmd_call`로 해당 회전을 실행하고 `pa` — b가 빌 때까지 반복한 뒤, `last_stack_a_sort`가 인덱스 0이 top에 오도록 가까운 방향으로 회전한다.
- **checker (bonus)**: stdin에서 명령어를 한 줄씩 읽어 실행하고(`checker_cmd_check`), 끝나면 a가 정렬되고 b가 비었는지에 따라 `OK` / `KO`를 출력한다.

## 빌드 & 실행
```bash
make
./push_swap 3 2 5 1 4
./push_swap "3 2 5 1 4"
```

bonus
```bash
make bonus
ARG="3 2 5 1 4"; ./push_swap $ARG | ./checker $ARG
```

`shell.sh`는 `jot`(macOS)으로 무작위 정수 500개를 만들어 100회 실행하고, 명령어 수가 1000 이상인 횟수와 평균을 출력하는 테스트 스크립트다.

## 구조
```
push_swap/
├── Makefile
├── headers/                  # push_swap.h, push_swap_bonus.h
├── main.c
├── input_utils*.c            # 인자 split, 숫자·범위·중복 검사
├── push_swap_list_utils*.c   # 원형 이중 연결 리스트
├── command_utils*.c          # sa sb ss pa pb ra rb rr rra rrb rrr
├── sort.c                    # quick_sort, 인덱스 부여
├── solution*.c               # 소규모 정렬, 구간 분할, 비용 계산
├── bonus/                    # checker
└── shell.sh                  # 반복 테스트 스크립트
```

42 Seoul 공통 과정 과제.
