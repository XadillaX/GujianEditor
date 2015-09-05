// MyButton.cpp : 实现文件
//

#include "stdafx.h"
#include "GujianEditor.h"
#include "MyButton.h"


// CMyButton

IMPLEMENT_DYNAMIC(CMyButton, CButton)

CMyButton::CMyButton(UINT U, UINT D)
: m_bPainted(false)
{
    m_U.LoadBitmapW(U);
    m_D.LoadBitmapW(D);
}

CMyButton::~CMyButton()
{
}


BEGIN_MESSAGE_MAP(CMyButton, CButton)
    ON_WM_LBUTTONDOWN()
    ON_WM_LBUTTONUP()
    ON_WM_MOUSEMOVE()
//    ON_WM_MOUSEHOVER()
//    ON_WM_CREATE()
ON_WM_PAINT()
ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()



// CMyButton 消息处理程序
void CMyButton::OnLButtonDown(UINT nFlags, CPoint point)
{
    // TODO: 在此添加消息处理程序代码和/或调用默认值
    ::SetCursor(AfxGetApp()->LoadCursorW(IDC_SWORD));
    SetBitmap(m_D);

    CButton::OnLButtonDown(nFlags, point);
}

void CMyButton::OnLButtonUp(UINT nFlags, CPoint point)
{
    // TODO: 在此添加消息处理程序代码和/或调用默认值
    ::SetCursor(AfxGetApp()->LoadCursorW(IDC_SWORD));
    SetBitmap(m_U);

    CButton::OnLButtonUp(nFlags, point);
}

void CMyButton::OnMouseMove(UINT nFlags, CPoint point)
{
    // TODO: 在此添加消息处理程序代码和/或调用默认值
    ::SetCursor(AfxGetApp()->LoadCursorW(IDC_SWORD));

    CButton::OnMouseMove(nFlags, point);
}

void CMyButton::OnPaint()
{
    //CPaintDC dc(this); // device context for painting
    // TODO: 在此处添加消息处理程序代码
    // 不为绘图消息调用 CButton::OnPaint()
    CButton::OnPaint();

    if(!m_bPainted)
    {
        SetBitmap(m_U);
        m_bPainted = true;
    }
}

void CMyButton::OnLButtonDblClk(UINT nFlags, CPoint point)
{
    // TODO: 在此添加消息处理程序代码和/或调用默认值
    ::SetCursor(AfxGetApp()->LoadCursorW(IDC_SWORD));

    CButton::OnLButtonDblClk(nFlags, point);
}
