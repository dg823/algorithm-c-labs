int Partition(int A[ ], int Left, int Right)
{ 
    int PartElem, Value;           // 0: 변수 선언 (PartElem: 피벗의 위치, Value: 피벗의 값)
    PartElem = Left;               // 1: 배열의 첫 번째 인덱스를 피벗 위치로 지정
    Value = A[PartElem];           // 2: 피벗의 값(예: 50)을 별도로 저장해둠

    do {                           // 3: 분할을 위한 전체 반복 시작
        do {                       
            Left++;                // 4-1: 왼쪽 감시병을 오른쪽으로 한 칸 이동
        } while(A[Left] < Value);  // 4-2: 피벗(Value)보다 큰 값을 찾을 때까지 계속 이동

        do {                       
            Right--;               // 5-1: 오른쪽 감시병을 왼쪽으로 한 칸 이동
        } while(A[Right] > Value); // 5-2: 피벗(Value)보다 작은 값을 찾을 때까지 계속 이동

        if (Left < Right) {        // 6: 두 감시병이 서로 교차하기 전이라면
            Swap(&A[Left], &A[Right]); // 찾은 큰 값과 작은 값을 서로 교체
        } else {                   
            break;                 // 7: 서로 엇갈렸다면(분할 완료) 루프 탈출
        }
    } while (1);                   // 8: 3번으로 돌아가서 계속 반복

    A[PartElem] = A[Right];        // 9: 피벗이 들어갈 자리(Right)에 원래 있던 값을 맨 앞으로 보냄
    A[Right] = Value;              // 10: 피벗(Value)을 드디어 제자리(Right)에 넣음
    
    return Right;                  // 11: 피벗의 최종 위치(인덱스)를 반환
}