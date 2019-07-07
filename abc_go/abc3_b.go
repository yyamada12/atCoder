package main

import (
	"fmt"
	"strings"
)

func main() {
	var S, T string
	fmt.Scan(&S, &T)
	for i := 0; i < len(S); i++ {
		if S[i] != T[i] {
			if strings.Contains("atcoder@", string(S[i])) && T[i] == '@' {
				continue
			}
			if strings.Contains("atcoder@", string(T[i])) && S[i] == '@' {
				continue
			}
			fmt.Println("You will lose")
			return
		}
	}
	fmt.Println("You can win")
}
