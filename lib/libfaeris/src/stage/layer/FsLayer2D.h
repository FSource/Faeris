#ifndef _FS_LAYER_2D_
#define _FS_LAYER_2D_

#include <vector>

#include "FsMacros.h"
#include "stage/layer/FsLayer.h"
#include "math/FsMatrix4.h"
#include "math/FsVector2.h"
#include "math/FsRect2D.h"
NS_FS_BEGIN
class FsArray;
class Layer2D:public Layer
{
public:
	enum 
	{
		SORT_NONE,
		SORT_ORDER_Z,
		SORT_Y,
	};
	public:
		static Layer2D* create();

	public:
		Rect2D getViewArea()const;


		void setViewArea(float x,float y,float width,float height);
		void getViewArea(float* x,float* y,float* width,float* height);
		void setViewArea(const Rect2D& area);

		void setSortMode(int mode);
		int getSortMode();

		/* eliminate */
		void setEliminate(bool eliminate);
		bool getEliminate();



	public:
		/* inherit  Layer */
		virtual void draw(Render *r);
		virtual Matrix4 getProjectMatrix();
		virtual Vector3 toLayerCoord(const Vector3& v);
		void toLayerCoord(float* x,float* y);

		/* inherit FsObject */
		virtual const char* className();

	protected:
		void getEntityInView(std::vector<Entity*>* entitys);
		void sortEntity(std::vector<Entity*>* entitys);

		Layer2D();
		~Layer2D();

	protected:
		Rect2D m_viewArea;
		int m_sortMode;
		bool m_eliminate;
};


NS_FS_END





#endif 
