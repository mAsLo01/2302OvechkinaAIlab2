#pragma once
#include "steck.h"
struct stack
{
	int index;
	steck a;
	stack* prev;
};