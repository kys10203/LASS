
// LSAM_GUIDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "LSAM_GUI.h"
#include "LSAM_GUIDlg.h"
#include "DlgProxy.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// ��� IP/Port ����
int g_nRemotePort;
CIPAddressCtrl g_RemoteIP;
CString g_strRemoteIP;
BYTE g_IP_a, g_IP_b, g_IP_c, g_IP_d;

//��� ���¸� ǥ��
BOOL g_bSocketOpen;

// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
    CAboutDlg();

    // ��ȭ ���� �������Դϴ�.
    enum { IDD = IDD_ABOUTBOX };

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

    // �����Դϴ�.
protected:
    DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CLSAM_GUIDlg ��ȭ ����


IMPLEMENT_DYNAMIC(CLSAM_GUIDlg, CDialogEx);

CLSAM_GUIDlg::CLSAM_GUIDlg(CWnd* pParent /*=NULL*/)
    : CDialogEx(CLSAM_GUIDlg::IDD, pParent)
    , pApp(NULL)
    , m_str_SendFuzMsg(_T(""))
    , m_str_SendRfMsg(_T(""))
    , m_bTddPower(FALSE)
    , m_bRfPower(FALSE)
    , m_bRxDisplay(TRUE)
    , m_bLogSave(FALSE)
    , b_WIRE(0)
    , f_bParamSet(FALSE)
    , f_bLooopback(FALSE)
    , m_u16LogCount(0)
{
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
    m_pAutoProxy = NULL;
    pApp = AfxGetApp();
}

CLSAM_GUIDlg::~CLSAM_GUIDlg()
{
    // �� ��ȭ ���ڿ� ���� �ڵ�ȭ ���Ͻð� ���� ��� �� ��ȭ ���ڿ� ����
    //  �Ĺ� �����͸� NULL�� �����Ͽ�
    //  ��ȭ ���ڰ� �����Ǿ����� �� �� �ְ� �մϴ�.
    if (m_pAutoProxy != NULL)
        m_pAutoProxy->m_pDialog = NULL;
}

void CLSAM_GUIDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_BTN_CONNECT, m_btn_Connect);
    DDX_Control(pDX, IDC_BTN_CONFIG, m_btn_Config);
    DDX_Control(pDX, IDC_BTN_EXIT, m_btn_Exit);
    DDX_Control(pDX, IDC_RICHEDIT_LOG, m_edit_Log);
    DDX_Control(pDX, IDC_EDIT_SEND_FUZ_MSG, m_edit_SendFuzMsg);
    DDX_Control(pDX, IDC_EDIT_SEND_RF_MSG, m_edit_SendRfMsg);
    DDX_Text(pDX, IDC_EDIT_SEND_FUZ_MSG, m_str_SendFuzMsg);
    DDX_Text(pDX, IDC_EDIT_SEND_RF_MSG, m_str_SendRfMsg);
    DDX_Control(pDX, IDC_CMB_POWER_TDD, m_cmb_PowerTdd);
    DDX_Control(pDX, IDC_CMB_POWER_RF, m_cmb_PowerRf);
    DDX_Control(pDX, IDC_BTN_TDD_ONOFF, m_btn_TddOnOff);
    DDX_Control(pDX, IDC_BTN_RF_ONOFF, m_btn_RfOnOff);
    DDX_Control(pDX, IDC_BTN_LOOPBACK, m_btn_Loopback);
    DDX_Control(pDX, IDC_BTN_RX_DISPLAY, m_btn_RxDisplay);
    DDX_Control(pDX, IDC_BTN_LOG_SAVE, m_btn_LogSave);
    DDX_Control(pDX, IDC_BTN_PARAM_SET, m_btn_ParamSet);
}

BEGIN_MESSAGE_MAP(CLSAM_GUIDlg, CDialogEx)
    ON_WM_SYSCOMMAND()
    ON_WM_CLOSE()
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_BTN_CONNECT, &CLSAM_GUIDlg::OnBnClickedBtnConnect)
    ON_BN_CLICKED(IDC_BTN_CONFIG, &CLSAM_GUIDlg::OnBnClickedBtnConfig)
    ON_BN_CLICKED(IDC_BTN_EXIT, &CLSAM_GUIDlg::OnBnClickedBtnExit)
    ON_MESSAGE(WM_DLG_MENU, &CLSAM_GUIDlg::OnDlgMenu)
    ON_MESSAGE(WM_CONNECT_EVENT, &CLSAM_GUIDlg::OnConnectEvent)
    ON_MESSAGE(WM_RECEIVE_EVENT, &CLSAM_GUIDlg::OnReceiveEvent)
    ON_BN_CLICKED(IDC_BTN_LOG_CLEAR, &CLSAM_GUIDlg::OnBnClickedBtnLogClear)
    ON_BN_CLICKED(IDC_BTN_FUZE_CLEAR, &CLSAM_GUIDlg::OnBnClickedBtnFuzeClear)
    ON_BN_CLICKED(IDC_BTN_RF_CLEAR, &CLSAM_GUIDlg::OnBnClickedBtnRfClear)
    ON_BN_CLICKED(IDC_BTN_FUZE_SEND, &CLSAM_GUIDlg::OnBnClickedBtnFuzeSend)
    ON_BN_CLICKED(IDC_BTN_RF_SEND, &CLSAM_GUIDlg::OnBnClickedBtnRfSend)
    ON_CBN_SELCHANGE(IDC_CMB_POWER_TDD, &CLSAM_GUIDlg::OnCbnSelchangeCmbPowerTdd)
    ON_BN_CLICKED(IDC_BTN_TDD_ONOFF, &CLSAM_GUIDlg::OnBnClickedBtnTddOnoff)
    ON_BN_CLICKED(IDC_BTN_RF_ONOFF, &CLSAM_GUIDlg::OnBnClickedBtnRfOnoff)
    ON_BN_CLICKED(IDC_BTN_LOOPBACK, &CLSAM_GUIDlg::OnBnClickedBtnLoopback)
    ON_BN_CLICKED(IDC_BTN_RX_DISPLAY, &CLSAM_GUIDlg::OnBnClickedBtnRxDisplay)
    ON_BN_CLICKED(IDC_BTN_LOG_SAVE, &CLSAM_GUIDlg::OnBnClickedBtnLogSave)
    ON_BN_CLICKED(IDC_BTN_PARAM_SET, &CLSAM_GUIDlg::OnBnClickedBtnParamSet)
    ON_BN_CLICKED(IDC_BTN_BIT, &CLSAM_GUIDlg::OnBnClickedBtnBit)
END_MESSAGE_MAP()


