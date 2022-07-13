
// LSAM_GUIDlg.h : 헤더 파일
//

#pragma once
#include "afxbutton.h"
#include "LSAM_Define.h"
#include "afxcmn.h"
#include "LSAM_Config.h"
#include "LSAM_ParamSet.h"
#include <string>
#include "afxwin.h"
#include "afx.h"
// #include "crc-8.h"

class CLSAM_GUIDlgAutoProxy;


// CLSAM_GUIDlg 대화 상자
class CLSAM_GUIDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLSAM_GUIDlg);
	friend class CLSAM_GUIDlgAutoProxy;

// 생성입니다.
public:
	CLSAM_GUIDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.
	virtual ~CLSAM_GUIDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_LSAM_GUI_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	CLSAM_GUIDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	DECLARE_MESSAGE_MAP()
public:
    CMFCButton m_btn_Connect;
    CMFCButton m_btn_Config;
    CMFCButton m_btn_Exit;
    afx_msg void OnBnClickedBtnConnect();
    afx_msg void OnBnClickedBtnConfig();
    afx_msg void OnBnClickedBtnExit();
protected:
    afx_msg LRESULT OnDlgMenu(WPARAM wParam, LPARAM lParam);
public:
    int TCP_CONNECT(void);
    void AddEventString(wchar_t* ap_string);
    void AddEventString(CString str);

    SOCKET m_hSocket;
    struct sockaddr_in srv_addr;
    virtual BOOL PreTranslateMessage(MSG* pMsg);
    CRichEditCtrl m_edit_Log;
protected:
    afx_msg LRESULT OnConnectEvent(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnReceiveEvent(WPARAM wParam, LPARAM lParam);
public:
    void LoadParam(void);
    CString m_strMainPath;
    //CLSAM_Config* pLSAM_Config;

    CWinApp *pApp;
    afx_msg void OnBnClickedBtnLogClear();
    afx_msg void OnBnClickedBtnFuzeClear();
    afx_msg void OnBnClickedBtnRfClear();


    CEdit m_edit_SendFuzMsg;
    CEdit m_edit_SendRfMsg;

    CString m_str_SendFuzMsg;
    CString m_str_SendRfMsg;
    CComboBox m_cmb_PowerTdd;
    CComboBox m_cmb_PowerRf;
    void ParseMsg(BYTE* buffer, int MsgSize);
    void AutoScroll(void);
    afx_msg void OnBnClickedBtnFuzeSend();
    afx_msg void OnBnClickedBtnRfSend();
    bool IsHex(const std::string& str);
    int asc2hex(BYTE* hex, int start, int end);
    int SendCommand(uCommandType ucommand, int nSize);
    afx_msg void OnCbnSelchangeCmbPowerTdd();
    int SendCmdTddVoltageSet(BYTE ucVoltage);
    afx_msg void OnBnClickedBtnTddOnoff();
    afx_msg void OnBnClickedBtnRfOnoff();

    CButton m_btn_TddOnOff;
    CButton m_btn_RfOnOff;
    BOOL m_bTddPower;
    BOOL m_bRfPower;

    int SendCmdTddPower(BYTE ucOnOff);
    int SendCmdRfPower(BYTE ucOnOff);
    CButton m_btn_Loopback;
    afx_msg void OnBnClickedBtnLoopback();
    CButton m_btn_RxDisplay;
    CButton m_btn_LogSave;
    afx_msg void OnBnClickedBtnRxDisplay();
    BOOL m_bRxDisplay;
    afx_msg void OnBnClickedBtnLogSave();
    BOOL m_bLogSave;
    CFile m_file;

    CLSAM_ParamSet* p_LSAM_ParamSet;
    CMFCButton m_btn_ParamSet;
    afx_msg void OnBnClickedBtnParamSet();
    uScenarioA0 prev_uScenarioA0;
    uScenarioA2 prev_uScenarioA2;
    uScenarioA4 prev_uScenarioA4;
    uScenario5A prev_uScenario5A;
    uScenario prev_uScenario;
    UINT8 b_WIRE;
    BOOL f_bParamSet;
    void SendRFDCA(UINT8 u8RfDCA, UINT16 u16MSec);
    afx_msg void OnBnClickedBtnBit();
    BOOL f_bLooopback;
    UINT16 m_u16LogCount;
};
