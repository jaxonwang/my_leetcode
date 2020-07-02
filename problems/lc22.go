package main

import "fmt"
import "strings"

func generateParenthesis(n int) []string {
	if n == 0 {
		p := []string{""}
		return p
	}
	var ps []string
	for i := 1; i < n+1; i++ {
		left := generateParenthesis(i - 1)
		right := generateParenthesis(n - i)
		for _, l := range left {
			for _, r := range right {
				ps = append(ps, strings.Join([]string{"(", l, ")", r}, ""))
			}
		}
	}
	return ps
}

func generateParenthesis_dp(n int) []string {
	var ps [][]string
	ps = append(ps, []string{""})

	for i := 1; i < n+1; i++ {
		var p []string
		for k := 1; k < i+1; k++ {
			for _, l := range ps[k-1] {
				for _, r := range ps[i-k] {
					p = append(p, strings.Join([]string{"(", l, ")", r}, ""))
				}
			}
		}
		ps = append(ps, p)
	}
	return ps[n]
}
func main() {
	fmt.Println(generateParenthesis_dp(6))
}