// CLSAM_GUIDlg �޽��� ó����

BOOL CLSAM_GUIDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
    //  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
    SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
    SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

    // TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
    m_btn_Connect.SetIcon( AfxGetApp() -> LoadIcon( IDI_ICON_CONNECT ) );
    m_btn_Config.SetIcon( AfxGetApp() -> LoadIcon( IDI_ICON_ETHRNT ) );
    m_btn_Exit.SetIcon( AfxGetApp() -> LoadIcon( IDI_ICON_EXIT ) );
    m_btn_ParamSet.SetIcon( AfxGetApp() -> LoadIcon( IDI_ICON_CONFIG ) );

    LoadParam();
    m_cmb_PowerTdd.SetCurSel(8);
    m_cmb_PowerRf.SetCurSel(0);
    // AfxMessageBox(g_strRemoteIP);
    prev_uScenario.arrScenario[0] = 0;
    prev_uScenario.arrScenario[1] = 0;
    prev_uScenario.arrScenario[2] = 0;
    prev_uScenario.arrScenario[3] = 0;
    prev_uScenario.arrScenario[4] = 0;
    prev_uScenario.arrScenario[5] = 0;
    prev_uScenario.arrScenario[6] = 0;
    prev_uScenario.arrScenario[7] = 0;
    prev_uScenario.arrScenario[8] = 0;
    prev_uScenario.arrScenario[9] = 0;
    prev_uScenario.arrScenario[10] = 0;
    prev_uScenario.arrScenario[11] = 0;
    prev_uScenario.arrScenario[12] = 0;

    prev_uScenarioA2.arrScenarioA2[0] = 0;
    prev_uScenarioA2.arrScenarioA2[1] = 0;
    prev_uScenarioA2.arrScenarioA2[2] = 0;
    prev_uScenarioA2.arrScenarioA2[3] = 0;
    prev_uScenarioA2.arrScenarioA2[4] = 0;
    prev_uScenarioA2.arrScenarioA2[5] = 0;
    prev_uScenarioA2.arrScenarioA2[6] = 0;
    prev_uScenarioA2.arrScenarioA2[7] = 0;
    prev_uScenarioA2.arrScenarioA2[8] = 0;
    prev_uScenarioA2.arrScenarioA2[9] = 0;
    prev_uScenarioA2.arrScenarioA2[10] = 0;
    prev_uScenarioA2.arrScenarioA2[11] = 0;
    prev_uScenarioA2.arrScenarioA2[12] = 0;
    prev_uScenarioA2.arrScenarioA2[13] = 0;
    prev_uScenarioA2.arrScenarioA2[14] = 0;
    prev_uScenarioA2.arrScenarioA2[15] = 0;

    prev_uScenarioA4.arrScenarioA4[0] = 0;
    prev_uScenarioA4.arrScenarioA4[1] = 0;
    prev_uScenarioA4.arrScenarioA4[2] = 0;
    prev_uScenarioA4.arrScenarioA4[3] = 0;
    prev_uScenarioA4.arrScenarioA4[4] = 0;
    prev_uScenarioA4.arrScenarioA4[5] = 0;
    prev_uScenarioA4.arrScenarioA4[6] = 0;
    prev_uScenarioA4.arrScenarioA4[7] = 0;
    prev_uScenarioA4.arrScenarioA4[8] = 0;
    prev_uScenarioA4.arrScenarioA4[9] = 0;
    prev_uScenarioA4.arrScenarioA4[10] = 0;
    prev_uScenarioA4.arrScenarioA4[11] = 0;
    prev_uScenarioA4.arrScenarioA4[12] = 0;
    prev_uScenarioA4.arrScenarioA4[13] = 0;
    prev_uScenarioA4.arrScenarioA4[14] = 0;
    prev_uScenarioA4.arrScenarioA4[15] = 0;

    prev_uScenario5A.arrScenario5A[0] = 0;
    prev_uScenario5A.arrScenario5A[1] = 0;
    prev_uScenario5A.arrScenario5A[2] = 0;
    prev_uScenario5A.arrScenario5A[3] = 0;
    prev_uScenario5A.arrScenario5A[4] = 0;
    prev_uScenario5A.arrScenario5A[5] = 0;
    prev_uScenario5A.arrScenario5A[6] = 0;
    prev_uScenario5A.arrScenario5A[7] = 0;
    prev_uScenario5A.arrScenario5A[8] = 0;
    prev_uScenario5A.arrScenario5A[9] = 0;
    prev_uScenario5A.arrScenario5A[10] = 0;
    prev_uScenario5A.arrScenario5A[11] = 0;
    prev_uScenario5A.arrScenario5A[12] = 0;
    prev_uScenario5A.arrScenario5A[13] = 0;
    prev_uScenario5A.arrScenario5A[14] = 0;
    prev_uScenario5A.arrScenario5A[15] = 0;

    return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CLSAM_GUIDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
    if ((nID & 0xFFF0) == IDM_ABOUTBOX)
    {
        CAboutDlg dlgAbout;
        dlgAbout.DoModal();
    }
    else
    {
        CDialogEx::OnSysCommand(nID, lParam);
    }
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CLSAM_GUIDlg::OnPaint()
{
    if (IsIconic())
    {
        CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

        SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

        // Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
        int cxIcon = GetSystemMetrics(SM_CXICON);
        int cyIcon = GetSystemMetrics(SM_CYICON);
        CRect rect;
        GetClientRect(&rect);
        int x = (rect.Width() - cxIcon + 1) / 2;
        int y = (rect.Height() - cyIcon + 1) / 2;

        // �������� �׸��ϴ�.
        dc.DrawIcon(x, y, m_hIcon);
    }
    else
    {
        CDialogEx::OnPaint();
    }
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CLSAM_GUIDlg::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(m_hIcon);
}

// ��Ʈ�ѷ����� �ش� ��ü �� �ϳ��� ��� ����ϰ� ���� ���
//  ����ڰ� UI�� ���� �� �ڵ�ȭ ������ �����ϸ� �� �˴ϴ�. �̵�
//  �޽��� ó����� ���Ͻð� ���� ��� ���� ��� UI�� ��������,
//  UI�� ǥ�õ��� �ʾƵ� ��ȭ ���ڴ�
//  ���� �Ӵϴ�.

void CLSAM_GUIDlg::OnClose()
{
    if (CanExit())
        CDialogEx::OnClose();
}

void CLSAM_GUIDlg::OnOK()
{
    if (CanExit())
        CDialogEx::OnOK();
}

