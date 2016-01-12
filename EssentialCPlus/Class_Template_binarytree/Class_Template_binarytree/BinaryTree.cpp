#include<iostream>
#include<string>
using namespace std;

template<typename elemtype>
class BTnode
{
	
public:
	 friend class BinaryTree<elemtype>;
	 void insert_value(const elemtype &);
	 void remove_value(const elemtype &val,BTnode *&prve);
	 void lchild_leaf(BTnode *,BTnode *);
private:
	elemtype _val;
	int _cnt;
	BTnode *_lchild;
	BTnode *_rchild;
};

template<typename elemtype>
class BinaryTree
{
public:
	BinaryTree():_root(0){}
	BinaryTree(const binaryTree&){copy (_root,rhs._root);}
	~Binary(){clear();}
	BinaryTree& operator=(const BinaryTree&);
    void insert(const elemtype &);
	void remove(const elemtype &val);
	void remove_root();

	bool empty(){return _root=0;}
	void clear(){if(_root){clear(_root);_root=0}};

	void preorder(BTnode *pt,ostream &os)const;
	void inorder(BTnode *pt,ostream &os)const;
	void postorder(BTnode *pt,ostream &os)const;
	 
private:
	BTnode<elemtype> *_root;
	void copy(BTnode<elemtype>*tar,BTnode <elemtype>*src);
	void clear(BTnode<elemtype>*);
};
/*BTnode类的函数定义*/
template<typename elemtype>
inline BTnode<elemtype>::
	BTnode(const elemtype &val):_val(val){_cnt=1;_lchild=_rchild=0;}

template<typename elemtype>
void BTnode<elemtype>::
insert_value(const elemtype &val)
{
	if(val==_val){_cnt++;return ;}
	if(val<_val)
	{
		if(!_lchild)
			_lchild=new BTnode(val);
		else _lchild->insert_value(val);
	}
	else
	{
		if(!_rchild)
			_rchild=new BTnode(val);
		else _rchild->insert_value(val);
	}
}

template<typename elemtype>
void BTnode<elemtype>::remove_value(const elemtype &val,BTnode *&prve)
{
	if(val<_val)
	{
		if(!_lchild)
			return ;
		else _lchild->remove_value(val,_lchild);
	}
	else if(val>_val)
	{
		if(!_rchild)
			return ;
		else _rchild->remove_value(val,_rchild);
	}
	else//找到该值，重置树，删除该节点
		if(_rchild)
		{
			prev=_child;
			if(_lchild)
				if(!prve->_lchild)
					prve->_lchild=_lchild;
				else Btnode<elemtype>::lchild_leaf(_lchild,prve->_lchild);
		}
		else prve=_lchild;
		delete this;
}

template<typename elemtype>
void BTnode<elemtype>::
lchild_leaf(BTnode *leaf,BTnode *subtree)
{
	while(subtree->_lchild)
		subtree=subtree->_lchild;
	subtree->lchild=leaf;
}


/*BinaryTree类的函数定义*/

template<class elemtype>
inline BinaryTree<elemtype>& BinaryTree<elemtype>::
operator=(const BinaryTree &rhs)
{
	if(this!=&rhs)
	{clear();copy(_root,rhs._root);}
	return *this;
}

template<typename elemtype>
inline void BinaryTree<elemtype>::insert(const elemtype &elem)
{
	if(!_root)
		_root=new BTnode<elemtype>(elem);
	else _root->insert_value(elem);
}

template<typename elemtype>
inline void BinaryTree<elemtype>::remove(const elemtype &elem)
{
	if(_root)
	{
		if(_root->_val==elem)
			remove_root();
		else
			_root->remove_value(elem,_root);
	}
}

template<typename elemtype>
void BinaryTree<elemtype>::remove_root()
{
	if(!_root)return ;
	BTnode<elemtype> *tmp=_root;
	if(_root->_rchild)
	{
		_root=_root->_rchild;
		//将左子树节点搬移到右子节点的左子树底部
		if(tmp->_lchild)
		{
			BTnode<elemtype>*lc=tmp->_lchild;
			BTnode<elemtype>*newrc=_root->_lchild;
			if(!newlc)
				_root->_lchild=lc;
			else BTnode<elemtype>::lchild_leaf(lc,newlc);
		}
		else _root=_root->_lchild;
		delete tmp;
	}
}

template <typename elemtype>
void BinaryTree<elemtype>::clear(BTnode<elemtype>*pt)
{
	if(pt)
	{
		clear(pt->_lchild);
		clear(pt->_rchild);
		delete pt;
	}
}

template<typename elemtype>
void BTnode<elemtype>::preorder(BTnode *pt,ostream &os=cout)const
{
	if(pt)
	{
		cout<<pt->_val<<" ";
		if(pt->_lchild)preorder(pt->_lchild,os);
		if(pt->_rchild)preorder(pt->_rchild,os);
	}
}

template<typename elemtype>
void BTnode<elemtype>::inorder(BTnode *pt,ostream &os=cout)const
{
	if(pt)
	{
		cout<<pt->_val<<" ";
		if(pt->_lchild)inorder(pt->_lchild,os);
		if(pt->_rchild)inorder(pt->_rchild,os);
	}
}

template<typename elemtype>
void BTnode<elemtype>::postorder(BTnode *pt,ostream &os=cout)const
{
	if(pt)
	{
		cout<<pt->_val<<" ";
		if(pt->_lchild)postorder(pt->_lchild,os);
		if(pt->_rchild)postorder(pt->_rchild,os);
	}
}



int main()
{
	BinaryTree<string> bt;

	bt.insert("Piglet");
	bt.insert("Eetore");
	bt.insert("Roo");
	bt.insert("Tigger");
	bt.insert("Chris");
	bt.insert("Pooh");
	bt.insert("Kanga");

	cout<<"Preorder traversal:\n";
	bt.preorder(bt._root,cout);

	bt.remove("Piglet");
	cout<<"\n\nPreorder traversal after Piglet removal:\n";
	bt.inorder(bt._root,cout);

	bt.remove("Eeyore");
	cout<<"\n\nPreorder traversal after Eeyore removal:\n";
	bt.postorder(bt._root,cout);

	system("pause");
	return 0;
}