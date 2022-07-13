
// DlgProxy.cpp : 구현 파일
//

#include "stdafx.h"
#include "LSAM_GUI.h"
#include "DlgProxy.h"
#include "LSAM_GUIDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLSAM_GUIDlgAutoProxy

IMPLEMENT_DYNCREATE(CLSAM_GUIDlgAutoProxy, CCmdTarget)

CLSAM_GUIDlgAutoProxy::CLSAM_GUIDlgAutoProxy()
{
	EnableAutomation();
	
	// 자동화 개체가 활성화되어 있는 동안 계속 응용 프로그램을 실행하기 위해 
	//	생성자에서 AfxOleLockApp를 호출합니다.
	AfxOleLockApp();

	// 응용 프로그램의 주 창 포인터를 통해 대화 상자에 대한
	//  액세스를 가져옵니다. 프록시의 내부 포인터를 설정하여
	//  대화 상자를 가리키고 대화 상자의 후방 포인터를 이 프록시로
	//  설정합니다.
	ASSERT_VALID(AfxGetApp()->m_pMainWnd);
	if (AfxGetApp()->m_pMainWnd)
	{
		ASSERT_KINDOF(CLSAM_GUIDlg, AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS(CLSAM_GUIDlg)))
		{
			m_pDialog = reinterpret_cast<CLSAM_GUIDlg*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}

CLSAM_GUIDlgAutoProxy::~CLSAM_GUIDlgAutoProxy()
{
	// 모든 개체가 OLE 자동화로 만들어졌을 때 응용 프로그램을 종료하기 위해
	// 	소멸자가 AfxOleUnlockApp를 호출합니다.
	//  이러한 호출로 주 대화 상자가 삭제될 수 있습니다.
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CLSAM_GUIDlgAutoProxy::OnFinalRelease()
{
	// 자동화 개체에 대한 마지막 참조가 해제되면
	// OnFinalRelease가 호출됩니다. 기본 클래스에서 자동으로 개체를 삭제합니다.
	// 기본 클래스를 호출하기 전에 개체에 필요한 추가 정리 작업을
	// 추가하십시오.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CLSAM_GUIDlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CLSAM_GUIDlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// 참고: IID_ILSAM_GUI에 대한 지원을 추가하여
//  VBA에서 형식 안전 바인딩을 지원합니다.
//  이 IID는 .IDL 파일에 있는 dispinterface의 GUID와 일치해야 합니다.

// {D0E2FB43-5655-4F30-9D35-43B8230E9D02}
static const IID IID_ILSAM_GUI =
{ 0xD0E2FB43, 0x5655, 0x4F30, { 0x9D, 0x35, 0x43, 0xB8, 0x23, 0xE, 0x9D, 0x2 } };

BEGIN_INTERFACE_MAP(CLSAM_GUIDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CLSAM_GUIDlgAutoProxy, IID_ILSAM_GUI, Dispatch)
END_INTERFACE_MAP()

// IMPLEMENT_OLECREATE2 매크로가 이 프로젝트의 StdAfx.h에 정의됩니다.
// {873568C0-64A6-4379-8769-3E69CEEEAFF9}
IMPLEMENT_OLECREATE2(CLSAM_GUIDlgAutoProxy, "LSAM_GUI.Application", 0x873568c0, 0x64a6, 0x4379, 0x87, 0x69, 0x3e, 0x69, 0xce, 0xee, 0xaf, 0xf9)


// CLSAM_GUIDlgAutoProxy 메시지 처리기
