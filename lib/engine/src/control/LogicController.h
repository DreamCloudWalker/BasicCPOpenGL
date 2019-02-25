/**@description    MVC controller
*  @author   	   dengjian
*  @email	  	   yashanhanhun@qq.com
*  @Create on      2014-04-06
*  @version        1.0
*  @modification   (Date,version,Revisor,content)
*  @
*/
#ifndef __LOGIC_CONTROLLER_H__
#define __LOGIC_CONTROLLER_H__

#ifdef __OPENGL_ES_2__

#endif
#include <string>
using namespace std;

#ifdef __ANDROID_PLATFORM__
#include "../platform/android/LogUtil.h"
#endif

namespace _opengl_lib
{
	class LogicController
	{
	private:
		LogicController();
		virtual ~LogicController();
	public:
		static void                 renderThread();
		static LogicController*     getInstance();// get singleton object
		unsigned long               release();
		bool                        init(char *resPath, float dpiScale = 1.0f);
		bool                        init(string resPath, float dpiScale = 1.0f);
	private:
		static LogicController*     m_instance;  // singleton object
	public:
#ifdef __OPENGL_ES_2__
		// ShaderProgram*              m_shaderProgram;
	private:
		static int                  m_vertexPosHandle;    // 通过调用 glGetAttribLocation 我们获取到 shader 中定义的变量 vertexPos 在 program 的槽位，通过该槽位就可以对 vPosition 进行操作
#endif
	};
}

#endif