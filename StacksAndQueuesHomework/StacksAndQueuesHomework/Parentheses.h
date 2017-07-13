#pragma once
class Parentheses
{

private:
	char parenthesis;
public:
	Parentheses();
	~Parentheses();

	void setParenthesis(char c) { parenthesis = c; }
	char getParenthesis() { return parenthesis; }

};

