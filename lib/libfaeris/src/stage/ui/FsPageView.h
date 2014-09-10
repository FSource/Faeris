#ifndef _FS_PAGE_VIEW_H_
#define _FS_PAGE_VIEW_H_

#include "FsMacros.h"
#include "FsUiWidget.h"


NS_FS_BEGIN

class PageViewContentPanel;
class PageView:public UiWidget 
{
	public:
		enum 
		{
			SCROLL_HORIZONTAL,
			SCROLL_VERTICAL,
		};

		enum 
		{
			ALIGN_LEFT,
			ALIGN_RIGHT,
			ALIGN_CENTER,
			ALIGN_TOP,
			ALIGN_BOTTOM,
		};


	public:
		static PageView* create(float width,float height);
		static PageView* create(int mode,float width,float height);

	public:
		void setMode(int mode);
		int getMode();

		void addPage(UiWidget* widget);
		void addPage(UiWidget* widget,int alignh,int alignv);

		void addPage(int index,UiWidget* widget);
		void addPage(int index,UiWidget* widget,int alignh,int alignv);

		void setPageAlign(int index,int alignh,int alignv);
		void setPageAlign(UiWidget* widget,int alignh,int alignv);

		void removePage(UiWidget* widget);
		void removePage(int index);

		void clearPage();

		int getPageNu();
		UiWidget* getPage(int index);
		int getPageIndex(UiWidget* widget);

		void setCurrentPageIndex(int index);
		int getCurrentPageIndex();

		void setCurrentPage(UiWidget* widget);
		UiWidget* getCurrentPage();


	public:
		/* inherit FsObject */
		virtual const char* className();

		/* inherit Entity */
		virtual  bool touchBegin(float x,float y);
		virtual  bool touchMove(float x,float y);
		virtual  bool touchEnd(float x,float y);

		virtual void update(float dt);


		/* inherit UiWidget */

		virtual void childSizeChanged(UiWidget* widget,float w,float h);
		virtual void childAnchorChanged(UiWidget* widget,float w,float h);

		virtual void sizeChanged(float width,float height);
		virtual void anchorChanged(float x,float y);

		virtual void removeWidget(UiWidget* widget);
		virtual void layout();

	protected:
		PageView(int mode,float width,float height);
		virtual ~PageView();

		void adjustContentPanel();

	protected:
		PageViewContentPanel* m_contentPanel;
		int m_currentPageIndex;

};

NS_FS_END 

#endif /*_FS_PAGE_VIEW_H_*/




