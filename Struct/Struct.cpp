#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student
{
	char name[20];
	int kor_score;
	int eng_score;
	int math_score;
};

int main()
{
	//struct Student *ptr = malloc(sizeof(struct Student));
	Student* ptr1 = new Student{ "Lee", 66, 76, 86 };
	Student* ptr2 = new Student{ "Jo", 77, 47, 27 };


	printf("%s,%d,%d,%d",
		ptr1->name,
		ptr1->kor_score,
		ptr1->eng_score,
		ptr1->math_score);

	printf("%s,%d,%d,%d",
		ptr2->name,
		ptr2->kor_score,
		ptr2->eng_score,
		ptr2->math_score);

	//free(ptr);
	delete ptr1;
	delete ptr2;

	return 0;
}

void whatIsStruct()
{
	struct Student s1, s2;

	s1 = { "Kang",90,80,70 };
	s2 = { "Lee",75,85,65 };

	//strcpy_s(s1.name, "Kang");
	////st.name = "kang";
	//s1.kor_score = 90;
	//s1.eng_score = 80;
	//s1.math_score = 70;

	printf("%s\n", s1.name);
	printf("%d\n", s1.kor_score);
	printf("%d\n", s1.eng_score);
	printf("%d\n", s1.math_score);

	printf("%s\n", s2.name);
	printf("%d\n", s2.kor_score);
	printf("%d\n", s2.eng_score);
	printf("%d\n", s2.math_score);
}
