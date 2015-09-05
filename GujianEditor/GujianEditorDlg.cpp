// GujianEditorDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "GujianEditor.h"
#include "GujianEditorDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���


class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CGujianEditorDlg �Ի���
#include "IncTables.cpp"

CGujianEditorDlg::CGujianEditorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGujianEditorDlg::IDD, pParent)
    , m_szEvPath(_T(""))
    , m_szContent(_T(""))
    , m_pBuf(NULL)
    , m_nLength(0)
    , m_bOpened(false)
    , m_pSelectedList(NULL)
    , m_nEditNum(0)
    , m_OpenSave(IDB_OPENSAVE, IDB_OPENSAVECLICK)
    , m_SaveSave(IDB_SAVESAVE, IDB_SAVESAVECLICK)
    , m_Tusu(IDB_TUSU, IDB_TUSUCLICK)
    , m_Qingxue(IDB_QINGXUE, IDB_QINGXUECLICK)
    , m_Hongyu(IDB_HONGYU, IDB_HONGYUCLICK)
    , m_Xiangling(IDB_XIANGLING, IDB_XIANGLINGCLICK)
    , m_Lansheng(IDB_LANSHENG, IDB_LANSHENGCLICK)
    , m_Qianshang(IDB_QIANSHANG, IDB_QIANSHANGCLICK)
    , m_szIntro(_T("���޽��ܡ�"))
    , m_szFileName(_T(""))
    , m_szPathName(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
    
    TCHAR szTmpPath[MAX_PATH];
    ::SHGetFolderPath(NULL, CSIDL_LOCAL_APPDATA, NULL, 0, szTmpPath);  //�õ�AppData�ļ�·��
    m_szEvPath.Format(L"%s", szTmpPath);

    m_szEvPath += L"\\Aurogon Games\\Gujian\\SaveData\\";

    //MessageBox(m_szEvPath);
}

void CGujianEditorDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_ITEMLIST, m_ItemList);
    DDX_Text(pDX, IDC_EDIT1, m_nEditNum);
    DDX_Control(pDX, IDC_EDIT1, m_BottomEditor);
    DDX_Control(pDX, IDC_EDITAPPLY, m_EditApply);
    DDX_Control(pDX, IDC_OPENSAVE, m_OpenSave);
    DDX_Control(pDX, IDC_SAVESAVE, m_SaveSave);
    DDX_Control(pDX, IDC_INTRO, m_IntroText);
    DDX_Control(pDX, IDC_BEAUTY, m_Beauty);
    DDX_Control(pDX, IDC_CLOTHMAN, m_ClothMan);
    DDX_Control(pDX, IDC_CLOTHWOMAN, ClothWoman);
    DDX_Control(pDX, IDC_HEADMAN, m_HeadMan);
    DDX_Control(pDX, IDC_HEADWOMAN, m_HeadWoman);
    DDX_Control(pDX, IDC_HOME, m_Home);
    DDX_Control(pDX, IDC_OUTSIDECLOTH, m_OutsideCloth);
    DDX_Control(pDX, IDC_RESOURCE, m_Resource);
    DDX_Control(pDX, IDC_SHOESMAN, m_ShoesMan);
    DDX_Control(pDX, IDC_SHOESWOMAN, m_ShoesWoman);
    DDX_Control(pDX, IDC_STATUS, m_Status);
    DDX_Control(pDX, IDC_TASK, m_Task);
    DDX_Control(pDX, IDC_BUTTON2, m_Tusu);
    DDX_Control(pDX, IDC_QXWeapon, m_Qingxue);
    DDX_Control(pDX, IDC_HYWeapon, m_Hongyu);
    DDX_Control(pDX, IDC_XLWeapon, m_Xiangling);
    DDX_Control(pDX, IDC_LSWeapon, m_Lansheng);
    DDX_Control(pDX, IDC_QSWEAPON, m_Qianshang);
    DDX_Control(pDX, IDC_CLOSE, m_CloseBtn);
}

