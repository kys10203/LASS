#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CLSAM_Config ��ȭ �����Դϴ�.

class CLSAM_Config : public CDialogEx
{
	DECLARE_DYNAMIC(CLSAM_Config)

public:
	CLSAM_Config(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CLSAM_Config();

	virtual void OnFinalRelease();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_LSAM_CONFIG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
    afx_msg void OnBnClickedBtnOpen();
    virtual BOOL OnInitDialog();
    CIPAddressCtrl m_RemoteIp;
    afx_msg void OnClose();
    CEdit m_edit_RemotePort;
};
