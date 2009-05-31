/*
 * Copyright (c) 2003-2009 Rony Shapiro <ronys@users.sourceforge.net>.
 * All rights reserved. Use of the code is allowed under the
 * Artistic License 2.0 terms, as specified in the LICENSE file
 * distributed with this code, or available from
 * http://www.opensource.org/licenses/artistic-license-2.0.php
 */

/** \file mainEdit.cpp
 *  This file contains implementations of PasswordSafeFrame
 *  member functions corresponding to actions under the 'Edit'
 *  menubar menu.
 */

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "PWSgrid.h"
#include "PWStree.h"

#include "passwordsafeframe.h"
#include "pwsclip.h"


/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_EDIT
 */

void PasswordSafeFrame::OnEditClick( wxCommandEvent& event )
{
////@begin wxEVT_COMMAND_MENU_SELECTED event handler for ID_EDIT in PasswordSafeFrame.
  // Before editing this code, remove the block markers.
  wxMessageBox(_("Edit Entry placeholder"));
////@end wxEVT_COMMAND_MENU_SELECTED event handler for ID_EDIT in PasswordSafeFrame. 
}


/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_CLEARCLIPBOARD
 */

void PasswordSafeFrame::OnClearclipboardClick( wxCommandEvent& event )
{
  PWSclip::ClearData();
}


/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_COPYPASSWORD
 */

void PasswordSafeFrame::OnCopypasswordClick( wxCommandEvent& event )
{
  const CItemData *item = GetSelectedEntry();
  if (item != NULL)
    PWSclip::SetData(item->GetPassword());
}


/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_COPYUSERNAME
 */

void PasswordSafeFrame::OnCopyusernameClick( wxCommandEvent& event )
{
  const CItemData *item = GetSelectedEntry();
  if (item != NULL)
    PWSclip::SetData(item->GetUser());
}


/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_COPYNOTESFLD
 */

void PasswordSafeFrame::OnCopynotesfldClick( wxCommandEvent& event )
{
  const CItemData *item = GetSelectedEntry();
  if (item != NULL)
    PWSclip::SetData(item->GetNotes());
}


/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_COPYURL
 */

void PasswordSafeFrame::OnCopyurlClick( wxCommandEvent& event )
{
  const CItemData *item = GetSelectedEntry();
  if (item != NULL)
    PWSclip::SetData(item->GetURL());
}
