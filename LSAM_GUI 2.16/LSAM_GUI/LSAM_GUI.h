
// LSAM_GUI.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CLSAM_GUIApp:
// �� Ŭ������ ������ ���ؼ��� LSAM_GUI.cpp�� �����Ͻʽÿ�.
//

class CLSAM_GUIApp : public CWinApp
{
public:
	CLSAM_GUIApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CLSAM_GUIApp theApp;