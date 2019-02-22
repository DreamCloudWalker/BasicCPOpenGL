#include "../../../include/EGLConfig.h"
#include <tchar.h>

using namespace _opengl_lib;
namespace _opengl_lib
{
	// C++�о�̬��Ա������Ҫ��ʹ�õĵط�������һ��
	RenderFunc EglConfig::m_pCallBackFunc;
	bool   EglConfig::m_bPause;

	EglConfig::EglConfig()
	{
		m_bPause = false;
	}

	EglConfig::~EglConfig()
	{
		m_bPause = false;
	}

	bool EglConfig::GLInit()
	{
		GLenum err = glewInit();
		if (GLEW_OK != err)
		{
			MessageBox(NULL, _T("glew init failed!"), _T("Error"), MB_OK | MB_ICONEXCLAMATION);
			return false;
		}

#ifndef __OPENGL_ES_2__ // opengl es 1.x
		glShadeModel(GL_SMOOTH);   // ��ɫģʽΪƽ������(ֻ�ڹ̶���Ⱦ����ʹ�ã���OpenGL ES1.0~1.1)
#endif
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);   // ��ʼ����Ļ����ɫ
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT); // ȡ��OpenGL ES1.x��glClearDepth(1.0f);������Ȼ���

		return true;
	}

	void EglConfig::SetRender(RenderFunc pCallBackFunc)
	{
		m_pCallBackFunc = pCallBackFunc;
	}

	void EglConfig::GLDraw()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// ˢ�±���
#ifndef __OPENGL_ES_2__ // opengl es 1.x
		glLoadIdentity();								 // ���õ�ǰ��ģ�͹۲����
#endif
		if (m_pCallBackFunc)
			m_pCallBackFunc();
	}

	void EglConfig::GLResize(int width, int height)
	{
		if (width == 0 || height == 0)
			return;
		glViewport(0, 0, width, height);
#ifdef __OPENGL_ES_2__ // opengl es 2
		// ��ʼ���������
		float ratio = (float)width / (float)height;
		//UMatrix4x4::GetInstance()->SetProjFrustum(-ratio, ratio, -1, 1, LIB_Z_NEAR, LIB_Z_FAR);
		//UMatrix4x4::GetInstance()->SetProjMatrix(LIB_FOVY_ANGLE, ratio, LIB_Z_NEAR, LIB_Z_FAR);
		//UMatrix4x4::GetInstance()->SetCamera(0.0, 0.0f, 3.0f, 0, 0, 0, 0, 1.0f, 0);
#else
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(LIB_HALF_FOVY, (GLfloat)width / (GLfloat)height, LIB_Z_NEAR, LIB_Z_FAR);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glScissor(0, 0, width, height);
#endif  // __OPENGL_ES_2__
	}

	void EglConfig::GLPause()
	{
		m_bPause = true;
	}

	void EglConfig::GLResume()
	{
		m_bPause = false;
	}
}