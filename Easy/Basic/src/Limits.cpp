
#include "../Limits.h"
#include "../Utilities.h"

namespace easy {
	namespace limits {
		char CHARACTER_MAX;
		char CHARACTER_MIN;
		byte BYTE_MAX = UCHAR_MAX; // 255
		byte BYTE_MIN = 0;

		ushort USHORT_MAX = USHRT_MAX; // 65,535
		ushort USHORT_MIN = 0;
		short SHORT_MAX = SHRT_MAX; // 32,767
		short SHORT_MIN = SHRT_MIN; // -32,768

		integer INTEGER_MAX = INT_MAX; // 2,147,483,647
		integer INTEGER_MIN = INT_MIN; // -2,147,483,648
		uinteger UINTEGER_MAX = UINT_MAX; // 4,294,967,295
		uinteger UINTEGER_MIN = 0;

		big BIG_MAX = LLONG_MAX; // -9,223,372,036,854,775,808
		big BIG_MIN = LLONG_MIN; // 9,223,372,036,854,775,807
		ubig UBIG_MAX = ULLONG_MAX; // 18,446,744,073,709,551,615
		ubig UBIG_MIN = 0;

		real REAL_MAX = DBL_MAX;
		real REAL_MIN = -DBL_MAX; // DBL_MIN is 0
		float FLOAT_MAX = FLT_MAX;
		float FLOAT_MIN = -FLT_MAX; // DBL_MIN is 0
	};
};
