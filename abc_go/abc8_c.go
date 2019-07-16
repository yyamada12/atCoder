package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N)
	C := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&C[i])
	}
	exp := 0.0
	for i := 0; i < N; i++ {
		m := 0
		for j := 0; j < N; j++ {
			if i != j && C[i]%C[j] == 0 {
				m++
			}
		}
		if m%2 == 0 {
			exp += float64(m+2) / float64(2*m+2)
		} else {
			exp += 0.5
		}
	}
	fmt.Println(exp)
}
