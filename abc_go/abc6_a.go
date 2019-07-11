package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N)
	if N%3 == 0 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}

}
