// SortButton.cpp : 实现文件
//

#include "stdafx.h"
#include "GujianEditor.h"
#include "SortButton.h"


// CSortButton

IMPLEMENT_DYNAMIC(CSortButton, CButton)

CSortButton::CSortButton()
: m_bPainted(false)
, m_bDown(false)
{
    m_Bmp.LoadBitmapW(IDB_SORT);
    m_BmpClick.LoadBitmapW(IDB_SORTCLICK);
}

CSortButton::~CSortButton()
{
}


BEGIN_MESSAGE_MAP(CSortButton, CButton)
//    ON_WM_PAINT()
    ON_WM_LBUTTONDOWN()
    ON_WM_LBUTTONUP()
    ON_WM_LBUTTONDBLCLK()
    ON_WM_MOUSEMOVE()
//    ON_WM_CTLCOLOR()
//ON_WM_PAINT()
ON_WM_DRAWITEM()
ON_WM_PAINT()
END_MESSAGE_MAP()



// CSortButton 消息处理程序

void CSortButton::OnLButtonDown(UINT nFlags, CPoint point)
{
    // TODO: 在此添加消息处理程序代码和/或调用默认值
    m_bDown = true;
    ::SetCursor(AfxGetApp()->LoadCursorW(IDC_SWORD));

    CButton::OnLButtonDown(nFlags, point);
}

void CSortButton::OnLButtonUp(UINT nFlags, CPoint point)
{
    // TODO: 在此添加消息处理程序代码和/或调用默认值
    m_bDown = false;
    ::SetCursor(AfxGetApp()->LoadCursorW(IDC_SWORD));

    CButton::OnLButtonUp(nFlags, point);
}

void CSortButton::OnLButtonDblClk(UINT nFlags, CPoint point)
{
    // TODO: 在此添加消息处理程序代码和/或调用默认值
    ::SetCursor(AfxGetApp()->LoadCursorW(IDC_SWORD));

    CButton::OnLButtonDblClk(nFlags, point);
}

void CSortButton::OnMouseMove(UINT nFlags, CPoint point)
{
    // TODO: 在此添加消息处理程序代码和/或调用默认值
    ::SetCursor(AfxGetApp()->LoadCursorW(IDC_SWORD));

    CButton::OnMouseMove(nFlags, point);
}

void CSortButton::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
{
    //CButton::OnDrawItem(nIDCtl, lpDrawItemStruct);
    // TODO: 在此添加消息处理程序代码和/或调用默认值

    //CDC *pDC = GetDC();
    //CRect rect(lpDrawItemStruct->rcItem);

    //pDC->DrawText(L"aaa", rect,  DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}

void CSortButton::OnPaint()
{
    CPaintDC dc(this); // device context for painting
    // TODO: 在此处添加消息处理程序代码
    // 不为绘图消息调用 CButton::OnPaint()

    if(!m_bPainted)
    {
        m_U.CreateCompatibleDC(&dc);
        m_U.SelectObject(m_Bmp);
        m_D.CreateCompatibleDC(&dc);
        m_D.SelectObject(m_BmpClick);

        m_bPainted = true;
    }

    if(m_bDown) dc.BitBlt(0, 0, 200, 200, &m_D, 0, 0, SRCCOPY);
    else dc.BitBlt(0, 0, 200, 200, &m_U, 0, 0, SRCCOPY);

    CFont f;
    f.CreateFont(18, 0, 0, 0, FW_NORMAL, FALSE, FALSE, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, L"微软雅黑"); 

    dc.SelectObject(&f);
    CString szTmp;
    this->GetWindowText(szTmp);
    CRect rect(0, 0, 86, 23);
    dc.SetBkMode(TRANSPARENT);
    dc.SetTextColor(RGB(0xff, 0xff, 0xff));
    dc.DrawText(szTmp, rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}
