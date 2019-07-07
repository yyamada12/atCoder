package main

import (
	"fmt"
)

func main() {
	var c [4][4]string
	for i := 0; i < 4; i++ {
		for j := 0; j < 4; j++ {
			var tc string
			fmt.Scan(&tc)
			c[i][j] = tc
		}
	}

	for i := 3; i >= 0; i-- {
		for j := 3; j >= 0; j-- {
			fmt.Print(c[i][j])
			if j != 0 {
				fmt.Print(" ")
			} else {
				fmt.Printf("\n")
			}
		}
	}
}
