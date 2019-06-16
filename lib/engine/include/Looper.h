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

class Looper {
public:
    Looper();
    virtual ~Looper();
    void prepare();
    void loop();
    Looper myLooper();
    
}; 

#endif