void CLSAM_GUIDlg::OnCancel()
{
    closesocket(m_hSocket);
    m_hSocket = INVALID_SOCKET;

    if (CanExit())
        CDialogEx::OnCancel();
}

BOOL CLSAM_GUIDlg::CanExit()
{
    // ���Ͻ� ��ü�� ��� ���� ������ �ڵ�ȭ ��Ʈ�ѷ�������
    //  �� ���� ���α׷��� ��� ����մϴ�. ��ȭ ���ڴ� ���� ������
    //  �ش� UI�� ����ϴ�.
    if (m_pAutoProxy != NULL)
    {
        ShowWindow(SW_HIDE);
        return FALSE;
    }

    return TRUE;
}



void CLSAM_GUIDlg::OnBnClickedBtnConnect()
{
    // TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
    theApp.GetMainWnd()->SendMessage(WM_DLG_MENU, eDlgMenuConnect);
}


void CLSAM_GUIDlg::OnBnClickedBtnConfig()
{
    // TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
    theApp.GetMainWnd()->SendMessage(WM_DLG_MENU, eDlgMenuConfig);
}


void CLSAM_GUIDlg::OnBnClickedBtnExit()
{
    // TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
    theApp.GetMainWnd()->SendMessage(WM_DLG_MENU, eDlgMenuExit);
}


afx_msg LRESULT CLSAM_GUIDlg::OnDlgMenu(WPARAM wParam, LPARAM lParam)
{
    switch(wParam)
    {
    case eDlgMenuConnect:
        TCP_CONNECT();

        break;
    case eDlgMenuConfig:
        {
            CLSAM_Config* pLSAM_Config = (CLSAM_Config*) new CLSAM_Config;
            pLSAM_Config->DoModal();
            delete pLSAM_Config;

            //delete pLSAM_Config;
            //if(pLSAM_Config->GetSafeHwnd() == NULL)
            //{
            //    pLSAM_Config = new CLSAM_Config;
            //    pLSAM_Config->Create(IDD_LSAM_CONFIG);
            //    pLSAM_Config->CenterWindow();
            //    pLSAM_Config->ShowWindow(SW_SHOW);
            //}
            //else
            //    pLSAM_Config->SetActiveWindow();

            break;
        }
    case eDlgMenuExit:
        closesocket(m_hSocket);
        m_hSocket = INVALID_SOCKET;
        SendMessage(WM_CLOSE, 0, 0);

        break;
    }
    return 0;
}


int CLSAM_GUIDlg::TCP_CONNECT(void)
{
    if(g_bSocketOpen == TRUE)    // ���� ���̶�� ������ ����
    {
        AddEventString(_T("> ������ ������ �����մϴ�."));
        m_btn_Connect.SetWindowTextW(L"����");

        closesocket(m_hSocket);
        m_hSocket = INVALID_SOCKET;

        g_bSocketOpen = FALSE;
        f_bLooopback = FALSE;
        return -1;
    }

    m_hSocket = socket( AF_INET, SOCK_STREAM, 0 );  //���� ����

    memset( &srv_addr, 0, sizeof( struct sockaddr_in ) );
    srv_addr.sin_family = AF_INET;
    srv_addr.sin_addr.s_addr = inet_addr( (CStringA)g_strRemoteIP );
    srv_addr.sin_port = htons( g_nRemotePort );

    // m_hSocket ���Ͽ� FD_CONNECT��� �̺�Ʈ�� �߻��ϸ� m_hWnd ���̾�α׿� WM_CONNECT_EVENT �޽��� ���� ��û
    WSAAsyncSelect( m_hSocket, m_hWnd, WM_CONNECT_EVENT, FD_CONNECT );

    g_bSocketOpen = TRUE;

    AddEventString(_T("> ������ ������ �õ��մϴ�."));

    connect(m_hSocket, (LPSOCKADDR)&srv_addr, sizeof(srv_addr));

    return 0;
}


void CLSAM_GUIDlg::AddEventString(wchar_t* ap_string)
{
    CString str = (LPCTSTR)ap_string;
    //   CHARFORMAT2W cf;

    //m_edit_Log.GetSelectionCharFormat(cf);

    //cf.cbSize		= sizeof(CHARFORMAT);
    //cf.dwMask		= CFM_COLOR | CFM_UNDERLINE | CFM_BOLD | CFM_SIZE | CFM_BACKCOLOR | CFM_CHARSET | CFM_FACE;
    //cf.dwEffects	= 0;	//	cf.dwEffects	= CFE_BOLD;	

    //cf.crTextColor	= RGB(000, 000, 000);
    //cf.crBackColor	= WHITE;
    //cf.yHeight = 160;
    //wcscpy_s(cf.szFaceName, _T("MS Shell Dlg"));

    //   m_edit_Log.SetSelectionCharFormat(cf);
    m_edit_Log.SetSel(-1, -1);

    int len = m_edit_Log.GetWindowTextLengthW();

    str += _T("\r\n");

    m_edit_Log.SetSel(len, len);
    m_edit_Log.ReplaceSel(str);

    AutoScroll();
}

void CLSAM_GUIDlg::AddEventString(CString str)
{
    m_edit_Log.SetSel(-1, -1);

    int len = m_edit_Log.GetWindowTextLengthW();

    str += _T("\r\n");

    m_edit_Log.SetSel(len, len);
    m_edit_Log.ReplaceSel(str);

    AutoScroll();
}


BOOL CLSAM_GUIDlg::PreTranslateMessage(MSG* pMsg)
{
    // TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
    if(pMsg->message == WM_KEYDOWN)
    {
        if(pMsg->wParam == VK_ESCAPE)
            return TRUE;
        else if(pMsg->wParam == VK_RETURN)
            return TRUE;
    }

    return CDialogEx::PreTranslateMessage(pMsg);
}


afx_msg LRESULT CLSAM_GUIDlg::OnConnectEvent(WPARAM wParam, LPARAM lParam)
{
    if (WSAGETSELECTERROR(lParam))  // if���� ������ ���� ����
    {
        g_bSocketOpen = FALSE;
        f_bLooopback = FALSE;
        closesocket(m_hSocket);
        m_hSocket = INVALID_SOCKET;

        AfxMessageBox(_T("> ���� ���� ����."));

        m_btn_Connect.SetWindowTextW(L"����");


    }
    else   // ���� ����
    {
        g_bSocketOpen = TRUE;
        AddEventString(_T("> ������ �����߽��ϴ�."));

        BOOL optval = TRUE;
        if(setsockopt(m_hSocket, IPPROTO_TCP,  TCP_NODELAY, (char*)&optval, sizeof(optval)))
        {
            AddEventString(_T("> NODELAY ���� ����."));
        }
        else
        {
            AddEventString(_T("> NODELAY ���� ����."));
        }

        WSAAsyncSelect(m_hSocket, m_hWnd, WM_RECEIVE_EVENT, FD_READ | FD_CLOSE);

        m_btn_Connect.SetWindowTextW(L"���� ����");
    }

    return 0;
}


