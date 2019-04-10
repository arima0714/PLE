/* 
A : データ数がすでに分かっている場合にデータとしてリスト構造を持たない配列を使用した場合

a. データの入力順に総和を求めたとき
b. データ入力後に、絶対値に関して昇順に並べ替えた後に総和を求めたとき
*/

#include <stdio.h>

double a(double *inputs, int max_content)
{
	double answer = 0;
	for (int j = 0; j < max_content; j++) {
		answer += inputs[j];
	}
	return answer;
}

double b(double *inputs, int max_content)
{
	double tmp = 0;
	double num_i = 0;
	double num_j = 0;
	double answer = 0;
	for (int i = 0; i < max_content; i++) {
		for (int j = 0; j < max_content; j++) {
			num_i = inputs[i];
			if(inputs[i] < 0){
				num_i = num_i * -1;
			}
			num_j = inputs[j];
			if(inputs[j] < 0){
				num_j = num_j * -1;
			}
			if(num_i < num_j){
				tmp = inputs[i];
				inputs[i] = inputs[j];
				inputs[j] = tmp;
			}
		}
	}
	for (int j = 0; j < max_content; j++) {
#ifdef DEBUG
		printf("inputs[%d] = %f\n", j, inputs[j]);
#endif
		answer += inputs[j];
	}
	return answer;
}

int main(void)
{
	char buf[128];
	double input;
	double inputs[128];
	int i;

	i = 0;

	while (fgets(buf, sizeof(buf), stdin) != NULL) {
		sscanf(buf, "%le", &input);
		inputs[i] = input;
#ifdef DEBUG
		printf("inputs[%d] = %f\n",i,input);
#endif
		i++;
	}
	printf("a() = %f\n", a(inputs, i));
	printf("b() = %f\n", b(inputs, i));
	return 0;
}
