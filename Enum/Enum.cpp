#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

enum ActorState
{
	Idle,
	Walk,
	Run,
	Sprint
};

int main() 
{
	enum ActorState actorstate;

	switch (actorstate)
	{
	case Idle:
		printf("지금은 대기상태입니다.");
		break;
	case Walk:
		printf("지금은 걷기상태입니다.");
		break;
	case Run:
		printf("지금은 달리기상태입니다.");
		break;
	case Sprint:
		printf("지금은 전력질주상태입니다.");
		break;
	default:
		break;
	}


	return 0;
}