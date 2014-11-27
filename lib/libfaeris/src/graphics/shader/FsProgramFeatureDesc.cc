#include "FsProgramFeatureDesc.h"

NS_FS_BEGIN

const char* ProgramFeatureDesc::className()
{
	return "ProgramFeatureDesc";
}

ProgramFeatureDesc* ProgramFeatureDesc::create()
{
	return new ProgramFeatureDesc();
}



ProgramFeatureDesc::ProgramFeatureDesc()
	:m_supportFlags(0),
	m_ambientLightNu(0),
	m_directionalLightNu(0),
	m_pointLightNu(0),
	m_spotLightNu(0),
	m_hemiSphereLightNu(0),
	m_shadowMapNu(0),
	m_shadowType(E_ShadowType::HARD),
	m_boneNu(0)
{
}

ProgramFeatureDesc* ProgramFeatureDesc::clone()
{
	ProgramFeatureDesc* ret=new ProgramFeatureDesc();

	ret->m_supportFlags=this->m_supportFlags;
	ret->m_ambientLightNu=this->m_ambientLightNu;
	ret->m_directionalLightNu=this->m_directionalLightNu;
	ret->m_pointLightNu=this->m_pointLightNu;
	ret->m_spotLightNu=this->m_spotLightNu;
	ret->m_hemiSphereLightNu=this->m_hemiSphereLightNu;


	ret->m_shadowMapNu=this->m_shadowMapNu;
	ret->m_shadowType=this->m_shadowType;

	ret->m_fogType = this->m_fogType;
	ret->m_boneNu=this->m_boneNu;
	return ret;
}




bool ProgramFeatureDesc::equal(ProgramFeatureDesc* l,ProgramFeatureDesc* r,uint32_t flags)
{
	if((l->m_supportFlags&flags)!=(r->m_supportFlags&flags))
	{
		return false;
	}


	uint32_t cp_flags=l->m_supportFlags&flags;

	if(cp_flags&E_ProgramFeatureSupport::AMBIENT_LIGHT&&(l->m_ambientLightNu!=r->m_ambientLightNu))
	{
		return false;
	}

	if(cp_flags&E_ProgramFeatureSupport::DIRECTIONAL_LIGHT
			&&(l->m_directionalLightNu!=r->m_directionalLightNu))
	{
		return false;
	}

	if(cp_flags&E_ProgramFeatureSupport::POINT_LIGHT
			&&(l->m_pointLightNu!=r->m_pointLightNu))
	{
		return false;
	}


	if(cp_flags&E_ProgramFeatureSupport::HEMI_SPHERE_LIGHT
			&&(l->m_hemiSphereLightNu!=r->m_hemiSphereLightNu))
	{
		return false;
	}

	if(cp_flags&E_ProgramFeatureSupport::DIRECTIONAL_LIGHT
			&&(l->m_directionalLightNu!=r->m_directionalLightNu))
	{
		return false;
	}


	if(cp_flags&E_ProgramFeatureSupport::SKELETON
			&&(l->m_boneNu!=r->m_boneNu))
	{
		return false;
	}

	return true;
}








NS_FS_END
