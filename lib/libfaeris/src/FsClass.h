/*************************************************************************/
/*  FsClass.h                                                            */
/*************************************************************************/
/* Copyright (C) 2012-2014 nosiclin@foxmail.com                          */
/* Copyright (C) 2014-2015 www.fsource.cn                                */
/*                                                                       */
/* http://www.fsource.cn                                                 */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/


#ifndef _FS_CLASS_H_
#define _FS_CLASS_H_

#include "FsMacros.h"
#include "FsObject.h"
#include "FsEnums.h"

NS_FS_BEGIN

class FsString;
class FsDict;
class FsArray;

class FsClass :public FsObject 
{
	public:
		typedef  FsObject* (*NewInstanceFunc)(FsDict* attrs);
		typedef void (*AttrSetFunc)(FsObject* ob,void*);
		typedef void* (*AttrGetFunc)(FsObject* ob);

	public:
		class FsAttributeDeclare
		{
			public:
				FsAttributeDeclare(const char* _name,E_FsType _type,FsAttributeDeclare* _sub,
									AttrSetFunc _setFunc,AttrGetFunc _getFunc)
				{
					name=_name;
					attrType=_type;
					subAttributeDeclare=_sub;
					setFunc=_setFunc;
					getFunc=_getFunc;
				}

			public:
				const char* name;
				E_FsType attrType;
				FsAttributeDeclare* subAttributeDeclare;
				AttrSetFunc setFunc;
				AttrGetFunc getFunc;
		};


		class FsAttribute:public FsObject
		{
			public:
				static FsAttribute* create(FsAttributeDeclare* desc)
				{
					FsAttribute* ret=new FsAttribute(desc);
					return ret;
				}

			public:
				bool callSet(FsObject* bo,const FsVariant& v);
				FsVariant callGet(FsObject* ob);
				FsString* getName(){return m_name;}


			protected:
				FsAttribute(FsAttributeDeclare* desc);
				~FsAttribute();

			protected:
				FsString* m_name;
				E_FsType m_attrType;
				FsDict* m_subAttributes;
				AttrSetFunc m_setFunc;
				AttrGetFunc m_getFunc;
		};

	public:
		static FsClass* create(const char* name,NewInstanceFunc new_func,FsAttributeDeclare* mb);
		static FsClass* create(FsClass* base,const char* name,NewInstanceFunc new_func,FsAttributeDeclare* mb);

	public:
		FsObject* newInstance();
		FsObject* newInstance(FsDict* attrs);
		FsObject* newInstance(const char* filename);


		bool callSet(FsObject* ob,const char* name,const FsVariant& v);
		bool callSet(FsObject* ob,FsString* name,const FsVariant& v);

		FsVariant callGet(FsObject* ob,const char* name);
		FsVariant callGet(FsObject* ob,FsString* name);

		bool callSets(FsObject* ob,FsDict* dict);


		FsAttribute* getAttribute(const char* name);
		FsAttribute* getAttribute(FsString* name);

	protected:
		FsClass();
		~FsClass();

		void init(FsClass* base,const char* name,NewInstanceFunc new_func,FsAttributeDeclare* mb);

	private:

		FsString* m_name;
		NewInstanceFunc m_newFunc;
		FsClass* m_baseClass;
		FsDict* m_attribute;
};


#define FS_CLASS_IMPLEMENT(cls,new_instnce,attrs) \
	Faeris::FsClass* cls::m_fsclass=NULL; \
	Faeris::FsClass* cls::getClass() \
	{ \
		if( cls::m_fsclass==NULL) \
		{ \
			cls::m_fsclass=Faeris::FsClass::create(#cls,(FsClass::NewInstanceFunc)new_instnce,attrs); \
		} \
		return cls::m_fsclass; \
	} \
	Faeris::FsClass* cls::objectClass()  \
	{ \
		return cls::getClass(); \
	} \
	const char* cls::getClassName()  \
	{ \
		static const char* class_name=#cls; \
		return  class_name; \
	} \
	const char* cls::className() \
	{ \
		return cls::getClassName(); \
   	} \




#define FS_CLASS_IMPLEMENT_WITH_BASE(cls,base_cls,new_instnce,attrs) \
	Faeris::FsClass* cls::m_fsclass=NULL; \
	Faeris::FsClass* cls::getClass() \
	{ \
		if( cls::m_fsclass==NULL) \
		{ \
			cls::m_fsclass=Faeris::FsClass::create(base_cls::getClass(),#cls,(FsClass::NewInstanceFunc)new_instnce,attrs); \
		} \
		return cls::m_fsclass; \
	} \
	Faeris::FsClass* cls::objectClass()  \
	{ \
		return cls::getClass(); \
	} \
	const char* cls::getClassName()  \
	{ \
		static const char* class_name=#cls; \
		return  class_name; \
	} \
	const char* cls::className() \
	{ \
		return cls::getClassName(); \
   	} \


/* chars */
#define FS_CLASS_ATTR_SET_CHARS_FUNCTION(cls,set)  \
	static  void cls##_##set(cls* ob,const char* v) \
	{ \
		ob->set(v); \
	} 
#define FS_CLASS_ATTR_GET_CHARS_FUNCTION(cls,get)  \
	static  const char* cls##_##get(cls* ob) \
	{ \
		return ob->get(); \
	} 


#define FS_CLASS_ATTR_SET_GET_CHARS_FUNCTION(cls,set,get)  \
	static  void cls##_##set(cls* ob,const char* v) \
	{ \
		ob->set(v); \
	} \
	static const char* cls##_##get(cls* ob)  \
	{ \
		return ob->get(); \
	} \
	

/* type */
#define FS_CLASS_ATTR_SET_FUNCTION(cls,set,t) \
	static  void cls##_##set(cls* ob,const t* v) \
	{ \
		ob->set(*v); \
	} \


#define FS_CLASS_ATTR_SET_GET_FUNCTION(cls,set,get,t)  \
	static  void cls##_##set(cls* ob,const t* v) \
	{ \
		ob->set(*v); \
	} \
	static const t* cls##_##get(cls* ob)  \
	{ \
		static t temp; \
		temp=ob->get(); \
		return &temp; \
	} \


/* enum */
#define FS_CLASS_ATTR_SET_GET_ENUM_CHAR_FUNCTION(cls,set,get,t) \
	static  void cls##_##set(cls* ob,const char* name) \
	{ \
		E_##t type=FsEnum_StrTo##t(name); \
		ob->set(type); \
	} \
	static const char* cls##_##get(cls* ob)  \
	{ \
		E_##t type=ob->get();  \
		return FsEnum_##t##ToStr(type); \
	} \



#define FS_CLASS_ATTR_DECLARE(name,type,sub_attr,set_func,get_func) \
	Faeris::FsClass::FsAttributeDeclare(name,type, \
			sub_attr, \
			(Faeris::FsClass::AttrSetFunc)set_func, \
			(Faeris::FsClass::AttrGetFunc)get_func)
 



 
 


NS_FS_END

#endif /*_FS_CLASS_H_*/