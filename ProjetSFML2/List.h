#ifndef _LIST_H_
#define _LIST_H_

/**********************************************************
Description de la representation

Chaine double de boites
Une boite supplementaire a la fin,
nommee apres en memoire automatique (non dynamique)
Une boite supplementaire au debut nommee avant 
en memoire automatique (non dynamique) dont le suivant 
pointe sur la premiere boite
size contient le nombre d'elements dans la liste


iterator: pointeur sur la boite concernee,
la fin est un pointeur sur la boite de queue (apres)

reverse_iterator: pointeur sur la boite qui concernee
(rbegin: celle pointe par le precedent de apres, rend: avant)

RESTRICTION par rapport a la SL
pas de const_iterator, donc pas d'iteration possible
sur une list const.

**********************************************************/

template <class TYPE>
class list {

private:
	struct boite {
		TYPE valeur;
		boite *suiv, *prec;
		boite(const TYPE& C, boite*S = nullptr, boite*P = nullptr) {} //a implanter
		~boite() { prec = suiv = nullptr; }
	};
	boite avant;
	boite apres;
	size_t size;

	//fonctions generatrices privees
	//inserer avant cette boite
	boite* insert(boite*, const TYPE&)
	{

	}

	//enlever cette boite
	boite* erase(boite* otherBox)
	{
		delete otherBox;
	}

public:
	class iterator;

	//constructeur
	list()
	{

	}

	//destructeur
	~list()
	{

	}

	//copie constructeur
	list(const list&)
	{

	}

	list(std::initializer_list<TYPE>)
	{

	}

	//affectateur. copie les elements de other dans la file courante. O(n) 
	list& operator=(const list& other)
	{

	}

	//echange les element des files courante et other O(1);
	void swap(list& other)
	{

	}

	//ajoute un element AVANT la boite en position pos. retourne un iterateur sur la nouvelle boite. O(1)
	iterator insert(iterator pos, const TYPE& value)
	{

	}

	//enleve l'element a la position pos. retourne un iterateur sur l'element suivant celui qui est retire. O(1)
	iterator erase(iterator pos)
	{

	}

	//Ajoute un element a la fin de la liste. O(1)
	void push_back(const TYPE&)
	{

	}

	//Enleve un element a la fin de la liste. O(1)
	void pop_back()
	{

	}

	//Ajoute un element au debut de la liste. O(1)
	void push_front(const TYPE&)
	{

	}

	//Enleve un element au debut de la liste. O(1)
	void pop_front()
	{

	}

	//Retourne une reference sur le dernier element de la liste. O(1)
	TYPE& back()
	{

	}

	//Retourne une reference sur le premier element de la liste. O(1)
	TYPE& front()
	{

	}

	void clear()
	{

	}

	size_t size() const
	{

	}

	bool empty() const
	{

	}

	//Retourne un iterateur sur la boite suivant avant.
	iterator begin()
	{

	}

	//Retourne un iterateur sur la boite apres.
	iterator end()
	{

	}

	//algorithmes
	//Inverse l'ordre des elements de la liste. O(n)
	void reverse()
	{

	}

	//Transfere les elements contenu dans other vers la liste courante. les element sont ajouter avant la boite en position pos. O(1)
	void splice(iterator pos, list& other)
	{

	}
};

///////////////////////////////////////////////////////////
//la classe iterator
///////////////////////////////////////////////////////////

template <typename TYPE>
class list<TYPE>::iterator {
	friend class list<TYPE>;
private:
	boite* POINTEUR;
public:
	iterator(boite*c = nullptr) :POINTEUR(c) {}

	//Dereference l'iterateur
	TYPE& operator*()const 
	{
		//TODO a faire...
		return TYPE();
	}

	TYPE* operator->()const { return &(POINTEUR->CONTENU); } 
	
	//++i
	iterator& operator++() 
	{
		//TODO a faire
		return *this;
	}

	//i++
	iterator operator++(int) 
	{   
		//TODO a faire
		return *this;
	}

	//--i
	iterator& operator--() 
	{
		//TODO a faire
		return *this;
	}

	//i--
	iterator operator--(int) 
	{   
		//TODO a faire
		return *this;
	}
	
	//comparaison d'iterateur
	bool operator==(const iterator&droite)const 
	{ 
		return POINTEUR == droite.POINTEUR;
	}

	//comparaison d'iterateur
	bool operator!=(const iterator&droite)const 
	{ 
		return POINTEUR != droite.POINTEUR;
	}
};
#endif //_LIST_H