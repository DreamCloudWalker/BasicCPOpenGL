#include "Looper.h"

// C++�о�̬��Ա������Ҫ��ʹ�õĵط�������һ��
thread_local Looper* Looper::s_looper = NULL;

Looper::Looper()
{
	m_messageQueue = new MessageQueue();
}

Looper::~Looper()
{
}

void Looper::prepare()
{
	if (NULL == s_looper)
	{
		s_looper = new Looper();
	}
}

void Looper::loop()
{

}

Looper* Looper::myLooper()
{
	return s_looper;
}
