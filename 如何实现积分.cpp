#include<iostream> //实验一：定积分数值计算  2019/03/28
#include<cmath>
using namespace std;

/* 函数Fx=1/√1-x^2 */
double F(double x) {
	return 1 / sqrt(1 - x * x);
}

/* 函数defIntegral，输入区间[a,b]以及区间等分数目n，计算f(x)=1/√1-x^2在[a,b]内的定积分近似值 */
void defIntegral(double a, double b, int n) {
	double x = a;
	double dx = (b - a) / n;	//沿x轴将面积分为n个小矩形，每个矩形宽为(b-a)/n
	double s, S = 0;			//s表示每个小矩形的面积，S表示总面积
	if (a < 0 || a >= 1)
		cout << "error left border" << endl;	//当a的值不在定义域内时，提示区间左值错误
	else if (b >= 1 || b <= 0)
		cout << "error right border" << endl;	//当b的值不在定义域内时，提示区间右值错误
	else {
		for (int i = 1; i <= n; i++) {
			s = F((x + x + dx) / 2) * dx;
			S += s;	//	将每个小矩形的面积叠加
			x += dx;
		}
		cout << S << endl;
	}
}

int main() {		//用3组区间5种精度检验函数结果准确性，这里仅给出一组
	cout << "输入区间为[0,0.999]" << endl;
	defIntegral(0, 0.999, 10);
	defIntegral(0, 0.999, 50);
	defIntegral(0, 0.999, 100);
	defIntegral(0, 0.999, 500);
	defIntegral(0, 0.999, 1000);

	return 0;
}
