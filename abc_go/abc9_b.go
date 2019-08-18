package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N)
	var max, second int
	for i := 0; i < N; i++ {
		var A int
		fmt.Scan(&A)
		if A > max {
			second = max
			max = A
		} else if A != max && A > second {
			second = A
		}
	}
	fmt.Println(second)
}