BEGIN_MESSAGE_MAP(CGujianEditorDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
    ON_BN_CLICKED(IDC_OPENSAVE, &CGujianEditorDlg::OnBnClickedOpensave)
    ON_BN_CLICKED(IDC_BEAUTY, &CGujianEditorDlg::OnBnClickedBeauty)
    ON_LBN_SELCHANGE(IDC_ITEMLIST, &CGujianEditorDlg::OnLbnSelchangeItemlist)
    ON_BN_CLICKED(IDC_CLOTHMAN, &CGujianEditorDlg::OnBnClickedButton3)
    ON_BN_CLICKED(IDC_CLOTHWOMAN, &CGujianEditorDlg::OnBnClickedButton4)
    ON_BN_CLICKED(IDC_HEADMAN, &CGujianEditorDlg::OnBnClickedButton5)
    ON_BN_CLICKED(IDC_HEADWOMAN, &CGujianEditorDlg::OnBnClickedButton6)
    ON_BN_CLICKED(IDC_HOME, &CGujianEditorDlg::OnBnClickedButton7)
    ON_BN_CLICKED(IDC_OUTSIDECLOTH, &CGujianEditorDlg::OnBnClickedButton8)
    ON_BN_CLICKED(IDC_RESOURCE, &CGujianEditorDlg::OnBnClickedButton9)
    ON_BN_CLICKED(IDC_SHOESMAN, &CGujianEditorDlg::OnBnClickedButton10)
    ON_BN_CLICKED(IDC_SHOESWOMAN, &CGujianEditorDlg::OnBnClickedButton11)
    ON_BN_CLICKED(IDC_STATUS, &CGujianEditorDlg::OnBnClickedButton12)
    ON_BN_CLICKED(IDC_TASK, &CGujianEditorDlg::OnBnClickedButton13)
    ON_WM_CTLCOLOR()
    ON_WM_MOUSEMOVE()
    ON_WM_LBUTTONDBLCLK()
    ON_WM_LBUTTONDOWN()
    ON_WM_LBUTTONUP()
    ON_WM_RBUTTONDBLCLK()
    ON_WM_RBUTTONDOWN()
    ON_WM_RBUTTONUP()
    ON_BN_CLICKED(IDC_EDITAPPLY, &CGujianEditorDlg::OnBnClickedEditapply)
    ON_BN_CLICKED(IDC_SAVESAVE, &CGujianEditorDlg::OnBnClickedSavesave)
    ON_BN_CLICKED(IDC_BUTTON2, &CGujianEditorDlg::OnBnClickedButton2)
    ON_BN_CLICKED(IDC_QXWeapon, &CGujianEditorDlg::OnBnClickedQxweapon)
    ON_BN_CLICKED(IDC_HYWeapon, &CGujianEditorDlg::OnBnClickedHyweapon)
    ON_BN_CLICKED(IDC_XLWeapon, &CGujianEditorDlg::OnBnClickedXlweapon)
    ON_BN_CLICKED(IDC_LSWeapon, &CGujianEditorDlg::OnBnClickedLsweapon)
    ON_BN_CLICKED(IDC_QSWEAPON, &CGujianEditorDlg::OnBnClickedQsweapon)
    ON_WM_NCHITTEST()
    ON_BN_CLICKED(IDC_CLOSE, &CGujianEditorDlg::OnBnClickedClose)
END_MESSAGE_MAP()


// CGujianEditorDlg ��Ϣ�������

BOOL CGujianEditorDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, TRUE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
    InitBeautyItem();
    InitClothManItem();
    InitClothWomanItem();
    InitHeadManItem();
    InitHeadWomanItem();
    InitHomeItem();
    InitHYWeaponItem();
    InitLSWeaponItem();
    InitOutsideClothItem();
    InitQSWeaponItem();
    InitQXWeaponItem();
    InitResourceItem();
    InitShoesManItem();
    InitShoesWomanItem();
    InitStatusItem();
    InitTaskItem();
    InitTSWeaponItem();
    InitXLWeaponItem();

    CBitmap bmp;
    bmp.LoadBitmapW(IDB_BG);
    m_brBk.CreatePatternBrush(&bmp);
    bmp.DeleteObject();
    bmp.LoadBitmapW(IDB_LISTBG);
    m_brLstBk.CreatePatternBrush(&bmp);
    bmp.DeleteObject();
    bmp.LoadBitmapW(IDB_INTROTEXT);
    m_brIntroBk.CreatePatternBrush(&bmp);
    bmp.DeleteObject();
    bmp.LoadBitmapW(IDB_CLOSE);
    m_CloseBtn.SetWindowPos(NULL, 538, 0, 20, 20, SWP_SHOWWINDOW);
    m_CloseBtn.SetBitmap(bmp);
    bmp.DeleteObject();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CGujianEditorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CGujianEditorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CGujianEditorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CGujianEditorDlg::OnBnClickedOpensave()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    TRY {
        CString szFilename(L"", 10000);
        CString szPathName(L"", MAX_PATH);
        CFileDialog OpenSave(true, NULL, L".SAV", OFN_FILEMUSTEXIST | OFN_FORCESHOWHIDDEN | OFN_NOREADONLYRETURN | OFN_EXPLORER, L"�Ž���̷�浵�ļ�(*.SAV)|*.SAV||", NULL, NULL, true);
        
        OpenSave.m_ofn.lpstrInitialDir = (LPCWSTR)(m_szEvPath);
        OpenSave.m_ofn.nMaxFile = 10000;
        OpenSave.m_ofn.lpstrFile = szFilename.GetBuffer(10000);

        //MessageBox(OpenSave.m_ofn.lpstrInitialDir);

        if(OpenSave.DoModal() == IDOK)
        {
            szPathName = OpenSave.GetPathName();
            szFilename = OpenSave.GetFileName();
            szPathName = szPathName.Left(szPathName.GetLength() - szFilename.GetLength() - 1);
            //MessageBox(szPathName);

            LoadData(szPathName + L"\\", szFilename);
        }
    }
    CATCH(CException, e) {
        MessageBox(L"�ļ��򿪳���", L"����", MB_ICONERROR);
    }
    END_CATCH;
}

