#pragma once

namespace miit::algebra
{
	/*
	* @brief  ласс Generator вирутальный.
	*/
	class Generator
	{
	public:
		/*
	    * @brief ƒеструктор.
	    */
		virtual ~Generator() = 0 {};
		/*
		* @brief ћетод генерации значени¤.
		*/
		virtual int generate() = 0;
	};

}

