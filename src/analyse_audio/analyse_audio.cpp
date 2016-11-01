#include "analyse_audio.h"

     analyse_audio::analyse_audio(const std::string &chemin_fichier)
    {

        if (!m_fichier_sound.openFromFile(chemin_fichier))
        {
            std::cerr<<"erreur"<<std::endl;
        }

    }

     sf::InputSoundFile& analyse_audio::get_fichier_sound(void)
     {
         return m_fichier_sound;
     }
