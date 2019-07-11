package main

import (
	"fmt"
)

func main() {
	var T, N, M int
	fmt.Scan(&T, &N)
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}
	fmt.Scan(&M)
	B := make([]int, M)
	for i := 0; i < M; i++ {
		fmt.Scan(&B[i])
	}

	used := make([]bool, N)

	for j := 0; j < M; j++ {
		for i := 0; i < N; i++ {
			if !used[i] && A[i] <= B[j] && A[i] >= B[j]-T {
				used[i] = true
				break
			}
			if i == N-1 {
				fmt.Println("no")
				return
			}
		}
	}

	fmt.Println("yes")

}
