/*
** Lua binding: FsLibLuaScript
** Generated automatically by tolua++-1.0.92 on 02/19/14 12:55:50.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_FsLibLuaScript_open (lua_State* tolua_S);


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
}

/* Open function */
TOLUA_API int tolua_FsLibLuaScript_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);

  { /* begin embedded lua code */
   int top = lua_gettop(tolua_S);
   static const unsigned char B[] = {
    10,102,117,110, 99,116,105,111,110, 32,102, 95,116, 97, 98,
    108,101,116,111,115,116,114,105,110,103, 40,116, 44,112,114,
    101,102,105,120, 41, 10,105,102, 32,110,111,116, 32,112,114,
    101,102,105,120, 32,116,104,101,110, 10,112,114,101,102,105,
    120, 61, 34, 34, 10,101,110,100, 10,108,111, 99, 97,108, 32,
    114,101,115,117,108,116, 61, 34, 34, 10,102,111,114, 32,107,
     44,118, 32,105,110, 32,112, 97,105,114,115, 40,116, 41, 32,
    100,111, 10,108,111, 99, 97,108, 32,107,101,121, 95,116,121,
    112,101, 61,116,121,112,101, 40,107, 41, 10,108,111, 99, 97,
    108, 32,118, 97,108,117,101, 95,116,121,112,101, 61,116,121,
    112,101, 40,118, 41, 10,108,111, 99, 97,108, 32,107,101,121,
     95,115,116,114, 10,108,111, 99, 97,108, 32,118, 97,108,117,
    101, 95,115,116,114, 10,105,102, 32,107,101,121, 95,116,121,
    112,101, 32, 61, 61, 32, 34,115,116,114,105,110,103, 34, 32,
    116,104,101,110, 10,107,101,121, 95,115,116,114, 32, 61, 32,
     34, 92, 91, 92, 34, 34, 46, 46,102, 95,101,115, 99,115,116,
    114,105,110,103, 40,107, 41, 46, 46, 34, 92, 34, 92, 93, 34,
     10,101,108,115,101,105,102, 32,107,101,121, 95,116,121,112,
    101, 32, 61, 61, 32, 34,110,117,109, 98,101,114, 34, 32,116,
    104,101,110, 10,107,101,121, 95,115,116,114, 32, 61, 32, 34,
     92, 91, 34, 46, 46,116,111,115,116,114,105,110,103, 40,107,
     41, 46, 46, 34, 92, 93, 34, 10,101,108,115,101, 10,101,114,
    114,111,114, 40,115,116,114,105,110,103, 46,102,111,114,109,
     97,116, 40, 34,107,101,121, 32,102,111,114, 32, 37,115, 32,
    110,111,116, 32,115,117,112,112,111,114,116, 34, 44,107,101,
    121, 95,116,121,112,101, 41, 41, 10,101,110,100, 10,105,102,
     32,118, 97,108,117,101, 95,116,121,112,101, 32, 61, 61, 32,
     34,115,116,114,105,110,103, 34, 32,116,104,101,110, 10,118,
     97,108,117,101, 95,115,116,114, 32, 61, 32, 34, 92, 34, 34,
     46, 46,102, 95,101,115, 99,115,116,114,105,110,103, 40,118,
     41, 46, 46, 34, 92, 34, 34, 10,101,108,115,101,105,102, 32,
    118, 97,108,117,101, 95,116,121,112,101, 32, 61, 61, 32, 34,
    110,117,109, 98,101,114, 34, 32,111,114, 32,118, 97,108,117,
    101, 95,116,121,112,101, 32, 61, 61, 32, 34, 98,111,111,108,
    101, 97,110, 34, 32,111,114, 32,118, 97,108,117,101, 95,116,
    121,112,101, 32, 61, 61, 32, 34,110,105,108, 34, 32,111,114,
     32,118, 97,108,117,101, 95,116,121,112,101, 61, 61, 34,117,
    115,101,114,100, 97,116, 97, 34, 32,116,104,101,110, 10,118,
     97,108,117,101, 95,115,116,114, 32, 61, 32,116,111,115,116,
    114,105,110,103, 40,118, 41, 10,101,108,115,101,105,102, 32,
    118, 97,108,117,101, 95,116,121,112,101, 32, 61, 61, 34,116,
     97, 98,108,101, 34, 32,116,104,101,110, 10,118, 97,108,117,
    101, 95,115,116,114, 32, 61, 32,102, 95,116, 97, 98,108,101,
    116,111,115,116,114,105,110,103, 40,118, 44,112,114,101,102,
    105,120, 46, 46, 34, 92,116, 34, 41, 10,101,108,115,101, 10,
    101,114,114,111,114, 40,115,116,114,105,110,103, 46,102,111,
    114,109, 97,116, 40, 34,118, 97,108,117,101, 32,102,111,114,
     32, 37,115, 32,110,111,116, 32,115,117,112,112,111,114,116,
     34, 44,118, 97,108,117,101, 95,116,121,112,101, 41, 41, 10,
    101,110,100, 10,114,101,115,117,108,116, 32, 61, 32,114,101,
    115,117,108,116, 46, 46, 32,112,114,101,102,105,120, 46, 46,
     34, 92,116, 34, 46, 46,107,101,121, 95,115,116,114, 46, 46,
     34, 61, 34, 46, 46,118, 97,108,117,101, 95,115,116,114, 46,
     46, 34, 44, 92,110, 34, 10,101,110,100, 10,114,101,116,117,
    114,110, 32, 34,123, 92,110, 34, 46, 46,114,101,115,117,108,
    116, 46, 46,112,114,101,102,105,120, 46, 46, 34,125, 34, 10,
    101,110,100, 10,102,117,110, 99,116,105,111,110, 32,102, 95,
    115, 97,118,101,116, 97, 98,108,101, 40,102,105,108,101,110,
     97,109,101, 44,116, 44,107,101,121, 41, 10,115,116,114, 61,
    102, 95,116, 97, 98,108,101,116,111,115,116,114,105,110,103,
     40,116, 41, 59, 10,105,102, 32,107,101,121, 32,116,104,101,
    110, 10,115,116,114, 61,102, 95,120,111,114,115,116,114,105,
    110,103, 40,115,116,114, 44,107,101,121, 41, 10,101,110,100,
     10,102, 95,115, 97,118,101,102,105,108,101, 40,102,105,108,
    101,110, 97,109,101, 44,115,116,114, 41, 10,101,110,100, 10,
    102,117,110, 99,116,105,111,110, 32,102, 95,108,111, 97,100,
    116, 97, 98,108,101, 40,102,105,108,101,110, 97,109,101, 44,
    107,101,121, 41, 10,108,111, 99, 97,108, 32,115,116,114, 61,
    102, 95,108,111, 97,100,102,105,108,101, 40,102,105,108,101,
    110, 97,109,101, 41, 10,105,102, 32,110,111,116, 32,115,116,
    114, 32,116,104,101,110, 10,114,101,116,117,114,110, 32,110,
    105,108, 10,101,110,100, 10,105,102, 32,107,101,121, 32,116,
    104,101,110, 10,115,116,114, 61, 32,102, 95,120,111,114,115,
    116,114,105,110,103, 40,115,116,114, 44,107,101,121, 41, 10,
    101,110,100, 10,115,116,114, 61, 34,114,101,116,117,114,110,
     32, 34, 46, 46,115,116,114, 10,108,111, 99, 97,108, 32, 99,
    104,117,110,107, 61,108,111, 97,100,115,116,114,105,110,103,
     40,115,116,114, 44,102,105,108,101,110, 97,109,101, 41, 10,
    105,102, 32, 99,104,117,110,107, 32,116,104,101,110, 10,114,
    101,116,117,114,110, 32, 99,104,117,110,107, 40, 41, 10,101,
    110,100, 10,101,110,100, 10,102,117,110, 99,116,105,111,110,
     32,102, 95,117,116,105,108,108,111,103, 40,102,109,116, 44,
     46, 46, 46, 41, 10,108,111, 99, 97,108, 32,115,116,114, 61,
    115,116,114,105,110,103, 46,102,111,114,109, 97,116, 40,102,
    109,116, 44, 46, 46, 46, 41, 10,102, 95,108,111,103, 40,115,
    116,114, 41, 10,101,110,100, 10,108,111, 99, 97,108, 32,108,
     95,108,111, 97,100,109,111,100,117,108,101, 61,123,125, 10,
    102,117,110, 99,116,105,111,110, 32,102, 95,114,101,113,117,
    105,114,101, 40,102,105,108,101,110, 97,109,101, 41, 10,105,
    102, 32,108, 95,108,111, 97,100,109,111,100,117,108,101, 91,
    102,105,108,101,110, 97,109,101, 93, 32,116,104,101,110, 10,
    114,101,116,117,114,110, 32,116,114,117,101, 10,101,110,100,
     10,105,102, 32,102, 95,105,109,112,111,114,116, 40,102,105,
    108,101,110, 97,109,101, 41, 32,116,104,101,110, 10,108, 95,
    108,111, 97,100,109,111,100,117,108,101, 91,102,105,108,101,
    110, 97,109,101, 93, 61,116,114,117,101, 10,114,101,116,117,
    114,110, 32,116,114,117,101, 10,101,110,100, 10,114,101,116,
    117,114,110, 32,102, 97,108,115,101, 10,101,110,100, 10,102,
    117,110, 99,116,105,111,110, 32,102, 95,110,101,119, 99,108,
     97,115,115, 40, 41, 10,108,111, 99, 97,108, 32,114,101,116,
     61,123,125, 10,114,101,116, 46, 95, 95,105,110,100,101,120,
     61,114,101,116, 10,114,101,116,117,114,110, 32,114,101,116,
     10,101,110,100, 10,102,117,110, 99,116,105,111,110, 32,102,
     95,101,120,116,101,110,100,115, 40,111, 44, 99, 41, 10,105,
    102, 32,116,121,112,101, 40,111, 41, 61, 61, 34,116, 97, 98,
    108,101, 34, 32,116,104,101,110, 10,115,101,116,109,101,116,
     97,116, 97, 98,108,101, 40,111, 44, 99, 41, 10,101,108,115,
    101,105,102, 32,116,121,112,101, 40,111, 41, 61, 61, 34,117,
    115,101,114,100, 97,116, 97, 34, 32,116,104,101,110, 10,105,
    102, 32,111, 46,100, 97,116, 97, 32,116,104,101,110, 10,115,
    101,116,109,101,116, 97,116, 97, 98,108,101, 40,111, 46,100,
     97,116, 97, 44, 99, 41, 10,101,108,115,101, 10,111, 46,100,
     97,116, 97, 61,123,125, 10,115,101,116,109,101,116, 97,116,
     97, 98,108,101, 40,111, 46,100, 97,116, 97, 44, 99, 41, 10,
    101,110,100, 10,101,108,115,101, 10,102, 95,117,116,105,108,
    108,111,103, 40, 34,110,111,116, 32,115,117,112,112,111,114,
    116, 32,116,121,112,101, 40, 37,115, 41, 32,101,120,116,101,
    110,100,115, 34, 44,116,121,112,101, 40,111, 41, 41, 59, 10,
    101,110,100, 10,101,110,100, 45, 45, 45, 45, 45, 45, 45, 45,
     45, 45, 45, 45, 45, 45, 45,32
   };
   tolua_dobuffer(tolua_S,(char*)B,sizeof(B),"tolua: embedded Lua code 1");
   lua_settop(tolua_S, top);
  } /* end of embedded lua code */

 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_FsLibLuaScript (lua_State* tolua_S) {
 return tolua_FsLibLuaScript_open(tolua_S);
};
#endif

