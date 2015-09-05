// GujianEditorDlg.h : 头文件
//

#pragma once

#include <map>
#include "afxwin.h"
#include "MyButton.h"
#include "sortbutton.h"
using namespace std;

struct Items {
    CString des;
    int id;
};

typedef map<CString, Items> List;

// CGujianEditorDlg 对话框
class CGujianEditorDlg : public CDialog
{
// 构造
public:
	CGujianEditorDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_GUJIANEDITOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedOpensave();
    CString m_szEvPath;
    bool LoadData(CString szPathname, CString szFilename);
    CString m_szContent;
    BYTE *m_pBuf;
    UINT m_nLength;
    List BeautyItem, ClothManItem, ClothWomanItem, HeadManItem, HeadWomanItem, HomeItem,
         HYWeaponItem, LSWeaponItem, OutsideClothItem, QSWeaponItem, QXWeaponItem,
         ResourceItem, ShoesManItem, ShoesWomanItem, StatusItem, TaskItem, TSWeaponItem, XLWeaponItem;

public:
    void InitBeautyItem();
    void InitClothManItem();
    void InitClothWomanItem();
    void InitHeadManItem();
    void InitHeadWomanItem();
    void InitHomeItem();
    void InitHYWeaponItem();
    void InitLSWeaponItem();
    void InitOutsideClothItem();
    void InitQSWeaponItem();
    void InitQXWeaponItem();
    void InitResourceItem();
    void InitShoesManItem();
    void InitShoesWomanItem();
    void InitStatusItem();
    void InitTaskItem();
    void InitTSWeaponItem();
    void InitXLWeaponItem();
    bool m_bOpened;
    List* m_pSelectedList;
    CListBox m_ItemList;
    bool UpdateItemList(List *m);
    afx_msg void OnBnClickedBeauty();
    BYTE m_nEditNum;
    CEdit m_BottomEditor;
    CButton m_EditApply;
    afx_msg void OnLbnSelchangeItemlist();
    afx_msg void OnBnClickedButton3();
    afx_msg void OnBnClickedButton4();
    afx_msg void OnBnClickedButton5();
    afx_msg void OnBnClickedButton6();
    afx_msg void OnBnClickedButton7();
    afx_msg void OnBnClickedButton8();
    afx_msg void OnBnClickedButton9();
    afx_msg void OnBnClickedButton10();
    afx_msg void OnBnClickedButton11();
    afx_msg void OnBnClickedButton12();
    afx_msg void OnBnClickedButton13();
    CBrush m_brBk;
    CBrush m_brLstBk;
    afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
    CMyButton m_OpenSave;
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
    afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
    afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
    CMyButton m_SaveSave;
    CString m_szIntro;
    CStatic m_IntroText;
    CBrush m_brIntroBk;
    CSortButton m_Beauty;
    CSortButton m_ClothMan;
    CSortButton ClothWoman;
    CSortButton m_HeadMan;
    CSortButton m_HeadWoman;
    CSortButton m_Home;
    CSortButton m_OutsideCloth;
    CSortButton m_Resource;
    CSortButton m_ShoesMan;
    CSortButton m_ShoesWoman;
    CSortButton m_Status;
    CSortButton m_Task;
    CMyButton m_Tusu;
    CMyButton m_Qingxue;
    CMyButton m_Hongyu;
    CMyButton m_Xiangling;
    CMyButton m_Lansheng;
    CMyButton m_Qianshang;
    afx_msg void OnBnClickedEditapply();
    afx_msg void OnBnClickedSavesave();
    CString m_szFileName;
    CString m_szPathName;
    afx_msg void OnBnClickedButton2();
    afx_msg void OnBnClickedQxweapon();
    afx_msg void OnBnClickedHyweapon();
    afx_msg void OnBnClickedXlweapon();
    afx_msg void OnBnClickedLsweapon();
    afx_msg void OnBnClickedQsweapon();
    afx_msg LRESULT OnNcHitTest(CPoint point);
    CButton m_CloseBtn;
    afx_msg void OnBnClickedClose();
protected:
    virtual void OnCancel();
    virtual void OnOK();
};