afx_msg LRESULT CLSAM_GUIDlg::OnReceiveEvent(WPARAM wParam, LPARAM lParam)
{
    CString str;
    int n_Length = 0;
    BYTE buffer[MESSAGE_SIZE_MAX] = {0, };

    if (WSAGETSELECTEVENT(lParam) == FD_READ)
    {
        WSAAsyncSelect(wParam, m_hWnd, WM_RECEIVE_EVENT, FD_CLOSE);

        n_Length = recv(wParam, (char*)buffer, MESSAGE_SIZE_MAX, 0);

        ParseMsg(buffer, n_Length);
        //::GetLocalTime(&systime);
        //str.Format(L"[%02d:%02d:%02d:%03d RX] %02X %02X %02X %02X %02X %02X %02X\r\n"
        //    , systime.wHour, systime.wMinute, systime.wSecond, systime.wMilliseconds,buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6]);
        //n_Length = m_edit_Log.GetWindowTextLengthW();
        //m_edit_Log.SetSel(n_Length, n_Length);
        //m_edit_Log.ReplaceSel(str);
    }
    else
    {//FD_CLOSE
        closesocket(m_hSocket);//Ŭ���̾�Ʈ ���� Ŭ����

        m_hSocket = INVALID_SOCKET;
        g_bSocketOpen = 0;//���� ���� flag ����
        f_bLooopback = FALSE;

        AddEventString(_T("> ������ ������ ���� �߽��ϴ�."));
        m_btn_Connect.SetWindowTextW(L"����");
    }

    WSAAsyncSelect(wParam, m_hWnd, WM_RECEIVE_EVENT, FD_READ | FD_CLOSE);

    return 0;
}


void CLSAM_GUIDlg::LoadParam(void)
{
    // ��ż��� ����
    g_nRemotePort	= theApp.GetProfileInt(_T("LSAM_Tester System Config"), _T("RemotePort"), 5000);
    g_IP_a			= 0xff & (BYTE)theApp.GetProfileInt(_T("LSAM_Tester System Config"), _T("RemoteIP_a"), 192);
    g_IP_b			= 0xff & (BYTE)theApp.GetProfileInt(_T("LSAM_Tester System Config"), _T("RemoteIP_b"), 168);
    g_IP_c			= 0xff & (BYTE)theApp.GetProfileInt(_T("LSAM_Tester System Config"), _T("RemoteIP_c"), 0);
    g_IP_d			= 0xff & (BYTE)theApp.GetProfileInt(_T("LSAM_Tester System Config"), _T("RemoteIP_d"), 146);
    g_strRemoteIP.Format(_T("%d.%d.%d.%d"), g_IP_a, g_IP_b, g_IP_c, g_IP_d);

    // ���α׷� ������ ����
    TCHAR chPath[MAX_PATH];
    GetCurrentDirectory(MAX_PATH, chPath);
    m_strMainPath.Format(_T("%s"), chPath);
    //AfxMessageBox(m_strMainPath);
}


void CLSAM_GUIDlg::OnBnClickedBtnLogClear()
{
    // TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
    m_edit_Log.SetSel(0, m_edit_Log.GetWindowTextLength());
    m_edit_Log.ReplaceSel(_T(""), false);
}


void CLSAM_GUIDlg::OnBnClickedBtnFuzeClear()
{
    // TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
    m_str_SendFuzMsg.Empty();
    UpdateData(FALSE);
}


void CLSAM_GUIDlg::OnBnClickedBtnRfClear()
{
    // TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
    m_str_SendRfMsg.Empty();
    UpdateData(FALSE);
}