bool CGujianEditorDlg::LoadData(CString szPathname, CString szFilename)
{
    CFile fs;
    CFileException e;
    CString tmp;

    if(!fs.Open(szPathname + szFilename, CFile::modeRead | CFile::typeBinary | CFile::shareExclusive, &e))
    {
        MessageBox(L"�ļ��򿪳���", L"����", MB_ICONERROR);
        return false;
    }
    else
    {
        if(m_pBuf != NULL)
        {
            delete []m_pBuf;
            m_pBuf = NULL;
        }

        m_nLength = fs.GetLength();
        m_pBuf = new BYTE[m_nLength];
        fs.Read(m_pBuf, m_nLength);
        fs.Close();

        m_szContent = L"";
        for(UINT i = 0; i < m_nLength; i++)
        {
            if(m_pBuf[i] != 0x00) tmp.Format(L"%c", m_pBuf[i]);
            else tmp = L".";

            m_szContent += tmp;
        }

        m_bOpened = true;
        
        m_BottomEditor.EnableWindow();
        m_EditApply.EnableWindow();
        MessageBox(L"�浵�򿪳ɹ���", L"��Ϣ", MB_OK);
        UpdateItemList(&ResourceItem);

        m_szFileName = szFilename, m_szPathName = szPathname;

        return true;
    }
}

