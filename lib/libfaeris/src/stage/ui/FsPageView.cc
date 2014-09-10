#include "FsPageView.h"


NS_FS_BEGIN

class PageViewContentPanel: public Entity
{
	protected:
		class PageViewItemInfo:public FsObject 
	{

		public:
			static PageViewItemInfo* create(int alignh,int alignv,UiWidget* widget)
			{
				return new PageViewItemInfo(alignh,alignv,widget);
			}

		public:
			virtual const char* className()
			{
				return "PageViewItemInfo";
			}


		public:
			int m_alignH;
			int m_alignV;
			UiWidget* m_widget;


		protected:
			PageViewItemInfo(int alignh,int alignv,UiWidget* widget)
			{
				m_alignH=alignh;
				m_alignV=alignv;
				m_widget=widget;
				FS_SAFE_ADD_REF(widget);
			}
			~PageViewItemInfo()
			{
				FS_SAFE_DEC_REF(m_widget);
			}
	};



	protected:
		FsArray* m_pageItem;
		int m_mode;
		float m_width;
		float m_height;

	public:
		static PageViewContentPanel* create(int mode,float width,float height)
		{
			PageViewContentPanel* ret=new PageViewContentPanel(mode,width,height);
			return ret;
		}


	protected:
		PageViewContentPanel(int mode,float width,float height)
		{
			m_mode=mode;
			m_width=width;
			m_height=height;
			setTouchEnabled(true);
			setDispatchTouchEnabled(true);
			m_pageItem=FsArray::create();
		}

		~PageViewContentPanel()
		{
			FS_SAFE_DEC_REF(m_pageItem);
		}


	public:
		void addPageItem(UiWidget* widget,int alignh,int alignv)
		{
			int index=m_pageItem->size();
			addPageItem(index,widget,alignh,alignv);
		}

		void addPageItem(int index,UiWidget* widget,int alignh,int alignv)
		{
			PageViewItemInfo* item=PageViewItemInfo::create(alignh,alignv,widget);

			if(index>(int)m_pageItem->size())
			{
				index=m_pageItem->size();
			}

			m_pageItem->insert(index,item);
			layout();
		}

		void removePageItem(UiWidget* widget)
		{
			int index=getPageItemIndex(widget);
			removePageItem(index);
		}

		void removePageItem(int index)
		{
			m_pageItem->remove(index);
			layout();
		}

		void clearPageItem()
		{
			m_pageItem->clear();
		}

		int getPageItemNu()
		{
			return m_pageItem->size();
		}

		void setMode(int mode)
		{
			m_mode=mode;
			layout();
		}

		int getMode()
		{
			return m_mode;
		}
		void setSize(float width,float height)
		{
			m_width=width;
			m_height=height;
			layout();
		}



		void setPageItemAlign(UiWidget* widget)
		{
			int index=getPageItemIndex(widget);
			PageViewItemInfo* item=(PageViewItemInfo*) m_pageItem->get(index);
			setPageItemAlign(index,item->m_alignH,item->m_alignV);
		}

		void setPageItemAlign(UiWidget* widget,int alignh,int alignv)
		{
			int index=getPageItemIndex(widget);
			setPageItemAlign(index,alignh,alignv);
		}

		void setPageItemAlign(int index,int alignh,int alignv)
		{
			setPageItemAlign(m_mode,index,alignh,alignv);
		}

		void setPageItemAlign(int mode,int index,int alignh,int alignv)
		{
			PageViewItemInfo* item=(PageViewItemInfo*) m_pageItem->get(index);
			float start_x,start_y;
			if(mode==PageView::SCROLL_HORIZONTAL)
			{
				start_x=m_width*index;
				start_y=0;
			}
			else 
			{
				start_x=0;
				start_y=-m_height*index;
			
			}

			float sminx,smaxx,sminy,smaxy;
			item->m_widget->getRSBoundSize2D(&sminx,&smaxx,&sminy,&smaxy);
			switch(alignh)
			{
			
				case PageView::ALIGN_LEFT:
					item->m_widget->setPositionX(start_x-sminx);
					break;
				
				case PageView::ALIGN_CENTER:
					item->m_widget->setPositionX(start_x+m_width/2-(sminx+smaxx)/2);
					break;

				case PageView::ALIGN_RIGHT:
					item->m_widget->setPositionX(start_y+m_width-smaxx);
					break;
				default:
					FS_TRACE_WARN("Unkown ALign For Page Item");
			}

			switch(alignv)
			{
				case PageView::ALIGN_TOP:
					item->m_widget->setPositionY(start_y-smaxy);
					break;

				case PageView::ALIGN_CENTER:
					item->m_widget->setPositionY(start_y-m_height/2-(smaxy+sminy)/2);
					break;

				case PageView::ALIGN_BOTTOM:
					item->m_widget->setPositionY(start_y-m_height-sminy);
					break;

				default:
					FS_TRACE_WARN("Unkown ALign For Page Item");
			}
		}


		UiWidget* getPageItem(int index)
		{
			PageViewItemInfo* item=(PageViewItemInfo*) m_pageItem->get(index);
			return item->m_widget;
		
		}


		int getPageItemAlignH(int index)
		{
			PageViewItemInfo* item=(PageViewItemInfo*) m_pageItem->get(index);
			return item->m_alignH;
		}

		int getPageItemAlignV(int index)
		{
			PageViewItemInfo* item=(PageViewItemInfo*) m_pageItem->get(index);
			return item->m_alignV;
		}


