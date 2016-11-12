
#ifndef SOUNDSTREAM_H
#define SOUNDSTREAM_H
#include"../define_serveur_client.h"
#include<iostream>
#include<vector>
#include<queue>



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

    virtual void onSeek(sf::Time);

    std::queue<std::vector< sf::Int16>>m_echantillon;
    std::size_t m_echantillon_en_cours;
    bool m_initialiser;
    decodeur_audio*m_decodeur;

};

#endif//SOUNDSTREAM_H



