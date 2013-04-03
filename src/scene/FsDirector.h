#ifndef _FS_DIRECTOR_H_
#define _FS_DIRECTOR_H_
#include "FsMacros.h"
#include "scheduler/FsSchedulerTarget.h"

NS_FS_BEGIN
class Scene;
class DirectorTouchEventListener;
class FsArray;
class Vector2;
class Render;
class Director :public SchedulerTarget
{
	public:
		static Director* create();

	public:
		/* inherit FsObject */
		virtual const char* className();

		/* inherit SchedulerTarget */
		virtual void update(int priority,float dt);

	public:
		void push();
		void pop();

		void run(Scene*  scene);

		void pause();
		void start();

		bool isRunning();

	protected:
		Director();
		~Director();
		void init();
		void destroy();
		void repace(Scene* scene);

		void draw();
		void update(float dt);
		void touchEvent(int type,float x,float y);
		void touchesEvent(int type,Vector2* points,int num);

	private:
		Scene* m_current;
		FsArray* m_secenQueue;
		bool m_stop;
		DirectorTouchEventListener* m_touchEventListener;

		friend DirectorTouchEventListener;
};


NS_FS_END 

#endif /*_FS_DIRECTOR_H_*/
