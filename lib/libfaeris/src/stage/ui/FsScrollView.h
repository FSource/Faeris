/*************************************************************************/
/*  FsScrollView.h                                                       */
/*************************************************************************/
/* Copyright (C) 2012-2014 nosiclin@foxmail.com                          */
/* Copyright (C) 2014-2015 www.fsource.cn                                */
/*                                                                       */
/* http://www.fsource.cn                                                 */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/


#ifndef _FS_SCROLL_VIEW_H_
#define _FS_SCROLL_VIEW_H_

#include "FsMacros.h"
#include "FsScrollWidget.h"


NS_FS_BEGIN

class ScrollView:public ScrollWidget 
{
	public:
		FS_CLASS_DECLARE(ScrollView);

	public:
		static ScrollView* create();
		static ScrollView* create(float width,float height);

	public:
		void setContentWidget(UiWidget* widget);
		UiWidget* getContentWidget();

	public:
		void addChild(Entity* en) FS_OVERRIDE;
		void clearChild() FS_OVERRIDE;
		void removeChild(Entity* en) FS_OVERRIDE;
		Entity* getChildByName(const char* name,bool reverse=false) FS_OVERRIDE;

	protected:
		void layoutContentWidget(float x,float y) FS_OVERRIDE;

	protected:
		ScrollView();
		ScrollView(float width,float height);
		virtual ~ScrollView();



	private:
		UiWidget* m_contentWidget;

};


NS_FS_END



#endif /*_FS_SCROLL_VIEW_H_*/