bool CGujianEditorDlg::UpdateItemList(List *m)
{
    //while(m_ItemList.GetCount()) m_ItemList.DeleteString(0);
    m_ItemList.ResetContent();
    m_pSelectedList = m;
    if(m != NULL && m_bOpened)
    {
        List::iterator ibegin = m->begin(), iend = m->end();
        for(List::iterator i = ibegin; i != iend; i++) m_ItemList.AddString(i->first);
        m_szIntro = L"���޽��ܡ�";
        m_IntroText.SetWindowTextW(m_szIntro);
        return true;
    }
    else return false;
}

void CGujianEditorDlg::OnLbnSelchangeItemlist()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    if(m_ItemList.GetSelCount() == 1)
    {
        CString szTmpName;
        CString szTmpStr;
        CString szTmp;
        int nTmp;
        m_ItemList.GetSelItems(m_ItemList.GetCount(), &nTmp);
        m_ItemList.GetText(nTmp, szTmpName);

        szTmpStr.Format(L".%d_Item20BK", (*m_pSelectedList)[szTmpName].id);
        int nPos = m_szContent.Find(szTmpStr);

        nPos += szTmpStr.GetLength();

        UpdateData();
        m_nEditNum = m_pBuf[nPos];
        UpdateData(FALSE);

        m_szIntro = (*m_pSelectedList)[szTmpName].des;
        if(m_szIntro == "") m_szIntro = L"���޽��ܡ�";

        m_IntroText.SetWindowTextW(m_szIntro);
    }
}

void CGujianEditorDlg::OnBnClickedBeauty()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    UpdateItemList(&BeautyItem);
}

void CGujianEditorDlg::OnBnClickedButton3()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    UpdateItemList(&ClothManItem);
}

void CGujianEditorDlg::OnBnClickedButton4()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    UpdateItemList(&ClothWomanItem);
}

void CGujianEditorDlg::OnBnClickedButton5()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    UpdateItemList(&HeadManItem);
}

void CGujianEditorDlg::OnBnClickedButton6()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    UpdateItemList(&HeadWomanItem);
}

void CGujianEditorDlg::OnBnClickedButton7()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    UpdateItemList(&HomeItem);
}

void CGujianEditorDlg::OnBnClickedButton8()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    UpdateItemList(&OutsideClothItem);
}

void CGujianEditorDlg::OnBnClickedButton9()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    UpdateItemList(&ResourceItem);
}

void CGujianEditorDlg::OnBnClickedButton10()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    UpdateItemList(&ShoesManItem);
}

void CGujianEditorDlg::OnBnClickedButton11()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    UpdateItemList(&ShoesWomanItem);
}

void CGujianEditorDlg::OnBnClickedButton12()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    UpdateItemList(&StatusItem);
}

void CGujianEditorDlg::OnBnClickedButton13()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    UpdateItemList(&TaskItem);
}

HBRUSH CGujianEditorDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
    HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

    // TODO:  �ڴ˸��� DC ���κ�����
    if(pWnd == this) return m_brBk;
    else
    if(pWnd == &m_ItemList) return m_brLstBk;
    else
    if(pWnd == &m_IntroText)
    {
        pDC->SetBkMode(TRANSPARENT);
        pDC->SetTextColor(RGB(0xff, 0x78, 0x00));
        return m_brIntroBk;
    }

    // TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
    return hbr;
}

void CGujianEditorDlg::OnMouseMove(UINT nFlags, CPoint point)
{
    // TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
    if(point.x >= 565 - 20 && point.x <= 565 && point.y >= 0 && point.y <= 20)
        SetCursor(LoadCursor(NULL, IDC_HAND));

    CDialog::OnMouseMove(nFlags, point);
}

void CGujianEditorDlg::OnLButtonDblClk(UINT nFlags, CPoint point)
{
    // TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

    CDialog::OnLButtonDblClk(nFlags, point);
}

void CGujianEditorDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
    // TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
    CDialog::OnLButtonDown(nFlags, point);
    PostMessage(WM_NCLBUTTONDOWN, HTCAPTION, MAKELPARAM(point.x, point.y));
}

void CGujianEditorDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
    // TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

    CDialog::OnLButtonUp(nFlags, point);
}