void CLSAM_GUIDlg::ParseMsg(BYTE* buffer, int MsgSize)
{
    SYSTEMTIME systime;
    CString str_systime;

    CString strMsg;
    CString strMsg2;
    CString strMsg3;
    CString strMsg4;
    CString strMsg5;
    CString strMsg6;
    CString strMsg7;
    CString strMsg8;
    CString strResult;

    CString strVal1;
    CString strVal2;
    CString strVal3;
    CString strVal4;
    CString strVal5;
    CString strVal6;
    CString strVal7;
    CString strVal8;

    int i = 0;
    int Result_MsgSize = (MsgSize-2)/8;

    bool bSplit;
    if(MsgSize % 2)
    {
        bSplit = true;
    }
    else
    {
        bSplit = false;
    }

    ::GetLocalTime(&systime);
    str_systime.Format(_T("[%02d:%02d:%02d:%03d RX] "), systime.wHour, systime.wMinute, systime.wSecond, systime.wMilliseconds);

    // if((buffer[3] == 0x11) | (buffer[1] == 0x03) | (buffer[1] == 0x04))
    {
        for(i = 2; i < (Result_MsgSize+2); i += 2) {
            if(bSplit && (i == Result_MsgSize) + 1)
            {
                strVal1.Format(_T("%02X "), buffer[i]);
            }
            else
                strVal1.Format(_T("%02X%02X "), buffer[i], buffer[i+1]);

            strMsg += strVal1;
        }
        strMsg = str_systime + strMsg;

        for(; i < ((Result_MsgSize*2)+2); i += 2) {
            if(bSplit && (i == (Result_MsgSize*2) + 1))
                strVal2.Format(_T("%02X "), buffer[i]);
            else
                strVal2.Format(_T("%02X%02X "), buffer[i], buffer[i+1]);

            strMsg2 += strVal2;
        }
        strMsg2 = str_systime + strMsg2;

        for(; i < ((Result_MsgSize*3)+2); i += 2) {
            if(bSplit && (i == (Result_MsgSize*3) + 1))
                strVal3.Format(_T("%02X "), buffer[i]);
            else
                strVal3.Format(_T("%02X%02X "), buffer[i], buffer[i+1]);

            strMsg3 += strVal3;
        }
        strMsg3 = str_systime + strMsg3;

        for(; i < ((Result_MsgSize*4)+2); i += 2) {
            if(bSplit && (i ==(Result_MsgSize*4) + 1))
                strVal4.Format(_T("%02X "), buffer[i]);
            else
                strVal4.Format(_T("%02X%02X "), buffer[i], buffer[i+1]);

            strMsg4 += strVal4;
        }
        strMsg4 = str_systime + strMsg4;

        for(; i < ((Result_MsgSize*5)+2); i += 2) {
            if(bSplit && (i ==(Result_MsgSize*5) + 1))
            {
                strVal5.Format(_T("%02X "), buffer[i]);
            }
            else
                strVal5.Format(_T("%02X%02X "), buffer[i], buffer[i+1]);

            strMsg5 += strVal5;
        }
        strMsg5 = str_systime + strMsg5;

        for(; i < ((Result_MsgSize*6)+2); i += 2) {
            if(bSplit && (i ==(Result_MsgSize*6) + 1))
                strVal6.Format(_T("%02X "), buffer[i]);
            else
                strVal6.Format(_T("%02X%02X "), buffer[i], buffer[i+1]);

            strMsg6 += strVal6;
        }
        strMsg6 = str_systime + strMsg6;

        for(; i < ((Result_MsgSize*7)+2); i += 2) {
            if(bSplit && (i ==(Result_MsgSize*7) + 1))
                strVal7.Format(_T("%02X "), buffer[i]);
            else
                strVal7.Format(_T("%02X%02X "), buffer[i], buffer[i+1]);

            strMsg7 += strVal7;
        }
        strMsg7 = str_systime + strMsg7;

        for(; i < (MsgSize); i += 2) {
            if(bSplit && (i ==(MsgSize) - 1))
                strVal8.Format(_T("%02X "), buffer[i]);
            else
                strVal8.Format(_T("%02X%02X "), buffer[i], buffer[i+1]);

            strMsg8 += strVal8;
        }
        strMsg8 = str_systime + strMsg8;

        strResult = strMsg + strVal2 + strVal3 + strVal4 + strVal5 + strVal6 + strVal7 + strVal8;

        if(m_bRxDisplay)
        {
            if((m_u16LogCount++)%4 == 0)
            {
                AddEventString(strMsg);
                AddEventString(strMsg2);
                AddEventString(strMsg3);
                AddEventString(strMsg4);
                AddEventString(strMsg5);
                AddEventString(strMsg6);
                AddEventString(strMsg7);
                AddEventString(strMsg8);
            }
        }


        if(m_bLogSave)
        {
            CStringA strResult;
            strResult = strMsg + _T("\r\n") + strMsg2 + _T("\r\n") + strMsg3 + _T("\r\n") + strMsg4 + _T("\r\n") + strMsg5 + _T("\r\n") + strMsg6 + _T("\r\n") + strMsg7 + _T("\r\n") + strMsg8 + _T("\r\n");
            // strResult = strMsg + strVal2 + strVal3 + strVal4 + strVal5 + strVal6 + strVal7 + strVal8 + _T("\r\n");

            char* cBufResult = strResult.GetBuffer();
            int nLenResult = strResult.GetLength();

            m_file.Write(cBufResult, (unsigned int)nLenResult);
        }
    }
}


void CLSAM_GUIDlg::AutoScroll(void)
{
    if(512 <m_u16LogCount)
    {
        OnBnClickedBtnLogClear();
        m_u16LogCount = 0;
    }

    int nDoLineScroll = m_edit_Log.GetLineCount() - 16 - m_edit_Log.GetFirstVisibleLine();	// 18 : �������� Line �� ����

    if (nDoLineScroll > 0)
        m_edit_Log.LineScroll(nDoLineScroll);
}


void CLSAM_GUIDlg::OnBnClickedBtnFuzeSend()
{
    // TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
    CString strSend = _T("");
    BYTE ucSendBuff[MESSAGE_SIZE_MAX];
    BYTE ucTempBuff[MESSAGE_SIZE_MAX];
    int nMsgLength = 0;

    ZeroMemory(ucSendBuff, MESSAGE_SIZE_MAX);
    ZeroMemory(ucTempBuff, MESSAGE_SIZE_MAX);

    UpdateData(TRUE);

    m_str_SendFuzMsg.Trim();
    m_str_SendFuzMsg.Remove(' ');

    nMsgLength = m_str_SendFuzMsg.GetLength() + 12;
    if(nMsgLength == 0 || nMsgLength % 4)
    {
        AfxMessageBox(_T("�޽����� ���̰� ���� �ʽ��ϴ�."));
        return ;
    }
    else if(nMsgLength > MESSAGE_SIZE_MAX) {
        AfxMessageBox(_T("�޽����� ���̰� �ʹ� ��ϴ�."));
        return ;
    }
    // �Էµ� ���ڿ��� Hex ���ڿ����� ����ó��2
    // Convert a TCHAR string to a LPCSTR
    CT2CA pszConvertedAnsiString(m_str_SendFuzMsg);
    // Construct a std::string using the LPCSTR input
    std::string s(pszConvertedAnsiString);
    if(!IsHex(s)) {
        AfxMessageBox(_T("�޽����� Hexa ���ڿ��� �ƴѰ��� �ֽ��ϴ�."));
        return ;
    }

    // ASCII => Hex ��ȯ
    strcpy_s((char*)ucTempBuff, MESSAGE_SIZE_MAX, CT2A(m_str_SendFuzMsg));

    ucSendBuff[0] =  0x00;
    ucSendBuff[1] = (nMsgLength-8)/4 + 1;
    ucSendBuff[2] = 0xAB;
    ucSendBuff[3] = 0x55;
    ucSendBuff[4] = 0x00;
    ucSendBuff[5] = 0xE0;

    for(int i=6, j=0; i < (nMsgLength/2)+6; i++, j+=2)
    {
        ucSendBuff[i] = asc2hex(ucTempBuff, j, j+1);
        //TRACE(_T("%02X "), ucSendBuff[i]);
    }

    // ����Ʈâ ��ȯ �޽��� ��¿� ó�� : 01 02 03 ...
    for(UINT nIndex = 0; nIndex < (UINT)m_str_SendFuzMsg.GetLength(); nIndex++)
    {
        CString strChar;
        strChar = m_str_SendFuzMsg.GetAt(nIndex);
        strSend += strChar;

        if((nIndex % 2) == 1)
        {
            strSend += _T(" ");
        }
    }

    m_str_SendFuzMsg = strSend;
    UpdateData(FALSE);

    // ���� �޽��� ���� ȣ��
    uCommandType uCommand;
    ZeroMemory(uCommand.bCommand, sizeof(uCommand.bCommand));
    memcpy_s(uCommand.bCommand, sizeof(uCommand), ucSendBuff, nMsgLength/2);
    SendCommand(uCommand, nMsgLength/2);
}


