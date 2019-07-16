package main

import (
	"fmt"
)

func main() {
	var A string
	fmt.Scan(&A)
	if A == "a" {
		fmt.Println(-1)
	} else {
		fmt.Println("a")
	}
}
