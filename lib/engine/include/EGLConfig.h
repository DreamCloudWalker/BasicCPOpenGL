/**@description    all native opengl init here
*  @author   	   dengjian
*  @email	  	   yashanhanhun@qq.com
*  @Create on      2014-04-06
*  @version        1.0
*  @modification   (Date,version,Revisor,content)
*  @
*/

#ifndef __EGL_CONFIG_H__
#define __EGL_CONFIG_H__

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#if defined __WINDOWS_PLATFORM__

#ifdef __OPENGL_ES_2__
#include <gl\glew.h>		// OpenGL32库的头文件,包含最新的gl.h,glu.h库
#include <gl\wglew.h>		// OpenGL32库的头文件
#include <gl\glut.h>        // 包含OpenGL实用库
#include <gl\glaux.h>
#include <gl\glext.h>       // 加上支持OpenGL 2.0高级功能如GLSL的扩展库
#include <gl\glfw3.h>
//#include <gl\glxext.h>
#include <gl\wglext.h>
//#include "UMatrix4x4.h"
#pragma comment( lib, "opengl32.lib")	// OpenGL32连接库
#pragma comment( lib, "glew32.lib")		// GLu32连接库
#pragma comment( lib, "glu32.lib")
#pragma comment( lib, "glaux.lib")
#pragma comment( lib, "glfw3.lib")
#else
#include <gl\glew.h>		// OpenGL32库的头文件,包含最新的gl.h,glu.h库
#include <gl\wglew.h>		// OpenGL32库的头文件
#include <gl\glut.h>        // 包含OpenGL实用库
#include <gl\glaux.h>
#pragma comment( lib, "opengl32.lib")	// OpenGL32连接库
#pragma comment( lib, "glew32.lib")		// GLu32连接库
#pragma comment( lib, "glu32.lib")
#pragma comment( lib, "glaux.lib")
#endif

// Add GL math head files
//#define GLM_SWIZZLE	// enable Swizzle operators, such as foo.x, foo.xxy, and so on
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtx/transform2.hpp>
//using glm::vec3;
//using glm::mat4;

#elif defined __ANDROID_PLATFORM__

#ifdef __OPENGL_ES_2__
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#else   // OpenGL ES 1.x
#include <GLES/gl.h>
#include <GLES/glext.h>
#endif

#elif defined __IOS_PLATFORM__

#ifdef __OPENGL_ES_2__
#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>
#else
#import <OpenGLES/ES1/gl.h>
#import <OpenGLES/ES1/glext.h>
#endif

#endif

#define GL_GENERATE_MIPMAP			0x8191

namespace _opengl_lib
{
	const float LIB_HALF_FOVY = 45.0f;
	const float LIB_Z_NEAR = 0.1f;
	const float LIB_Z_FAR = 1000.0f;
	typedef void(*RenderFunc)(void); 

	class EglConfig
	{
	public:
		EglConfig();
		virtual ~EglConfig();
	public:
		static bool GLInit();
		static void SetRender(RenderFunc pCallBackFunc);
		static void GLDraw();
		static void GLResize(int width, int height);
		static void GLPause();
		static void GLResume();
	private:
		static RenderFunc m_pCallBackFunc;
	public:
		static bool m_bPause;
	};
}
#endif