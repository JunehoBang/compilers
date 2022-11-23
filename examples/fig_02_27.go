package main

import (
	"fmt"
	"strconv"
)

type Parser struct {
	eq        string
	lookahead int
}
type MyError struct{}

func (m *MyError) Error() string {
	return "syntax error"
}

func (p Parser) initialize() {
	p.lookahead = 0
	p.eq = ""
}

func (p Parser) getEquation() {
	fmt.Scanln(&p.eq)
}

func (p Parser) expr() error {
	p.term()
	for j := 1; j > 0; j++ {
		if p.lookahead >= len(p.eq) {
			return nil
		} else if string(p.eq[p.lookahead]) == "+" {

		} else if string(p.eq[p.lookahead]) == "-" {
			p.match("-")
			p.match(string(p.eq[p.lookahead]))

		} else {
			return fmt.Errorf("syntax error")
		}
	}
}

func (p Parser) term() error {
	if _, err := strconv.Atoi(string(p.eq[p.lookahead])); err != nil {
		return fmt.Errorf("syntax error")
	}
	fmt.Println(p.eq[p.lookahead])
	p.match(string(p.eq[p.lookahead]))
	return nil
}

func (p Parser) match(c string) error {
	if c != string(p.eq[p.lookahead]) {
		return fmt.Errorf("syntax error")
	}
	p.lookahead++
	return nil
}

func main() {
	var p Parser
	p.initialize()
	p.getEquation()
	p.expr()
	fmt.Println('\n')
}
