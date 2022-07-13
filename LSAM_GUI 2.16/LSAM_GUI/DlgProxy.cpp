
// DlgProxy.cpp : ���� ����
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
	
	// �ڵ�ȭ ��ü�� Ȱ��ȭ�Ǿ� �ִ� ���� ��� ���� ���α׷��� �����ϱ� ���� 
	//	�����ڿ��� AfxOleLockApp�� ȣ���մϴ�.
	AfxOleLockApp();

	// ���� ���α׷��� �� â �����͸� ���� ��ȭ ���ڿ� ����
	//  �׼����� �����ɴϴ�. ���Ͻ��� ���� �����͸� �����Ͽ�
	//  ��ȭ ���ڸ� ����Ű�� ��ȭ ������ �Ĺ� �����͸� �� ���Ͻ÷�
	//  �����մϴ�.
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
	// ��� ��ü�� OLE �ڵ�ȭ�� ��������� �� ���� ���α׷��� �����ϱ� ����
	// 	�Ҹ��ڰ� AfxOleUnlockApp�� ȣ���մϴ�.
	//  �̷��� ȣ��� �� ��ȭ ���ڰ� ������ �� �ֽ��ϴ�.
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CLSAM_GUIDlgAutoProxy::OnFinalRelease()
{
	// �ڵ�ȭ ��ü�� ���� ������ ������ �����Ǹ�
	// OnFinalRelease�� ȣ��˴ϴ�. �⺻ Ŭ�������� �ڵ����� ��ü�� �����մϴ�.
	// �⺻ Ŭ������ ȣ���ϱ� ���� ��ü�� �ʿ��� �߰� ���� �۾���
	// �߰��Ͻʽÿ�.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CLSAM_GUIDlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CLSAM_GUIDlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// ����: IID_ILSAM_GUI�� ���� ������ �߰��Ͽ�
//  VBA���� ���� ���� ���ε��� �����մϴ�.
//  �� IID�� .IDL ���Ͽ� �ִ� dispinterface�� GUID�� ��ġ�ؾ� �մϴ�.

// {D0E2FB43-5655-4F30-9D35-43B8230E9D02}
static const IID IID_ILSAM_GUI =
{ 0xD0E2FB43, 0x5655, 0x4F30, { 0x9D, 0x35, 0x43, 0xB8, 0x23, 0xE, 0x9D, 0x2 } };

BEGIN_INTERFACE_MAP(CLSAM_GUIDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CLSAM_GUIDlgAutoProxy, IID_ILSAM_GUI, Dispatch)
END_INTERFACE_MAP()

// IMPLEMENT_OLECREATE2 ��ũ�ΰ� �� ������Ʈ�� StdAfx.h�� ���ǵ˴ϴ�.
// {873568C0-64A6-4379-8769-3E69CEEEAFF9}
IMPLEMENT_OLECREATE2(CLSAM_GUIDlgAutoProxy, "LSAM_GUI.Application", 0x873568c0, 0x64a6, 0x4379, 0x87, 0x69, 0x3e, 0x69, 0xce, 0xee, 0xaf, 0xf9)


// CLSAM_GUIDlgAutoProxy �޽��� ó����
