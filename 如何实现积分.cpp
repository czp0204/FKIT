#include<iostream> //ʵ��һ����������ֵ����  2019/03/28
#include<cmath>
using namespace std;

/* ����Fx=1/��1-x^2 */
double F(double x) {
	return 1 / sqrt(1 - x * x);
}

/* ����defIntegral����������[a,b]�Լ�����ȷ���Ŀn������f(x)=1/��1-x^2��[a,b]�ڵĶ����ֽ���ֵ */
void defIntegral(double a, double b, int n) {
	double x = a;
	double dx = (b - a) / n;	//��x�Ὣ�����Ϊn��С���Σ�ÿ�����ο�Ϊ(b-a)/n
	double s, S = 0;			//s��ʾÿ��С���ε������S��ʾ�����
	if (a < 0 || a >= 1)
		cout << "error left border" << endl;	//��a��ֵ���ڶ�������ʱ����ʾ������ֵ����
	else if (b >= 1 || b <= 0)
		cout << "error right border" << endl;	//��b��ֵ���ڶ�������ʱ����ʾ������ֵ����
	else {
		for (int i = 1; i <= n; i++) {
			s = F((x + x + dx) / 2) * dx;
			S += s;	//	��ÿ��С���ε��������
			x += dx;
		}
		cout << S << endl;
	}
}

int main() {		//��3������5�־��ȼ��麯�����׼ȷ�ԣ����������һ��
	cout << "��������Ϊ[0,0.999]" << endl;
	defIntegral(0, 0.999, 10);
	defIntegral(0, 0.999, 50);
	defIntegral(0, 0.999, 100);
	defIntegral(0, 0.999, 500);
	defIntegral(0, 0.999, 1000);

	return 0;
}
