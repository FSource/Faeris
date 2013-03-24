#ifndef _TOLUA_HACK_H_
#define _TOLUA_HACK_H_

#include "tolua++.h"


namespace Faeris
{
	class FsObject;
}

TOLUA_API void toluaext_open(lua_State* L);

/* fs object */
TOLUA_API void toluaext_fsobject(lua_State* l,const char* name);


TOLUA_API void toluaext_pushfsobject(lua_State* l,Faeris::FsObject* ob);

/* lua function */
TOLUA_API int toluaext_is_luafunction(lua_State* L,
		int lo,
		const char* type,
		int def,
		tolua_Error* err);


TOLUA_API int  toluaext_to_luafunction(lua_State* L,int lo,int def);
TOLUA_API void toluaext_push_luafunction(lua_State* L,int refid);
TOLUA_API void toluaext_remove_luafunction(lua_State* L,int refid);


/* lua table */
TOLUA_API int  toluaext_is_luatable(lua_State* L,
		int lo,
		const char* type,
		int def,
		tolua_Error* err);

TOLUA_API int  toluaext_to_luatable(lua_State* L,int lo,int def);
TOLUA_API void toluaext_remove_luatable(lua_State* L,int refid);
TOLUA_API void toluaext_push_luatable(lua_State* L,int refid);




#endif /*_TOLUA_HACK_H_*/

