
// DlgProxy.h: ��� ����
//

#pragma once

class CLSAM_GUIDlg;


// CLSAM_GUIDlgAutoProxy ��� ���

class CLSAM_GUIDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CLSAM_GUIDlgAutoProxy)

	CLSAM_GUIDlgAutoProxy();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.

// Ư���Դϴ�.
public:
	CLSAM_GUIDlg* m_pDialog;

// �۾��Դϴ�.
public:

// �������Դϴ�.
	public:
	virtual void OnFinalRelease();

// �����Դϴ�.
protected:
	virtual ~CLSAM_GUIDlgAutoProxy();

	// ������ �޽��� �� �Լ�

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CLSAM_GUIDlgAutoProxy)

	// ������ OLE ����ġ �� �Լ�

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

