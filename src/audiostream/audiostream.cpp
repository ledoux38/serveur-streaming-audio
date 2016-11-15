

#include "audiostream.h"
audiostream::audiostream()
{


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


void audiostream::initialization(unsigned int canaux, unsigned int taux_echantillonnage)
{
    initialize(canaux,taux_echantillonnage);
    m_initialiser = true;
}
