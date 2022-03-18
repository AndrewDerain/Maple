//
// Created by 宋豪杰 on 2022/3/8.
//

#pragma once
#include <string>
#include <vector>
#include <iostream>

namespace Utility
{
	template<class _T>
	class Type
	{
	public:
		static const char* Name() {
			if(strcmp(_Name, "") == 0)
				_PraseTypeName();

			return _Name;
		}

	private:
		static char _Name[256];

		static void _PraseTypeName() {
			char 		slenv[5];
			int 		slenp 	= 0;
			const char* sysnmv 	= typeid(_T).name();
			const int 	sysnml  = strlen(sysnmv);
			int 		usrnmp	= 0;

			int 		i = sysnmv[0] == 'N' ? 1 : 0;
			const int 	e = sysnml - 1 - i;

			for(; i < sysnml; i++) {

				if(std::isdigit(sysnmv[i])) {
					slenv[slenp++] = sysnmv[i];
				}
				else {
					slenv[slenp] = '\0';
					int len = std::atoi(slenv);
					strncpy(&_Name[usrnmp], &sysnmv[i], len);
					usrnmp	+= len;
					slenp 	= 0;
					i 		+= len - 1;

					if( i == e) {
						break;
					}
					else {
						strncpy(&_Name[usrnmp], "::", 2);
						usrnmp += 2;
					}
				}
			}
		}
	};

	template<typename _T>
	char Type<_T>::_Name[256] = "";

};