void CLSAM_GUIDlg::OnBnClickedBtnRfSend()
{
    // TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
    CString strSend = _T("");
    BYTE ucSendBuff[MESSAGE_SIZE_MAX];
    BYTE ucTempBuff[MESSAGE_SIZE_MAX];
    int nMsgLength = 0;

    ZeroMemory(ucSendBuff, MESSAGE_SIZE_MAX);
    ZeroMemory(ucTempBuff, MESSAGE_SIZE_MAX);

    UpdateData(TRUE);

    m_str_SendRfMsg.Trim();
    m_str_SendRfMsg.Remove(' ');

    nMsgLength = m_str_SendRfMsg.GetLength() + 8;
    if(nMsgLength == 0 || nMsgLength % 4)
    {
        AfxMessageBox(_T("�޽����� ���̰� ���� �ʽ��ϴ�."));
        return ;
    }
    else if(nMsgLength > MESSAGE_SIZE_MAX) {
        AfxMessageBox(_T("�޽����� ���̰� �ʹ� ��ϴ�."));
        return ;
    }
    // �Էµ� ���ڿ��� Hex ���ڿ����� ����ó��2
    // Convert a TCHAR string to a LPCSTR
    CT2CA pszConvertedAnsiString(m_str_SendRfMsg);
    // Construct a std::string using the LPCSTR input
    std::string s(pszConvertedAnsiString);
    if(!IsHex(s)) {
        AfxMessageBox(_T("�޽����� Hexa ���ڿ��� �ƴѰ��� �ֽ��ϴ�."));
        return ;
    }

    // ASCII => Hex ��ȯ
    strcpy_s((char*)ucTempBuff, MESSAGE_SIZE_MAX, CT2A(m_str_SendRfMsg));

    ucSendBuff[1] = (nMsgLength-4)/4;
    ucSendBuff[3] = 0x04;

    for(int i=4, j=0; i < (nMsgLength/2)+4; i++, j+=2)
    {
        ucSendBuff[i] = asc2hex(ucTempBuff, j, j+1);
        //TRACE(_T("%02X "), ucSendBuff[i]);
    }

    // ����Ʈâ ��ȯ �޽��� ��¿� ó�� : 01 02 03 ...
    for(UINT nIndex = 0; nIndex < (UINT)m_str_SendRfMsg.GetLength(); nIndex++)
    {
        CString strChar;
        strChar = m_str_SendRfMsg.GetAt(nIndex);
        strSend += strChar;

        if((nIndex % 2) == 1)
        {
            strSend += _T(" ");
        }
    }

    m_str_SendRfMsg = strSend;
    UpdateData(FALSE);

    // ���� �޽��� ���� ȣ��
    uCommandType uCommand;
    ZeroMemory(uCommand.bCommand, sizeof(uCommand.bCommand));
    memcpy_s(uCommand.bCommand, sizeof(uCommand), ucSendBuff, nMsgLength/2);
    SendCommand(uCommand, nMsgLength/2);
}


bool CLSAM_GUIDlg::IsHex(const std::string& str)
{
    for (size_t i = 0; i < str.length(); i++) 
    {
        char current = str[i];
        if (current >= '0' && current <= '9') {
            continue;
        }

        if (current >= 'A' && current <= 'F') {
            continue;
        }

        if (current >= 'a' && current <= 'f') {
            continue;
        }

        return false;
    }

    return true;
}


int CLSAM_GUIDlg::asc2hex(BYTE* hex, int start, int end)
{
    int nTrans = 0;
    for (int i = start; i<=end; i++)
    {
        if (('0' <= hex[i]) && (hex[i] <= '9'))
        {
            nTrans = 16 * nTrans + (hex[i] - '0'); 
            //TRACE("nTrans-n : %x \n", nTrans);
        }
        else if (('A' <= hex[i]) && (hex[i] <= 'F')) 
        {
            nTrans = 16 * nTrans + (hex[i] - 55);
            //TRACE("nTrans-c : %x \n", nTrans);
        }
        else if (('a' <= hex[i]) && (hex[i] <= 'f'))
        {
            nTrans = 16 * nTrans + (hex[i] - 87); 
            //TRACE("nTrans-n : %x \n", nTrans);
        }
        else
            return 0;
    }
    return nTrans;
}


int CLSAM_GUIDlg::SendCommand(uCommandType ucommand, int nSize)
{
    SYSTEMTIME systime;
    CString strTime;
    CString strMsg;
    CString strVal;
    int nResult = -1;
    BYTE bCmd[MESSAGE_SIZE_MAX];
    memset(bCmd, 0, MESSAGE_SIZE_MAX);
    memcpy(bCmd, ucommand.bCommand, nSize);

    //////////////////////////////////////////////////////////////
    // ���� �޽��� �α� ó��
    {
        // ���� ����� �޸� Read/Write �� �α� ��� ����.
        ::GetLocalTime(&systime);
        strTime.Format(_T("[%02d:%02d:%02d:%03d TX] "), systime.wHour, systime.wMinute, systime.wSecond, systime.wMilliseconds);

        int nLoop;
        bool bSplit;
        if(nSize % 2) {
            nLoop = nSize/2 + 1;
            bSplit = true;
        } else {
            nLoop = nSize/2;
            bSplit = false;
        }

        for(int i = 0; i < nLoop; i ++)
        {
            if(bSplit && (i == (nLoop-1)))
                strVal.Format(_T("%02X "),ucommand.bCommand[nSize-1]);
            else
                strVal.Format(_T("%04X "),htons(ucommand.wCommand[i]));
            strMsg += strVal;
        }

        //for(int n=0; n<nSize; n+=2)
        //{
        //    strVal.Format(_T("%02x%02x "), bCmd[n], bCmd[n+1]);
        //    // sDat += sTmp; 
        //    strMsg += strVal;
        //}
        AddEventString(strTime + strMsg);

        // TX �����
        //    if(m_pWndViewMain->m_bLogSave)
        //{
        //    CStringA strA;
        //    strA = strTime + strMsg + _T("\r\n");

        //    char* cBuf = strA.GetBuffer();
        //    int nLen = strA.GetLength();

        //    m_file.Write(cBuf, (unsigned int)nLen);
        //}
    }

    //////////////////////////////////////////////////////////////
    // Command ����
    nResult = send(m_hSocket, (const char*)bCmd, nSize, 0);
    if(nResult == -1) {
        AddEventString(_T("+++++++ [ERROR] SendCommand() Socket Error!"));
    }

    return nResult;
}


