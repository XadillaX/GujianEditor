#pragma once
#include "afxwin.h"


// CSortButton

class CSortButton : public CButton
{
	DECLARE_DYNAMIC(CSortButton)

public:
	CSortButton();
	virtual ~CSortButton();

protected:
	DECLARE_MESSAGE_MAP()
public:
    CBitmap m_Bmp;
    CBitmap m_BmpClick;
    bool m_bPainted;
//    afx_msg void OnPaint();
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
    afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
//    afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
    bool m_bDown;
//    afx_msg void OnPaint();
    CDC m_U;
    CDC m_D;
    afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
    afx_msg void OnPaint();
};


