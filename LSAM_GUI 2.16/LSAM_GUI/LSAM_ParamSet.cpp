// LSAM_ParamSet.cpp : 구현 파일입니다.
//
// #include <cmath>
#include "stdafx.h"
#include "LSAM_GUI.h"
#include "LSAM_ParamSet.h"
#include "LSAM_GUIDlg.h"
#include "afxdialogex.h"

// CLSAM_ParamSet 대화 상자입니다.

IMPLEMENT_DYNAMIC(CLSAM_ParamSet, CDialogEx)

    CLSAM_ParamSet::CLSAM_ParamSet(CWnd* pParent /*=NULL*/)
    : CDialogEx(CLSAM_ParamSet::IDD, pParent)
    , u8RF_IN(0)
    , u8RF_OUT(0)
    , f_bScenario(FALSE)
    , f_bFixedTgt(FALSE)
{

    EnableAutomation();

}

CLSAM_ParamSet::~CLSAM_ParamSet()
{
}

void CLSAM_ParamSet::OnFinalRelease()
{
    // 자동화 개체에 대한 마지막 참조가 해제되면
    // OnFinalRelease가 호출됩니다. 기본 클래스에서 자동으로 개체를 삭제합니다.
    // 기본 클래스를 호출하기 전에 개체에 필요한 추가 정리 작업을
    // 추가하십시오.

    CDialogEx::OnFinalRelease();
}

void CLSAM_ParamSet::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_CHECK_TGT_INFO, m_chk_TgtInfo);
    DDX_Control(pDX, IDC_RADIO_RF_IN1, m_btn_RfIn1);
    DDX_Control(pDX, IDC_RADIO_RF_IN2, m_btn_RfIn2);
    DDX_Control(pDX, IDC_RADIO_RF_IN3, m_btn_RfIn3);
    DDX_Control(pDX, IDC_RADIO_RF_IN4, m_btn_RfIn4);
    DDX_Control(pDX, IDC_RADIO_RF_IN5, m_btn_RfIn5);
    DDX_Control(pDX, IDC_RADIO_RF_IN6, m_btn_RfIn6);
    DDX_Control(pDX, IDC_RADIO_RF_IN7, m_btn_RfIn7);
    DDX_Control(pDX, IDC_RADIO_RF_IN8, m_btn_RfIn8);
    DDX_Control(pDX, IDC_RADIO_RF_OUT1, m_btn_RfOut1);
    DDX_Control(pDX, IDC_RADIO_RF_OUT2, m_btn_RfOut2);
    DDX_Control(pDX, IDC_RADIO_RF_OUT3, m_btn_RfOut3);
    DDX_Control(pDX, IDC_RADIO_RF_OUT4, m_btn_RfOut4);
    DDX_Control(pDX, IDC_RADIO_RF_OUT5, m_btn_RfOut5);
    DDX_Control(pDX, IDC_RADIO_RF_OUT6, m_btn_RfOut6);
    DDX_Control(pDX, IDC_RADIO_RF_OUT7, m_btn_RfOut7);
    DDX_Control(pDX, IDC_RADIO_RF_OUT8, m_btn_RfOut8);
    DDX_Control(pDX, IDC_RADIO_WIRED, m_rdo_Wired);
    DDX_Control(pDX, IDC_EDIT_DOPPLER_FREQUENCY, m_edit_DopplerFreq);
    DDX_Control(pDX, IDC_EDIT_DCA_OFFSET, m_edit_DCAOffset);
    DDX_Control(pDX, IDC_EDIT_START_RANGE, m_edit_StartRange);
    DDX_Control(pDX, IDC_EDIT_STOP_RANGE, m_edit_StopRange);
    DDX_Control(pDX, IDC_EDIT_INTERVAL_DATA, m_edit_IntervalData);
    DDX_Control(pDX, IDC_BTN_A1_SET, m_btn_A1Set);
    DDX_Control(pDX, IDC_RADIO_WIRELESS, m_rdo_Wireless);
    DDX_Control(pDX, IDC_EDIT_RF_DCA, m_edit_RfDCA);
    DDX_Control(pDX, IDC_BTN_A4_SET, m_btn_A4Set);
    DDX_Control(pDX, IDC_EDIT_START_ADDR, m_edit_StartAddr);
    DDX_Control(pDX, IDC_EDIT_R1_DCA, m_edit_R1DCA);
    DDX_Control(pDX, IDC_EDIT_R2_DCA, m_edit_R2DCA);
    DDX_Control(pDX, IDC_EDIT_R3_DCA, m_edit_R3DCA);
    DDX_Control(pDX, IDC_EDIT_R4_DCA, m_edit_R4DCA);
    DDX_Control(pDX, IDC_EDIT_R5_DCA, m_edit_R5DCA);
    DDX_Control(pDX, IDC_EDIT_R6_DCA, m_edit_R6DCA);
    DDX_Control(pDX, IDC_EDIT_R7_DCA, m_edit_R7DCA);
    DDX_Control(pDX, IDC_EDIT_R8_DCA, m_edit_R8DCA);
    DDX_Control(pDX, IDC_EDIT_R9_DCA, m_edit_R9DCA);
    DDX_Control(pDX, IDC_EDIT_R10_DCA, m_edit_R10DCA);
    DDX_Control(pDX, IDC_EDIT_ROM_ADDR, m_edit_ROMAddr);
    DDX_Control(pDX, IDC_EDIT_RF_DCA1, m_edit_RfDCA1);
    DDX_Control(pDX, IDC_EDIT_RF_DCA2, m_edit_RfDCA2);
    DDX_Control(pDX, IDC_EDIT_RF_DCA3, m_edit_RfDCA3);
}


BEGIN_MESSAGE_MAP(CLSAM_ParamSet, CDialogEx)
    ON_BN_CLICKED(IDC_CHECK_TGT_INFO, &CLSAM_ParamSet::OnBnClickedCheckTgtInfo)
    ON_BN_CLICKED(IDC_RADIO_WIRED, &CLSAM_ParamSet::OnBnClickedRadioWired)
    ON_BN_CLICKED(IDC_RADIO_WIRELESS, &CLSAM_ParamSet::OnBnClickedRadioWireless)
    ON_BN_CLICKED(IDC_BTN_A0_SET, &CLSAM_ParamSet::OnBnClickedBtnA0Set)
    ON_BN_CLICKED(IDC_RADIO_RF_IN1, &CLSAM_ParamSet::OnBnClickedRadioRfIn1)
    ON_BN_CLICKED(IDC_RADIO_RF_IN2, &CLSAM_ParamSet::OnBnClickedRadioRfIn2)
    ON_BN_CLICKED(IDC_RADIO_RF_IN3, &CLSAM_ParamSet::OnBnClickedRadioRfIn3)
    ON_BN_CLICKED(IDC_RADIO_RF_IN4, &CLSAM_ParamSet::OnBnClickedRadioRfIn4)
    ON_BN_CLICKED(IDC_RADIO_RF_IN5, &CLSAM_ParamSet::OnBnClickedRadioRfIn5)
    ON_BN_CLICKED(IDC_RADIO_RF_IN6, &CLSAM_ParamSet::OnBnClickedRadioRfIn6)
    ON_BN_CLICKED(IDC_RADIO_RF_IN7, &CLSAM_ParamSet::OnBnClickedRadioRfIn7)
    ON_BN_CLICKED(IDC_RADIO_RF_IN8, &CLSAM_ParamSet::OnBnClickedRadioRfIn8)
    ON_BN_CLICKED(IDC_RADIO_RF_OUT1, &CLSAM_ParamSet::OnBnClickedRadioRfOut1)
    ON_BN_CLICKED(IDC_RADIO_RF_OUT2, &CLSAM_ParamSet::OnBnClickedRadioRfOut2)
    ON_BN_CLICKED(IDC_RADIO_RF_OUT3, &CLSAM_ParamSet::OnBnClickedRadioRfOut3)
    ON_BN_CLICKED(IDC_RADIO_RF_OUT4, &CLSAM_ParamSet::OnBnClickedRadioRfOut4)
    ON_BN_CLICKED(IDC_RADIO_RF_OUT5, &CLSAM_ParamSet::OnBnClickedRadioRfOut5)
    ON_BN_CLICKED(IDC_RADIO_RF_OUT6, &CLSAM_ParamSet::OnBnClickedRadioRfOut6)
    ON_BN_CLICKED(IDC_RADIO_RF_OUT7, &CLSAM_ParamSet::OnBnClickedRadioRfOut7)
    ON_BN_CLICKED(IDC_RADIO_RF_OUT8, &CLSAM_ParamSet::OnBnClickedRadioRfOut8)
    ON_WM_CLOSE()
    ON_BN_CLICKED(IDC_BTN_A1_SET, &CLSAM_ParamSet::OnBnClickedBtnA1Set)
    ON_BN_CLICKED(IDC_BTN_A4_SET, &CLSAM_ParamSet::OnBnClickedBtnA4Set)
    ON_BN_CLICKED(IDC_BTN_A2_SET, &CLSAM_ParamSet::OnBnClickedBtnA2Set)
    ON_BN_CLICKED(IDC_BTN_A2_SET2, &CLSAM_ParamSet::OnBnClickedBtnA2Set2)
    ON_BN_CLICKED(IDC_BTN_STOP, &CLSAM_ParamSet::OnBnClickedBtnStop)
    ON_BN_CLICKED(IDC_BTN_A4_STOP, &CLSAM_ParamSet::OnBnClickedBtnA4Stop)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CLSAM_ParamSet, CDialogEx)
END_DISPATCH_MAP()

// 참고: IID_ILSAM_ParamSet에 대한 지원을 추가하여
//  VBA에서 형식 안전 바인딩을 지원합니다. 
//  이 IID는 .IDL 파일에 있는 dispinterface의 GUID와 일치해야 합니다.

