#include <callingDepth.hpp>
using namespace std;

namespace calling_depth_eric
{
	void calling_depth(int current_depth, int target_depth) throw(int)
	{
		if (current_depth == target_depth)
		{
			throw(current_depth);
		}
		else
		{
			calling_depth(current_depth+1, target_depth);
		}
	}
}
