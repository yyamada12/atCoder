package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	fmt.Scan(&s)
	fmt.Println(strings.ToUpper(string(s[0])) + strings.ToLower(s[1:]))
}
