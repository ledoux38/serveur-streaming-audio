
#ifndef SOUNDSTREAM_H
#define SOUNDSTREAM_H

#include<iostream>
#include<vector>
#include<queue>

#include"../define_serveur_client.h"
#include"../decodeur_audio/decodeur_audio.h"

class audiostream : public sf::SoundStream
{
public:
    audiostream();
    void load(std::array< sf::Int16,TABLE_SIZE> tableau);
    void load(std::vector<sf::Int16> &tableau);
    void initialization(unsigned int canaux, unsigned int taux_echantillonnage);
    void lecture_audio();
protected:

private:
    virtual bool onGetData(Chunk &data);

    virtual void onSeek(sf::Time timeoffset);

    std::queue<std::vector< sf::Int16>>m_echantillon;
    std::size_t m_echantillon_en_cours;
    bool m_initialiser;
    decodeur_audio*m_decodeur;

};

#if(VERSION_PROJET == 2)


#ifndef SOUNDSTREAM_H
#define SOUNDSTREAM_H
//#include<SFML/Audio.hpp>
//#include<SFML/Network.hpp>



#include<iostream>
#include<vector>
#include<queue>

#include"../define_serveur_client.h"


class audiostream : public sf::SoundStream
{
public:
    audiostream();
    void load(std::array< sf::Int16,TABLE_SIZE> tableau);
    void load(std::vector<opus_uint8> tableau);
    void reception_donnee_audio(sf::Packet);
    void initialization(unsigned int canaux, unsigned int taux_echantillonnage);
    void lecture_audio();
protected:

private:
    virtual bool onGetData(Chunk &data);

    virtual void onSeek(sf::Time timeoffset);

    std::queue<std::vector< sf::Int16>>m_echantillon;
    std::size_t m_echantillon_en_cours;
    bool m_initialiser;
    int m_erreur;
    OpusDecoder* m_decodeur;

};

#endif//SOUNDSTREAM_H


#endif

#endif//SOUNDSTREAM_H



