#include "LogicController.h"
#include <stdio.h>

using namespace _opengl_lib;
namespace _opengl_lib
{
#define RES_FOLDER_MODEL    "model/"
	// C++中静态成员变量需要在使用的地方再声明一次
	LogicController* LogicController::m_instance = NULL;

#ifdef __OPENGL_ES_2__
	//int LogicController::m_vertexPosHandle = 0;
#endif // __OPENGL_ES_2__

	LogicController::LogicController()
	{
#ifdef __OPENGL_ES_2__
		//m_shaderProgram = NULL;
#endif
	}
	LogicController::~LogicController()
	{
		
	}

	LogicController* LogicController::GetInstance()
	{
		if (NULL == m_instance)
		{
			m_instance = new LogicController;
		}

		return m_instance;
	}

	unsigned long LogicController::Release()
	{
		delete m_instance;
		m_instance = NULL;

		return 0;
	}

	// init res path
	bool LogicController::Init(string resPath, float dpiScale)
	{
		//LogUtilI("NativeDraw LogicController::Init resPath = %s", resPath);
		return false;
	}

	// init res path
	bool LogicController::Init(char *resPath, float dpiScale)
	{
		return false;
	}

	// Win32 used by WinMain OpenGLInit::SetRender, android/ios used by LogicCallProxy
	void LogicController::GLRenderThread()
	{
		if (NULL == m_instance)
		{
			return;
		}

	}
}