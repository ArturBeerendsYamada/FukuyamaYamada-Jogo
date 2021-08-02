<<<<<<< HEAD
/*#pragma once
=======
#pragma once
#include "Personagem.h"
>>>>>>> c45bac8d0c5c7b779cca9816debfc85aa3d073e5

class GerenciadorGrafico;

class Lista{
    private:
        
        class ElementoLista{
            private:
                Personagem* info;
                ElementoLista* pElLProx;
                ElementoLista* pElLAnt;
            
            public:
                ElementoLista(Personagem* info=nullptr, ElementoLista* Ant=nullptr,ElementoLista* Prox=nullptr);
                ~ElementoLista();

                ElementoLista* getAnt() const;
                void setAnt(ElementoLista* pAnt);
                ElementoLista* getProx() const;
                void setProx(ElementoLista* pProx);
                Personagem* getInfo() const;
                void setInfo(Personagem* in);
        };

        ElementoLista* pElLIn;
        ElementoLista* pElLFin;
        ElementoLista* pElLAt;

    public:
        Lista();
        ~Lista();

        void inserir(Personagem* info);
        void esvaziar();

        Personagem* voltarInicio();
	    Personagem* irProximo();

        void inicializarPersonagens(GerenciadorGrafico &g);
        void atualizarPersonagens(float t);
        void desenharPersonagens(GerenciadorGrafico &g);
        void destruirPersonagens();


};*/