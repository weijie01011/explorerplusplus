// Copyright (C) Explorer++ Project
// SPDX-License-Identifier: GPL-3.0-only
// See LICENSE in the top level directory

#pragma once

#include "BookmarkContextMenuController.h"
#include "BookmarkHelper.h"
#include "BookmarkItem.h"
#include "BookmarkTree.h"

__interface IExplorerplusplus;

class BookmarkContextMenu
{
public:

	BookmarkContextMenu(BookmarkTree *bookmarkTree, HMODULE resourceModule, IExplorerplusplus *expp);

	BOOL ShowMenu(HWND parentWindow, BookmarkItem *parentFolder, const RawBookmarkItems &bookmarkItems,
		const POINT &ptScreen, bool recursive = false);
	bool IsShowingMenu() const;

private:

	void SetUpMenu(HMENU menu, const RawBookmarkItems &bookmarkItems);
	void SetMenuItemStates(HMENU menu);

	BookmarkTree *m_bookmarkTree;
	HMODULE m_resourceModule;
	IExplorerplusplus *m_expp;
	BookmarkContextMenuController m_controller;
	bool m_showingMenu;
};