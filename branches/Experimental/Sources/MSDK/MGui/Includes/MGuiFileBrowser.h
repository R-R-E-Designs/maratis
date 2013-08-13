/////////////////////////////////////////////////////////////////////////////////////////////////////////
// MGui
// MGuiFileBrowser.h
/////////////////////////////////////////////////////////////////////////////////////////////////////////

//========================================================================
// Copyright (c) 2012-2013 Anael Seghezzi <www.maratis3d.com>
//
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would
//    be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such, and must not
//    be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source
//    distribution.
//
//========================================================================

#ifndef _MGUI_FILE_BROWSER_H
#define _MGUI_FILE_BROWSER_H


enum MGUI_FILE_BROWSER_EVENT_TYPE
{
	MGUI_FILE_BROWSER_EVENT_OK = 0,
	MGUI_FILE_BROWSER_EVENT_CANCEL
};

class M_GUI_EXPORT MGuiFileBrowser
{
private:
	
	MFontRef * m_font;
	
	MGuiWindow * m_dirWin;
	MGuiWindow * m_fileWin;
	MGuiWindow * m_headWin;
	MGuiWindow * m_mainWin;
	
	MGuiEditText * m_dirEditText;
	MGuiEditText * m_fileEditText;
	MGuiButton * m_okButton;
	MGuiButton * m_cancelButton;
	
	float m_fileButtonsWidth;
	float m_fileButtonsHeight;
	float m_browserHeight;
	float m_margin;
	
	MVector4 m_headWinColor;
	MVector4 m_mainWinColor;
	MVector4 m_filesWinColor;
	MVector4 m_headTextColor;
	MVector4 m_browserTextColor;
	MVector4 m_buttonColor;
	MVector4 m_highButtonColor;
	MVector4 m_pressButtonColor;
	
	MString m_currentDirectory;
	MString m_currentFile;
	vector <string> m_files;
	
	// events function pointer
	void (* m_eventCallback)(MGuiFileBrowser * fileBrowser, MGUI_FILE_BROWSER_EVENT_TYPE event);
	
	void updateMainWin(void);
	void selectFile(unsigned int id);
	
	static void fileBrowserCancelButtonEvents(MGuiButton * button, MGUI_EVENT_TYPE event);
	static void fileBrowserOkButtonEvents(MGuiButton * button, MGUI_EVENT_TYPE event);
	static void mainWinEvents(MGuiWindow * window, MGUI_EVENT_TYPE event);
	static void dirEditTextEvents(MGuiEditText * editText, MGUI_EVENT_TYPE event);
	
public:
	
	MGuiFileBrowser(MWindow * rootWindow, MFontRef * font);
	~MGuiFileBrowser(void);
	
	void resize(const MVector2 & position, const MVector2 & scale);
	void open(const char * startDirectory = NULL, const char * startFile = NULL, const char * okName = "ok", void (* eventCallback)(MGuiFileBrowser * fileBrowser, MGUI_FILE_BROWSER_EVENT_TYPE guiEvent) = NULL);
	void close(void);
	
	const char * getCurrentDirectory(void){ return m_currentDirectory.getData(); }
	const char * getCurrentFile(void){ return m_currentFile.getData(); }
};

#endif
