#pragma once
#include <vector>
#include <iostream>
using namespace std;

#define MAX_NODES 1000

template <class T>
class Tree
{
	typedef struct
	{
		unsigned int uiId;
		unsigned int uiParentId;
		T data;
		vector<unsigned int> listChildren;
	}Node;

private:
	vector<Node> m_NodeList;
	unsigned int m_CurrNodeId;

	bool removeChild(unsigned int id);
public:
	Tree() 
	{
		m_CurrNodeId = 0;
	};
	~Tree() {};

	unsigned int AddNode(T data);
	bool RemoveNode(unsigned int id);
	unsigned int AddChild(unsigned int uiParent, T data);
	vector<Node> GetChildren(unsigned int uiParent);
	void PrintTree();
};

#include "Tree.h"


// Add a node to the Tree
template <class T>
unsigned int Tree<T>::AddNode(T data)
{
	unsigned retVal = 0;

	//  If we can still add a node, then create one and 
	// push it in the list
	if (m_CurrNodeId < MAX_NODES)
	{
		Node node;
		node.data = data;
		node.uiParentId = 0;
		m_CurrNodeId++;
		node.uiId = m_CurrNodeId;
		retVal = m_CurrNodeId;
		m_NodeList.push_back(node);
	}

	return retVal;
}

// Add a node to the Tree
template <class T>
bool Tree<T>::RemoveNode(unsigned int id)
{
	bool retVal = removeChild();
	if (retVal)
	{
		unsigned int size = m_NodeList.size();
		for (unsigned int i = 0; i < size; i++)
		{
			if (m_NodeList[i].uiId == id)
			{
				m_NodeList.remove(i);
				retVal = true;
				break;
			}
		}
	}
	return retVal;
}

// Remove Child, this is private and used by RemoveNode
template <class T>
bool Tree<T>::removeChild(unsigned int id)
{
	bool retVal = false;
	unsigned int size = m_NodeList.size();
	for (unsigned int i = 0; i < size; i++)
	{
		vector<Node> children = m_NodeList[i].listChildren;
		for (unsigned int j = 0; j < children.size(); j++)
		{
			if (children[j].uiId == id)
			{
				children.remove(j);
				retVal = true;
				break;
			}
		}
	}
	return retVal;
}

// Add a child to parent specified by uiParent
// The method returns child's id
template <class T>
unsigned int Tree<T>::AddChild(unsigned int uiParent, T data)
{
	unsigned int retVal = AddNode(data);

	// If we were able to add node, then update the parent's 
	// list of children
	if (retVal > 0)
	{
		unsigned int size = m_NodeList.size();
		for (unsigned int i = 0; i < size; i++)
		{
			if (m_NodeList[i].uiId == uiParent)
			{
				m_NodeList[i].listChildren.push_back(m_CurrNodeId);
				break;
			}
		}
	}
	return retVal;
}


template <class T>
vector<Tree::Node> Tree<T>::GetChildren(unsigned int uiParent)
{
	vector<Tree::Node> children;
	for (unsigned int i = 0; i < m_CurrNodeId; i++)
	{
		if (m_NodeList[i].uiParentId == uiParent)
		{
			children = m_NodeList[i].listChildren;
			break;
		}
	}
	return children;
}

template <class T>
void Tree<T>::PrintTree()
{
	unsigned int size = m_NodeList.size();
	for (unsigned int i = 0; i < size; i++)
	{
		cout << "Parent: " << m_NodeList[i].uiId << "\n";
		vector<unsigned int> children = m_NodeList[i].listChildren;
		for (unsigned int j = 0; j < children.size(); j++)
		{
			cout << "   Child: " << children[j] << "\n";
		}
	}
}
