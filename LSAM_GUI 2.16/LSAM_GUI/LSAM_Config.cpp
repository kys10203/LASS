// LSAM_Config.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "LSAM_GUI.h"
#include "LSAM_Config.h"
#include "afxdialogex.h"
#include "LSAM_GUIDlg.h"

//변수 선언
extern int g_nRemotePort;
extern CIPAddressCtrl g_RemoteIP;
extern CString g_strRemoteIP;
extern BYTE g_IP_a, g_IP_b, g_IP_c, g_IP_d;
extern BOOL g_bSocketOpen;

// CLSAM_Config 대화 상자입니다.

IMPLEMENT_DYNAMIC(CLSAM_Config, CDialogEx)

    CLSAM_Config::CLSAM_Config(CWnd* pParent /*=NULL*/)
    : CDialogEx(CLSAM_Config::IDD, pParent)
{

    EnableAutomation();

}

CLSAM_Config::~CLSAM_Config()
{
}

void CLSAM_Config::OnFinalRelease()
{
    // 자동화 개체에 대한 마지막 참조가 해제되면
    // OnFinalRelease가 호출됩니다. 기본 클래스에서 자동으로 개체를 삭제합니다.
    // 기본 클래스를 호출하기 전에 개체에 필요한 추가 정리 작업을
    // 추가하십시오.

    CDialogEx::OnFinalRelease();
}

void CLSAM_Config::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_REMOTE_IP, m_RemoteIp);
    DDX_Control(pDX, IDC_EDIT_REMOTE_PORT, m_edit_RemotePort);
}


BEGIN_MESSAGE_MAP(CLSAM_Config, CDialogEx)
    ON_BN_CLICKED(IDC_BTN_OPEN, &CLSAM_Config::OnBnClickedBtnOpen)
    ON_WM_CLOSE()
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CLSAM_Config, CDialogEx)
END_DISPATCH_MAP()

// 참고: IID_ILSAM_Config에 대한 지원을 추가하여
//  VBA에서 형식 안전 바인딩을 지원합니다. 
//  이 IID는 .IDL 파일에 있는 dispinterface의 GUID와 일치해야 합니다.

// {A66129B0-442B-4E4D-B974-0D81FE968A3E}
static const IID IID_ILSAM_Config =
{ 0xA66129B0, 0x442B, 0x4E4D, { 0xB9, 0x74, 0xD, 0x81, 0xFE, 0x96, 0x8A, 0x3E } };

BEGIN_INTERFACE_MAP(CLSAM_Config, CDialogEx)
    INTERFACE_PART(CLSAM_Config, IID_ILSAM_Config, Dispatch)
END_INTERFACE_MAP()


// CLSAM_Config 메시지 처리기입니다.

BOOL CLSAM_Config::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    if(g_bSocketOpen) {
        GetDlgItem(IDC_BTN_OPEN)->SetWindowText(_T("연결 해제"));
        GetDlgItem(IDC_REMOTE_IP)->EnableWindow(FALSE);
        GetDlgItem(IDC_EDIT_REMOTE_PORT)->EnableWindow(FALSE);
    }
    else
    {
        GetDlgItem(IDC_BTN_OPEN)->SetWindowText(_T("연결"));
        GetDlgItem(IDC_REMOTE_IP)->EnableWindow(TRUE);
        GetDlgItem(IDC_EDIT_REMOTE_PORT)->EnableWindow(TRUE);
    }

    m_RemoteIp.SetAddress(g_IP_a, g_IP_b, g_IP_c, g_IP_d);
    SetDlgItemInt(IDC_EDIT_REMOTE_PORT, g_nRemotePort);

    return TRUE;  // return TRUE unless you set the focus to a control
}


void CLSAM_Config::OnBnClickedBtnOpen()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

    if (g_bSocketOpen)
    {
        theApp.GetMainWnd()->SendMessage(WM_DLG_MENU, eDlgMenuConnect, 0);
        GetDlgItem(IDC_BTN_OPEN)->SetWindowText(_T("연결"));
        GetDlgItem(IDC_REMOTE_IP)->EnableWindow(TRUE);
        GetDlgItem(IDC_EDIT_REMOTE_PORT)->EnableWindow(TRUE);
    }
    else
    {
        UpdateData(TRUE);

        g_nRemotePort = GetDlgItemInt(IDC_EDIT_REMOTE_PORT);

        m_RemoteIp.GetAddress(g_IP_a, g_IP_b, g_IP_c, g_IP_d);
        g_strRemoteIP.Format(_T("%d.%d.%d.%d"), g_IP_a, g_IP_b, g_IP_c, g_IP_d);
        // AfxMessageBox(g_strRemoteIP);

        theApp.WriteProfileInt(_T("LSAM_Tester System Config"), _T("RemotePort"), g_nRemotePort);
        theApp.WriteProfileInt(_T("LSAM_Tester System Config"), _T("RemoteIP_a"), g_IP_a);
        theApp.WriteProfileInt(_T("LSAM_Tester System Config"), _T("RemoteIP_b"), g_IP_b);
        theApp.WriteProfileInt(_T("LSAM_Tester System Config"), _T("RemoteIP_c"), g_IP_c);
        theApp.WriteProfileInt(_T("LSAM_Tester System Config"), _T("RemoteIP_d"), g_IP_d);

        theApp.GetMainWnd()->SendMessage(WM_DLG_MENU, eDlgMenuConnect, 0);
        GetDlgItem(IDC_BTN_OPEN)->SetWindowText(_T("연결 해제"));
        GetDlgItem(IDC_REMOTE_IP)->EnableWindow(FALSE);
        GetDlgItem(IDC_EDIT_REMOTE_PORT)->EnableWindow(FALSE);
    }
}


void CLSAM_Config::OnClose()
{
    // TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
    CDialogEx::OnClose();
}
