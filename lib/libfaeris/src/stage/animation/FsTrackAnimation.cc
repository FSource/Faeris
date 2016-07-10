#include "FsTrackAnimation.h"
#include "FsClass.h"
#include "FsKeyFrame.h"


NS_FS_BEGIN

void TrackAnimation::update(Animator* at,float time,float dt) 
{
}


float TrackAnimation::getTimeLength()
{
	return m_totalTime;
}

void TrackAnimation::setLerpMode(E_LerpMode mode)
{
	m_lerpMode=mode;
}

E_LerpMode TrackAnimation::getLerpMode() const
{
	return m_lerpMode;
}

void TrackAnimation::insertKeyFrame(KeyFrame* frame)
{
	float time=frame->getTime();
	int index=getNearBeforeIndex(time);

	if(index!=-1)
	{
		KeyFrame* old=m_keyFrames[index];
		if(old->getTime()==time)
		{
			m_keyFrames[index]=frame;
			delete old;
			calTotoalTime();
			return;
		}
	}

	int insert_index=index+1;
	m_keyFrames.insert(m_keyFrames.begin()+insert_index,frame);
	calTotoalTime();
}

void TrackAnimation::removeTime(float time)
{
	int index=getNearBeforeIndex(time);
	if(index!=-1)
	{
		KeyFrame* old=m_keyFrames[index];
		if(old->getTime()==time)
		{
			m_keyFrames.erase(m_keyFrames.begin()+index);
		}
	}

	calTotoalTime();

}

void TrackAnimation::removeRange(float begin,float end)
{
	int before=getNearBeforeIndex(begin);
	int after=getNearAfterIndex(end);

	for(int i=after;i>=before;i--)
	{
		int size=m_keyFrames.size();
		if(i<size)
		{
			KeyFrame* frame=m_keyFrames[i];
			float time=frame->getTime();
			if(time>=begin&&time<=end)
			{
				m_keyFrames.erase(m_keyFrames.begin()+i);
				delete frame;
			}
		}
	}
	calTotoalTime();
}


int TrackAnimation::getKeyFrameNu()
{
	return m_keyFrames.size();
}


KeyFrame* TrackAnimation::getKeyFrame(int index)
{
	FS_ASSERT(index>=0&&index<(int)m_keyFrames.size());
	return m_keyFrames[index];
}

void TrackAnimation::clearKeyFrame()
{
	int size=m_keyFrames.size();
	for(int i=0;i<size;i++)
	{
		delete m_keyFrames[i];
	}
	m_keyFrames.clear();
}

TrackAnimation::TrackAnimation()
{
	m_lerpMode=E_LerpMode::SMOOTH;
	m_totalTime=0;
}


TrackAnimation::~TrackAnimation()
{
	clearKeyFrame();
}


int TrackAnimation::getNearBeforeIndex(float time)
{
	int size=m_keyFrames.size();
	int index=-1;

	for(int i=0;i<size;i++)
	{
		if(m_keyFrames[i]->getTime()<=time)
		{
			index=i;
		}
		else 
		{
			break;
		}
	}
	return index;
}

int TrackAnimation::getNearAfterIndex(float time)
{
	int size=m_keyFrames.size();
	int index=-1;
	for(int i=0;i<size;i++)
	{
		if(m_keyFrames[i]->getTime()<time)
		{
			index=i;
		}
		else 
		{
			break;
		}
	}
	return index+1;
}

void TrackAnimation::calTotoalTime()
{
	if(m_keyFrames.size()>0)
	{
		m_totalTime=m_keyFrames[m_keyFrames.size()-1]->getTime();
	}
	else 
	{
		m_totalTime=0;
	}
}


void TrackAnimation::getNearKeyFrame(float time,KeyFrame** prev,KeyFrame** next)
{
	int pre_index=getNearBeforeIndex(time);
	int next_index=getNearAfterIndex(time);
	if(pre_index==-1)
	{
		*prev=NULL;
	}
	else 
	{
		*prev=m_keyFrames[pre_index];
	}


	if(next_index==(int) m_keyFrames.size())
	{
		*next=NULL;
	}
	else 
	{
		*next=m_keyFrames[next_index];
	}
}

std::vector<KeyFrame*>  TrackAnimation::getKeyFrame(float begin,float end)
{
	int pre_index=getNearAfterIndex(begin);
	int next_index=getNearBeforeIndex(end);

	std::vector<KeyFrame*> ret;

	for(int i=pre_index;i<=next_index;i++)
	{
		ret.push_back(m_keyFrames[i]);
	}

	return ret;
}



/** Used For TrackAnimation Attribute */
FS_CLASS_ATTR_SET_GET_ENUM_CHAR_FUNCTION(TrackAnimation,setLerpMode,getLerpMode,LerpMode);

static FsClass::FsAttributeDeclare S_TrackAnimation_Main_Attr[]={
	FS_CLASS_ATTR_DECLARE("lerpMode",E_FsType::FT_CHARS,NULL,TrackAnimation_setLerpMode,TrackAnimation_getLerpMode),
	FS_CLASS_ATTR_DECLARE(NULL,E_FsType::FT_IN_VALID,NULL,0,0)
};

FS_CLASS_IMPLEMENT_WITH_BASE(TrackAnimation,Animation,0,S_TrackAnimation_Main_Attr);




NS_FS_END