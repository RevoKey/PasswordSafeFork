/*
* Copyright (c) 2003-2009 Rony Shapiro <ronys@users.sourceforge.net>.
* All rights reserved. Use of the code is allowed under the
* Artistic License 2.0 terms, as specified in the LICENSE file
* distributed with this code, or available from
* http://www.opensource.org/licenses/artistic-license-2.0.php
*/

#include "DboxMain.h"
#include "PWPropertyPage.h"

#if defined(POCKET_PC)
#error "TBD - define proper PropertyPage base class for PPC"
#endif

extern const TCHAR *EYE_CATCHER;

IMPLEMENT_DYNAMIC(CPWPropertyPage, CPropertyPage)

LRESULT CPWPropertyPage::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
  // list of all the events that signify actual user activity, as opposed
  // to Windows internal events...
  if (message == WM_KEYDOWN ||
      message == WM_COMMAND ||
      message == WM_SYSCOMMAND ||
      message == WM_MOUSEMOVE ||
      message == WM_MOVE ||
      message == WM_LBUTTONDOWN ||
      message == WM_LBUTTONDBLCLK ||
      message == WM_CONTEXTMENU ||
      message == WM_MENUSELECT ||
      message == WM_VSCROLL ||
      message == WM_HSCROLL) {
    CWnd *p = GetParent();
    while (p != NULL) {
      DboxMain *pDbx = dynamic_cast<DboxMain *>(p);
      if (pDbx != NULL && pDbx->m_eye_catcher != NULL &&
          _tcscmp(pDbx->m_eye_catcher, EYE_CATCHER) == 0) {
        pDbx->ResetIdleLockCounter();
        break;
      } else
        p = p->GetParent();
    }
    if (p == NULL)
      TRACE(_T("CPWPropertyPage::WindowProc - couldn't find DboxMain ancestor\n"));
  }
  return CPropertyPage::WindowProc(message, wParam, lParam);
}
