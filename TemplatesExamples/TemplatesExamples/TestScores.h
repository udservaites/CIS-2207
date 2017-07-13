#pragma once
template <class T> 
class TestScores
{

private:
	 T score;
public:
	//TestScores(void);
	TestScores(int s);
	//~TestScores(void);

	T getScore() {return score;}
	void setScore(int s) {score = s;}

	template <class T>
TestScores <T>:: TestScores(T s) {
	score = s;
}

TestScores<T>::~TestScores(void)
{
};