// {9BE3EAEB-69CB-4002-8CED-ECC808C8CFDC}
static const IID IID_ILSAM_ParamSet =
{ 0x9BE3EAEB, 0x69CB, 0x4002, { 0x8C, 0xED, 0xEC, 0xC8, 0x8, 0xC8, 0xCF, 0xDC } };

BEGIN_INTERFACE_MAP(CLSAM_ParamSet, CDialogEx)
    INTERFACE_PART(CLSAM_ParamSet, IID_ILSAM_ParamSet, Dispatch)
END_INTERFACE_MAP()


// CLSAM_ParamSet 메시지 처리기입니다.


BOOL CLSAM_ParamSet::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    m_chk_TgtInfo.SetCheck(TRUE);

    /*  if(((CLSAM_GUIDlg *)GetParent())->f_bParamSet)*/
    u8RF_IN = 0x02;
    u8RF_OUT = 0x02;
    LoadPrevSet();

    OnBnClickedBtnA4Stop();

    return TRUE;  // return TRUE unless you set the focus to a control

}


void CLSAM_ParamSet::OnBnClickedCheckTgtInfo()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    if(m_chk_TgtInfo.GetCheck())
    {
        GetDlgItem(IDC_EDIT_DOPPLER_FREQUENCY)->EnableWindow(TRUE);
        GetDlgItem(IDC_EDIT_DCA_OFFSET)->EnableWindow(TRUE);
        GetDlgItem(IDC_EDIT_START_RANGE)->EnableWindow(TRUE);
        GetDlgItem(IDC_EDIT_STOP_RANGE)->EnableWindow(TRUE);
        GetDlgItem(IDC_EDIT_INTERVAL_DATA)->EnableWindow(TRUE);
        GetDlgItem(IDC_EDIT_RF_DCA)->EnableWindow(TRUE);
    }
    else
    {
        GetDlgItem(IDC_EDIT_DOPPLER_FREQUENCY)->EnableWindow(FALSE);
        GetDlgItem(IDC_EDIT_DCA_OFFSET)->EnableWindow(FALSE);
        GetDlgItem(IDC_EDIT_START_RANGE)->EnableWindow(FALSE);
        GetDlgItem(IDC_EDIT_STOP_RANGE)->EnableWindow(FALSE);
        GetDlgItem(IDC_EDIT_INTERVAL_DATA)->EnableWindow(FALSE);
        GetDlgItem(IDC_EDIT_RF_DCA)->EnableWindow(FALSE);
    }
}


void CLSAM_ParamSet::OnBnClickedBtnTxrxSet()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}





int CLSAM_ParamSet::SendCmdRxTx(int m_ClickedCtrl)
{
    UINT8 b_RfIn1, b_RfIn2, b_RfIn3, b_RfIn4, b_RfIn5, b_RfIn6, b_RfIn7, b_RfIn8
        , b_RfOut1, b_RfOut2, b_RfOut3, b_RfOut4, b_RfOut5, b_RfOut6, b_RfOut7, b_RfOut8;
    CString str = _T("");

    b_RfIn1 = m_btn_RfIn1.GetCheck();
    b_RfIn2 = m_btn_RfIn2.GetCheck();
    b_RfIn3 = m_btn_RfIn3.GetCheck();
    b_RfIn4 = m_btn_RfIn4.GetCheck();
    b_RfIn5 = m_btn_RfIn5.GetCheck();
    b_RfIn6 = m_btn_RfIn6.GetCheck();
    b_RfIn7 = m_btn_RfIn7.GetCheck();
    b_RfIn8 = m_btn_RfIn8.GetCheck();

    b_RfOut1 = m_btn_RfOut1.GetCheck();
    b_RfOut2 = m_btn_RfOut2.GetCheck();
    b_RfOut3 = m_btn_RfOut3.GetCheck();
    b_RfOut4 = m_btn_RfOut4.GetCheck();
    b_RfOut5 = m_btn_RfOut5.GetCheck();
    b_RfOut6 = m_btn_RfOut6.GetCheck();
    b_RfOut7 = m_btn_RfOut7.GetCheck();
    b_RfOut8 = m_btn_RfOut8.GetCheck();

    int n_RfIn, n_RfOut, n_RfResult;

    if(b_RfIn1) 
        n_RfIn = 0x0100;
    else if(b_RfIn2) 
        n_RfIn = 0x0200; 
    else if(b_RfIn3) 
        n_RfIn = 0x0300;
    else if(b_RfIn4) 
        n_RfIn = 0x0400;
    else if(b_RfIn5) 
        n_RfIn = 0x0500; 
    else if(b_RfIn6) 
        n_RfIn = 0x0600;
    else if(b_RfIn7) 
        n_RfIn = 0x0700;
    else if(b_RfIn8) 
        n_RfIn = 0x0800;

    if(b_RfOut1) 
        n_RfOut = 0x0001;
    else if(b_RfOut2) 
        n_RfOut = 0x0002; 
    else if(b_RfOut3) 
        n_RfOut = 0x0003;
    else if(b_RfOut4) 
        n_RfOut = 0x0004;
    else if(b_RfOut1) 
        n_RfOut = 0x0005;
    else if(b_RfOut2) 
        n_RfOut = 0x0006; 
    else if(b_RfOut3) 
        n_RfOut = 0x0007;
    else if(b_RfOut4) 
        n_RfOut = 0x0008;  

    n_RfResult = n_RfIn | n_RfOut; 

    WORD wLen = 0, wOp = 0;

    uCommandType uCommand;
    int nCmdIndex = 0;

    wLen = 0x0009, wOp = HEAD_OF_DATA;

    uCommand.wCommand[nCmdIndex++] = htons(wLen);			//0x0009);
    uCommand.wCommand[nCmdIndex++] = htons(wOp);			//0xAB00);
    uCommand.wCommand[nCmdIndex++] = htons((WORD)n_RfResult);

    ((CLSAM_GUIDlg *)GetParent())->SendCommand(uCommand, nCmdIndex*2);

    return 0;
}


void CLSAM_ParamSet::OnBnClickedRadioWired()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    SendCmdWire(WIRE);
}


void CLSAM_ParamSet::OnBnClickedRadioWireless()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    SendCmdWire(WIRELESS);
}


int CLSAM_ParamSet::SendCmdWire(int m_ClickedCtrl)
{
    UINT8 b_WIRE;
    CString str = _T("");

    b_WIRE = m_rdo_Wired.GetCheck();

    WORD wLen = 0, wOp = 0, wWire = 0;

    if(b_WIRE) 
        wWire = 0x0001;
    else
        wWire = 0x0000;

    uCommandType uCommand;
    int nCmdIndex = 0;

    wLen = 0x0002, wOp = WIRE_SET_OP;

    uCommand.wCommand[nCmdIndex++] = htons(wOp);			// 0x5200);
    uCommand.wCommand[nCmdIndex++] = htons(wLen);			// 0x0001);
    uCommand.wCommand[nCmdIndex++] = htons(wWire);

    ((CLSAM_GUIDlg *)GetParent())->SendCommand(uCommand, nCmdIndex*2);
    ((CLSAM_GUIDlg *)GetParent())->b_WIRE = (UINT8)wWire;

    return 0;
}


