#include "HashMap.hpp"

namespace
{
	unsigned int hash(const std::string& word)
	{
		int sum = 0;
		for (int k=0; k<word.length(); k++)
			sum = sum + int(word[k]);
		return sum;
	}
}

HashMap::HashMap()
       :head{new Node*[initialBucketCount]}, sz{0}, capacity{initialBucketCount}, hasher{hash}
{
	for (unsigned int i=0; i<capacity; i++)
	{
		head[i] = nullptr;
	}
}

HashMap::HashMap(HashFunction hasher)
       :head{new Node*[initialBucketCount]}, sz{0}, capacity{initialBucketCount},hasher{hasher}
{
	for (unsigned int i=0; i<capacity; i++)
	{
		head[i] = nullptr;
	}
}

HashMap::HashMap(const HashMap& hm)
       :head{new Node*[hm.capacity]}, sz{hm.sz}, capacity{hm.capacity}, hasher{hm.hasher}
{
	for (unsigned int i=0; i<capacity; i++)
	{
		head[i] = nullptr;
	}
	arraycopy(head, hm.head, hm.capacity);
}

HashMap::~HashMap()
{
	for (unsigned int i=0; i<capacity; i++)
	{
		deletenodes(head[i]);
	}
	delete[] head;
}


void HashMap::deletenodes(Node* node)
{
	if (node != nullptr)
	{
		Node* temp = node;
		Node* temp2;
		while (temp != nullptr)
		{
			temp2 = temp;
			temp = temp->next;
		    delete temp2;
	    }	
    }
}

void HashMap::arraycopy(Node** target, Node** source, unsigned int cap)
{
	for (unsigned int i = 0; i < cap; i++)
	{
		target[i] = nullptr;
		Node* snode = source[i];
		if (snode != nullptr)
		{
			target[i] = new Node{snode->key, snode->value, nullptr};
			while (snode->next != nullptr)
			{
				Node* p = new Node{snode->next->key, snode->next->value, nullptr};
				p -> next = target[i];
				snode = snode->next;
				target[i] = p;
			}
		}
	}
}


HashMap& HashMap::operator=(const HashMap& hm)
{
	if (this != &hm)
	{
		sz = hm.sz;
		capacity = hm.capacity;
		hasher = hm.hasher;
		Node** newHead = new Node*[hm.capacity];
		arraycopy(newHead, hm.head, hm.capacity);
		for (unsigned int i=0; i<capacity; i++)
	    {
	    	deletenodes(head[i]);
	    }
		delete[] head;
		head = newHead;
	}
	return *this;
}


void HashMap::add(const std::string& key, const std::string& value)
{
	if (contains(key)==false)
	{
		sz++;
		unsigned int location = hasher(key)%capacity;
		Node* n = head[location];
		if (n != nullptr)
		{
			head[location]= new Node{key,value, nullptr};
			head[location]->next = n;
		}
		else
		{
			head[location]= new Node{key,value, nullptr};
		}
	}

	if (loadFactor() >= 0.8)
	{
		rehash();
	}
}

void HashMap::rehash()
{
	int newcap = capacity*2+1;
    Node** newhead = new Node*[newcap];
    for (unsigned int i=0; i<newcap; i++)
	{
		newhead[i] = nullptr;
	}
	for (unsigned int i = 0; i < capacity; i++)
	{
		Node*s = head[i];
		while (s != nullptr)
		{
			Node* c =newhead[hasher(s->key)%newcap];
			newhead[hasher(s->key)%newcap] = new Node{s->key, s->value, nullptr};
			newhead[hasher(s->key)%newcap]->next = c;
			s = s->next;
		}
	}

	for (unsigned int i=0; i<capacity; i++)
	{
		deletenodes(head[i]);
	}
	delete[] head;
	capacity = newcap;
	head = newhead;
}

void HashMap::remove(const std::string& key)
{
	if (contains(key)==true)
	{
		sz--;	
		unsigned int location = hasher(key)%capacity;
		Node* n = head[location];
		if (n != nullptr)
	    {	
	    	if (n->key == key)
	    	{
	    		head[location] = n -> next;
	    		delete n;
	    	}
	    	else
	    	{
	    		while (n->next->key != key)
	    		{
	    			if (n->key != key)
	    			{
	    				add(n->key, n->value);
	    			}
	    	    	n = n->next;
	    		}
	    		Node* c = n->next;
	    		if (c->next != nullptr)
	    		{
	    			n->next = c-> next;
	    		}
	    		else
	    		{
	    			n->next = nullptr;
	    		}
	    	}
	    }
	}
}


bool HashMap::contains(const std::string& key) const
{
	unsigned int i = hasher(key)%capacity;
	Node* l;
	l = head[i];
	while (l != nullptr)
	{
		if (l->key == key)
		{
		   	return true;
	    }
	    l = l->next;
	}
	return false;
}



unsigned int HashMap::size() const
{
	return sz;
}


std::string HashMap::value(const std::string& key) const
{
	unsigned int i = hasher(key)%capacity;
	Node* l;
	l = head[i];
	while (l != nullptr)
	{
		if (l->key == key)
		{
		    return l->value;
		}
		l = l->next;
	}
	return "";
}


unsigned int HashMap::bucketCount() const
{
	return capacity;
}


double HashMap::loadFactor() const
{
	return (double)sz/(double)capacity;
}


unsigned int HashMap::maxBucketSize() const
{
	unsigned int max_size = 0;
	for (unsigned int i = 0; i < capacity; i++)
	{
		Node* l;
		l = head[i];
		unsigned int size = 0;
		while (l != nullptr)
		{
			size += 1;
		    l = l->next;
		}
		if (size > max_size)
		{
			max_size = size;
		}
	}
	return max_size;
}

void HashMap::clear() 
{ 
	for (unsigned int i=0; i<capacity; i++)
	{
		head[i] = nullptr;
	}
	sz = 0;
}
