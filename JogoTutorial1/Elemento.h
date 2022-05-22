#pragma once
template <class TE> class Elemento
{
private:
	Elemento<TE>* pProx;
	TE* pitem;
public:
	Elemento();
	~Elemento();

	void setPprox(Elemento<TE>* p) { this->pProx = p; }
	void setItem(TE* i) { this->pitem = i; }
	Elemento<TE>* getPprox() { return pProx; }
	TE* getItem() { return pitem; }
};

template<class TE>
inline Elemento<TE>::Elemento()
{
	pProx = nullptr;
	pitem = nullptr;
}

template<class TE>
inline Elemento<TE>::~Elemento()
{
}