		int getPageItemIndex(UiWidget* widget)
		{
			int size=m_pageItem->size();
			for(int i=0;i<size;i++)
			{
				PageViewItemInfo* item=(PageViewItemInfo*)m_pageItem->get(i);
				if(item->m_widget==widget)
				{
					return i;
				}
			}
			return -1;
		}

	public:
		virtual bool hit2D(float x,float y){return true;}

		void layout()
		{
			int size=m_pageItem->size();
			for(int i=0;i<size;i++)
			{
				PageViewItemInfo* item=(PageViewItemInfo*) m_pageItem->get(i);
				setPageItemAlign(i,item->m_alignH,item->m_alignV);
			}
		}
};


const char* PageView::className()
{
	return FS_PAGE_VIEW_CLASS_NAME;
}

PageView* PageView::create(int mode,float width,float height)
{
	PageView* ret=new PageView(mode,width,height);
	return ret;
}


PageView* PageView::create(float width,float height)
{
	PageView* ret=new PageView(SCROLL_HORIZONTAL,width,height);
	return ret;
}

PageView::PageView(int mode,float w,float h)
{
	m_contentPanel=PageViewContentPanel::create(mode,w,h);
	FS_NO_REF_DESTROY(m_contentPanel);
	addChild(m_contentPanel);
	setMode(mode);

	setSize(w,h);
	setScissorEnabled(true);

}

PageView::~PageView()
{
	int size=m_contentPanel->getPageItemNu();

	for(int i=0;i<size;i++)
	{
		UiWidget* widget=m_contentPanel->getPageItem(i);
		widget->setParentWidget(NULL);
	}

	remove(m_contentPanel);
	FS_SAFE_DESTROY(m_contentPanel);
}





void PageView::setMode(int mode)
{
	m_contentPanel->setMode(mode);
}

int PageView::getMode()
{
	return m_contentPanel->getMode();
}

void PageView::addPage(UiWidget* widget)
{
	addPage(widget,ALIGN_CENTER,ALIGN_CENTER);
}

void PageView::addPage(UiWidget* widget,int alignh,int alignv)
{
	int size=m_contentPanel->getPageItemNu();

	addPage(size,widget,alignh,alignv);
}

void PageView::addPage(int index,UiWidget* widget)
{
	addPage(index,widget,ALIGN_CENTER,ALIGN_CENTER);
}

void PageView::addPage(int index,UiWidget* widget,int alignh,int alignv)
{
	if(widget->getParentWidget()==this)
	{
		FS_TRACE_WARN("widget Alread Add to ListView");
		return;
	}
	if(widget->getParentWidget())
	{
		FS_TRACE_WARN("widget Alread Add to Other Widget");
		return;
	}

	if(widget)
	{
		m_contentPanel->addPageItem(index,widget,alignh,alignv);
		m_contentPanel->addChild(widget);
		widget->setParentWidget(this);
	}

}

void PageView::setPageAlign(int index,int alignh,int alignv)
{
	m_contentPanel->setPageItemAlign(index,alignh,alignv);
}

void PageView::setPageAlign(UiWidget* widget,int alignh,int alignv)
{
	m_contentPanel->setPageItemAlign(widget,alignh,alignv);
}

void PageView::removePage(int index)
{
	UiWidget* widget=m_contentPanel->getPageItem(index);
	removePage(widget);

}

void PageView::removePage(UiWidget* widget)
{
	if(widget->getParentWidget()!=this)
	{
		FS_TRACE_WARN("Widget Is Not Add to PageView");
		return;
	}
	widget->setParentWidget(NULL);
	m_contentPanel->removePageItem(widget);
	m_contentPanel->remove(widget);
}


void PageView::clearPage()
{

}

int PageView::getPageNu()
{
	return m_contentPanel->getPageItemNu();
}

UiWidget* PageView::getPage(int index)
{
	return m_contentPanel->getPageItem(index);
}

int PageView::getPageIndex(UiWidget* widget)
{
	return m_contentPanel->getPageItemIndex(widget);
}

void PageView::setCurrentPageIndex(int index)
{

}

int PageView::getCurrentPageIndex()
{
	return m_currentPageIndex;
}

void PageView::setCurrentPage(UiWidget* widget)
{
	int size=m_contentPanel->getPageItemNu();

	for(int i=0;i<size;i++)
	{
		UiWidget* widget=m_contentPanel->getPageItem(i);
		widget->setParentWidget(NULL);
		m_contentPanel->remove(widget);
	}
	m_contentPanel->clearPageItem();
}

UiWidget* PageView::getCurrentPage()
{
	return m_contentPanel->getPageItem(m_currentPageIndex);
}


bool  PageView::touchBegin(float x,float y)
{
	return true;
}

bool  PageView::touchMove(float x,float y)
{
	return true;
}

bool PageView::touchEnd(float x,float y)
{
	return true;
}

void PageView::update(float dt)
{
}

void PageView::childSizeChanged(UiWidget* widget,float w,float h)
{
	m_contentPanel->setPageItemAlign(widget);
}

void PageView::childAnchorChanged(UiWidget* widget,float w,float h)
{
	m_contentPanel->setPageItemAlign(widget);
}

void PageView::sizeChanged(float width,float height)
{
	m_contentPanel->setSize(width,height);

	adjustContentPanel();
}
void PageView::anchorChanged(float x,float y)
{
	adjustContentPanel();
}

void PageView::removeWidget(UiWidget* widget)
{
	removePage(widget);
}


void PageView::layout()
{
	adjustContentPanel();

}
void PageView::adjustContentPanel()
{

}










NS_FS_END 