void CLSAM_ParamSet::OnBnClickedBtnA0Set()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

    CString sTmp;

    if(m_chk_TgtInfo.GetCheck())
    {
        bool bInst = FALSE;
        CString sMsg, sDpl, sDCA, sStart, sStp, sInterv;

        GetDlgItem(IDC_EDIT_DOPPLER_FREQUENCY)->GetWindowTextW(sDpl); 
        bInst = sDpl.IsEmpty();
        if(bInst)
        {
            AfxMessageBox(_T("값을 입력해주세요 - 도플러 주파수"));
            return; 
        }

        GetDlgItem(IDC_EDIT_DCA_OFFSET)->GetWindowTextW(sDCA); 
        bInst = sDCA.IsEmpty();
        if(bInst)
        {
            AfxMessageBox(_T("값을 입력해주세요 - DCA offset"));
            return; 
        }

        GetDlgItem(IDC_EDIT_START_RANGE)->GetWindowTextW(sStart); 
        bInst = sStart.IsEmpty();
        if(bInst)
        {
            AfxMessageBox(_T("값을 입력해주세요 - Start Range"));
            return; 
        }

        GetDlgItem(IDC_EDIT_STOP_RANGE)->GetWindowTextW(sStp); 
        bInst = sStp.IsEmpty();
        if(bInst)
        {
            AfxMessageBox(_T("값을 입력해주세요 - Stop Range"));
            return; 
        }

        GetDlgItem(IDC_EDIT_INTERVAL_DATA)->GetWindowTextW(sInterv); 
        bInst = sInterv.IsEmpty();
        if(bInst)
        {
            AfxMessageBox(_T("값을 입력해주세요 - Interval Data"));
            return; 
        }

        GetDlgItem(IDC_EDIT_RF_DCA)->GetWindowTextW(sInterv); 
        bInst = sInterv.IsEmpty();
        if(bInst)
        {
            AfxMessageBox(_T("값을 입력해주세요 - RF DCA"));
            return; 
        }

        m_edit_StartRange.GetWindowTextW(sTmp);
        if(_tstof(sTmp) >= 128)
        {
            AfxMessageBox(_T("값이 너무 큽니다 - Start Range"));
            return;
        }

        m_edit_StopRange.GetWindowTextW(sTmp);
        if(_tstof(sTmp) >= 128)
        {
            AfxMessageBox(_T("값이 너무 큽니다 - Stop Range"));
            return;
        }
    }
    //if(!(m_sDopplerFreq.GetLength() & m_sDCAOffset.GetLength() & m_sStartRange.GetLength() & m_sStopRange.GetLength() & m_sIntervalData.GetLength()))
    //{
    //    // AfxMessageBox(_T("값을 입력해주세요."));
    //    CString str;
    //    str.Format(_T("%d %d %d %d %d"), m_sDopplerFreq.GetLength(), m_sDCAOffset.GetLength(), m_sStartRange.GetLength(), m_sStopRange.GetLength(), m_sIntervalData.GetLength());
    //    AfxMessageBox(str);
    //    return;
    //}

    double dDopplerFreq, dDCAOffset, dStartRange, dStopRange, dIntervalData;

    U32BIT u32DopplerFreq, u32IntervalData;
    uScenarioA0 uScenarioA0;

    m_edit_DopplerFreq.GetWindowTextW(sTmp);
    dDopplerFreq = _tstof(sTmp);
    u32DopplerFreq = (U32BIT)(dDopplerFreq);

    //sTmp.Format(_T("%d"), u32DopplerFreq);
    //AfxMessageBox(sTmp);
    uScenarioA0.stScenarioA0.FreqData3 = u32DopplerFreq>>24;
    uScenarioA0.stScenarioA0.FreqData2 = u32DopplerFreq>>16;
    uScenarioA0.stScenarioA0.FreqData1 = u32DopplerFreq>>8;
    uScenarioA0.stScenarioA0.FreqData0 = u32DopplerFreq>>0;

    if(!(m_chk_TgtInfo.GetCheck()))
    {
        uScenarioA0.stScenarioA0.OffsetPower = 0xff;
    }
    else
    {
        m_edit_DCAOffset.GetWindowTextW(sTmp);

        if(_tstof(sTmp) >= 128)
        {
            AfxMessageBox(_T("값이 너무 큽니다 - DCA offset"));
            uScenarioA0.stScenarioA0.OffsetPower = 0xff;
        }
        else
        {
            dDCAOffset = _tstof(sTmp);
            uScenarioA0.stScenarioA0.OffsetPower = (BYTE)(dDCAOffset * 2);
        }
    }

    uScenarioA0.stScenarioA0.RF_IN_Path = u8RF_IN;
    uScenarioA0.stScenarioA0.RF_OUT_Path = u8RF_OUT;

    m_edit_StartRange.GetWindowTextW(sTmp);
    dStartRange = _tstof(sTmp);
    uScenarioA0.stScenarioA0.StartRange = (BYTE)(dStartRange);

    m_edit_StopRange.GetWindowTextW(sTmp);
    dStopRange = _tstof(sTmp);
    uScenarioA0.stScenarioA0.StopRange = (BYTE)(dStopRange);

    m_edit_IntervalData.GetWindowTextW(sTmp);
    dIntervalData = _tstof(sTmp);
    u32IntervalData = (U32BIT)floor((0.5/(dIntervalData * 340))*10000000);
    //sTmp.Format(_T("%d"), u32IntervalData);
    //AfxMessageBox(sTmp);
    uScenarioA0.stScenarioA0.IntervalData1 = u32IntervalData>>8;
    uScenarioA0.stScenarioA0.IntervalData0 = u32IntervalData>>0;

    uScenarioA0.stScenarioA0.CRC8 = RtnCRC8(0x00, uScenarioA0.arrScenarioA0, 15);

    WORD wLen = 0, wOp = 0;
    uCommandType uCommand;

    wLen = 0x0009, wOp = RF_CONTROL_OP;
    int nCmdIndex = 0;

    uCommand.wCommand[nCmdIndex++] = htons(wLen);			//0x0010);
    uCommand.wCommand[nCmdIndex++] = htons(wOp);			//0xAB00);
    uCommand.wCommand[nCmdIndex++] = htons(ITEM_A0);
    uCommand.wCommand[nCmdIndex++] = htons(NO_ITEM);
    uCommand.wCommand[nCmdIndex++] = (MAKEWORD(uScenarioA0.stScenarioA0.FreqData3, uScenarioA0.stScenarioA0.FreqData2 ));
    uCommand.wCommand[nCmdIndex++] = (MAKEWORD(uScenarioA0.stScenarioA0.FreqData1, uScenarioA0.stScenarioA0.FreqData0 ));
    uCommand.wCommand[nCmdIndex++] = (MAKEWORD(uScenarioA0.stScenarioA0.OffsetPower, uScenarioA0.stScenarioA0.RF_IN_Path ));
    uCommand.wCommand[nCmdIndex++] = (MAKEWORD(uScenarioA0.stScenarioA0.RF_OUT_Path, uScenarioA0.stScenarioA0.StartRange ));
    uCommand.wCommand[nCmdIndex++] = (MAKEWORD(uScenarioA0.stScenarioA0.StopRange, uScenarioA0.stScenarioA0.IntervalData1 ));
    uCommand.bCommand[18] = uScenarioA0.stScenarioA0.IntervalData0;
    uCommand.bCommand[19] =  RtnCRC8(0x00, uCommand.bCommand, 17);
    nCmdIndex++;

    ((CLSAM_GUIDlg *)GetParent())->SendCommand(uCommand, nCmdIndex*2);
    ((CLSAM_GUIDlg *)GetParent())->prev_uScenario.stScenario.FreqData3 = uScenarioA0.stScenarioA0.FreqData3;
    ((CLSAM_GUIDlg *)GetParent())->prev_uScenario.stScenario.FreqData2 = uScenarioA0.stScenarioA0.FreqData2;
    ((CLSAM_GUIDlg *)GetParent())->prev_uScenario.stScenario.FreqData1 = uScenarioA0.stScenarioA0.FreqData1;
    ((CLSAM_GUIDlg *)GetParent())->prev_uScenario.stScenario.FreqData0 = uScenarioA0.stScenarioA0.FreqData0;
    ((CLSAM_GUIDlg *)GetParent())->prev_uScenario.stScenario.OffsetPower = uScenarioA0.stScenarioA0.OffsetPower;
    ((CLSAM_GUIDlg *)GetParent())->prev_uScenario.stScenario.RF_IN_Path = uScenarioA0.stScenarioA0.RF_IN_Path;
    ((CLSAM_GUIDlg *)GetParent())->prev_uScenario.stScenario.RF_OUT_Path = uScenarioA0.stScenarioA0.RF_OUT_Path;
    ((CLSAM_GUIDlg *)GetParent())->prev_uScenario.stScenario.StartRange = uScenarioA0.stScenarioA0.StartRange;
    ((CLSAM_GUIDlg *)GetParent())->prev_uScenario.stScenario.StopRange = uScenarioA0.stScenarioA0.StopRange;
    ((CLSAM_GUIDlg *)GetParent())->prev_uScenario.stScenario.IntervalData1 = uScenarioA0.stScenarioA0.IntervalData1;
    ((CLSAM_GUIDlg *)GetParent())->prev_uScenario.stScenario.IntervalData0 = uScenarioA0.stScenarioA0.IntervalData0;

    // ((CLSAM_GUIDlg *)GetParent())->f_bParamSet = TRUE;
}


void CLSAM_ParamSet::OnBnClickedRadioRfIn1()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    u8RF_IN = 0x02;
    SetRFGroup(1);
}


void CLSAM_ParamSet::OnBnClickedRadioRfIn2()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    u8RF_IN = 0x04;
    SetRFGroup(2);
}


void CLSAM_ParamSet::OnBnClickedRadioRfIn3()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    u8RF_IN = 0x01;
    SetRFGroup(3);
}


void CLSAM_ParamSet::OnBnClickedRadioRfIn4()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    u8RF_IN = 0x03;
    SetRFGroup(4);
}


void CLSAM_ParamSet::OnBnClickedRadioRfIn5()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    u8RF_IN = 0x02;
    SetRFGroup(5);
}


void CLSAM_ParamSet::OnBnClickedRadioRfIn6()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    u8RF_IN = 0x04;
    SetRFGroup(6);
}


void CLSAM_ParamSet::OnBnClickedRadioRfIn7()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    u8RF_IN = 0x01;
    SetRFGroup(7);
}


void CLSAM_ParamSet::OnBnClickedRadioRfIn8()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    u8RF_IN = 0x03;
    SetRFGroup(8);
}


void CLSAM_ParamSet::OnBnClickedRadioRfOut1()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    u8RF_OUT = 0x02;
}


void CLSAM_ParamSet::OnBnClickedRadioRfOut2()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    u8RF_OUT = 0x04;
}


void CLSAM_ParamSet::OnBnClickedRadioRfOut3()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    u8RF_OUT = 0x01;
}


void CLSAM_ParamSet::OnBnClickedRadioRfOut4()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    u8RF_OUT = 0x03;
}


void CLSAM_ParamSet::OnBnClickedRadioRfOut5()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    u8RF_OUT = 0x02;
}


void CLSAM_ParamSet::OnBnClickedRadioRfOut6()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    u8RF_OUT = 0x04;
}


void CLSAM_ParamSet::OnBnClickedRadioRfOut7()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    u8RF_OUT = 0x01;
}


void CLSAM_ParamSet::OnBnClickedRadioRfOut8()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    u8RF_OUT = 0x03;
}


void CLSAM_ParamSet::OnClose()
{
    // TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
    DestroyWindow();
    CDialogEx::OnClose();
}


BOOL CLSAM_ParamSet::PreTranslateMessage(MSG* pMsg)
{
    // TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
    if(pMsg->message == WM_KEYDOWN)
    {
        if(pMsg->wParam == VK_ESCAPE)
            return TRUE;
        else if(pMsg->wParam == VK_RETURN)
            return TRUE;
    }

    return CDialogEx::PreTranslateMessage(pMsg);
}


void CLSAM_ParamSet::OnBnClickedBtnA1Set()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    // ((CLSAM_GUIDlg *)GetParent())->SendRFDCA(0, 50);
    WORD wLen = 0, wOp = 0;
    uCommandType uCommand;


    wLen = 0x0009, wOp = RF_CONTROL_OP;
    int nCmdIndex = 0;

    uCommand.wCommand[nCmdIndex++] = htons(wLen);			//0x0010);
    uCommand.wCommand[nCmdIndex++] = htons(wOp);			//0xAB00);
    uCommand.wCommand[nCmdIndex++] = htons(ITEM_A1);
    uCommand.wCommand[nCmdIndex++] = htons(NO_ITEM);
    uCommand.wCommand[nCmdIndex++] = (MAKEWORD(0x00, 0x01));
    uCommand.wCommand[nCmdIndex++] = (MAKEWORD(0x00, 0x00));
    uCommand.wCommand[nCmdIndex++] = (MAKEWORD(0x00, 0x00));
    uCommand.wCommand[nCmdIndex++] = (MAKEWORD(0x00, 0x00));
    uCommand.wCommand[nCmdIndex++] = (MAKEWORD(0x00, 0x00));
    uCommand.wCommand[nCmdIndex++] = (MAKEWORD(0x00, 0x00));

    ((CLSAM_GUIDlg *)GetParent())->SendCommand(uCommand, nCmdIndex*2);
}


