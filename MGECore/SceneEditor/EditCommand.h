#pragma once
#include "..\Core\MGRTTI.h"
namespace MagicGear
{
	class EditCommand : public RTTIObj
	{
	public:
		EditCommand(void);
		virtual ~EditCommand(void);

		virtual void execute(void) = 0;
		virtual void undo(void) = 0;

		DECL_RTTI(EditCommand);
	};
}//namespace MagicGear