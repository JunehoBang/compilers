package main

// excercise 2.4.1 (b) in page 68
import "fmt"

func main() {
	//get the string
	S := "())"
	if delim(S) {
		fmt.Println("Juneho: Compile OK")
	} else {
		fmt.Println("Juneho : Syntax error")
	}
}

func delim(S string) bool {
	if len(S) == 0 {
		return true
	}
	if len(S) == 1 {
		return false
	}
	if !match(S[:1], `(`) || !match(S[len(S)-1:], `)`) {
		return false
	}
	return delim(S[1 : len(S)-1])
}

func match(S string, c string) bool {
	return true
}
