//共分散
#include <iostream>
using namespace std;

typedef struct{
	int math;
	int japanese;
	int dev_pr;
} data;

int main(){
	float convariance;
	float avg_math, avg_japanese;
	//４人分の国語と数学の点数データ
	data a = {36, 90};
	data b = {73, 57};
	data c = {51, 36};
	data d = {80, 17};
	//平均求める
	avg_math = (a.math + b.math + c.math + d.math) / 4.0;
	avg_japanese = (a.japanese + b.japanese + c.japanese + d.japanese) /4.0;
	//cout << avg_math;
	//ｘの偏差とｙの偏差の積を求める
	a.dev_pr = (a.math - avg_math) * (a.japanese - avg_japanese);
	b.dev_pr = (b.math - avg_math) * (b.japanese - avg_japanese);
	c.dev_pr = (c.math - avg_math) * (c.japanese - avg_japanese);
	d.dev_pr = (d.math - avg_math) * (d.japanese - avg_japanese);
	//cout << a.dev_pr;
	//共分散を求める
	convariance = (a.dev_pr + b.dev_pr + c.dev_pr + d.dev_pr) / 4.0;
	cout << convariance << endl;
	return 0;
}
