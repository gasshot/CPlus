#include <iostream>

int main()
{
	int a = 156;
	float b = 0.0f;

	b = static_cast<float> (a);

	a = static_cast<int>(b - 50.7f);


	printf("%f\n", b);
	printf("%d", a);

	return 0;

}
