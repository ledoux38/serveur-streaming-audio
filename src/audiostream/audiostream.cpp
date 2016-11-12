

#include "audiostream.h"
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

}


void audiostream::onSeek(sf::Time)
{

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
