#ifndef _H_DEQUE_
#define _H_DEQUE_

//File a 2 bouts qui permet l'ajout et le retrait au 2 bouts de la file (tete et queue) ainsi que l'acces direct aux elements.
template <typename TYPE>
class deque {
private:
	TYPE*  tab; //le tableau dynamique qui contiendra les donnees
	size_t cap; //la capacite du tableau
	size_t size; //le nombre d'elements presentement contenu dans la file
	size_t tete; //l'indice ou se trouve le premier element de la file
public:
	//constructeur, le parametre permet construire une file avec un nombre d'elements en reserve.
	//J'accepte un constructeur qui me prend pas de parametre et qui cree une file sans reserve. A vous de choisir celui qui vous plait le plus.
	deque(size_t = 0);	
	~deque();			//destructeur
	deque(const deque&);//copie constructeur
	deque& operator=(const deque& other); //affectateur. copie les elements de other dans la file courante. O(n) 
	void swap(deque& other); //echange les element des files courante et other O(1);

	//selecteurs
	size_t size()const; //retour le nombre d'elements contenu dans la file. O(1)
	bool empty()const; //retourne true si la file est vide. O(1)

	//gestion de la memoire
	void resize(size_t); //change la dimension. O(n)
	void reserve(size_t);//augmente la capacite. O(n)
	void clear();        //vide la memoire. O(1)

						 //acces aux elements individuels
	TYPE& operator[](size_t idx); //retourne l'element a la position idx. O(1)
	//const TYPE& operator[](size_t)const; //Optionnel. Version constante de la methode precedente. A implanter si vous en avez besoin.
	//TYPE& at(size_t idx); //OPTIONNEL. Retourne l'element a la position idx et cause une erreur (exception ou assert) si idx > nombre d'elements. O(1)
	//const TYPE& at(size_t)const; //Optionnel. Version constante de la methode precedente. A implanter si vous en avez besoin.

	void push_back(const TYPE&); //Ajoute un element a la fin de la file. O(1) amortis
	void pop_back(); //Retire l'element qui se trouve a la fin de la file. O(1)
	void push_front(const TYPE&); //Ajoute un element au debut de la file. O(1) amortis
	void pop_front(); //Retire l'element qui se trouve au debut de la file. O(1)
};
#endif //_H_DEQUE_
