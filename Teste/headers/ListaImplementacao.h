  #include "Lista.h"
  
  template <typename TF>
  template <typename TE>
  Lista<TF>::ElementoLista<TE>::ElementoLista(TE Info, ElementoLista<TE>* Ant, ElementoLista<TE>* Prox) :
  info{Info}, pElLAnt{Ant}, pElLAProx{Prox} {

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
    return ant;
  }

  template <typename TF>
  template <typename TE>
  void Lista<TF>::ElementoLista<TE>::setAnt(ElementoLista<TE>* Ant) {
    ant = Ant;
  }

  template <typename TF>
  template <typename TE>
  Lista<TF>::ElementoLista<TE>* Lista<TF>::ElementoLista<TE>::getProx() const{
    return prox;
  }

  template <typename TF>
  template <typename TE>
  void Lista<TF>::ElementoLista<TE>::setProx(ElementoLista<TE>* Prox) {
    prox = Prox;
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
      
      ElementoLista<TF>* novo = new ElementoLista<TF>(info);

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

    ElementoLista<TF>* paux = pElLIn;
    pElLAt = pElLIn;
    
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

    if (pElLAt) return pElLAt->getInfo();
    else return nullptr;

  }

  template <typename TF>
  TF Lista<TF>::irProximo() {

    pElLAt = pElLAt->getProx();

    return (pElLAt) ? pElLAt->getInfo() : nullptr;


  }