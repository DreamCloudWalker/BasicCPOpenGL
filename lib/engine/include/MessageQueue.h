/**
*  @description    MessageQueue
*  @author   	   dengjian
*  @email	  	   yashanhanhun@qq.com
*  @Create on      2019-06-15
*  @version        1.0
*  @modification   (Date,version,Revisor,content)
*/

#ifndef __MESSAGE_QUEUE_H__
#define __MESSAGE_QUEUE_H__

#include <chrono>

#include "Message.h"

class MessageQueue {
public:
    MessageQueue();
    virtual ~MessageQueue();

    void enqueueMessage(Message& msg);
    Message* next();
}; 

#endif