void CLSAM_GUIDlg::OnCbnSelchangeCmbPowerTdd()
{
    // TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
    BYTE ucVoltage = 0;

    // TDD �������� �� ����
    int nCurSel = m_cmb_PowerTdd.GetCurSel();

    switch(nCurSel)
    {
    case 0:
        ucVoltage = POWER_TDD_24_0;
        break;
    case 1:
        ucVoltage = POWER_TDD_24_5;
        break;
    case 2:
        ucVoltage = POWER_TDD_25_0;
        break;
    case 3:
        ucVoltage = POWER_TDD_25_5;
        break;
    case 4:
        ucVoltage = POWER_TDD_26_0;
        break;
    case 5:
        ucVoltage = POWER_TDD_26_5;
        break;
    case 6:
        ucVoltage = POWER_TDD_27_0;
        break;
    case 7:
        ucVoltage = POWER_TDD_27_5;
        break;
    case 8:
        ucVoltage = POWER_TDD_28_0;
        break;
    case 9:
        ucVoltage = POWER_TDD_28_5;
        break;
    case 10:
        ucVoltage = POWER_TDD_29_0;
        break;
    case 11:
        ucVoltage = POWER_TDD_29_5;
        break;
    case 12:
        ucVoltage = POWER_TDD_30_0;
        break;
    case 13:
        ucVoltage = POWER_TDD_30_5;
        break;
    case 14:
        ucVoltage = POWER_TDD_31_0;
        break;
    case 15:
        ucVoltage = POWER_TDD_31_5;
        break;
    case 16:
        ucVoltage = POWER_TDD_32_0;
        break;
    case 17:
        ucVoltage = POWER_TDD_32_5;
        break;
    case 18:
        ucVoltage = POWER_TDD_33_0;
        break;
    case 19:
        ucVoltage = POWER_TDD_33_5;
        break;
    case 20:
        ucVoltage = POWER_TDD_34_0;
        break;
    default:
        ucVoltage = POWER_TDD_28_0;
        break;
    }

    SendCmdTddVoltageSet(ucVoltage);
}


int CLSAM_GUIDlg::SendCmdTddVoltageSet(BYTE ucVoltage)
{
    uCommandType uCommand;
    int nCmdIndex = 0;
    WORD wdData = ucVoltage << 8;

    memset(uCommand.bCommand, 0, sizeof(uCommand));
    uCommand.wCommand[nCmdIndex++] = htons(0x0003);
    uCommand.wCommand[nCmdIndex++] = htons(0xAA55);
    uCommand.wCommand[nCmdIndex++] = htons(0x00B1);
    uCommand.wCommand[nCmdIndex++] = htons(wdData);

    return SendCommand(uCommand, nCmdIndex*2);
}


void CLSAM_GUIDlg::OnBnClickedBtnTddOnoff()
{
    // TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
    if(m_bTddPower)
    {
        m_btn_TddOnOff.SetWindowText(_T("ON"));
        m_bTddPower = FALSE;
        SendCmdTddPower(POWER_OFF);
    }
    else
    {
        m_btn_TddOnOff.SetWindowText(_T("OFF"));
        m_bTddPower = TRUE;
        SendCmdTddPower(POWER_ON);
    }
}


void CLSAM_GUIDlg::OnBnClickedBtnRfOnoff()
{
    // TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
    if(m_bRfPower)
    {
        m_btn_RfOnOff.SetWindowText(_T("ON"));
        m_bRfPower = FALSE;
        SendCmdRfPower(POWER_OFF);
    }
    else
    {
        m_btn_RfOnOff.SetWindowText(_T("OFF"));
        m_bRfPower = TRUE;
        SendCmdRfPower(POWER_ON);
        // SendRFDCA(63, 2000);
    }
}


int CLSAM_GUIDlg::SendCmdTddPower(BYTE ucOnOff)
{
    uCommandType uCommand;
    int nCmdIndex = 0;
    WORD wdData = ucOnOff;

    memset(uCommand.bCommand, 0, sizeof(uCommand));
    uCommand.wCommand[nCmdIndex++] = htons(0x0003);
    uCommand.wCommand[nCmdIndex++] = htons(0xAA00);
    uCommand.wCommand[nCmdIndex++] = htons(0x00B0);
    uCommand.wCommand[nCmdIndex++] = htons(wdData);

    return SendCommand(uCommand, nCmdIndex*2);
}


int CLSAM_GUIDlg::SendCmdRfPower(BYTE ucOnOff)
{
    uCommandType uCommand;
    int nCmdIndex = 0;
    WORD wdData = ucOnOff;

    memset(uCommand.bCommand, 0, sizeof(uCommand));
    uCommand.wCommand[nCmdIndex++] = htons(0x0003);
    uCommand.wCommand[nCmdIndex++] = htons(0x0002);
    uCommand.wCommand[nCmdIndex++] = htons(0x00C1);
    uCommand.wCommand[nCmdIndex++] = htons(wdData);

    return SendCommand(uCommand, nCmdIndex*2);
}


void CLSAM_GUIDlg::OnBnClickedBtnLoopback()
{
    // TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
    uCommandType uCommand;
    int nCmdIndex = 0;
    f_bLooopback = TRUE;

    ZeroMemory(uCommand.bCommand, sizeof(uCommand.bCommand));
    uCommand.wCommand[nCmdIndex++] = htons(0x0000);
    uCommand.wCommand[nCmdIndex++] = htons(0xAB55);
    uCommand.wCommand[nCmdIndex++] = htons(0x00E0);
    uCommand.wCommand[nCmdIndex++] = htons(0x0000);
    uCommand.wCommand[nCmdIndex++] = htons(0x1111);
    uCommand.wCommand[nCmdIndex++] = htons(0x2222);
    uCommand.wCommand[nCmdIndex++] = htons(0x3333);
    uCommand.wCommand[nCmdIndex++] = htons(0x4444);
    uCommand.wCommand[nCmdIndex++] = htons(0x5555);
    uCommand.wCommand[nCmdIndex++] = htons(0x6666);
    uCommand.wCommand[nCmdIndex++] = htons(0x7777);
    uCommand.wCommand[nCmdIndex++] = htons(0x8888);
    //uCommand.wCommand[nCmdIndex++] = htons(0x0000);
    //uCommand.wCommand[nCmdIndex++] = htons(0x5555);
    //uCommand.wCommand[nCmdIndex++] = htons(0x0000);
    //uCommand.wCommand[nCmdIndex++] = htons(0x6666);
    //uCommand.wCommand[nCmdIndex++] = htons(0x0000);
    //uCommand.wCommand[nCmdIndex++] = htons(0x7777);
    //uCommand.wCommand[nCmdIndex++] = htons(0x0000);
    //uCommand.wCommand[nCmdIndex++] = htons(0x8888);
    //uCommand.wCommand[nCmdIndex++] = htons(0x0000);
    //uCommand.wCommand[nCmdIndex++] = htons(0x9999);
    //uCommand.wCommand[nCmdIndex++] = htons(0x0000);

    uCommand.wCommand[0] = htons(nCmdIndex - 1);

    SendCommand(uCommand, nCmdIndex*2);
}


