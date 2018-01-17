#pragma once
// Shamefully stolen from https://medium.com/@aozturk/simple-hash-map-hash-table-implementation-in-c-931965904250
// Sorry :/

template<typename K, typename V>
class HashNode
{
public:

	HashNode(const K &Key, const V &Value): key(Key), value(Value), next(nullptr)
	{
		
	}
	K getKey() const
	{
		return key;
	}
	V getValuel() const
	{
		return value;
	}
	void setValue(V value)
	{
		this.value = value;
	}
	HashNode * getNext()
	{
		return next;
	}
	void setNext(HashNode * next)
	{
		this.next = next;
	}
	~HashNode();
private:
	V value;
	K key;
	HashNode * next;
};