void CGujianEditorDlg::OnRButtonDblClk(UINT nFlags, CPoint point)
{
    // TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

    CDialog::OnRButtonDblClk(nFlags, point);
}

void CGujianEditorDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
    // TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

    CDialog::OnRButtonDown(nFlags, point);
}

void CGujianEditorDlg::OnRButtonUp(UINT nFlags, CPoint point)
{
    // TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

    CDialog::OnRButtonUp(nFlags, point);
}

void CGujianEditorDlg::OnBnClickedEditapply()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    TRY {
        int nCnt = m_ItemList.GetCount();

        UpdateData();
        UpdateData(FALSE);

        for(int i = 0; i < nCnt; i++)
        {
            if(m_ItemList.GetSel(i) > 0)
            {
                CString szTmpName;
                CString szTmpStr;
                m_ItemList.GetText(i, szTmpName);
                szTmpStr.Format(L".%d_Item20BK", (*m_pSelectedList)[szTmpName].id);

                int nPos = m_szContent.Find(szTmpStr, 0);
                nPos += szTmpStr.GetLength();

                m_pBuf[nPos] = m_nEditNum;
            }
        }
        MessageBox(L"�޸ĳɹ���");
    }
    CATCH(CException, e) {
        MessageBox(L"������0~255�����֣�");
    }
    END_CATCH;
}

void CGujianEditorDlg::OnBnClickedSavesave()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    if(m_bOpened)
    {
        CTime T;
        T = CTime::GetCurrentTime();
        CString BakFileName = T.Format(L"%Y-%m-%d %H��%M''%S'");
        BakFileName = L"�Ž���̷[" + BakFileName + L"].SAV";

        //MessageBox(m_szPathName + m_szFileName);
        if(CopyFile(m_szPathName + m_szFileName, m_szPathName + BakFileName, true))
        {
            CFile fs;
            CFileException e;
            CString tmp;

            if(fs.Open(m_szPathName + m_szFileName, CFile::modeWrite | CFile::typeBinary | CFile::shareExclusive))
            {
                fs.Write(m_pBuf, m_nLength);
                fs.Close();

                MessageBox(L"�ĵ�����ɹ��������ļ���Ϊ��" + BakFileName, L"�ɹ�");
            }
            else MessageBox(L"�浵����ʧ�ܣ����Ժ����ԡ�", L"����");
        }
        else MessageBox(L"�ļ�����ʧ�ܣ���ʱ�����棬���Ժ����ԡ�", L"����");
    }
    else MessageBox(L"��δ�򿪴浵�ļ���", L"����");
}

void CGujianEditorDlg::OnBnClickedButton2()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    UpdateItemList(&TSWeaponItem);
}

void CGujianEditorDlg::OnBnClickedQxweapon()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    UpdateItemList(&QXWeaponItem);
}

void CGujianEditorDlg::OnBnClickedHyweapon()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    UpdateItemList(&HYWeaponItem);
}

void CGujianEditorDlg::OnBnClickedXlweapon()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    UpdateItemList(&XLWeaponItem);
}

void CGujianEditorDlg::OnBnClickedLsweapon()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    UpdateItemList(&LSWeaponItem);
}

void CGujianEditorDlg::OnBnClickedQsweapon()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    UpdateItemList(&QSWeaponItem);
}

LRESULT CGujianEditorDlg::OnNcHitTest(CPoint point)
{
    // TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
    UINT nHitTest = CDialog::OnNcHitTest(point);

    return (nHitTest == HTCLIENT) ? HTCAPTION : nHitTest;
}

void CGujianEditorDlg::OnBnClickedClose()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    exit(0);
}

void CGujianEditorDlg::OnCancel()
{
    // TODO: �ڴ����ר�ô����/����û���

    //CDialog::OnCancel();
}

void CGujianEditorDlg::OnOK()
{
    // TODO: �ڴ����ר�ô����/����û���

    //CDialog::OnCancel();
}
