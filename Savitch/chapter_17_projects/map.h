#ifndef MAP_H
#define MAP_H
#include <map>

namespace eric_map
{
	template<class T, class V>
	class Map
	{
	public:
		Map();
		~Map();
		
		void add(T key, V value);
		void set(T key, V new_value);
		void remove(T key);
		bool find(T key);
		V retrieve(T key);
		
		Map& operator =(const Map& right);
		
		template<class U,class X>
		friend std::ostream& operator <<(std::ostream& outs, const Map<U,X>& the_map);
		
	private:
		std::map<T,V> data;
	};	
}

#endif //MAP_H