void CLSAM_GUIDlg::OnBnClickedBtnRxDisplay()
{
    // TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
    if(m_bRxDisplay)
    {
        m_btn_RxDisplay.SetWindowText(_T("ON"));
        m_bRxDisplay = FALSE;
    } else {
        m_btn_RxDisplay.SetWindowText(_T("OFF"));
        m_bRxDisplay = TRUE;
    }
}


void CLSAM_GUIDlg::OnBnClickedBtnLogSave()
{
    // TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
    if(m_bLogSave)
    {
        m_btn_LogSave.SetWindowText(_T("ON"));
        m_bLogSave = FALSE;

        m_file.Close();
    } else {
        m_btn_LogSave.SetWindowText(_T("OFF"));
        m_bLogSave = TRUE;

        CTime time=CTime::GetCurrentTime();
        CString strFilPath;
        strFilPath.Format(_T("%s\\ReceiveData_%0.4d-%0.2d-%0.2d [%02d��%02d��].log"), m_strMainPath, time.GetYear(), time.GetMonth(), time.GetDay(), time.GetHour(), time.GetMinute());

        if(m_file.Open(strFilPath, CFile::modeWrite | CFile::modeCreate | CFile::modeNoTruncate|CFile::shareDenyNone))
        {
            m_file.Seek(0, CFile::end);
        }
    }
}


void CLSAM_GUIDlg::OnBnClickedBtnParamSet()
{
    // TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
    if(p_LSAM_ParamSet->GetSafeHwnd() == NULL)   // �ߺ� ���� ����
    {
        p_LSAM_ParamSet = new CLSAM_ParamSet;
        p_LSAM_ParamSet->Create(IDD_LSAM_PARAMSET);  // ����
        p_LSAM_ParamSet->CenterWindow();
        p_LSAM_ParamSet->ShowWindow(SW_SHOW);
    }
    else
    {
        p_LSAM_ParamSet->SetActiveWindow();
    }
}


void CLSAM_GUIDlg::SendRFDCA(UINT8 u8RfDCA, UINT16 u16MSec)
{
    // TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
    // Sleep(u16MSec);

    uScenario5A uScenario5A;

    //sTmp.Format(_T("%d"), u32DopplerFreq);
    //AfxMessageBox(sTmp);
    uScenario5A.stScenario5A.Header1 = HEADER1;
    uScenario5A.stScenario5A.Header2 = HEADER2;
    uScenario5A.stScenario5A.Header3 = HEADER3;
    uScenario5A.stScenario5A.Command = 0x5A;

    uScenario5A.stScenario5A.Reserved1 = 0x00;
    uScenario5A.stScenario5A.Reserved2 = 0x00;
    uScenario5A.stScenario5A.Reserved3 = 0x00;
    uScenario5A.stScenario5A.Reserved4 = 0x00;
    uScenario5A.stScenario5A.Reserved5 = 0x00;
    uScenario5A.stScenario5A.Reserved6 = 0x00;
    uScenario5A.stScenario5A.Reserved7 = 0x00;
    uScenario5A.stScenario5A.Reserved8 = 0x00;

    if(u8RfDCA == 63)
    {
        uScenario5A.stScenario5A.ROM_Addr = 0x3F;
        uScenario5A.stScenario5A.DCA_D15to8 = 0xFF;
        uScenario5A.stScenario5A.DCA_D7to0 = 0xFF;
        uScenario5A.stScenario5A.CRC8 = 0x31;
    }
    else if(u8RfDCA == 0)
    {
        uScenario5A.stScenario5A.ROM_Addr = 0x00;
        uScenario5A.stScenario5A.DCA_D15to8 = 0x00;
        uScenario5A.stScenario5A.DCA_D7to0 = 0x00;
        uScenario5A.stScenario5A.CRC8 = 0xA8;
    }

    WORD wLen = 0x0010, wOp = HEAD_OF_DATA;
    uCommandType uCommand;

    int nCmdIndex = 0;

    uCommand.wCommand[nCmdIndex++] = htons(wOp);			//0xAB00);
    uCommand.wCommand[nCmdIndex++] = htons(wLen);			//0010);
    uCommand.wCommand[nCmdIndex++] = (MAKEWORD(uScenario5A.stScenario5A.Header1, uScenario5A.stScenario5A.Header2 ));
    uCommand.wCommand[nCmdIndex++] = (MAKEWORD(uScenario5A.stScenario5A.Header3, uScenario5A.stScenario5A.Command ));
    uCommand.wCommand[nCmdIndex++] = (MAKEWORD(uScenario5A.stScenario5A.ROM_Addr, uScenario5A.stScenario5A.DCA_D15to8 ));
    uCommand.wCommand[nCmdIndex++] = (MAKEWORD(uScenario5A.stScenario5A.DCA_D7to0, uScenario5A.stScenario5A.Reserved1 ));
    uCommand.wCommand[nCmdIndex++] = (MAKEWORD(uScenario5A.stScenario5A.Reserved2, uScenario5A.stScenario5A.Reserved3 ));
    uCommand.wCommand[nCmdIndex++] = (MAKEWORD(uScenario5A.stScenario5A.Reserved4, uScenario5A.stScenario5A.Reserved5 ));
    uCommand.wCommand[nCmdIndex++] = (MAKEWORD(uScenario5A.stScenario5A.Reserved6, uScenario5A.stScenario5A.Reserved7 ));
    uCommand.wCommand[nCmdIndex++] = (MAKEWORD(uScenario5A.stScenario5A.Reserved8, uScenario5A.stScenario5A.CRC8 ));

    SendCommand(uCommand, nCmdIndex*2);

    Sleep(500);
}


void CLSAM_GUIDlg::OnBnClickedBtnBit()
{
    // TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
    uCommandType uCommand;
    uCommand.bCommand[0] = 0x00;
    uCommand.bCommand[1] = 0x03;
    uCommand.bCommand[2] = 0x00;
    uCommand.bCommand[3] = 0x01;
    uCommand.bCommand[4] = 0x00;
    uCommand.bCommand[5] = 0xC0;
    uCommand.bCommand[6] = 0x00;
    uCommand.bCommand[7] = 0x01;
    SendCommand(uCommand, 4*2);
}
