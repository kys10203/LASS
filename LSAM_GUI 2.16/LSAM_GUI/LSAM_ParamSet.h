#pragma once
#include "afxwin.h"


// CLSAM_ParamSet 대화 상자입니다.

class CLSAM_ParamSet : public CDialogEx
{
	DECLARE_DYNAMIC(CLSAM_ParamSet)

public:
	CLSAM_ParamSet(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CLSAM_ParamSet();

	virtual void OnFinalRelease();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_LSAM_PARAMSET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
    afx_msg void OnBnClickedCheckTgtInfo();
    CButton m_chk_TgtInfo;
    afx_msg void OnBnClickedBtnTxrxSet();
    int SendCmdRxTx(int m_ClickedCtrl);
    CButton m_btn_RfIn1;
    CButton m_btn_RfIn2;
    CButton m_btn_RfIn3;
    CButton m_btn_RfIn4;
    CButton m_btn_RfIn5;
    CButton m_btn_RfIn6;
    CButton m_btn_RfIn7;
    CButton m_btn_RfIn8;
    CButton m_btn_RfOut1;
    CButton m_btn_RfOut2;
    CButton m_btn_RfOut3;
    CButton m_btn_RfOut4;
    CButton m_btn_RfOut5;
    CButton m_btn_RfOut6;
    CButton m_btn_RfOut7;
    CButton m_btn_RfOut8;
    afx_msg void OnBnClickedRadioWired();
    afx_msg void OnBnClickedRadioWireless();
    int SendCmdWire(int m_ClickedCtrl);
    CButton m_rdo_Wired;
    virtual BOOL OnInitDialog();
    CEdit m_edit_DopplerFreq;
    CEdit m_edit_DCAOffset;
    CEdit m_edit_StartRange;
    CEdit m_edit_StopRange;
    CEdit m_edit_IntervalData;
    CEdit m_edit_RfDCA;
    afx_msg void OnBnClickedBtnA0Set();
    afx_msg void OnBnClickedRadioRfIn1();
    afx_msg void OnBnClickedRadioRfIn2();
    afx_msg void OnBnClickedRadioRfIn3();
    afx_msg void OnBnClickedRadioRfIn4();
    afx_msg void OnBnClickedRadioRfIn5();
    afx_msg void OnBnClickedRadioRfIn6();
    afx_msg void OnBnClickedRadioRfIn7();
    afx_msg void OnBnClickedRadioRfIn8();
    afx_msg void OnBnClickedRadioRfOut1();
    afx_msg void OnBnClickedRadioRfOut2();
    afx_msg void OnBnClickedRadioRfOut3();
    afx_msg void OnBnClickedRadioRfOut4();
    afx_msg void OnBnClickedRadioRfOut5();
    afx_msg void OnBnClickedRadioRfOut6();
    afx_msg void OnBnClickedRadioRfOut7();
    afx_msg void OnBnClickedRadioRfOut8();
    UINT8 u8RF_IN;
    UINT8 u8RF_OUT;
    afx_msg void OnClose();
    virtual BOOL PreTranslateMessage(MSG* pMsg);
    CButton m_btn_A1Set;
    BOOL f_bScenario;
    BOOL f_bFixedTgt;
    afx_msg void OnBnClickedBtnA1Set();
    void LoadPrevSet(void);
    CButton m_rdo_Wireless;
    afx_msg void OnBnClickedBtnA4Set();
    CButton m_btn_A4Set;
    afx_msg void OnBnClickedBtnA2Set();
    CEdit m_edit_StartAddr;
    CEdit m_edit_R1DCA;
    CEdit m_edit_R2DCA;
    CEdit m_edit_R3DCA;
    CEdit m_edit_R4DCA;
    CEdit m_edit_R5DCA;
    CEdit m_edit_R6DCA;
    CEdit m_edit_R7DCA;
    CEdit m_edit_R8DCA;
    CEdit m_edit_R9DCA;
    CEdit m_edit_R10DCA;
    CEdit m_edit_ROMAddr;
    CEdit m_edit_RfDCA1;
    CEdit m_edit_RfDCA2;
    CEdit m_edit_RfDCA3;
    afx_msg void OnBnClickedBtnA2Set2();
    BYTE RtnCRC8(unsigned char init_crc, const void* data, int length);
    afx_msg void OnBnClickedBtnStop();
    afx_msg void OnBnClickedBtnA4Stop();
    void SetRFGroup(UINT8 u8RFPort);
};
