#define WM_DLG_MENU (WM_USER+1001)
#define WM_SOCKET_STATE (WM_USER+1002)

#define MESSAGE_SIZE_MAX 1024

// 제어명령
#define HEADER1 0x2E
#define HEADER2 0x3A
#define HEADER3 0x4F
#define FULL_ATTENUATOR 0xFF

// TDD 공급전원 제어값
#define POWER_TDD_24_0				0x62
#define POWER_TDD_24_5				0x65
#define POWER_TDD_25_0				0x67
#define POWER_TDD_25_5				0x69
#define POWER_TDD_26_0				0x6B
#define POWER_TDD_26_5				0x6D
#define POWER_TDD_27_0				0x70
#define POWER_TDD_27_5				0x72
#define POWER_TDD_28_0				0x74
#define POWER_TDD_28_5				0x76
#define POWER_TDD_29_0				0x79
#define POWER_TDD_29_5				0x7B
#define POWER_TDD_30_0				0x7D
#define POWER_TDD_30_5				0x7F
#define POWER_TDD_31_0				0x81
#define POWER_TDD_31_5				0x84
#define POWER_TDD_32_0				0x86
#define POWER_TDD_32_5				0x88
#define POWER_TDD_33_0				0x8B
#define POWER_TDD_33_5				0x8D
#define POWER_TDD_34_0				0x8F

// 전원 On/Off 정의
#define POWER_OFF					0x00
#define POWER_ON					0x01

#define RF_IN1				0x01
#define RF_IN2				0x02
#define RF_IN3				0x03
#define RF_IN4				0x04
#define RF_IN5				0x05
#define RF_IN6				0x06
#define RF_IN7				0x07
#define RF_IN8				0x08
#define RF_OUT1				0x01
#define RF_OUT2				0x02
#define RF_OUT3				0x03
#define RF_OUT4				0x04
#define RF_OUT5				0x05
#define RF_OUT6				0x06
#define RF_OUT7				0x07
#define RF_OUT8				0x08
#define WIRE            0x31
#define WIRELESS      0x32


// 통신
#define WM_CONNECT_EVENT   (WM_USER+25001)
#define WM_RECEIVE_EVENT  (WM_USER+25002)

// 색상
#define WHITE   RGB(255, 255, 255)
#define BLUE    RGB(60, 60, 250)

////// OP Code CMD ========================== 
////// OP Code 
////#define PERIOD_OP						0x00					// Period Communication 
#define TDD_PWR_OP					0x0010					// 
#define SAD_PWR_OP					0x0011					// 
#define TDD_MSLAWAY_OP			0x0012					// 
#define TDD_TX_OP						0x0013					// 
#define TXOUT_MEAS_OP				0x0014					// None - 2014.03.19 
#define SD_SIG_OP						0x0015					// None	- 2014.03.19 
#define ED_SIG_OP						0x0016					// 
#define FIRE_DLY_OP						0x0017					// 
#define FUZ_SCMODE_OP				0x0018					// 2014.03.19 Add 
#define FUZ_FLAGBIRD_OP				0x0019					// 2014.03.19 Add 
#define PARAM_SET_OP					0x0020					// 
#define TGT_RXPWR_OP					0x0030					// Target Info  --> 42 통합
#define TGT_DPLR_OP					0x0031					//  --> 42 통합 
#define CLT_RXPWR_OP					0x0040					// Clutter Info  --> 42 통합 
#define CLT_DPLR_OP					0x0041					//  --> 42 통합 
#define TGTCLT_INFOSET_OP			0x0042					// Target & Clutter Set 

#define ANT_SET_OP						0x0050					// 
#define SAD_SET_OP						0x0051					// 
#define WIRE_SET_OP					0xAB52					// 
#define FUZ_STATUS_OP				0x0060					// None - 2012.07.26 
#define FUZ_RSLTST_OP				0x0070					// Rx Only - 1ms, File Save
//#define FILE_SAVE_OP					0x0070					// Rx Only - File Save Start/End 
#define TGTCLT_SET_OP				0x0080					// 
#define TGTCLT_DDSREG_OP			0x0081					// FW USED Only 
#define TGTCLT_DDSRST_OP			0x0082					// 
#define TGTCLT_DDSIOUP_OP		0x0083					// FW USED Only 
#define TGTCLT_FRQSET_OP			0x0084					// 
#define TGTCLT_RFSET_OP				0x0088					// 
#define CHKDEV_BIT_OP				0x008E					// 점검장비 BIT 
#define TGTCLT_STATE_OP			0x008F					// Status Read On/Off 
#define FUZ_ESSMOD_OP				0x0090					// ESS Test Mode 

