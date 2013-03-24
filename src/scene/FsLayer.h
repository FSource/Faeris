#ifndef _FS_LAYER_H_
#define _FS_LAYER_H_

#include "core/FsObject.h"

NS_FS_BEGIN
class Entity;
class Scene;
class Render;
class FsDict;
class Vector2;

class Layer:public FsObject
{
	public:
		/* visible */
		bool visible(){return m_visible;}
		void setVisible(bool visible){m_visible=visible;}

		/* touch enable */
		bool touchEnabled(){return m_touchEnabled;}
		void setTouchEnabled(bool enable){m_touchEnabled=enable;}

		/* entity */
		void add(Entity* entity);
		void remove(Entity* entity);

		/* used for Entity parent change,
		 * user can't direct call this interface */
		void takeOwnership(Entity* entity);
		void dropOwnership(Entity* entity);

		Scene* scene();
	public:
		/* event hook */
		virtual void update(float dt);
		virtual void draw(Render* render);

		/* touch event */
		virtual bool touchBegin(float x,float y);
		virtual bool touchMove(float x,float y);
		virtual bool touchEnd(float x,float y);

		/* touches event */
		virtual bool touchesBegin(Vector2* points,int num);
		virtual bool touchesMove(Vector2* points,int num);
		virtual bool touchesEnd(Vector2* points,int num);

		/* inherit FsObject */
		virtual const char* className();


	protected:
		Layer();
		virtual ~Layer();
		void init();
		void destroy();


	protected:
		FsDict* m_entity;  /* direct add to layer */
		FsDict* m_ownerEntity; /* all sub chirld */
		bool m_visible;
		bool m_touchEnabled;

};
NS_FS_END

#endif /*_FS_LAYER_H_*/