void CLSAM_ParamSet::LoadPrevSet(void)
{
    CString sTmp;
    double dTmp = 0;
    U32BIT u32Tmp = 0;

    // 도플러 주파수 Load
    sTmp.Format(_T("%X%X%X%X"), ((CLSAM_GUIDlg *)GetParent())->prev_uScenario.stScenario.FreqData3, ((CLSAM_GUIDlg *)GetParent())->prev_uScenario.stScenario.FreqData2
        , ((CLSAM_GUIDlg *)GetParent())->prev_uScenario.stScenario.FreqData1, ((CLSAM_GUIDlg *)GetParent())->prev_uScenario.stScenario.FreqData0);
    sTmp.Format(_T("%.1f"), (double)(_tcstol(sTmp, NULL, 16)));
    SetDlgItemTextW(IDC_EDIT_DOPPLER_FREQUENCY, sTmp);

    // DCA offset Load
    sTmp.Format(_T("%X"), ((CLSAM_GUIDlg *)GetParent())->prev_uScenario.stScenario.OffsetPower);

    sTmp.Format(_T("%.1f"), ((double)(_tcstol(sTmp, NULL, 16))) / 2);
    SetDlgItemTextW(IDC_EDIT_DCA_OFFSET, sTmp);

    switch(((CLSAM_GUIDlg *)GetParent())->prev_uScenario.stScenario.RF_IN_Path)
    {
    case 0:
        m_btn_RfIn1.SetCheck(TRUE);
        break;
    case 1:
        m_btn_RfIn2.SetCheck(TRUE);
        break;
    case 2:
        m_btn_RfIn3.SetCheck(TRUE);
        break;
    case 3:
        m_btn_RfIn4.SetCheck(TRUE);
        break;
    case 4:
        m_btn_RfIn5.SetCheck(TRUE);
        break;
    case 5:
        m_btn_RfIn6.SetCheck(TRUE);
        break;
    case 6:
        m_btn_RfIn7.SetCheck(TRUE);
        break;
    case 7:
        m_btn_RfIn8.SetCheck(TRUE);
        break;
    }

    switch(((CLSAM_GUIDlg *)GetParent())->prev_uScenario.stScenario.RF_OUT_Path)
    {
    case 0:
        m_btn_RfOut1.SetCheck(TRUE);
        break;
    case 1:
        m_btn_RfOut2.SetCheck(TRUE);
        break;
    case 2:
        m_btn_RfOut3.SetCheck(TRUE);
        break;
    case 3:
        m_btn_RfOut4.SetCheck(TRUE);
        break;
    case 4:
        m_btn_RfOut5.SetCheck(TRUE);
        break;
    case 5:
        m_btn_RfOut6.SetCheck(TRUE);
        break;
    case 6:
        m_btn_RfOut7.SetCheck(TRUE);
        break;
    case 7:
        m_btn_RfOut8.SetCheck(TRUE);
        break;
    }

    switch(((CLSAM_GUIDlg *)GetParent())->b_WIRE)
    {
    case 0:
        m_rdo_Wired.SetCheck(TRUE);
        break;
    case 1:
        m_rdo_Wireless.SetCheck(TRUE);
        break;
    }

    // Start Range
    sTmp.Format(_T("%X"), ((CLSAM_GUIDlg *)GetParent())->prev_uScenario.stScenario.StartRange);

    sTmp.Format(_T("%.1f"), (double)(_tcstol(sTmp, NULL, 16)));
    SetDlgItemTextW(IDC_EDIT_START_RANGE, sTmp);

    // Stop Range
    sTmp.Format(_T("%X"), ((CLSAM_GUIDlg *)GetParent())->prev_uScenario.stScenario.StopRange);

    sTmp.Format(_T("%.1f"), (double)(_tcstol(sTmp, NULL, 16)));
    SetDlgItemTextW(IDC_EDIT_STOP_RANGE, sTmp);

    // Interval Data
    //if( (((CLSAM_GUIDlg *)GetParent())->prev_uScenario.stScenario.IntervalData1 == 0) & (((CLSAM_GUIDlg *)GetParent())->prev_uScenario.stScenario.IntervalData0 == 0) )
    //{
    //    return;
    //}

    sTmp.Format(_T("%X%X"), ((CLSAM_GUIDlg *)GetParent())->prev_uScenario.stScenario.IntervalData1, ((CLSAM_GUIDlg *)GetParent())->prev_uScenario.stScenario.IntervalData0);
    dTmp = (double)(_tcstol(sTmp, NULL, 16));
    if(dTmp != 0)
    {
        dTmp = dTmp/10000000;
        //sTmp.Format(_T("%f"), dTmp);
        //AfxMessageBox(sTmp);
        sTmp.Format(_T("%.1f"), (0.5/dTmp)/340);
        SetDlgItemTextW(IDC_EDIT_INTERVAL_DATA, sTmp);
    }
    else
    {
        sTmp.Format(_T("0.0"));
        SetDlgItemTextW(IDC_EDIT_INTERVAL_DATA, sTmp);
    }

    sTmp.Format(_T("%X"), ((CLSAM_GUIDlg *)GetParent())->prev_uScenario.stScenario.RF_DCA);
    dTmp = (double)(_tcstol(sTmp, NULL, 16));
    if(dTmp != 0)
    {
        dTmp = dTmp/2;
        //sTmp.Format(_T("%f"), dTmp);
        //AfxMessageBox(sTmp);
        sTmp.Format(_T("%.1f"), dTmp);
        SetDlgItemTextW(IDC_EDIT_RF_DCA, sTmp);
    }
    else
    {
        sTmp.Format(_T("0.0"));
        SetDlgItemTextW(IDC_EDIT_RF_DCA, sTmp);
    }

    if(((CLSAM_GUIDlg *)GetParent())->prev_uScenarioA4.stScenarioA4.Start_Stop)
    {
        m_btn_A4Set.SetWindowText(_T("고정표적 중지"));
    }
    else
    {
        m_btn_A4Set.SetWindowText(_T("고정표적 발생"));
    }

    // 감쇄기 데이터 : A2
    sTmp.Format(_T("%X"), ((CLSAM_GUIDlg *)GetParent())->prev_uScenarioA2.stScenarioA2.Start_Addr);
    sTmp.Format(_T("%.1f"), (double)(_tcstol(sTmp, NULL, 16)));
    SetDlgItemTextW(IDC_EDIT_START_ADDR, sTmp);

    sTmp.Format(_T("%X"), ((CLSAM_GUIDlg *)GetParent())->prev_uScenarioA2.stScenarioA2.R1_DCA);
    sTmp.Format(_T("%.1f"), ((double)(_tcstol(sTmp, NULL, 16))/2));
    SetDlgItemTextW(IDC_EDIT_R1_DCA, sTmp);

    sTmp.Format(_T("%X"), ((CLSAM_GUIDlg *)GetParent())->prev_uScenarioA2.stScenarioA2.R2_DCA);
    sTmp.Format(_T("%.1f"), ((double)(_tcstol(sTmp, NULL, 16))/2));
    SetDlgItemTextW(IDC_EDIT_R2_DCA, sTmp);

    sTmp.Format(_T("%X"), ((CLSAM_GUIDlg *)GetParent())->prev_uScenarioA2.stScenarioA2.R3_DCA);
    sTmp.Format(_T("%.1f"), ((double)(_tcstol(sTmp, NULL, 16))/2));
    SetDlgItemTextW(IDC_EDIT_R3_DCA, sTmp);

    sTmp.Format(_T("%X"), ((CLSAM_GUIDlg *)GetParent())->prev_uScenarioA2.stScenarioA2.R4_DCA);
    sTmp.Format(_T("%.1f"), ((double)(_tcstol(sTmp, NULL, 16))/2));
    SetDlgItemTextW(IDC_EDIT_R4_DCA, sTmp);

    sTmp.Format(_T("%X"), ((CLSAM_GUIDlg *)GetParent())->prev_uScenarioA2.stScenarioA2.R5_DCA);
    sTmp.Format(_T("%.1f"), ((double)(_tcstol(sTmp, NULL, 16))/2));
    SetDlgItemTextW(IDC_EDIT_R5_DCA, sTmp);

    sTmp.Format(_T("%X"), ((CLSAM_GUIDlg *)GetParent())->prev_uScenarioA2.stScenarioA2.R6_DCA);
    sTmp.Format(_T("%.1f"), ((double)(_tcstol(sTmp, NULL, 16))/2));
    SetDlgItemTextW(IDC_EDIT_R6_DCA, sTmp);

    sTmp.Format(_T("%X"), ((CLSAM_GUIDlg *)GetParent())->prev_uScenarioA2.stScenarioA2.R7_DCA);
    sTmp.Format(_T("%.1f"), ((double)(_tcstol(sTmp, NULL, 16))/2));
    SetDlgItemTextW(IDC_EDIT_R7_DCA, sTmp);

    sTmp.Format(_T("%X"), ((CLSAM_GUIDlg *)GetParent())->prev_uScenarioA2.stScenarioA2.R8_DCA);
    sTmp.Format(_T("%.1f"), ((double)(_tcstol(sTmp, NULL, 16))/2));
    SetDlgItemTextW(IDC_EDIT_R8_DCA, sTmp);

    sTmp.Format(_T("%X"), ((CLSAM_GUIDlg *)GetParent())->prev_uScenarioA2.stScenarioA2.R9_DCA);
    sTmp.Format(_T("%.1f"), ((double)(_tcstol(sTmp, NULL, 16))/2));
    SetDlgItemTextW(IDC_EDIT_R9_DCA, sTmp);

    sTmp.Format(_T("%X"), ((CLSAM_GUIDlg *)GetParent())->prev_uScenarioA2.stScenarioA2.R10_DCA);
    sTmp.Format(_T("%.1f"), ((double)(_tcstol(sTmp, NULL, 16))/2));
    SetDlgItemTextW(IDC_EDIT_R10_DCA, sTmp);

    sTmp.Format(_T("%X"), ((CLSAM_GUIDlg *)GetParent())->prev_uScenario5A.stScenario5A.ROM_Addr);
    sTmp.Format(_T("%.1f"), ((double)(_tcstol(sTmp, NULL, 16))/2));
    SetDlgItemTextW(IDC_EDIT_ROM_ADDR, sTmp);

    sTmp.Format(_T("%X"), ((CLSAM_GUIDlg *)GetParent())->prev_uScenario5A.stScenario5A.DCA_D15to8);
    sTmp.Format(_T("%.0f"), ((double)(_tcstol(sTmp, NULL, 16))/8));
    SetDlgItemTextW(IDC_EDIT_RF_DCA3, sTmp);

    U8BIT u8DCA1 = 0, u8DCA2 = 0;

    //sTmp.Format(_T("%0X"), ((CLSAM_GUIDlg *)GetParent())->prev_uScenario5A.stScenario5A.DCA_D7to0);
    //AfxMessageBox(sTmp);

    u8DCA2 = _tcstol(sTmp, NULL, 16) >> 4;
    u8DCA1 = _tcstol(sTmp, NULL, 16) / 2;

    sTmp.Format(_T("%u"), u8DCA2);
    SetDlgItemTextW(IDC_EDIT_RF_DCA2, sTmp);
    sTmp.Format(_T("%u"), u8DCA1);
    SetDlgItemTextW(IDC_EDIT_RF_DCA1, sTmp);
}


