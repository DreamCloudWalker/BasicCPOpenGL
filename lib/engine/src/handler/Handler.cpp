#include "../../include/Handler.h"
#include "../../include/Message.h"

Handler::Handler() {

}

Handler::~Handler() {

}

bool Handler::sendMessageAtTime(Message & msg, long uptimeMillis)
{
	return false;
}

bool Handler::sendMessage(Message & msg)
{
	return false;
}

bool Handler::sendEmptyMessage(int what)
{
	return false;
}

bool Handler::sendEmptyMessage(int what, long uptimeMillis)
{
	return false;
}

void Handler::removeMessages(int what)
{
}

void Handler::enqueueMessage(Message & msg)
{
}

void Handler::handleMessage(Message & msg)
{
}

void Handler::dispatchMessage(Message & msg)
{
	handleMessage(msg);
}