#define HEAD_OF_DATA    0xAD55  // GUI-보드 간 헤더
#define RF_CONTROL_OP      0x0004
#define NO_ITEM     0x0000
#define ITEM_A0     0x00A0
#define ITEM_5A     0x005A
#define ITEM_A1     0x00A1
#define ITEM_A2     0x00A2
#define ITEM_A4     0x00A4
#define ITEM_C3     0x00C3

typedef unsigned char   BOOLEAN;
typedef char    CHAR;

typedef signed char S8BIT;
typedef unsigned char   U8BIT;

typedef signed short    S16BIT;
typedef unsigned short  U16BIT;

typedef signed int  S32BIT;
typedef unsigned int    U32BIT;

typedef signed long long    S64BIT;

typedef unsigned char       BYTE;
typedef unsigned short      WORD;

typedef enum _eDlgMenuMsg {
	eDlgMenuExit,
	eDlgMenuConnect,
	eDlgMenuConfig
}eTopMenuMsg;

typedef enum _eSocketState {
	eSocketClose,
	eSocketOpen
}eSocketState;

typedef union _uCommandType {
	BYTE bCommand[1024];
	WORD wCommand[512];
}uCommandType;

const WORD HEADER_TDD			= 0xAA55;
const WORD HEADER_TDD_POWER		= 0xAA00;
const WORD HEADER_RF_POWER		= 0xCC00;

typedef struct _sScenarioA0 {
    BYTE Header1;
    BYTE Header2;
    BYTE Header3;
    BYTE Command;
    BYTE FreqData3;
    BYTE FreqData2;
    BYTE FreqData1;
    BYTE FreqData0;
    BYTE OffsetPower;
    BYTE RF_IN_Path;
    BYTE RF_OUT_Path;
    BYTE StartRange;
    BYTE StopRange;
    BYTE IntervalData1;
    BYTE IntervalData0;
    BYTE CRC8;
}sScenarioA0;

typedef union _uScenarioA0 {
    sScenarioA0 stScenarioA0;
    BYTE arrScenarioA0[16];
}uScenarioA0;

typedef struct _sScenarioA4 {
    BYTE Header1;
    BYTE Header2;
    BYTE Header3;
    BYTE Command;
    BYTE FreqData3;
    BYTE FreqData2;
    BYTE FreqData1;
    BYTE FreqData0;
    BYTE OffsetPower;
    BYTE RF_IN_Path;
    BYTE RF_OUT_Path;
    BYTE StartRange;
    BYTE StopRange;
    BYTE RF_DCA;
    BYTE Start_Stop;
    BYTE CRC8;
}sScenarioA4;

typedef union _uScenarioA4 {
    sScenarioA4 stScenarioA4;
    BYTE arrScenarioA4[16];
}uScenarioA4;

typedef struct _sScenario {
    BYTE FreqData3;
    BYTE FreqData2;
    BYTE FreqData1;
    BYTE FreqData0;
    BYTE OffsetPower;
    BYTE RF_IN_Path;
    BYTE RF_OUT_Path;
    BYTE StartRange;
    BYTE StopRange;
    BYTE IntervalData1;
    BYTE IntervalData0;
    BYTE RF_DCA;
    BYTE Start_Stop;
}sScenario;

typedef union _uScenario {
    sScenario stScenario;
    BYTE arrScenario[13];
}uScenario;

typedef struct _sScenarioA2 {
    BYTE Header1;
    BYTE Header2;
    BYTE Header3;
    BYTE Command;
    BYTE Start_Addr;
    BYTE R1_DCA;
    BYTE R2_DCA;
    BYTE R3_DCA;
    BYTE R4_DCA;
    BYTE R5_DCA;
    BYTE R6_DCA;
    BYTE R7_DCA;
    BYTE R8_DCA;
    BYTE R9_DCA;
    BYTE R10_DCA;
    BYTE CRC8;
}sScenarioA2;

typedef union _uScenarioA2 {
    sScenarioA2 stScenarioA2;
    BYTE arrScenarioA2[16];
}uScenarioA2;

typedef struct _sScenario5A {
    BYTE Header1;
    BYTE Header2;
    BYTE Header3;
    BYTE Command;
    BYTE ROM_Addr;
    BYTE DCA_D15to8;
    BYTE DCA_D7to0;
    BYTE Reserved1;
    BYTE Reserved2;
    BYTE Reserved3;
    BYTE Reserved4;
    BYTE Reserved5;
    BYTE Reserved6;
    BYTE Reserved7;
    BYTE Reserved8;
    BYTE CRC8;
}sScenario5A;

typedef union _uScenario5A {
    sScenario5A stScenario5A;
    BYTE arrScenario5A[16];
}uScenario5A;
