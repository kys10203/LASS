
// DlgProxy.h: 헤더 파일
//

#pragma once

class CLSAM_GUIDlg;


// CLSAM_GUIDlgAutoProxy 명령 대상

class CLSAM_GUIDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CLSAM_GUIDlgAutoProxy)

	CLSAM_GUIDlgAutoProxy();           // 동적 만들기에 사용되는 protected 생성자입니다.

// 특성입니다.
public:
	CLSAM_GUIDlg* m_pDialog;

// 작업입니다.
public:

// 재정의입니다.
	public:
	virtual void OnFinalRelease();

// 구현입니다.
protected:
	virtual ~CLSAM_GUIDlgAutoProxy();

	// 생성된 메시지 맵 함수

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CLSAM_GUIDlgAutoProxy)

	// 생성된 OLE 디스패치 맵 함수

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

