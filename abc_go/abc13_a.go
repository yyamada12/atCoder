package main

import (
	"fmt"
)

func main() {
	var X string
	fmt.Scan(&X)
	fmt.Println(X[0] - 'A' + 1)
}
