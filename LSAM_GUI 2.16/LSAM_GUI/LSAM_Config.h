#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CLSAM_Config 대화 상자입니다.

class CLSAM_Config : public CDialogEx
{
	DECLARE_DYNAMIC(CLSAM_Config)

public:
	CLSAM_Config(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CLSAM_Config();

	virtual void OnFinalRelease();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_LSAM_CONFIG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
