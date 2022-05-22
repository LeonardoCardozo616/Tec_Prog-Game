#pragma once
#include "Elemento.h"
template <class TL> class Lista
{
private:
	Elemento<TL>* pPrimeiro;
	Elemento<TL>* pUltimo;
	int len;
public:
	Lista();
	~Lista();

	int getLen() { return len; }

	TL* getItem(int posicao) {
		Elemento<TL>* temp = pPrimeiro;
		if (posicao == 0)
			return temp->getItem();
		for (int i = 0; i < posicao; i++) {
			temp = temp->getPprox();
		}
		return temp->getItem();
	}
	void push(TL* item) {
		if (pPrimeiro == nullptr) {
			pPrimeiro = new Elemento<TL>;
			pPrimeiro->setItem(item);
			pUltimo = pPrimeiro;
		}
		else {
			Elemento<TL> *temp = new Elemento<TL>;
			temp->setItem(item);
			pUltimo->setPprox(temp);
			pUltimo = temp;
		}
		len++;
	}
	void pop(TL* item) {
		Elemento<TL> *temp = pPrimeiro;
		Elemento<TL> *tempAnt = nullptr;
		
		while (temp->getItem() != item) {
			tempAnt = temp;
			temp = temp->getPprox();
		}
		if (temp == pPrimeiro) {
			pPrimeiro = temp->getPprox();
		}
		else if (temp == pUltimo) {
			tempAnt->getPprox() = nullptr;
			pUltimo = tempAnt;
		}
		else {
			tempAnt->setPprox(temp->getPprox());
		}
		delete temp;
		len--;
	}
	//void pop&delete(TL* item);
};

template<class TL>
inline Lista<TL>::Lista()
{
	pPrimeiro = nullptr;
	pUltimo = nullptr;
	len = 0;
}

template<class TL>
inline Lista<TL>::~Lista()
{
}
