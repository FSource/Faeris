#ifndef _FS_TOUCH_DISPATCHER_H_
#define _FS_TOUCH_DISPATCHER_H_


#include "FsMacros.h"
#include "core/FsObject.h"
#include "scheduler/FsSchedulerTarget.h"
#include "math/FsVector2.h"
#include "util/FsSlowArray.h"

NS_FS_BEGIN

class TouchDispatcher:public  SchedulerTarget
{
	public:
		enum 
		{
			TOUCH_BEGIN,
			TOUCH_MOVE,
			TOUCH_END,
			TOUCH_CANCEL,
			TOUCHES_BEGIN,
			TOUCHES_MOVE,
			TOUCHES_END,
			TOUCHES_CANCEL,
		};
		class TouchEvent 
		{
			public:
				TouchEvent(int type,int x,int y);
				TouchEvent(int type,Vector2* points,int num);
			public:
				int m_type;
				union{
					struct 
					{
						int m_x;
						int m_y;
					};
					struct 
					{
						int m_num;
						Vector2* m_points;
					};
				};
		};

	public:
		typedef  std::vector<TouchEvent*> EventQueue;
	public:
		TouchDispatcher* create();

	public:
		/* inherit SchedulerTarget */
		virtual void update(int priority,float dt);

		/* inherit FsObject */
		const char* className() const ;

	public:
		void dispathTouchEvent(int type,float x,float y);
		void dispathTouchesEvent(int type,Vector2* points,int num);

		void addEventListener(TouchEventListener* l);
		void removeEventListener(TouchEventListener* l);

	protected:
		TouchDispatcher();
		~TouchDispatcher();
		void init();
		void destroy();
		void swapEventQueue();
		void clearEvent(EventQueue* queue);

	private:
		EventQueue* m_eventPending;
		EventQueue* m_eventHandling;

		FsSlowArray* m_listenArray;
};
NS_FS_END
#endif /*_FS_TOUCH_DISPATCHER_H_*/









