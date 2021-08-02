#include "../headers/ListaPersonagem.h"

Lista::ElementoLista::ElementoLista(Personagem* Info, ElementoLista* Ant,ElementoLista* Prox):
info{Info}, pElLAnt{Ant}, pElLProx{Prox} 
{

}
Lista::ElementoLista::~ElementoLista(){


}

Lista::ElementoLista* Lista::ElementoLista::getAnt() const{
    return pElLAnt;
}
void Lista::ElementoLista::setAnt(ElementoLista* pAnt){
    pElLAnt = pAnt;
}
Lista::ElementoLista* Lista::ElementoLista::getProx() const{
    return pElLProx;
}
void Lista::ElementoLista::setProx(ElementoLista* pProx){
    pElLProx = pProx;
}
Personagem*  Lista::ElementoLista::getInfo() const{
    return info;
}
void Lista::ElementoLista::setInfo(Personagem* in){
    info = in;
}

Lista::Lista():
pElLIn{nullptr}, pElLFin{nullptr}, pElLAt{nullptr}
{
}
Lista::~Lista(){
    esvaziar();
}

void Lista::inserir(Personagem* info){
    if(info){
        ElementoLista* novo = new ElementoLista(info);

        if(!pElLIn){
            pElLIn = novo;
            pElLFin = novo;            
        } else{

            pElLFin->setProx(novo);
            novo->setAnt(pElLFin);

            pElLFin = novo;
        }
    }

}
void Lista::esvaziar(){

    ElementoLista* pAux = pElLIn;
    pElLAt = pElLIn;

    while (pElLAt != nullptr){
        pAux = pElLAt->getProx();

        delete pElLAt;

        pElLAt = pAux;
    }

    pElLIn = nullptr;
    pElLFin = nullptr;
    pElLAt = nullptr;
}

Personagem* Lista::voltarInicio(){
    pElLAt = pElLIn;

    if(pElLAt) 
        return pElLAt->getInfo();
    else return nullptr;
}
Personagem* Lista::irProximo(){

    pElLAt = pElLAt->getProx();

    return (pElLAt) ? pElLAt->getInfo() : nullptr;

}

void Lista::inicializarPersonagens(GerenciadorGrafico &g){
    Personagem* p = voltarInicio();

    while(p){
        p->inicializar(g);

        p = irProximo();
    }
}

void Lista::atualizarPersonagens(float t){
    Personagem* p = voltarInicio();

    while(p){
        p->atualizar(t);

        p=irProximo();
    }
    
}
void Lista::desenharPersonagens(GerenciadorGrafico &g){
    Personagem* p = voltarInicio();

    while(p){
        p->desenhar(g);

        p=irProximo();
    }

}
void Lista::destruirPersonagens(){
    Personagem* p = voltarInicio();

    while(p){

        delete p;

        p= irProximo();
    }

    esvaziar();
}
