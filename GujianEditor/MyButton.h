#pragma once
#include "afxwin.h"


// CMyButton

class CMyButton : public CButton
{
	DECLARE_DYNAMIC(CMyButton)

public:
	CMyButton(UINT U, UINT D);
	virtual ~CMyButton();

protected:
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
//    afx_msg void OnMouseHover(UINT nFlags, CPoint point);
    CBitmap m_U;
    CBitmap m_D;
//    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnPaint();
    bool m_bPainted;
    afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};


