/*
 This file is part of gbpablog.
 
 gbpablog is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 gbpablog is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with gbpablog.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __BASERENDERER_H__
#define __BASERENDERER_H__

#include <wx/wx.h>
#include <wx/dnd.h>
#include "Def.h"
#include "../IGBScreenDrawable.h"


/*******************************************************************************
 * RendererBase Class
 *******************************************************************************/

class RendererBase: public IGBScreenDrawable {
private:
	wxWindow * renderer;
	int  selPalette;
	
protected:
	BYTE * imgBuf;
	
public:
	RendererBase(wxWindow * renderer, wxWindow * parent);
	~RendererBase();
	
	void CreateScreen();
	void ChangeSize();
	void ChangePalette(bool original);
	
	void OnClear();
	void OnRefreshScreen();
	void OnPreDraw();
	void OnPostDraw();
	void OnDrawPixel(int idColor, int x, int y);
};

// A drop target that adds filenames to a list box
class DnDFile : public wxFileDropTarget {
public:
	DnDFile(wxWindow *parent);
	virtual bool OnDropFiles(wxCoord x, wxCoord y, const wxArrayString& filenames);
private:
	wxWindow *parent;
};

#endif
