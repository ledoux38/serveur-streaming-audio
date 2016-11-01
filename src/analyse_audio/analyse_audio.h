#ifndef ANALYSE_AUDIO_H
#define ANALYSE_AUDIO_H

//#include <SFML/Network.hpp>
//#include <SFML/Audio.hpp>



#include <iostream>
#include "../define_serveur_client.h"
class analyse_audio
{
public:
analyse_audio(const std::string &chemin_fichier);

sf::InputSoundFile& get_fichier_sound(void);
protected:

private:
sf::InputSoundFile m_fichier_sound;

};


#endif //ANALYSE_AUDIO_H