void CLSAM_ParamSet::OnBnClickedBtnA4Set()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    // ((CLSAM_GUIDlg *)GetParent())->SendRFDCA(0, 50);

    CString sTmp;

    if(m_chk_TgtInfo.GetCheck())
    {
        bool bInst = FALSE;
        CString sMsg, sDpl, sDCA, sStart, sStp, sRfDCA;

        GetDlgItem(IDC_EDIT_DOPPLER_FREQUENCY)->GetWindowTextW(sDpl); 
        bInst = sDpl.IsEmpty();
        if(bInst)
        {
            AfxMessageBox(_T("값을 입력해주세요 - 도플러 주파수"));
            return; 
        }

        GetDlgItem(IDC_EDIT_DCA_OFFSET)->GetWindowTextW(sDCA); 
        bInst = sDCA.IsEmpty();
        if(bInst)
        {
            AfxMessageBox(_T("값을 입력해주세요 - DCA offset"));
            return; 
        }

        GetDlgItem(IDC_EDIT_START_RANGE)->GetWindowTextW(sStart); 
        bInst = sStart.IsEmpty();
        if(bInst)
        {
            AfxMessageBox(_T("값을 입력해주세요 - Start Range"));
            return; 
        }

        GetDlgItem(IDC_EDIT_STOP_RANGE)->GetWindowTextW(sStp); 
        bInst = sStp.IsEmpty();
        if(bInst)
        {
            AfxMessageBox(_T("값을 입력해주세요 - Stop Range"));
            return; 
        }

        GetDlgItem(IDC_EDIT_RF_DCA)->GetWindowTextW(sRfDCA); 
        bInst = sRfDCA.IsEmpty();
        if(bInst)
        {
            AfxMessageBox(_T("값을 입력해주세요 - RF DCA"));
            return; 
        }

        m_edit_StartRange.GetWindowTextW(sTmp);
        if(_tstof(sTmp) >= 128)
        {
            AfxMessageBox(_T("값이 너무 큽니다 - Start Range"));
            return;
        }

        m_edit_StopRange.GetWindowTextW(sTmp);
        if(_tstof(sTmp) >= 128)
        {
            AfxMessageBox(_T("값이 너무 큽니다 - Stop Range"));
            return;
        }
    }

    double dDopplerFreq, dDCAOffset, dStartRange, dStopRange, dRfDCA;

    U32BIT u32DopplerFreq;
    uScenarioA4 uScenarioA4;

    //if(f_bFixedTgt)
    //{
    //    uScenarioA4.stScenarioA4.Start_Stop = 0x00;
    //    m_btn_A4Set.SetWindowText(_T("고정표적 발생"));
    //}
    //else
    //{
    //    uScenarioA4.stScenarioA4.Start_Stop =  0x01;
    //    m_btn_A4Set.SetWindowText(_T("고정표적 중지"));
    //}

    //f_bFixedTgt = !f_bFixedTgt;

    m_edit_DopplerFreq.GetWindowTextW(sTmp);
    dDopplerFreq = _tstof(sTmp);
    u32DopplerFreq = (U32BIT)(dDopplerFreq);

    //sTmp.Format(_T("%d"), u32DopplerFreq);
    //AfxMessageBox(sTmp);
    uScenarioA4.stScenarioA4.FreqData3 = u32DopplerFreq>>24;
    uScenarioA4.stScenarioA4.FreqData2 = u32DopplerFreq>>16;
    uScenarioA4.stScenarioA4.FreqData1 = u32DopplerFreq>>8;
    uScenarioA4.stScenarioA4.FreqData0 = u32DopplerFreq>>0;
    uScenarioA4.stScenarioA4.Start_Stop =  0x01;

    if(!(m_chk_TgtInfo.GetCheck()))
    {
        uScenarioA4.stScenarioA4.OffsetPower = 0xff;
    }
    else
    {
        m_edit_DCAOffset.GetWindowTextW(sTmp);

        if(_tstof(sTmp) >= 128)
        {
            AfxMessageBox(_T("값이 너무 큽니다 - DCA offset"));
            uScenarioA4.stScenarioA4.OffsetPower = 0xff;
        }
        else
        {
            dDCAOffset = _tstof(sTmp);
            //if(!f_bFixedTgt)
            //     uScenarioA4.stScenarioA4.OffsetPower = 0xFF;
            //else
            uScenarioA4.stScenarioA4.OffsetPower = (BYTE)(dDCAOffset * 2);
        }
    }

    uScenarioA4.stScenarioA4.RF_IN_Path = u8RF_IN;
    uScenarioA4.stScenarioA4.RF_OUT_Path = u8RF_OUT;

    m_edit_StartRange.GetWindowTextW(sTmp);
    dStartRange = _tstof(sTmp);
    uScenarioA4.stScenarioA4.StartRange = (BYTE)(dStartRange);

    m_edit_StopRange.GetWindowTextW(sTmp);
    dStopRange = _tstof(sTmp);
    uScenarioA4.stScenarioA4.StopRange = (BYTE)(dStopRange);

    m_edit_RfDCA.GetWindowTextW(sTmp);
    dRfDCA = _tstof(sTmp);
    uScenarioA4.stScenarioA4.RF_DCA = (BYTE)(dRfDCA*2);
    //sTmp.Format(_T("%d"), u32IntervalData);
    //AfxMessageBox(sTmp);


    WORD wLen = 0, wOp = 0;
    uCommandType uCommand;

    wLen = 0x0009, wOp = RF_CONTROL_OP;
    int nCmdIndex = 0;

    uCommand.wCommand[nCmdIndex++] = htons(wLen);			//0x0010);
    uCommand.wCommand[nCmdIndex++] = htons(wOp);			//0xAB00);
    uCommand.wCommand[nCmdIndex++] = htons(ITEM_A4);
    uCommand.wCommand[nCmdIndex++] = htons(NO_ITEM);
    uCommand.wCommand[nCmdIndex++] = (MAKEWORD(uScenarioA4.stScenarioA4.FreqData3, uScenarioA4.stScenarioA4.FreqData2 ));
    uCommand.wCommand[nCmdIndex++] = (MAKEWORD(uScenarioA4.stScenarioA4.FreqData1, uScenarioA4.stScenarioA4.FreqData0 ));
    uCommand.wCommand[nCmdIndex++] = (MAKEWORD(uScenarioA4.stScenarioA4.OffsetPower, uScenarioA4.stScenarioA4.RF_IN_Path ));
    uCommand.wCommand[nCmdIndex++] = (MAKEWORD(uScenarioA4.stScenarioA4.RF_OUT_Path, uScenarioA4.stScenarioA4.StartRange ));
    uCommand.wCommand[nCmdIndex++] = (MAKEWORD(uScenarioA4.stScenarioA4.StopRange, uScenarioA4.stScenarioA4.RF_DCA ));
    uCommand.bCommand[18] = uScenarioA4.stScenarioA4.Start_Stop;
     uCommand.bCommand[19] = RtnCRC8(0x00, uCommand.bCommand, 19);
     nCmdIndex++;

    ((CLSAM_GUIDlg *)GetParent())->SendCommand(uCommand, nCmdIndex*2);
    ((CLSAM_GUIDlg *)GetParent())->prev_uScenario.stScenario.FreqData3 = uScenarioA4.stScenarioA4.FreqData3;
    ((CLSAM_GUIDlg *)GetParent())->prev_uScenario.stScenario.FreqData2 = uScenarioA4.stScenarioA4.FreqData2;
    ((CLSAM_GUIDlg *)GetParent())->prev_uScenario.stScenario.FreqData1 = uScenarioA4.stScenarioA4.FreqData1;
    ((CLSAM_GUIDlg *)GetParent())->prev_uScenario.stScenario.FreqData0 = uScenarioA4.stScenarioA4.FreqData0;
    ((CLSAM_GUIDlg *)GetParent())->prev_uScenario.stScenario.OffsetPower = uScenarioA4.stScenarioA4.OffsetPower;
    ((CLSAM_GUIDlg *)GetParent())->prev_uScenario.stScenario.RF_IN_Path = uScenarioA4.stScenarioA4.RF_IN_Path;
    ((CLSAM_GUIDlg *)GetParent())->prev_uScenario.stScenario.RF_OUT_Path = uScenarioA4.stScenarioA4.RF_OUT_Path;
    ((CLSAM_GUIDlg *)GetParent())->prev_uScenario.stScenario.StartRange = uScenarioA4.stScenarioA4.StartRange;
    ((CLSAM_GUIDlg *)GetParent())->prev_uScenario.stScenario.StopRange = uScenarioA4.stScenarioA4.StopRange;
    ((CLSAM_GUIDlg *)GetParent())->prev_uScenario.stScenario.RF_DCA = uScenarioA4.stScenarioA4.RF_DCA;
    ((CLSAM_GUIDlg *)GetParent())->prev_uScenario.stScenario.Start_Stop = uScenarioA4.stScenarioA4.Start_Stop;

    // ((CLSAM_GUIDlg *)GetParent())->f_bParamSet = TRUE;
}


