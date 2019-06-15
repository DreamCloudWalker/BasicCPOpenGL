/**
*  @description    handler
*  @author   	   dengjian
*  @email	  	   yashanhanhun@qq.com
*  @Create on      2019-06-15
*  @version        1.0
*  @modification   (Date,version,Revisor,content)
*/

#ifndef __HANDLER_H__
#define __HANDLER_H__

#include "Message.h"

class Handler {
public:
    Handler();
    virtual ~Handler();

    bool sendMessageAtTime(Message& msg, long uptimeMillis);
	bool sendMessage(Message& msg);
	bool sendEmptyMessage(int what);
	bool sendEmptyMessage(int what, long uptimeMillis);

    // bool post(Message::Function f);
	// bool postAtTime(Message::Function f, long uptimeMillis);
 
	void removeMessages(int what);

    virtual void handleMessage(Message& msg);
	void dispatchMessage(Message& msg);
}; 

#endif