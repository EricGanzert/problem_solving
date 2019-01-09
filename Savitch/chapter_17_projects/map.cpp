#ifndef MAP_CPP
#define MAP_CPP
#include <map.h>

namespace eric_map
{
	using namespace std;
	template<class T,class V>
	Map<T,V>::Map()
	{
		//empty
	}
	
	
	template<class T,class V>
	Map<T,V>::~Map()
	{
		data.clear();
	}
	
	template<class T,class V>
	void Map<T,V>::add(T key, V value)
	{
		data.insert(make_pair(key, value));
	}
	
	template<class T,class V>
	void Map<T,V>::set(T key, V new_value)
	{
		data[key] = new_value;
	}
	
	template<class T,class V>
	void Map<T,V>::remove(T key)
	{
		data.erase(key);
	}
	
	template<class T,class V>
	bool Map<T,V>::find(T key)
	{
		return (data.find(key) != data.end());
	}
	
	template<class T,class V>
	V Map<T,V>::retrieve(T key)
	{
		V result;
		typename map<T,V>::iterator p;
		p = data.find(key);
		if (p != data.end())
		{
			result = p->second;
		}
		return result;
	}
	
	template<class T,class V>
	Map<T,V>& Map<T,V>::operator =(const Map& right)
	{
		data.clear();
		data = right.data();
		return *this;
	}
	
	template<class U,class X>
	ostream& operator <<(ostream& outs, const Map<U,X>& the_map)
	{
		typename map<U,X>::const_iterator p;
		for (p = the_map.data.begin(); p != the_map.data.end(); ++p)
		{
			outs << p->first << " : " << p->second << "\n";
		}
		return outs;
	}
}

#endif //MAP_CPP
