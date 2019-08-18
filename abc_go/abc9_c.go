package main

import (
	"fmt"
	"math"
	"sort"
	"strings"
)

func countDiffNum1(a, b []string) int {
	mp := map[string]int{}
	for _, v := range a {
		mp[v]++
	}
	for _, v := range b {
		mp[v]--
	}
	res := 0
	for _, v := range mp {
		res += int(math.Abs(float64(v)))
	}
	return res / 2
}

func countDiffNum2(a, b []string) int {
	res := 0
	for i, c := range a {
		if c != b[i] {
			res++
		}
	}
	return res
}

func main() {
	var N, K int
	fmt.Scan(&N, &K)
	var S string
	fmt.Scan(&S)
	s := strings.Split(S, "")
	sorted := strings.Split(S, "")

	ans := []string{}

	for i, c := range s {
		sort.Strings(sorted)
		for j := 0; j < N; j++ {
			num := countDiffNum1(s[i+1:], sorted[1:])
			if sorted[0] != c {
				num++
			}
			num += countDiffNum2(s[:i], ans)
			if num <= K {
				ans = append(ans, sorted[0])
				sorted = sorted[1:]
				break
			}
			sorted = append(sorted[1:], sorted[0])
		}
	}

	fmt.Println(strings.Join(ans, ""))

}
