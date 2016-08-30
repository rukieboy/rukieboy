#include "callback.h"
#include <time.h>
void setCallback(funcPtr callback)
{
	m_pCallback = callback;
}


void test()
{
	m_pCallback(m_Index);
}

void main()
{
	int i = 0;
	setCallback(dq_error);

	test();
}