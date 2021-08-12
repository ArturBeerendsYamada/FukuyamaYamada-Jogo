#include "Lista.h"

template <typename TF>
template <typename TE>
Lista<TF>::ElementoLista<TE>::ElementoLista(TE Info, ElementoLista<TE>* Ant, ElementoLista<TE>* Prox) :
info{Info}, pElLAnt{Ant}, pElLProx{Prox} {

}

template <typename TF>
template <typename TE>
Lista<TF>::ElementoLista<TE>::~ElementoLista() {

}

template <typename TF>
template <typename TE>
TE Lista<TF>::ElementoLista<TE>::getInfo() const{
  return info;
}

template <typename TF>
template <typename TE>
void Lista<TF>::ElementoLista<TE>::setInfo(TE Info) {
  info = Info;
}

template <typename TF>
template <typename TE>
Lista<TF>::ElementoLista<TE>* Lista<TF>::ElementoLista<TE>::getAnt() const{
  return pElLAnt;
}

template <typename TF>
template <typename TE>
void Lista<TF>::ElementoLista<TE>::setAnt(ElementoLista<TE>* Ant) {
  pElLAnt = Ant;
}

template <typename TF>
template <typename TE>
Lista<TF>::ElementoLista<TE>* Lista<TF>::ElementoLista<TE>::getProx() const{
  return pElLProx;
}

template <typename TF>
template <typename TE>
void Lista<TF>::ElementoLista<TE>::setProx(ElementoLista<TE>* Prox) {
  pElLProx = Prox;
}

template <typename TF>
template <typename TE>
void Lista<TF>::ElementoLista<TE>::remover() {
  if(pElLAnt){
    pElLAnt->pElLProx = pElLProx;
  }
  if(pElLProx){
    pElLProx->pElLAnt = pElLAnt;
  }
}

template <typename TF>
Lista<TF>::Lista() :
  pElLIn{nullptr}, pElLFin{nullptr}, pElLAt{nullptr} {

}

template <typename TF>
Lista<TF>::~Lista() {
  esvaziar();
}

template <typename TF>
void Lista<TF>::inserir(TF info) {
  if (info) {
    
    ElementoLista<TF>* novo = new ElementoLista<TF>;
    novo->setInfo(info);

    if (!pElLIn) {
    
      pElLIn = novo;
      pElLFin = novo;
    
    } else {
      
      pElLFin->setProx(novo);
      novo->setAnt(pElLFin);

      pElLFin = novo;

    }

  }
}

template <typename TF>
void Lista<TF>::esvaziar() {

  ElementoLista<TF>* paux = nullptr;
  paux = pElLAt = pElLIn;
      
  while (pElLAt != nullptr) {
    paux = pElLAt->getProx();

    delete pElLAt;

    pElLAt = paux;

  }

  pElLIn = nullptr;
  pElLFin = nullptr;
  pElLAt = nullptr;
}

template <typename TF>
TF Lista<TF>::voltarInicio() {
  pElLAt = pElLIn;

  if (pElLAt) 
    return pElLAt->getInfo();
  else 
    return nullptr;

}

template <typename TF>
TF Lista<TF>::irProximo() {

  pElLAt = pElLAt->getProx();

  return (pElLAt) ? pElLAt->getInfo() : nullptr;
}

template <typename TF>
void Lista<TF>::removerElemento(TF elemento)
{
  voltarInicio();
  for(voltarInicio(); pElLAt!=NULL; irProximo())
  {
    if(pElLAt->getInfo() == elemento)
    {
      if(pElLAt == pElLIn)
        pElLIn = pElLAt->getProx();
      if(pElLAt == pElLFin)
        pElLFin = pElLAt->getAnt();
      pElLAt->remover();
      delete pElLAt;
      voltarInicio();
      return;
    }
  }
}