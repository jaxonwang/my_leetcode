package main

import "fmt"

func lengthOfLongestSubstring(s string) int {
	a := make(map[byte]int)
	pre_length := 0
	cur := 0
	max := 0

	for i := 0; i < len(s); i++ {
		p, ok := a[s[i]]
		if ok == false {
			cur = pre_length + 1
		} else if p >= i-pre_length {
			cur = i - p
		} else {
			cur = pre_length + 1
		}
		a[s[i]] = i
		pre_length = cur
		if max < cur {
			max = cur
		}
	}
	return max
}

func main() {
	fmt.Println(lengthOfLongestSubstring("pwwkew"))
}
