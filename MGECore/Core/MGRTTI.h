#pragma once

namespace MagicGear
{
	class RTTInfo;
	/**	\class RTTIObj
		\biref Runtime type identify object, base class for RTTI object
	*/
	class RTTIObj
	{
	public:
		RTTIObj(void);
		virtual ~RTTIObj(void);

		bool	isKindOf(const char* szClassName) const;
		bool	isStaticClass(const char* szClassName) const;
		bool	isKindOf(const RTTInfo *pInfo) const;
		bool	isStaticClass(const RTTInfo *pInfo) const;

		const char* getClassName();

		//-- RTTI defines
		static	RTTInfo		m_classRTTIObj;
		virtual RTTInfo*	getRTTInfo() const;
		//static RTTIObj	*CreateObj();
	};

	//--abstract class declear
#define DECL_RTTI(className)\
public:\
	static	RTTInfo		m_class##className;\
	virtual RTTInfo*	GetRTTInfo() const;

#define IMP_RTTI(className,superClass)\
	RTTInfo		className::m_class##className(#className,&superClass::m_class##superClass,NULL);\
	RTTInfo*	className::GetRTTInfo() const\
	{	return &m_class##className; }

	//--
#define DECL_RTTI_DYNC(className)\
public:\
	static	RTTInfo		m_class##className;\
	virtual RTTInfo*	GetRTTInfo() const;\
	static RTTIObj	*CreateObj();
#define IMP_RTTI_DYNC(className,superClass)\
	RTTIObj*	className::CreateObj()\
	{ return new className;}\
	RTTInfo		className::m_class##className(#className,&superClass::m_class##superClass,className::CreateObj);\
	RTTInfo*	className::GetRTTInfo() const\
	{	return &m_class##className; }

	//--
#define IS_KIND_OF(className)\
	IsKindOf(&className::m_class##className)
#define IS_STATIC_CLASS(className)\
	IsStaticClass(&className::m_class##className)

	//----------------------------------------------------------------------------
	/**	\class RTTInfo
	\brief Runtime type info
	*/
	class RTTInfo
	{
		typedef RTTIObj* (FuncCreateObj)();
	public:
		RTTInfo(const char* szClassName,RTTInfo *pSuperClass,FuncCreateObj *pFunc);
		~RTTInfo(void);

		bool isKindOf(const RTTInfo *pInfo);
		bool isKindOf(const char* szClassName);

		const char*		m_szClassName;
		RTTInfo*		m_pSuperClass;
		FuncCreateObj	*m_pfnCreateObj;	//NULL for abstract class
	};

	//----------------------------------------------------------------------------
	/**	\class RTTFactory
	\brief Runtime type factor
	\remarks record all RTTInfo, create object at run time by class name
	\see RTTInfo,RTTIObj
	*/
	class RTTFactory
	{
	public:
		RTTFactory();
		~RTTFactory();

		static RTTFactory *getInst();

		void	addRuntimeClass(const RTTInfo *pInfo);

		RTTIObj	*createObj(const char* szClassName);

		unsigned int getNumClass() const;
		const RTTInfo *getClass(unsigned int i) const;


	private:
		class Member;
		Member	*m_p;
	};
}//namespace MagicGear