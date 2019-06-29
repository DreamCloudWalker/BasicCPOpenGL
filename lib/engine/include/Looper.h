/**
*  @description    Looper
*  @author   	   dengjian
*  @email	  	   yashanhanhun@qq.com
*  @Create on      2019-06-15
*  @version        1.0
*  @modification   (Date,version,Revisor,content)
*/

#ifndef __LOOPER_H__
#define __LOOPER_H__

#include <chrono>

#include "MessageQueue.h"

class Looper {
public:
    Looper();
    virtual ~Looper();
	static void prepare();
    static void loop();
	static Looper* myLooper();
private:
	static thread_local Looper* s_looper;
	MessageQueue* m_messageQueue;
}; 

#endif