void CLSAM_ParamSet::OnBnClickedBtnA2Set()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    CString sTmp;

    if(m_chk_TgtInfo.GetCheck())
    {
        bool bInst = FALSE;
        CString sMsg;

        GetDlgItem(IDC_EDIT_START_ADDR)->GetWindowTextW(sMsg); 
        bInst = sMsg.IsEmpty();
        if(bInst)
        {
            AfxMessageBox(_T("값을 입력해주세요 - Strart_Addr"));
            return; 
        }

        GetDlgItem(IDC_EDIT_R1_DCA)->GetWindowTextW(sMsg); 
        bInst = sMsg.IsEmpty();
        if(bInst)
        {
            AfxMessageBox(_T("값을 입력해주세요 - R1_DCA"));
            return; 
        }

        GetDlgItem(IDC_EDIT_R2_DCA)->GetWindowTextW(sMsg); 
        bInst = sMsg.IsEmpty();
        if(bInst)
        {
            AfxMessageBox(_T("값을 입력해주세요 - R2_DCA"));
            return; 
        }

        GetDlgItem(IDC_EDIT_R3_DCA)->GetWindowTextW(sMsg); 
        bInst = sMsg.IsEmpty();
        if(bInst)
        {
            AfxMessageBox(_T("값을 입력해주세요 - R3_DCA"));
            return; 
        }

        GetDlgItem(IDC_EDIT_R4_DCA)->GetWindowTextW(sMsg); 
        bInst = sMsg.IsEmpty();
        if(bInst)
        {
            AfxMessageBox(_T("값을 입력해주세요 - R4_DCA"));
            return; 
        }

        GetDlgItem(IDC_EDIT_R4_DCA)->GetWindowTextW(sMsg); 
        bInst = sMsg.IsEmpty();
        if(bInst)
        {
            AfxMessageBox(_T("값을 입력해주세요 - R4_DCA"));
            return; 
        }

        GetDlgItem(IDC_EDIT_R4_DCA)->GetWindowTextW(sMsg); 
        bInst = sMsg.IsEmpty();
        if(bInst)
        {
            AfxMessageBox(_T("값을 입력해주세요 - R4_DCA"));
            return; 
        }

        GetDlgItem(IDC_EDIT_R4_DCA)->GetWindowTextW(sMsg); 
        bInst = sMsg.IsEmpty();
        if(bInst)
        {
            AfxMessageBox(_T("값을 입력해주세요 - R4_DCA"));
            return; 
        }

        GetDlgItem(IDC_EDIT_R4_DCA)->GetWindowTextW(sMsg); 
        bInst = sMsg.IsEmpty();
        if(bInst)
        {
            AfxMessageBox(_T("값을 입력해주세요 - R4_DCA"));
            return; 
        }

        GetDlgItem(IDC_EDIT_R4_DCA)->GetWindowTextW(sMsg); 
        bInst = sMsg.IsEmpty();
        if(bInst)
        {
            AfxMessageBox(_T("값을 입력해주세요 - R4_DCA"));
            return; 
        }

        GetDlgItem(IDC_EDIT_R4_DCA)->GetWindowTextW(sMsg); 
        bInst = sMsg.IsEmpty();
        if(bInst)
        {
            AfxMessageBox(_T("값을 입력해주세요 - R4_DCA"));
            return; 
        }
    }

    double dTmp;
    U8BIT u8StartAddr, u8R1DCA, u8R2DCA, u8R3DCA, u8R4DCA, u8R5DCA, u8R6DCA, u8R7DCA, u8R8DCA, u8R9DCA, u8R10DCA;
    uScenarioA2 uScenarioA2;

    m_edit_StartAddr.GetWindowTextW(sTmp);
    dTmp = _tstof(sTmp);
    u8StartAddr = (U8BIT)dTmp;
    uScenarioA2.stScenarioA2.Start_Addr = u8StartAddr;

    m_edit_R1DCA.GetWindowTextW(sTmp);
    dTmp = _tstof(sTmp);
    u8R1DCA = (U8BIT)(dTmp*2);
    uScenarioA2.stScenarioA2.R1_DCA = u8R1DCA;

    m_edit_R2DCA.GetWindowTextW(sTmp);
    dTmp = _tstof(sTmp);
    u8R2DCA = (U8BIT)(dTmp*2);
    uScenarioA2.stScenarioA2.R2_DCA = u8R2DCA;

    m_edit_R3DCA.GetWindowTextW(sTmp);
    dTmp = _tstof(sTmp);
    u8R3DCA = (U8BIT)(dTmp*2);
    uScenarioA2.stScenarioA2.R3_DCA = u8R3DCA;

    m_edit_R4DCA.GetWindowTextW(sTmp);
    dTmp = _tstof(sTmp);
    u8R4DCA = (U8BIT)(dTmp*2);
    uScenarioA2.stScenarioA2.R4_DCA = u8R4DCA;

    m_edit_R5DCA.GetWindowTextW(sTmp);
    dTmp = _tstof(sTmp);
    u8R5DCA = (U8BIT)(dTmp*2);
    uScenarioA2.stScenarioA2.R5_DCA = u8R5DCA;

    m_edit_R6DCA.GetWindowTextW(sTmp);
    dTmp = _tstof(sTmp);
    u8R6DCA = (U8BIT)(dTmp*2);
    uScenarioA2.stScenarioA2.R6_DCA = u8R6DCA;

    m_edit_R7DCA.GetWindowTextW(sTmp);
    dTmp = _tstof(sTmp);
    u8R7DCA = (U8BIT)(dTmp*2);
    uScenarioA2.stScenarioA2.R7_DCA = u8R7DCA;

    m_edit_R8DCA.GetWindowTextW(sTmp);
    dTmp = _tstof(sTmp);
    u8R8DCA = (U8BIT)(dTmp*2);
    uScenarioA2.stScenarioA2.R8_DCA = u8R8DCA;

    m_edit_R9DCA.GetWindowTextW(sTmp);
    dTmp = _tstof(sTmp);
    u8R9DCA = (U8BIT)(dTmp*2);
    uScenarioA2.stScenarioA2.R9_DCA = u8R9DCA;

    m_edit_R10DCA.GetWindowTextW(sTmp);
    dTmp = _tstof(sTmp);
    u8R10DCA = (U8BIT)(dTmp*2);
    uScenarioA2.stScenarioA2.R10_DCA = u8R10DCA;

    WORD wLen = 0x0009, wOp = RF_CONTROL_OP;
    uCommandType uCommand;

    int nCmdIndex = 0;

    uCommand.wCommand[nCmdIndex++] = htons(wLen);
    uCommand.wCommand[nCmdIndex++] = htons(wOp);
    uCommand.wCommand[nCmdIndex++] = htons(ITEM_A2);
    uCommand.wCommand[nCmdIndex++] = htons(NO_ITEM);
    uCommand.wCommand[nCmdIndex++] = (MAKEWORD(uScenarioA2.stScenarioA2.Start_Addr, uScenarioA2.stScenarioA2.R1_DCA ));
    uCommand.wCommand[nCmdIndex++] = (MAKEWORD(uScenarioA2.stScenarioA2.R2_DCA, uScenarioA2.stScenarioA2.R3_DCA ));
    uCommand.wCommand[nCmdIndex++] = (MAKEWORD(uScenarioA2.stScenarioA2.R4_DCA, uScenarioA2.stScenarioA2.R5_DCA ));
    uCommand.wCommand[nCmdIndex++] = (MAKEWORD(uScenarioA2.stScenarioA2.R6_DCA, uScenarioA2.stScenarioA2.R7_DCA ));
    uCommand.wCommand[nCmdIndex++] = (MAKEWORD(uScenarioA2.stScenarioA2.R8_DCA, uScenarioA2.stScenarioA2.R9_DCA ));
    uCommand.bCommand[18] = uScenarioA2.stScenarioA2.R10_DCA;
    uCommand.bCommand[19] = RtnCRC8(0x00, uCommand.bCommand, 19);
    nCmdIndex++;

    ((CLSAM_GUIDlg *)GetParent())->SendCommand(uCommand, nCmdIndex*2);
    ((CLSAM_GUIDlg *)GetParent())->prev_uScenarioA2.stScenarioA2.Start_Addr = uScenarioA2.stScenarioA2.Start_Addr;
    ((CLSAM_GUIDlg *)GetParent())->prev_uScenarioA2.stScenarioA2.R1_DCA = uScenarioA2.stScenarioA2.R1_DCA;
    ((CLSAM_GUIDlg *)GetParent())->prev_uScenarioA2.stScenarioA2.R2_DCA = uScenarioA2.stScenarioA2.R2_DCA;
    ((CLSAM_GUIDlg *)GetParent())->prev_uScenarioA2.stScenarioA2.R3_DCA = uScenarioA2.stScenarioA2.R3_DCA;
    ((CLSAM_GUIDlg *)GetParent())->prev_uScenarioA2.stScenarioA2.R4_DCA = uScenarioA2.stScenarioA2.R4_DCA;
    ((CLSAM_GUIDlg *)GetParent())->prev_uScenarioA2.stScenarioA2.R5_DCA = uScenarioA2.stScenarioA2.R5_DCA;
    ((CLSAM_GUIDlg *)GetParent())->prev_uScenarioA2.stScenarioA2.R6_DCA = uScenarioA2.stScenarioA2.R6_DCA;
    ((CLSAM_GUIDlg *)GetParent())->prev_uScenarioA2.stScenarioA2.R7_DCA = uScenarioA2.stScenarioA2.R7_DCA;
    ((CLSAM_GUIDlg *)GetParent())->prev_uScenarioA2.stScenarioA2.R8_DCA = uScenarioA2.stScenarioA2.R8_DCA;
    ((CLSAM_GUIDlg *)GetParent())->prev_uScenarioA2.stScenarioA2.R9_DCA = uScenarioA2.stScenarioA2.R9_DCA;
    ((CLSAM_GUIDlg *)GetParent())->prev_uScenarioA2.stScenarioA2.R10_DCA = uScenarioA2.stScenarioA2.R10_DCA;

    // ((CLSAM_GUIDlg *)GetParent())->f_bParamSet = TRUE;
}


