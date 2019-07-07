package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N)
	N = N % 30
	arr := [6]int{1, 2, 3, 4, 5, 6}
	for i := 0; i < N; i++ {
		arr[i%5], arr[i%5+1] = arr[i%5+1], arr[i%5]
	}
	for i := 0; i < 6; i++ {
		fmt.Print(arr[i])
	}
	fmt.Printf("\n")
}
