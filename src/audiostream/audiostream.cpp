

#include "audiostream.h"
#if(VERSION_PROJET==1 || VERSION_PROJET ==0)
audiostream::audiostream()
{


}


void audiostream::load(std::array< sf::Int16,TABLE_SIZE> tableau)
{


    std::vector< sf::Int16>tmp(TABLE_SIZE);
    for(int i(0);i<TABLE_SIZE;i++)
    {
        tmp.push_back(tableau[i]);
    }
    m_echantillon.push(tmp);


}

    void audiostream::load(std::vector<sf::Int16>& tableau)
    {

        m_echantillon.push(tableau);
    }

bool audiostream::onGetData(Chunk &data)
{


         if(m_echantillon.size()>=RESERVE_SAMPLE)
         {

             m_echantillon.pop();
             data.samples = &m_echantillon.front()[0];
             data.sampleCount = m_echantillon.front().size();
             return true;

         }
//LOG(this->getStatus())
//         return false;
}


void audiostream::onSeek(sf::Time timeoffset)
{
    //     m_echantillon_en_cours = static_cast<std::size_t>(timeoffset.asSeconds()+getSampleRate()*getChannelCount());
}

void audiostream::lecture_audio()
{

    play();
    std::cout<<"lecture "<<std::endl;
    while(this->getStatus() == audiostream::Playing)
    {
        sf::sleep(sf::seconds(0.1f));
    }
}

void audiostream::initialization(unsigned int canaux, unsigned int taux_echantillonnage)
{
    initialize(canaux,taux_echantillonnage);
    m_initialiser = true;
}
#endif

#if(VERSION_PROJET==2)
audiostream::audiostream()
{
    m_decodeur=opus_decoder_create(FREQUENCE_SAMPLE_OPUS,2,&m_erreur);

}


void audiostream::load(std::array< sf::Int16,TABLE_SIZE> tableau)
{


    std::vector< sf::Int16>tmp;
    tmp.reserve(TABLE_SIZE);
    for(int i(0);i<TABLE_SIZE;i++)
    {
        tmp.push_back(tableau[i]);
    }
    m_echantillon.push(tmp);


}

    void audiostream::load(std::vector<opus_uint8> tableau)
    {
        int taille_decode;
        std::vector<sf::Int16>echantillions(TAILLE_ABSOLU);
        taille_decode=opus_decode(m_decodeur,&tableau[0],tableau.size(),&echantillions[0],VARIABLE_ELEMENTAIRE,0);
        LOG("TAILLE_DECODE",taille_decode);
        echantillions.resize(taille_decode*CANAUX);
        m_echantillon.push(echantillions);

    }

bool audiostream::onGetData(Chunk &data)
{        //const int echantillion_du_flux = TABLE_SIZE;


         if(m_echantillon.size()>=RESERVE_SAMPLE)
         {

             m_echantillon.pop();
             data.samples = &m_echantillon.front()[0];
            //data.sampleCount = TABLE_SIZE;
             LOG("sampleCount",m_echantillon.front().size());
            data.sampleCount = m_echantillon.front().size();
             return true;

         }
}


void audiostream::onSeek(sf::Time timeoffset)
{
    //     m_echantillon_en_cours = static_cast<std::size_t>(timeoffset.asSeconds()+getSampleRate()*getChannelCount());
}

void audiostream::lecture_audio()
{

    play();
    std::cout<<"lecture "<<std::endl;
    while(this->getStatus() == audiostream::Playing)
    {
        sf::sleep(sf::seconds(0.1f));
    }
}

void audiostream::initialization(unsigned int canaux, unsigned int taux_echantillonnage)
{
    initialize(canaux,taux_echantillonnage);
    m_initialiser = true;
}

#endif