void CLSAM_ParamSet::OnBnClickedBtnA2Set2()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    CString sTmp;

    bool bInst = FALSE;
    CString sMsg;

    GetDlgItem(IDC_EDIT_ROM_ADDR)->GetWindowTextW(sMsg); 
    bInst = sMsg.IsEmpty();
    if(bInst)
    {
        AfxMessageBox(_T("값을 입력해주세요 - RF_DCA"));
        return; 
    }

    GetDlgItem(IDC_EDIT_RF_DCA1)->GetWindowTextW(sMsg); 
    bInst = sMsg.IsEmpty();
    if(bInst)
    {
        AfxMessageBox(_T("값을 입력해주세요 - RF_DCA1"));
        return; 
    }

    GetDlgItem(IDC_EDIT_RF_DCA2)->GetWindowTextW(sMsg); 
    bInst = sMsg.IsEmpty();
    if(bInst)
    {
        AfxMessageBox(_T("값을 입력해주세요 - RF_DCA2"));
        return; 
    }

    GetDlgItem(IDC_EDIT_RF_DCA3)->GetWindowTextW(sMsg); 
    bInst = sMsg.IsEmpty();
    if(bInst)
    {
        AfxMessageBox(_T("값을 입력해주세요 - RF_DCA3"));
        return; 
    }

    double dTmp;
    U8BIT u8RfDCA, u8RfDCA1, u8RfDCA2, u8RfDCA3;
    uScenario5A uScenario5A;

    m_edit_ROMAddr.GetWindowTextW(sTmp);
    dTmp = _tstof(sTmp);
    u8RfDCA = (U8BIT)(dTmp*2);
    uScenario5A.stScenario5A.ROM_Addr = u8RfDCA;

    m_edit_RfDCA1.GetWindowTextW(sTmp);
    dTmp = _tstof(sTmp);
    u8RfDCA1 = (U8BIT)(dTmp*2);
    m_edit_RfDCA2.GetWindowTextW(sTmp);
    u8RfDCA2 = _tstol(sTmp) * 4;
    m_edit_RfDCA3.GetWindowTextW(sTmp);
    u8RfDCA3 = _tstol(sTmp)*8;

    uScenario5A.stScenario5A.DCA_D15to8 = u8RfDCA3 + (u8RfDCA2 >> 4);
    u8RfDCA2 = u8RfDCA2 + (u8RfDCA1 >> 4);
    uScenario5A.stScenario5A.DCA_D7to0 = ((u8RfDCA2 << 4) | u8RfDCA1 );

    uScenario5A.stScenario5A.Reserved1 = 0x00;
    uScenario5A.stScenario5A.Reserved2 = 0x00;
    uScenario5A.stScenario5A.Reserved3 = 0x00;
    uScenario5A.stScenario5A.Reserved4 = 0x00;
    uScenario5A.stScenario5A.Reserved5 = 0x00;
    uScenario5A.stScenario5A.Reserved6 = 0x00;
    uScenario5A.stScenario5A.Reserved7 = 0x00;
    uScenario5A.stScenario5A.Reserved8 = 0x00;
    // uScenario5A.stScenario5A.CRC8 = 0x00;

    WORD wLen = 0x0009, wOp = RF_CONTROL_OP;
    uCommandType uCommand;

    int nCmdIndex = 0;

    uCommand.wCommand[nCmdIndex++] = htons(wLen);
    uCommand.wCommand[nCmdIndex++] = htons(wOp);
    uCommand.wCommand[nCmdIndex++] = htons(ITEM_5A);
    uCommand.wCommand[nCmdIndex++] = htons(NO_ITEM);
    uCommand.wCommand[nCmdIndex++] = (MAKEWORD(uScenario5A.stScenario5A.ROM_Addr, uScenario5A.stScenario5A.DCA_D15to8 ));
    uCommand.wCommand[nCmdIndex++] = (MAKEWORD(uScenario5A.stScenario5A.DCA_D7to0, uScenario5A.stScenario5A.Reserved1 ));
    uCommand.wCommand[nCmdIndex++] = (MAKEWORD(uScenario5A.stScenario5A.Reserved2, uScenario5A.stScenario5A.Reserved3 ));
    uCommand.wCommand[nCmdIndex++] = (MAKEWORD(uScenario5A.stScenario5A.Reserved4, uScenario5A.stScenario5A.Reserved5 ));
    uCommand.wCommand[nCmdIndex++] = (MAKEWORD(uScenario5A.stScenario5A.Reserved6, uScenario5A.stScenario5A.Reserved7 ));
    uCommand.bCommand[18] = uScenario5A.stScenario5A.Reserved8;
    uCommand.bCommand[19] = RtnCRC8(0x00, uCommand.bCommand, 17);
    nCmdIndex++;

    ((CLSAM_GUIDlg *)GetParent())->SendCommand(uCommand, nCmdIndex*2);
    ((CLSAM_GUIDlg *)GetParent())->prev_uScenario5A.stScenario5A.ROM_Addr = uScenario5A.stScenario5A.ROM_Addr;
    ((CLSAM_GUIDlg *)GetParent())->prev_uScenario5A.stScenario5A.DCA_D15to8 = uScenario5A.stScenario5A.DCA_D15to8;
    ((CLSAM_GUIDlg *)GetParent())->prev_uScenario5A.stScenario5A.DCA_D7to0 = uScenario5A.stScenario5A.DCA_D7to0;
}


BYTE CLSAM_ParamSet::RtnCRC8(unsigned char init_crc, const void* data, int length)
{
    static byte crc_table[256] = {
    0x00, 0x07, 0x0E, 0x09, 0x1C, 0x1B, 0x12, 0x15,
    0x38, 0x3F, 0x36, 0x31, 0x24, 0x23, 0x2A, 0x2D,
    0x70, 0x77, 0x7E, 0x79, 0x6C, 0x6B, 0x62, 0x65,
    0x48, 0x4F, 0x46, 0x41, 0x54, 0x53, 0x5A, 0x5D,
    0xE0, 0xE7, 0xEE, 0xE9, 0xFC, 0xFB, 0xF2, 0xF5,
    0xD8, 0xDF, 0xD6, 0xD1, 0xC4, 0xC3, 0xCA, 0xCD,
    0x90, 0x97, 0x9E, 0x99, 0x8C, 0x8B, 0x82, 0x85,
    0xA8, 0xAF, 0xA6, 0xA1, 0xB4, 0xB3, 0xBA, 0xBD,
    0xC7, 0xC0, 0xC9, 0xCE, 0xDB, 0xDC, 0xD5, 0xD2,
    0xFF, 0xF8, 0xF1, 0xF6, 0xE3, 0xE4, 0xED, 0xEA,
    0xB7, 0xB0, 0xB9, 0xBE, 0xAB, 0xAC, 0xA5, 0xA2,
    0x8F, 0x88, 0x81, 0x86, 0x93, 0x94, 0x9D, 0x9A,
    0x27, 0x20, 0x29, 0x2E, 0x3B, 0x3C, 0x35, 0x32,
    0x1F, 0x18, 0x11, 0x16, 0x03, 0x04, 0x0D, 0x0A,
    0x57, 0x50, 0x59, 0x5E, 0x4B, 0x4C, 0x45, 0x42,
    0x6F, 0x68, 0x61, 0x66, 0x73, 0x74, 0x7D, 0x7A,
    0x89, 0x8E, 0x87, 0x80, 0x95, 0x92, 0x9B, 0x9C,
    0xB1, 0xB6, 0xBF, 0xB8, 0xAD, 0xAA, 0xA3, 0xA4,
    0xF9, 0xFE, 0xF7, 0xF0, 0xE5, 0xE2, 0xEB, 0xEC,
    0xC1, 0xC6, 0xCF, 0xC8, 0xDD, 0xDA, 0xD3, 0xD4,
    0x69, 0x6E, 0x67, 0x60, 0x75, 0x72, 0x7B, 0x7C,
    0x51, 0x56, 0x5F, 0x58, 0x4D, 0x4A, 0x43, 0x44,
    0x19, 0x1E, 0x17, 0x10, 0x05, 0x02, 0x0B, 0x0C,
    0x21, 0x26, 0x2F, 0x28, 0x3D, 0x3A, 0x33, 0x34,
    0x4E, 0x49, 0x40, 0x47, 0x52, 0x55, 0x5C, 0x5B,
    0x76, 0x71, 0x78, 0x7F, 0x6A, 0x6D, 0x64, 0x63,
    0x3E, 0x39, 0x30, 0x37, 0x22, 0x25, 0x2C, 0x2B,
    0x06, 0x01, 0x08, 0x0F, 0x1A, 0x1D, 0x14, 0x13,
    0xAE, 0xA9, 0xA0, 0xA7, 0xB2, 0xB5, 0xBC, 0xBB,
    0x96, 0x91, 0x98, 0x9F, 0x8A, 0x8D, 0x84, 0x83,
    0xDE, 0xD9, 0xD0, 0xD7, 0xC2, 0xC5, 0xCC, 0xCB,
    0xE6, 0xE1, 0xE8, 0xEF, 0xFA, 0xFD, 0xF4, 0xF3
};

    unsigned char crc;
    const unsigned char* buf = (const unsigned char*)data;

    crc = init_crc;
    while (length--) {
        crc = crc_table[crc ^ *buf++];
    }
    return crc;
}


