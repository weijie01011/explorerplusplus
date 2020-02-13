// Copyright (C) Explorer++ Project
// SPDX-License-Identifier: GPL-3.0-only
// See LICENSE in the top level directory

#pragma once

#include "../Helper/BaseDialog.h"
#include "../Helper/DialogSettings.h"
#include "../Helper/ResizableDialog.h"
#include <wil/resource.h>
#include <MsXml2.h>
#include <objbase.h>
#include <list>
#include <string>

__interface IExplorerplusplus;
class WildcardSelectDialog;

class WildcardSelectDialogPersistentSettings : public DialogSettings
{
public:

	static			WildcardSelectDialogPersistentSettings &GetInstance();

private:

	friend			WildcardSelectDialog;

	static const	TCHAR SETTINGS_KEY[];

	static const	TCHAR SETTING_PATTERN_LIST[];
	static const	TCHAR SETTING_CURRENT_TEXT[];

	WildcardSelectDialogPersistentSettings();

	WildcardSelectDialogPersistentSettings(const WildcardSelectDialogPersistentSettings &);
	WildcardSelectDialogPersistentSettings & operator=(const WildcardSelectDialogPersistentSettings &);

	void			SaveExtraRegistrySettings(HKEY hKey);
	void			LoadExtraRegistrySettings(HKEY hKey);

	void			SaveExtraXMLSettings(IXMLDOMDocument *pXMLDom, IXMLDOMElement *pParentNode);
	void			LoadExtraXMLSettings(BSTR bstrName, BSTR bstrValue);

	TCHAR			m_szPattern[256];
	std::list<std::wstring>	m_PatternList;
};

class WildcardSelectDialog : public BaseDialog
{
public:

	WildcardSelectDialog(HINSTANCE hInstance, HWND hParent, BOOL bSelect, IExplorerplusplus *pexpp);

protected:

	INT_PTR	OnInitDialog();
	INT_PTR	OnCommand(WPARAM wParam,LPARAM lParam);
	INT_PTR	OnClose();

private:

	void				GetResizableControlInformation(BaseDialog::DialogSizeConstraint &dsc, std::list<ResizableDialog::Control_t> &ControlList);
	void				SaveState();

	void				OnOk();
	void				OnCancel();
	void				SelectItems(TCHAR *szPattern);

	IExplorerplusplus	*m_pexpp;
	BOOL				m_bSelect;

	wil::unique_hicon	m_icon;

	WildcardSelectDialogPersistentSettings	*m_pwsdps;
};