void CLSAM_ParamSet::OnBnClickedBtnStop()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    // ((CLSAM_GUIDlg *)GetParent())->SendRFDCA(0, 50);
    WORD wLen = 0, wOp = 0;
    uCommandType uCommand;


    wLen = 0x0009, wOp = RF_CONTROL_OP;
    int nCmdIndex = 0;

    uCommand.wCommand[nCmdIndex++] = htons(wLen);			//0x0010);
    uCommand.wCommand[nCmdIndex++] = htons(wOp);			//0xAB00);
    uCommand.wCommand[nCmdIndex++] = htons(ITEM_A1);
    uCommand.wCommand[nCmdIndex++] = htons(NO_ITEM);
    uCommand.wCommand[nCmdIndex++] = (MAKEWORD(0x00, 0x00));
    uCommand.wCommand[nCmdIndex++] = (MAKEWORD(0x00, 0x00));
    uCommand.wCommand[nCmdIndex++] = (MAKEWORD(0x00, 0x00));
    uCommand.wCommand[nCmdIndex++] = (MAKEWORD(0x00, 0x00));
    uCommand.wCommand[nCmdIndex++] = (MAKEWORD(0x00, 0x00));
    uCommand.wCommand[nCmdIndex++] = (MAKEWORD(0x00, 0x00));

    ((CLSAM_GUIDlg *)GetParent())->SendCommand(uCommand, nCmdIndex*2);
}


void CLSAM_ParamSet::OnBnClickedBtnA4Stop()
{
    uScenarioA4 uScenarioA4;

    uScenarioA4.stScenarioA4.FreqData3 =  0x00;
    uScenarioA4.stScenarioA4.FreqData2 =  0x00;
    uScenarioA4.stScenarioA4.FreqData1 =  0x00;
    uScenarioA4.stScenarioA4.FreqData0 =  0x00;
    uScenarioA4.stScenarioA4.Start_Stop =  0x01;
    uScenarioA4.stScenarioA4.StartRange =  0x00;
    uScenarioA4.stScenarioA4.StopRange =  0x00;

    if(!(m_chk_TgtInfo.GetCheck()))
    {
        uScenarioA4.stScenarioA4.OffsetPower = 0xff;
    }
    else
    {
        uScenarioA4.stScenarioA4.OffsetPower = 15*2;
    }

    uScenarioA4.stScenarioA4.RF_IN_Path = u8RF_IN;
    uScenarioA4.stScenarioA4.RF_OUT_Path = u8RF_OUT;

    uScenarioA4.stScenarioA4.RF_DCA = 75*2;
    
    uScenarioA4.stScenarioA4.CRC8 = RtnCRC8(0x00, uScenarioA4.arrScenarioA4, 15);

    WORD wLen = 0, wOp = 0;
    uCommandType uCommand;

    wLen = 0x0009, wOp = RF_CONTROL_OP;
    int nCmdIndex = 0;

    uCommand.wCommand[nCmdIndex++] = htons(wLen);			//0x0010);
    uCommand.wCommand[nCmdIndex++] = htons(wOp);			//0xAB00);
    uCommand.wCommand[nCmdIndex++] = htons(ITEM_A4);			//0xAB00);
    uCommand.wCommand[nCmdIndex++] = htons(NO_ITEM);			//0xAB00);
    uCommand.wCommand[nCmdIndex++] = (MAKEWORD(uScenarioA4.stScenarioA4.FreqData3, uScenarioA4.stScenarioA4.FreqData2 ));
    uCommand.wCommand[nCmdIndex++] = (MAKEWORD(uScenarioA4.stScenarioA4.FreqData1, uScenarioA4.stScenarioA4.FreqData0 ));
    uCommand.wCommand[nCmdIndex++] = (MAKEWORD(uScenarioA4.stScenarioA4.OffsetPower, uScenarioA4.stScenarioA4.RF_IN_Path ));
    uCommand.wCommand[nCmdIndex++] = (MAKEWORD(uScenarioA4.stScenarioA4.RF_OUT_Path, uScenarioA4.stScenarioA4.StartRange ));
    uCommand.wCommand[nCmdIndex++] = (MAKEWORD(uScenarioA4.stScenarioA4.StopRange, uScenarioA4.stScenarioA4.RF_DCA ));
    uCommand.bCommand[18] = uScenarioA4.stScenarioA4.Start_Stop;
    uCommand.bCommand[19] = RtnCRC8(0x00, uCommand.bCommand, 19);
    nCmdIndex++;

    ((CLSAM_GUIDlg *)GetParent())->SendCommand(uCommand, nCmdIndex*2);
    ((CLSAM_GUIDlg *)GetParent())->prev_uScenario.stScenario.FreqData3 = uScenarioA4.stScenarioA4.FreqData3;
    ((CLSAM_GUIDlg *)GetParent())->prev_uScenario.stScenario.FreqData2 = uScenarioA4.stScenarioA4.FreqData2;
    ((CLSAM_GUIDlg *)GetParent())->prev_uScenario.stScenario.FreqData1 = uScenarioA4.stScenarioA4.FreqData1;
    ((CLSAM_GUIDlg *)GetParent())->prev_uScenario.stScenario.FreqData0 = uScenarioA4.stScenarioA4.FreqData0;
    ((CLSAM_GUIDlg *)GetParent())->prev_uScenario.stScenario.OffsetPower = uScenarioA4.stScenarioA4.OffsetPower;
    ((CLSAM_GUIDlg *)GetParent())->prev_uScenario.stScenario.RF_IN_Path = uScenarioA4.stScenarioA4.RF_IN_Path;
    ((CLSAM_GUIDlg *)GetParent())->prev_uScenario.stScenario.RF_OUT_Path = uScenarioA4.stScenarioA4.RF_OUT_Path;
    ((CLSAM_GUIDlg *)GetParent())->prev_uScenario.stScenario.StartRange = uScenarioA4.stScenarioA4.StartRange;
    ((CLSAM_GUIDlg *)GetParent())->prev_uScenario.stScenario.StopRange = uScenarioA4.stScenarioA4.StopRange;
    ((CLSAM_GUIDlg *)GetParent())->prev_uScenario.stScenario.RF_DCA = uScenarioA4.stScenarioA4.RF_DCA;
    ((CLSAM_GUIDlg *)GetParent())->prev_uScenario.stScenario.Start_Stop = uScenarioA4.stScenarioA4.Start_Stop;
}


void CLSAM_ParamSet::SetRFGroup(UINT8 u8RFPort)
{
    uCommandType uCommand;
    int nCmdIndex = 0;

    uCommand.wCommand[nCmdIndex++] = htons(0x0003);
        uCommand.wCommand[nCmdIndex++] = htons(0x0003);
        uCommand.wCommand[nCmdIndex++] = htons(0x00C2);

        m_btn_RfOut1.SetCheck(FALSE);
        m_btn_RfOut2.SetCheck(FALSE);
        m_btn_RfOut3.SetCheck(FALSE);
        m_btn_RfOut4.SetCheck(FALSE);
        m_btn_RfOut5.SetCheck(FALSE);
        m_btn_RfOut6.SetCheck(FALSE);
        m_btn_RfOut7.SetCheck(FALSE);
        m_btn_RfOut8.SetCheck(FALSE);

    if(u8RFPort <= 4)
    {
        uCommand.wCommand[nCmdIndex++] = htons(0x0000);
        GetDlgItem(IDC_RADIO_RF_OUT1)->EnableWindow(TRUE);
    GetDlgItem(IDC_RADIO_RF_OUT2)->EnableWindow(TRUE);
    GetDlgItem(IDC_RADIO_RF_OUT3)->EnableWindow(TRUE);
    GetDlgItem(IDC_RADIO_RF_OUT4)->EnableWindow(TRUE);
        GetDlgItem(IDC_RADIO_RF_OUT5)->EnableWindow(FALSE);
    GetDlgItem(IDC_RADIO_RF_OUT6)->EnableWindow(FALSE);
    GetDlgItem(IDC_RADIO_RF_OUT7)->EnableWindow(FALSE);
    GetDlgItem(IDC_RADIO_RF_OUT8)->EnableWindow(FALSE);
    }
    else
    {
        uCommand.wCommand[nCmdIndex++] = htons(0x0001);
        GetDlgItem(IDC_RADIO_RF_OUT1)->EnableWindow(FALSE);
    GetDlgItem(IDC_RADIO_RF_OUT2)->EnableWindow(FALSE);
    GetDlgItem(IDC_RADIO_RF_OUT3)->EnableWindow(FALSE);
    GetDlgItem(IDC_RADIO_RF_OUT4)->EnableWindow(FALSE);
    GetDlgItem(IDC_RADIO_RF_OUT5)->EnableWindow(TRUE);
    GetDlgItem(IDC_RADIO_RF_OUT6)->EnableWindow(TRUE);
    GetDlgItem(IDC_RADIO_RF_OUT7)->EnableWindow(TRUE);
    GetDlgItem(IDC_RADIO_RF_OUT8)->EnableWindow(TRUE);
    }
    ((CLSAM_GUIDlg *)GetParent())->SendCommand(uCommand, nCmdIndex*2);
}
